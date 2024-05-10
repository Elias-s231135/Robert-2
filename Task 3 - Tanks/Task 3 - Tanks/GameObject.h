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
    
    //// Gets an angle
    //void AngleFrom2D(Mine::Vector3(fwd));
    
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
    GameObject* GetChild(size_t childIndex);
    // Get a child at specific index from its vector of children - const-qualified
    const GameObject* GetChild(size_t childIndex) const;

    // Gets its local position relative to its parent
    Mine::Vector3 GetLocalPosition() const;
    // Set its local position relative to its parent
    void SetLocalPosition(Mine::Vector3 newPosition);
    // Set its local position relative to its parent
    void SetLocalPosition(float newX, float newY);

    // Get its world position
    Mine::Vector3 GetWorldPosition() const;

    // Get its local rotation relative to its parent
    float GetLocalRotation() const;
    // Set its local rotation relative to its parent
    void SetLocalRotation(float newRotation);

    // Get its world rotation
    float GetWorldRotation() const;

    // Get its local scale relative to its parent
    Mine::Vector3 GetLocalScale() const;
    // Set its local scale relative to its parent
    void SetLocalScale(Mine::Vector3 newScale);
    // Set its local scale relative to its parent
    void SetLocalScale(float newX, float newY);

    // Get its world scale
    Mine::Vector3 GetWorldScale() const;

    // Get the direction it is facing in world-space
    Mine::Vector3 GetForward() const;

    //Get its local transformation matrix
    Mine::Matrix3 GetLocalMatrix() const;
    // Get its world transformation matrix
    Mine::Matrix3 GetWorldMatrix() const;

    //Transformations

    // Move locally on X and Y axis - Z is untouched
    void Translate(float x, float y);
    // Move locally on X, Y, Z axes
    void Translate(Mine::Vector3 translation);

    // Rotate locally by given number of radians
    void Rotate(float radians);

    // Scale locally on X and Y axis - Z is untouched
    void Scale(float x, float y);
    // Scale locally on X, Y, Z axes
    void Scale(Mine::Vector3 scalar);
};
