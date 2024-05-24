//GameObject.cpp
#include "GameObject.h"
#include "Vector3.h"
#include <algorithm>

//void GameObject::AngleFrom2D(Mine::Vector3(fwd))
//{
//	fwd = atan(fwd.x);
//}

static GameObject* m_root;

GameObject* GameObject::GetRoot()
{
	return m_root;
}

void GameObject::SetRoot(GameObject* go)
{
	m_root = go;
}

GameObject::GameObject()
{
	Parent = nullptr;
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

	// TODO: iterate through children and call Update on them.

	for (size_t i = 0; i < Children.size(); i++)
	{
		Children[i]->Update(deltaTime);
	}

	//get the size of the children vector by using .size()
	//use a for loop to loop increment values of i until i >= size()
	//we will iterate through every object in that vector
	
	//for(int i = 0; i < "vector name".size(); i++) 

	//std::vector<Thing> things;
	//things.push_back("Object of type <Thing>") //that object will be added "pushed back" to the vector

}

void GameObject::Draw()
{
	OnDraw();

	// TODO: iterate through children and call Draw on them
	for (size_t i = 0; i < Children.size(); i++)
	{
		Children[i]->Draw();
	}
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

Mine::Vector3 GameObject::GetLocalPosition() const
{
	return LocalPosition;
}

void GameObject::SetLocalPosition(Mine::Vector3 newPosition)
{
	LocalPosition = newPosition;
}

void GameObject::SetLocalPosition(float newX, float newY)
{
	LocalPosition = Mine::Vector3(newX, newY, LocalPosition.z);
}

float GameObject::GetLocalRotation() const
{
	return LocalRotation;
}

void GameObject::SetLocalRotation(float newRotation)
{
	LocalRotation = newRotation;
}

Mine::Vector3 GameObject::GetLocalScale() const
{
	return LocalScale;
}

void GameObject::SetLocalScale(Mine::Vector3 newScale)
{
	LocalScale = newScale;
}

void GameObject::SetLocalScale(float newX, float newY)
{
	LocalScale = Mine::Vector3(newX, newY, LocalScale.z);
}

Mine::Matrix3 GameObject::GetLocalMatrix() const
{
	return
		Mine::Matrix3::MakeTranslation(LocalPosition) *
		Mine::Matrix3::MakeRotateZ(LocalRotation) *
		Mine::Matrix3::MakeScale(LocalScale.x, LocalScale.y);
}

Mine::Matrix3 GameObject::GetWorldMatrix() const
{
	// no parent - use as-is
	if (Parent == nullptr)
	{
		return GetLocalMatrix();
	}
	// combine w/ parent's world
	else
	{
		return Parent->GetWorldMatrix() * GetLocalMatrix();
	}
}

Mine::Vector3 GameObject::GetWorldPosition() const
{
	Mine::Matrix3 worldMat = GetWorldMatrix();
	return Mine::Vector3(worldMat.m7, worldMat.m8, worldMat.m9);
}

float GameObject::GetWorldRotation() const
{
	Mine::Vector3 fwd = GetForward();
	//return AngleFrom2D(fwd.x, fwd.y);
	return atan2f(fwd.y, fwd.x); //returning angle in radians of forward compared to x-axis

}

Mine::Vector3 GameObject::GetWorldScale() const
{
	// calculate the local transform matrix
	Mine::Matrix3 myTransform = GetWorldMatrix();

	return Mine::Vector3(Mine::Vector3(myTransform.m1, myTransform.m2, 0).Magnitude(),
						 Mine::Vector3(myTransform.m4, myTransform.m5, 0).Magnitude(),
						 1.0f);
}

Mine::Vector3 GameObject::GetForward() const
{
	auto mat = GetWorldMatrix();
	return Mine::Vector3(mat[0], mat[1], mat[2]);
}

void GameObject::Translate(float x, float y)
{
	LocalPosition += Mine::Vector3(x, y, 0);
}

void GameObject::Translate(Mine::Vector3 translation)
{
	LocalPosition += translation;
}

void GameObject::Rotate(float radians)
{
	LocalRotation += radians;
}

void GameObject::Scale(float x, float y)
{
	LocalScale *= Mine::Vector3(x, y, 1);
}

void GameObject::Scale(Mine::Vector3 scaling)
{
	LocalScale *= scaling;
}

void GameObject::GetAllColliders(std::vector<Collider*>& c)
{
	if (m_collider != nullptr)
	{
		c.push_back(m_collider);
	}

	for (size_t i = 0; i < Children.size(); i++)
	{
		Children[i]->GetAllColliders(c);
	}
}

void GameObject::OnCollision()
{
}

void GameObject::Destroy()
{

	Parent->Children.erase(std::remove(Parent->Children.begin(), Parent->Children.end(), this), Parent->Children.end());
	//SetParent(nullptr);
	Parent = nullptr;
	//delete this; ----- call deconstructor instead
}

