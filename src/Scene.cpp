#include "..\include\Scene.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <vector>

//initiate generic scene with default assets
Scene::Scene(unsigned int screenHeightOffset)
{
	sf::Vector2f cameraWorldPos = sf::Vector2f(0,0);
	//init camera

	worldSize = sf::Vector2u(256, 32);
	Tiles[worldSize.x][worldSize.y];
	unsigned int tileSize = 16;
	sceneBackgroundTex.loadFromFile("../defaultBG.png");
	sceneBackgroundSprite.setTexture(sceneBackgroundTex);

	//init tile atlas
	if (!tileAtlas.loadFromFile("../defaultTiles.png")) std::cout << "hyvä tileset.... VITTU!";

	sf::Sprite sceneBackgroundSprite;//scenen taustakuvan sprite joka renderöidään taustalle
	//initiate world matrix: iterate through every index and initiate.

	//generate defualt wolrd tiles
	for (unsigned int y = 0; y < worldSize.y; y++) {
		//iterate through height
		for (unsigned int x = 0; x < worldSize.x; x++) {
			//iterate through width

			//this if is here for generating the default floor.
			if (y > 28) {
				Tiles[x][y] = Tile { 1, true };
			}
			else if (y == 28) {
				//grasstop
				Tiles[x][y] = Tile{ 2, true };
			}
			else {
				Tiles[x][y] = Tile{ 0, false };
			}
			//debug:
			//std::cout << "TILE x" << x << ", y" << y << ". as data: " << Tiles[x][y].collider;
		}
	}

	//ei voida piirtää vitunmoista määrää spritejä (koska spritet on kaikki erillisiä drawcalleja)
	//joten luodaan quad mesh jonka sfml voi syöttää näyttikselle(opengl)
	//mobiilivempaimet ei ymmärrä quadeja joten tämä ei käänny ainakaan androideille.

	sf::Vector2u tileAtlasDimensions = tileAtlas.getSize();
	worldMesh.setPrimitiveType(sf::Quads);
	//muuta mesh format quadeiksi
	worldMesh.resize(worldSize.x * worldSize.y * 4);
	//mesh objekti koostuu vektoreista (vertex). "alusta" (muuta) vertexin "arrayn" koko
	//jotta sinne mahtuu kaikki vektorit (vertex) jokaisessa quadissa on 4 vertexiä joten kerrotaan 4.

	for (unsigned int y = 0; y < worldSize.y; y++) {
		//iterate through height
		for (unsigned int x = 0; x < worldSize.x; x++) {
			//iterate through width

			// get the current tile number
			int tileNumber = Tiles[x][y].tileID;

			// find its position in the tileset texture
			//quad's UV cordinate precalculation
			int tu = tileNumber % (tileAtlasDimensions.x / tileSize);
			int tv = tileNumber / (tileAtlasDimensions.x / tileSize);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &worldMesh[(x + y * worldSize.x) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(x * tileSize, screenHeightOffset - (worldSize.y - y) * tileSize);
			quad[1].position = sf::Vector2f((x + 1) * tileSize, screenHeightOffset - (worldSize.y - y) * tileSize);
			quad[2].position = sf::Vector2f((x + 1) * tileSize, screenHeightOffset - ((worldSize.y - y) - 1) * tileSize);
			quad[3].position = sf::Vector2f(x * tileSize, screenHeightOffset - ((worldSize.y - y) - 1) * tileSize);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
			quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
		}
	}
}


Scene::Scene(unsigned int screenHeightOffset, std::string tilemapPath, std::string backgroundPath, unsigned int tileSize, sf::Vector2u worldSize)
{
	sf::Vector2f cameraWorldPos = sf::Vector2f(0, 0);
	//init camera
	this->worldSize = worldSize;
	Tiles[worldSize.x][worldSize.y];

	if (!sceneBackgroundTex.loadFromFile(backgroundPath)) std::cout << "background path on väärä";

	//init tile atlas
	if (!tileAtlas.loadFromFile(backgroundPath)) std::cout << "tileset path on väärä";

	sf::Sprite sceneBackgroundSprite;//scenen taustakuvan sprite joka renderöidään taustalle
	//initiate world matrix: iterate through every index and initiate.

	//generate defualt wolrd tiles
	for (unsigned int y = 0; y < worldSize.y; y++) {
		//iterate through height
		for (unsigned int x = 0; x < worldSize.x; x++) {
			//iterate through width

			//this if is here for generating the default floor.
			if (y > worldSize.y - 3) {
				Tiles[x][y] = Tile{ 1, true };
			}
			else {
				//slappin some random tiles around and about just to test tile textures etc
				Tiles[x][y] = Tile{ (unsigned int)rand() % 4, false };
			}
			//debug:
			//std::cout << "TILE x" << x << ", y" << y << ". as data: " << Tiles[x][y].collider;
		}
	}



	//ei voida piirtää vitunmoista määrää spritejä (koska spritet on kaikki erillisiä drawcalleja)
	//joten luodaan quad mesh jonka sfml voi syöttää näyttikselle(opengl)
	//mobiilivempaimet ei ymmärrä quadeja joten tämä ei käänny ainakaan androideille.

	sf::Vector2u tileAtlasDimensions = tileAtlas.getSize();
	worldMesh.setPrimitiveType(sf::Quads);
	//muuta mesh format quadeiksi
	worldMesh.resize(worldSize.x * worldSize.y * 4);
	//mesh objekti koostuu vektoreista (vertex). "alusta" (muuta) vertexin "arrayn" koko
	//jotta sinne mahtuu kaikki vektorit (vertex) jokaisessa quadissa on 4 vertexiä joten kerrotaan 4.

	for (unsigned int y = 0; y < worldSize.y; y++) {
		//iterate through height
		for (unsigned int x = 0; x < worldSize.x; x++) {
			//iterate through width

			// get the current tile number
			int tileNumber = Tiles[x][y].tileID;

			// find its position in the tileset texture
			//quad's UV cordinate precalculation
			int tu = tileNumber % (tileAtlasDimensions.x / tileSize);
			int tv = tileNumber / (tileAtlasDimensions.x / tileSize);

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &worldMesh[(x + y * worldSize.x) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(x * tileSize, screenHeightOffset - (worldSize.y - y) * tileSize);
			quad[1].position = sf::Vector2f((x + 1) * tileSize, screenHeightOffset - (worldSize.y - y) * tileSize);
			quad[2].position = sf::Vector2f((x + 1) * tileSize, screenHeightOffset - ((worldSize.y - y) - 1) * tileSize);
			quad[3].position = sf::Vector2f(x * tileSize, screenHeightOffset - ((worldSize.y - y) - 1) * tileSize);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tu * tileSize, tv * tileSize);
			quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize, tv * tileSize);
			quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize, (tv + 1) * tileSize);
			quad[3].texCoords = sf::Vector2f(tu * tileSize, (tv + 1) * tileSize);
		}
	}
}


Scene::~Scene()
{
}

//wip älä pyöritä tätä
void Scene::SaveScene(std::string filename)
{
	std::string savedata = "";
	savedata += "#";//end of file merkki varmuuden vuoksi
	std::ofstream file(filename + ".lateScene");
	file << savedata;
	file.close();
	std::cout << filename << ".lateScene on tallennettu.\n";
}

//wip älä pyöritä tätä
void Scene::LoadScene(std::string filepath)
{


}

void Scene::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	target.draw(sceneBackgroundSprite);
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &tileAtlas;
	// draw the vertex array
	target.draw(worldMesh, states);

}