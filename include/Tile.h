#pragma once
#include <SFML/Graphics.hpp>

//tile luokka sis‰lt‰‰ tietoa yksitt‰isist‰ tiilist‰.
//koska maailma on ruudukko, voimme s‰ilytt‰‰ tiilien datan helposti matriisissa/multidim.arrayss‰.

class Tile
{
public:
	Tile();
	~Tile();
	sf::Sprite tileSprite;
	sf::Texture tileTexture;
	sf::Vector2<int> worldPos;
	//spriten sijainti "maailma kordinaatistossa"
	bool collisions;
	//onko t‰ll‰ tilell‰ collisionit p‰‰ll‰?





};

