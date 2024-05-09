//GameObject.cpp
#include "GameObject.h"
#include "Vector3.h"
#include <algorithm>

GameObject::GameObject()
{
	// IMPORTANT: Set LocalPosition.Z to 1 to ensure children will inherit translations
	LocalPosition = Mine::Vector3(0, 0, 1);
	LocalRotation = 0;
	LocalScale = Mine::Vector3(1, 1, 1);
}

void GameObject::OnUpdate(float deltaTime)
{
	// left intentionally blank
}

void GameObject::OnDraw()
{
	// left intentionally blank
}

void GameObject::Update(float deltaTime)
{
	OnUpdate(deltaTime);

	// TODO: iterate through children and call Update on them
}

void GameObject::Draw()
{
	OnDraw();

	// TODO: iterate through children and call Draw on them
}

GameObject::GameObject()
{
	Parent = nullptr;

	// IMPORTANT: SetLocalPosition.Z to 1 if translation should be inherited
	LocalPosition = Mine::Vector3(0, 0, 1);
	LocalRotation = 0;
	LocalScale = Mine::Vector3(1, 1, 1);
}

void GameObject::SetParent(GameObject* newParent)
{
	// remove from existing parent if any
	if (Parent != nullptr)
	{
		// returns an iterator to this child in its parent's vector of children
		auto findIt = std::find(Parent->Children.begin(), Parent->Children.end(), this);

		// if found, iterator will be something besides the end of the vector
		if (findIt != Parent->Children.end())
		{
			Parent->Children.erase(findIt);
			Parent = nullptr;
		}
	}

	// add to new parent if any
	if (newParent != nullptr)
	{
		Parent = newParent;
		Parent->Children.push_back(this);
	}
}

GameObject* GameObject::GetParent()
{
	return Parent;
}

const GameObject* GameObject::GetParent() const
{
	return Parent;
}

GameObject* GameObject::GetChild(size_t childIndex)
{
	return Children[childIndex];
}

const GameObject* GameObject::GetChild(size_t childIndex) const
{
	return Children[childIndex];
}