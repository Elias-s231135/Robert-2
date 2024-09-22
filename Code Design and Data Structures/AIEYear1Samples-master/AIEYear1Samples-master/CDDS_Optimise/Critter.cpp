#include "Critter.h"


Critter::Critter()
{
	// Constructor
	m_position = Vector2{ 0, 0 };
	m_velocity = Vector2{ 0, 0 };
	m_radius = 0;
	m_isLoaded = false;
}

Critter::~Critter()
{
	// Deconstructor
	//UnloadTexture(m_texture);
	m_isLoaded = false;
}


//
void Critter::Init(Vector2 position, Vector2 velocity, float radius, Texture2D texture)
{
	// Constructor that takes in values + texture
	m_position = position;
	m_velocity = velocity;
	m_radius = radius;
	
	m_texture = texture;	

	m_isLoaded = true;
}

void Critter::Destroy()
{
	// Destroys Critter
	//UnloadTexture(m_texture);
	m_isLoaded = false;
}
//

void Critter::Update(float dt)
{
	// Updates the Critter
	if (m_isLoaded == false)
		return;

	m_position.x += m_velocity.x * dt;
	m_position.y += m_velocity.y * dt;

	m_isDirty = false;
}


void Critter::Draw()
{
	// Draws the Critter

	if (m_isLoaded == false)
		return;

	DrawTexture(m_texture, m_position.x, m_position.y, WHITE);
}
