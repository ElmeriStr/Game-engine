#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

//scene sis‰lt‰‰ tilemapin datan. mm. tiilien sijainnit

//todo:::juo kaljaaaaaaaaaaaaaaa

class Scene : public sf::Drawable, public sf::Transformable
{
public:
	Scene(unsigned int screenHeightOffset);
	//basic "default scene" loader func. need screen height for mesh heigh offset.
	//TODO: create an overload of the constructor that loads a map from a json(?) or a proprietary format
	//and a custom tilemap from a given file.

	Scene(unsigned int screenHeightOffset, std::string tilemapPath, std::string backgroundPath, unsigned int tileSize, sf::Vector2u worldSize);
	//perus kentt‰ loaderi. k‰tev‰ jos meinaa tehd‰ esim. sen main menu -> stage editor jutun,
	//niin t‰ll‰ saa m‰‰r‰tty‰ maailman kokoa jne.
	
	~Scene();
	sf::Vector2f cameraWorldPos;
	//kameran sijainti maailmassa.
	//pidet‰‰n floattina koska kameran sijainti intiss‰ ei oikeen toimi (kamera hyppisi pikselist‰ pikseliin)
	
	void SaveScene(std::string filename);
	//sylje scene data ulos stringin‰ johonkin .txt tiedostoon.
	void LoadScene(std::string filepath);
	//lataa scene tiedostosta


	struct Tile {
		unsigned int tileID;//tile's ID
		bool collider;//is collision enabled
	};

	//tarvii olla vektori jotta saa m‰‰r‰tty‰ arrayn koon runtimessa. hyv‰ ohjelmointikieli... VITTU
	//annan olla arrayn‰ kunnes tarvii muuttaan.. jos tarvii
	Tile Tiles[256][32];
	//[WIDTH][HEIGHT]
	//matrix jonka sis‰ll‰ on maailman tiilet. maailman koko (pikseleiss‰) on matriisin koko * tiilen pikselikoko.
	//koska maailma on ruudukko, pystymme indeksoimaan kaikki palikat ruutuihin minecraft tyyliin.


private:
	sf::Texture sceneBackgroundTex;//scenen taustakuvan texture container
	sf::Sprite sceneBackgroundSprite;//scenen taustakuvan sprite joka renderˆid‰‰n taustalle
	sf::Vector2u worldSize;
	sf::Texture tileAtlas;//scenen tilemap atlas. periaatteessa jokaiseen kentt‰‰n voi ladata oman texture atlaksen
	//niinkuin texturepack tyyliin
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	//ei mit‰‰ hajuu mit‰ t‰‰ tekee mut se toimii niin hyv‰ niin. scenen drawcall toimii window.draw(Scene);
	sf::VertexArray worldMesh;//scenen fyysiset pirrett‰v‰t "tiilet"
};
