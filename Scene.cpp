#include "DXUT.h"
#include "Include.h"

Scene::Scene()
{
}

Scene::~Scene()
{
}

void Scene::Enter()
{
}

void Scene::Update()
{
	for (auto n : v_node)
	{
		if (n->IsActive)
			n->Update();
	}
}

void Scene::Render()
{
	sort(v_node.begin(), v_node.end(), Comp);
	for (auto n : v_node)
	{
		if (n->IsActive)
			n->Render();
	}
}

void Scene::Exit()
{
}

bool Scene::Comp(Node* a, Node* b)
{
	return (a->nLayer < b->nLayer);
}

bool Scene::AABB(WCHAR* head1, WCHAR* head2)
{
	for (auto n : v_node)
	{
		if (n->tag == head1)
		{
			for (auto n2 : v_node)
			{
				if (n2->tag == head2)
				{
					RECT r;
					return (IntersectRect(&r, &n->ColRect, &n2->ColRect));
				}
			}
		}
	}

	return false;
}

bool Scene::SphereVsOther(WCHAR* sphere, WCHAR* other)
{
	for (auto Nsphere : v_node)
	{
		if (Nsphere->tag == sphere)
		{
			for (auto Nother : v_node)
			{
				if (Nother->tag == other)
				{
					float distance = sqrt(
						(Nsphere->position.x - Nother->position.x) * (Nsphere->position.x - Nother->position.x) 
						+ (Nsphere->position.y - Nother->position.y) * (Nsphere->position.y - Nother->position.y));

					return distance < (Nsphere->rotation + Nother->rotation);
				}
			}
		}
	}

	return false;
}

bool Scene::SphereVsPoint(WCHAR* sphere, WCHAR* point)
{
	for (auto Nsphere : v_node)
	{
		if (Nsphere->tag == sphere)
		{
			for (auto Npoint : v_node)
			{
				if (Npoint->tag == point)
				{
					float distance = sqrt(
						(Npoint->position.x - Nsphere->position.x) * (Npoint->position.x - Nsphere->position.x) +
						(Npoint->position.y - Nsphere->position.y) * (Npoint->position.y - Nsphere->position.y));
					return distance < Nsphere->rotation;
				}
			}
		}
	}

	return false;
}

bool Scene::SphereVsBox(WCHAR* sphere, WCHAR* box)
{
	for (auto Nsphere : v_node)
	{
		if (Nsphere->tag == sphere)
		{
			for (auto Nbox : v_node)
			{
				if (Nbox->tag == box)
				{
					float x = max(Nbox->ImgRect.left, min(Nsphere->position.x, Nbox->ImgRect.right));
					float y = max(Nbox->ImgRect.top , min(Nsphere->position.y, Nbox->ImgRect.bottom));

					float distance = sqrt(
						(x - Nsphere->position.x) * (x - Nsphere->position.x) +
						(y - Nsphere->position.y) * (y - Nsphere->position.y));

					return distance < Nsphere->rotation;
				}
			}
		}
	}

	return false;
}
