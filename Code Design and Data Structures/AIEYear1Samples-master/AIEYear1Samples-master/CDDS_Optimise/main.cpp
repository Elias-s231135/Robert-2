/*******************************************************************************************
*
*   raylib [core] example - Basic window
*
*   Welcome to raylib!
*
*   To test examples, just press F6 and execute raylib_compile_execute script
*   Note that compiled executable is placed in the same folder as .c file
*
*   You can find all basic examples on C:\raylib\raylib\examples folder or
*   raylib official webpage: www.raylib.com
*
*   Enjoy using raylib. :)
*
*   This example has been created using raylib 1.0 (www.raylib.com)
*   raylib is licensed under an unmodified zlib/libpng license (View raylib.h for details)
*
*   Copyright (c) 2014 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "raylib.h"
#include "raymath.h"
#include <random>
#include <time.h>
#include "Critter.h"
#include "ObjectPool.h"
#include "HashTable.h"

int main(int argc, char* argv[])
{
    // Initialization
    //--------------------------------------------------------------------------------------
    int screenWidth = 800;
    int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "raylib [core] example - basic window");

    //SetTargetFPS(60);
    //--------------------------------------------------------------------------------------

    //Texture2D bigS("res/9.png");
    //Texture2D smallS("res/10.png");

    srand(time(NULL));

    HashTable textures(2);

    // array for small critters
    //Critter critters[1000];
   
    Texture2D critterSprite = LoadTexture("res/10.png");
    Texture2D destroyerSprite = LoadTexture("res/9.png");

    HashTable critterTextures(20);
    critterTextures.AddTo("critterS", critterSprite);
    critterTextures.AddTo("destroyerS", destroyerSprite);

    // create some critters
    const int CRITTER_COUNT = 50;
    const int MAX_VELOCITY = 80;

    ObjectPool critterPool(CRITTER_COUNT);

    //
    // for loop that creates small critters
    for (int i = 0; i < CRITTER_COUNT; i++)
    {
        // create a random direction vector for the velocity
        Vector2 velocity = { -100+(rand()%200), -100+(rand()%200) };
        // normalize and scale by a random speed
        velocity = Vector2Scale(Vector2Normalize(velocity), MAX_VELOCITY);

        Critter tempCritter;

        // create a critter in a random location
        tempCritter.Init(
            { (float)(5+rand() % (screenWidth-10)), (float)(5+(rand() % screenHeight-10)) },
            velocity,
            12, critterTextures["critterS"]);
        critterPool.Allocate(tempCritter);
            /*LoadTexture("res/10.png")*/;
    }
    //

    // big critter
    Critter destroyer;
    Vector2 velocity = { -100 + (rand() % 200), -100 + (rand() % 200) };
    velocity = Vector2Scale(Vector2Normalize(velocity), MAX_VELOCITY);
    destroyer.Init(Vector2{ (float)(screenWidth >> 1), (float)(screenHeight >> 1) }, velocity, 20, critterTextures["destroyerS"]);

    float timer = 1;
    Vector2 nextSpawnPos = destroyer.GetPosition();

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------
        // TODO: Update your variables here
        //----------------------------------------------------------------------------------

        float delta = GetFrameTime();

        // update the destroyer
        destroyer.Update(delta);

        /*for (int i = 0; i < CRITTER_COUNT; i++)
        {
            LoadTexture("res/10.png");
        };*/

        // check each critter against screen bounds
        if (destroyer.GetX() < 0) {
            destroyer.SetX(0);
            destroyer.SetVelocity(Vector2{ -destroyer.GetVelocity().x, destroyer.GetVelocity().y });
        }
        if (destroyer.GetX() > screenWidth) {
            destroyer.SetX(screenWidth);
            destroyer.SetVelocity(Vector2{ -destroyer.GetVelocity().x, destroyer.GetVelocity().y });
        }
        if (destroyer.GetY() < 0) {
            destroyer.SetY(0);
            destroyer.SetVelocity(Vector2{ destroyer.GetVelocity().x, -destroyer.GetVelocity().y });
        }
        if (destroyer.GetY() > screenHeight) {
            destroyer.SetY(screenHeight);
            destroyer.SetVelocity(Vector2{ destroyer.GetVelocity().x, -destroyer.GetVelocity().y });
        }

        // update the critters
        // (dirty flags will be cleared during update)
        for (int i = 0; i < critterPool.CurrentUsed(); i++)
        {
            critterPool.GetAlive()[i].Update(delta);

            // check each critter against screen bounds
            if (critterPool.GetAlive()[i].GetX() < 0) {
                critterPool.GetAlive()[i].SetX(0);
                critterPool.GetAlive()[i].SetVelocity(Vector2{ -critterPool.GetAlive()[i].GetVelocity().x, critterPool.GetAlive()[i].GetVelocity().y });
            }
            if (critterPool.GetAlive()[i].GetX() > screenWidth) {
                critterPool.GetAlive()[i].SetX(screenWidth);
                critterPool.GetAlive()[i].SetVelocity(Vector2{ -critterPool.GetAlive()[i].GetVelocity().x, critterPool.GetAlive()[i].GetVelocity().y });
            }
            if (critterPool.GetAlive()[i].GetY() < 0) {
                critterPool.GetAlive()[i].SetY(0);
                critterPool.GetAlive()[i].SetVelocity(Vector2{ critterPool.GetAlive()[i].GetVelocity().x, -critterPool.GetAlive()[i].GetVelocity().y });
            }
            if (critterPool.GetAlive()[i].GetY() > screenHeight) {
                critterPool.GetAlive()[i].SetY(screenHeight);
                critterPool.GetAlive()[i].SetVelocity(Vector2{ critterPool.GetAlive()[i].GetVelocity().x, -critterPool.GetAlive()[i].GetVelocity().y });
            }

        //
            // kill any critter touching the destroyer
            // simple circle-to-circle collision check
            float dist = Vector2Distance(critterPool.GetAlive()[i].GetPosition(), destroyer.GetPosition());
            if (dist < critterPool.GetAlive()[i].GetRadius() + destroyer.GetRadius())
            {
                critterPool.GetAlive()[i].Destroy();
                // this would be the perfect time to put the critter into an object pool
                critterPool.Deallocate(i);
            }
        }
        //       

        // check for critter-on-critter collisions
        for (int i = 0; i < CRITTER_COUNT; i++)
        {            
            for (int j = 0; j < CRITTER_COUNT; j++){
                if (i == j || critterPool.GetAlive()[i].IsDirty()) // note: the other critter (j) could be dirty - that's OK
                    continue;
                // check every critter against every other critter
                float dist = Vector2Distance(critterPool.GetAlive()[i].GetPosition(), critterPool.GetAlive()[j].GetPosition());
                if (dist < critterPool.GetAlive()[i].GetRadius() + critterPool.GetAlive()[j].GetRadius())
                {
                    // collision!
                    // do math to get critters bouncing
                    Vector2 normal = Vector2Normalize( Vector2Subtract(critterPool.GetAlive()[j].GetPosition(), critterPool.GetAlive()[i].GetPosition()));

                    // not even close to real physics, but fine for our needs
                    critterPool.GetAlive()[i].SetVelocity(Vector2Scale(normal, -MAX_VELOCITY));
                    // set the critter to *dirty* so we know not to process any more collisions on it
                    critterPool.GetAlive()[i].SetDirty(); 

                    // we still want to check for collisions in the case where 1 critter is dirty - so we need a check 
                    // to make sure the other critter is clean before we do the collision response
                    if (!critterPool.GetAlive()[j].IsDirty()) {
                        critterPool.GetAlive()[j].SetVelocity(Vector2Scale(normal, MAX_VELOCITY));
                        critterPool.GetAlive()[j].SetDirty();
                    }
                    break;
                }
            }
        }

        timer -= delta;
        if (timer <= 0)
        {
            timer = 1;

            // find any dead critters and spit them out (respawn)
            for (int i = critterPool.CurrentUsed(); i < critterPool.CurrentSize(); i++)
            {
                Vector2 normal = Vector2Normalize(destroyer.GetVelocity());

                // get a position behind the destroyer, and far enough away that the critter won't bump into it again
                Vector2 pos = destroyer.GetPosition();
                pos = Vector2Add(pos, Vector2Scale(normal, -50));
                // its pretty ineficient to keep reloading textures. ...if only there was something else we could do
                Critter tempCritter;
                tempCritter.Init(pos, Vector2Scale(normal, -MAX_VELOCITY), 12, critterTextures["critterS"]);

                critterPool.Allocate(tempCritter);
                break;
                
            }
            nextSpawnPos = destroyer.GetPosition();
        }

        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

        ClearBackground(RAYWHITE);

        // draw the critters
        for (int i = 0; i < CRITTER_COUNT; i++)
        {
            critterPool.GetAlive()[i].Draw();
        }
        // draw the destroyer
        // (if you're wondering why it looks a little odd when sometimes critters are destroyed when they're not quite touching the 
        // destroyer, it's because the origin is at the top-left. ...you could fix that!)
        destroyer.Draw();

        DrawFPS(10, 10);
        //DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    for (int i = 0; i < CRITTER_COUNT; i++)
    {
        critterPool.GetAlive()[i].Destroy();
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------   
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}