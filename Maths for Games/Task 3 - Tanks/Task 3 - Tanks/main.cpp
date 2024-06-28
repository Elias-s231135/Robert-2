// main.cpp
#include "raylib-cpp.hpp"   // for raylib API
#include "SpriteObject.h"   // for our drawable object
#include "TankPlayer.h"     // for TankPlayer
#include "TurretPlayer.h"   // for TurretPlayer
#include "PivotPlayer.h"    // for PivotPlayer
#include "Bullet.h"         // for Bullet
#include "Colliders.h"      // for Colliders
#include "Crate.h"          // for Crate
//#include "Plane.h"          // for Plane
#include "Border.h"         // for Border

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "Tank");
    Mine::Vector3 cornerTopLeft (0, 0, 0);
    Mine::Vector3 cornerTopRight(screenWidth, 0, 0);
    Mine::Vector3 cornerBottomLeft(0, screenHeight, 0);
    Mine::Vector3 cornerBottomRight(screenWidth, screenHeight, 0);
    

    SetTargetFPS(60);

    raylib::Texture2D tankSprite("res/aie.png");
    raylib::Texture2D turretSprite("res/aie.png");
    raylib::Texture2D bulletSprite("res/aie.png"); // change to a bullet before submitting
    raylib::Texture2D crateSprite("res/aie.png");

    GameObject root;
    GameObject::SetRoot(&root);
    std::vector <Collider*> cols;

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

    Crate crate(Mine::Vector3(200, 112, 1));
    crate.Sprite = &crateSprite;
    crate.SetParent(&root);



    Border borderLeft(cornerTopLeft, cornerBottomLeft);
    borderLeft.SetParent(&root);
    
    Border borderRight(cornerTopRight, cornerBottomRight);
    borderRight.SetParent(&root);
    
    Border borderTop(cornerTopLeft, cornerTopRight);
    borderTop.SetParent(&root);
    
    Border borderBottom(cornerBottomLeft, cornerBottomRight);
    borderBottom.SetParent(&root);



    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {   // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        // Update your variables here

        float deltaTime = window.GetFrameTime();
        cols.clear();
        root.GetAllColliders(cols);

        for (size_t i = 0; i < cols.size(); i++)
        {

            for (size_t j = 0; j < cols.size(); j++)
            {


                if (i == j)
                {

                }
                else
                {
                    cols[i]->CheckCollision(cols[j]);
                }
            }
        }

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