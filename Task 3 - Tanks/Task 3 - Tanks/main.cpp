// main.cpp
#include "raylib-cpp.hpp"   // for raylib API
#include "SpriteObject.h"   // for our drawable object
#include "TankPlayer.h"     // for TankPlayer
#include "TurretPlayer.h"   // for TurretPlayer
#include "PivotPlayer.h"    // for PivotPlayer
#include "Bullet.h"         // for Bullet
#include "Colliders.h"      // for Colliders

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "Tank");
   /* Mine::Vector3 cornerTopLeft (0, 0, 0);
    Mine::Vector3 cornerTopRight(800, 0, 0);
    Mine::Vector3 cornerBottomLeft(0, 450, 0);
    Mine::Vector3 cornerBottomRight(800, 450, 0);*/

    SetTargetFPS(60);

    raylib::Texture2D tankSprite("res/tankBody_red_outline.png");
    raylib::Texture2D turretSprite("res/tankRed_barrel1_outline.png");
    raylib::Texture2D bulletSprite("res/bulletRed2_outline.png"); // change to a bullet before submitting
    
    GameObject root;

    TankPlayer Player;
    Player.Sprite = &tankSprite;
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);
    Player.SetParent(&root);

    PivotPlayer Point;
    // No sprite necessary
    Point.SetLocalPosition(6, 0);
    Point.SetParent(&Player);

    TurretPlayer Turret;
    Turret.Sprite = &turretSprite;
    Turret.SetLocalPosition(25, 0);
    Turret.SetParent(&Point);

    Turret.bulletTexture = &bulletSprite;

    //Plane leftSide(cornerTopLeft, cornerBottomRight);


    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {   // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        // Update your variables here

        float deltaTime = window.GetFrameTime();

        //Player.Update(deltaTime);
        //Point.Update(deltaTime);
        //Turret.Update(deltaTime);

        root.Update(deltaTime);

        //-----------------------------------------------------------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(Color { 250, 217, 175, 255 });

            //Player.Draw();
            //Turret.Draw();

            root.Draw();
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}