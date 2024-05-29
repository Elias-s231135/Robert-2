#pragma once

#include "SpriteObject.h"

class Border : public SpriteObject
{
public:

    //Mine::Vector3 cornerTopLeft(0, 0, 0);
    //Mine::Vector3 cornerTopRight(800, 0, 0);
    //Mine::Vector3 cornerBottomLeft(0, 450, 0);
    //Mine::Vector3 cornerBottomRight(800, 450, 0);

    Mine::Vector3 cornerTopLeft = Mine::Vector3(0, 0, 0);
    Mine::Vector3 cornerTopRight = Mine::Vector3(800, 0, 0);
    Mine::Vector3 cornerBottomLeft = Mine::Vector3(0, 450, 0);
    Mine::Vector3 cornerBottomRight = Mine::Vector3(800, 450, 0);

public:
    
   Border();

   void BorderT();
   void BorderR();
   void BorderB();
   void BorderL();

    void OnDraw() override;
};

