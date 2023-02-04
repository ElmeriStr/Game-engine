#pragma once
#include <map>
#include <memory>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Font.hpp>
#include <string>
namespace Engine {
	//Asset manager hoitaa tekstuureiden ja fonttejen merkkauksen jotta niit� voi kutsua luotettavasti oikealla id:ll�

class AssetManager
{
public:
	AssetManager();
	~AssetManager();									//bool wantRepeated mahdollistaa saman tekstuurin id:n k�yt�n useasti
	void AddTexture(int id,const  std::string& filePath, bool wantRepeated = false);
	void AddFont(int id,const  std::string& filePath);
	const sf::Texture &GetTexture(int id)const;
	const sf::Font &GetFont(int id) const;
private:
	std::map<int, std::unique_ptr<sf::Texture>> m_textures;
	std::map<int, std::unique_ptr<sf::Font>> m_fonts;
	//Jos luo music/sfx kategorian t�nne niin copypastaa n�m� kaikki linet mit� muilla mut nimi vaan muuttaa
};
}
