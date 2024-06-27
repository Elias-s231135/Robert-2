#pragma once

//class Player
//{
//public:
//	Player();
//	Player(const char* name);
//	Player(int a_max_ammo, int a_max_health);
//	Player(float x, float y);
//	Player(Player& a_player);
//
//	float X, Y;
//	int ammo;
//	int max_ammo;
//	int health;
//	int max_health;
//	char name[64];
//};
//
//class Player
//{
//public:
//	struct Bullet { float x, y; };
//
//	Player(int max_ammo)
//	{
//		bullets = new Bullet[max_ammo];
//		ammo = 0;
//		health = 0;
//		max_health = 100;
//	}
//
//	~Player(); // implement this
//
//	int health;
//	int max_health;
//	int ammo;
//	int max_ammo;
//	Bullet* bullets;
//};
//class TileMap
//{
//public:
//	struct Tile { int x, y; int tile_value; };
//
//	TileMap(int a_width, int a_height)
//	{
//		width = a_width;
//		height = a_height;
//
//		tiles = new Tile*[height];
//
//		for (int row_index = 0;
//			row_index < height;
//			++row_index)
//		{
//			tiles[row_index] = new Tile[width];
//		}
//	}
//	~TileMap(); // implement this
//
//	int width;
//	int height;
//	Tile** tiles;
//};
class Texture
{
public:
	Texture(char* a_filepath,
		int a_width,
		int a_height,
		int a_bytes_per_pixel)
	{
		int path_len = strlen(a_filepath);
		filepath = new char[path_len + 1];
		strcpy(filepath, a_filepath);

		width = a_width;
		height = a_height;

		pixel_data = new char[width * height * a_bytes_per_pixel];
	}

	~Texture(); // implement this

	char * filepath;
	char * pixel_data;
	int width;
	int height;
};