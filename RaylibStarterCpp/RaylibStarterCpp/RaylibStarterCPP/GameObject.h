// GameObject.h
#pragma once
#include <vector>

#include "Vector3.h"
#include "Matrix3.h"

class GameObject
{
protected:
    // The position of this object relative to its parent
    Mine::Vector3 LocalPosition;

    // The rotation of this object relative to its parent, in radians
    float LocalRotation;

    // The scale of this object relative to its parent
    Mine::Vector3 LocalScale;

    // Called when this specific object needs to update
    virtual void OnUpdate(float deltaTime);

    // Called when this specific object needs to draw to the screen
    virtual void OnDraw();

    // Pointer to your parent (or nullptr if none)
    GameObject* Parent;
    // Vector of children
    std::vector<GameObject*> Children;

public:
    // Set default values for its data members (e.g., Local Position)
    GameObject();

    //
    // Gameplay
    //

    // Updates this object and all of its children
    void Update(float deltaTime);
    // Draws this object and all of its children
    void Draw();

    // Set a new parent for this object and/or unassign it from its parent
    void SetParent(GameObject* parent);
    // Get the current parent for this object
    GameObject* GetParent();
    // Get the current parent for this object - const-qualified
    const GameObject* GetParent() const;

    // Get a child at specific index from its vector of children
    const GameObject* GetChild(size_t childIndex) const;
};
