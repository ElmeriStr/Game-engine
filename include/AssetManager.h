#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
namespace Engine {
	//Asset manager hoitaa tekstuureiden ja fonttejen merkkauksen jotta niitä voi kutsua luotettavasti oikealla id:llä

class AssetManager
{
public:
	AssetManager();
	~AssetManager();									//bool wantRepeated mahdollistaa saman tekstuurin id:n käytön useasti
	void AddTexture(int id,const  std::string& filePath, bool wantRepeated = false);
	void AddFont(int id,const  std::string& filePath);
	const sf::Texture &GetTexture(int id)const;
	const sf::Font &GetFont(int id) const;
private:
	std::map<int, std::unique_ptr<sf::Texture>> m_textures;
	std::map<int, std::unique_ptr<sf::Font>> m_fonts;
	//Jos luo music/sfx kategorian tänne niin copypastaa nämä kaikki linet mitä muilla mut nimi vaan muuttaa
};
}
