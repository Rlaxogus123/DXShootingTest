#pragma once
class Scene
{
public:
	Scene();
	~Scene();

	vector<Node*> v_node;
public:
	virtual void Enter();
	virtual void Update();
	virtual void Render();
	virtual void Exit();

	static bool Comp(Node* a, Node* b);
	bool AABB(WCHAR* head1, WCHAR* head2);
	bool SphereVsOther(WCHAR* sphere, WCHAR* other);
	bool SphereVsPoint(WCHAR* sphere, WCHAR* point);
	bool SphereVsBox(WCHAR* sphere, WCHAR* box);
};

