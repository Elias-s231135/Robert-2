// main.cpp
#include "raylib-cpp.hpp"   // for raylib API
#include "SpriteObject.h"   // for our drawable object
#include "TankPlayer.h"     // for TankPlayer
#include "TurretPlayer.h"   // for TurretPlayer
#include "PivotPlayer.h"    // for PivotPlayer

int main() {
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;
    raylib::Color textColor = raylib::Color::LightGray();
    raylib::Window window(screenWidth, screenHeight, "raylib [core] example - basic window");

    SetTargetFPS(60);

    raylib::Texture2D tankSprite("res/tankBody_red_outline.png");
    raylib::Texture2D turretSprite("res/tankRed_barrel1_outline.png");
    
    TankPlayer Player;
    Player.Sprite = &tankSprite;
    Player.SetLocalPosition(screenWidth / 2, screenHeight / 2);

    PivotPlayer Point;
    // No sprite necessary
    Point.SetLocalPosition(6, 0);
    Point.SetParent(&Player);

    TurretPlayer Turret;
    Turret.Sprite = &turretSprite;
    Turret.SetLocalPosition(25, 0);
    Turret.SetParent(&Point);

    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!window.ShouldClose()) {   // Detect window close button or ESC key
        // Update
        //----------------------------------------------------------------------------------
        // Update your variables here

        float deltaTime = window.GetFrameTime();

        Player.Update(deltaTime);
        Point.Update(deltaTime);
        Turret.Update(deltaTime);

        //-------------------------------------------------r---------------------------------

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();
        {
            window.ClearBackground(BEIGE);

            Player.Draw();
            Turret.Draw();
        }
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    return 0;
}