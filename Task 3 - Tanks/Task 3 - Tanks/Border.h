#pragma once
#include "raylib-cpp.hpp"   // for raylib API
#include "GameObject.h"

class Border : public GameObject
{
public:
    
    //Mine::Vector3 cornerTopLeft(0, 0, 0);
    //Mine::Vector3 cornerTopRight(800, 0, 0);
    //Mine::Vector3 cornerBottomLeft(0, 450, 0);
    //Mine::Vector3 cornerBottomRight(800, 450, 0);

 /*   Mine::Vector3 cornerTopLeft = Mine::Vector3(0, 0, 0);
    Mine::Vector3 cornerTopRight = Mine::Vector3(800, 0, 0);
    Mine::Vector3 cornerBottomLeft = Mine::Vector3(0, 450, 0);
    Mine::Vector3 cornerBottomRight = Mine::Vector3(800, 450, 0);*/

   /* Border* borderTop;
    Border* borderBottom;
    Border* borderLeft;
    Border* borderRight;*/

    raylib::Vector2 startSmall;
    raylib::Vector2 endSmall;

public:
    
    Border(Mine::Vector3 start, Mine::Vector3 end);

   void OnDraw() override;

//   void BorderT();
//   void BorderR();
//   void BorderB();
//   void BorderL();
//
//    void OnDraw() override;
};

