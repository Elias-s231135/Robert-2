#include <iostream>
#include "TurretPlayer.h"
#include "Bullet.h"
#include <thread>

using namespace std;
using namespace std::this_thread;

void TurretPlayer::OnUpdate(float deltaTime)
{
		float radRotation = GetWorldRotation();

	float degRotation = (GetWorldRotation() / PI * 180);

		if (IsKeyPressed(KeyboardKey::KEY_SPACE))
		{
			Bullet* bullet = new Bullet();	//change to be heap allocated (new Keyword)	// No longer necessary
			bullet->Sprite = bulletTexture;
			// cout << degRotation << endl;	//Debug
			//bullet.Draw(); 
			//bullet.Update();
			bullet->SetLocalPosition(this->GetWorldPosition());
			bullet->SetLocalRotation(this->GetWorldRotation());

			//Add the bullet to a storage container in this object
			//bullets.push_back(bullet);
			bullet->SetParent(GameObject::GetRoot());
		};

		////loop through all our stored bullets and update them
		//for (int i = 0; i < bullets.size(); i++)
		//{
		//	bullets[i]->Update(deltaTime);
		//}
}

void TurretPlayer::OnDraw()
{
	SpriteObject::OnDraw();

	////Loop through all our stored bullets and draw them here
	//for (int i = 0; i < bullets.size(); i++)
	//{
	//	bullets[i]->Draw();
	//}

}


//The Bullet Problem:
/*
1.Pass our bullet sprite ref(loaded in main) to out TurretPlayer

2.Create a std::vector container to store our current bullets in TurretPlayer class

3.Change Bullets to be allocated on the heap (use the new keyword when making bullets)

4.After we create our bullets and set them up(location, rotation, setting sprite)
  add that readied bullet to our vector

5.Add our bullet draw + update loops to our TurretPlayer OnDraw + OnUpdate 
*/
