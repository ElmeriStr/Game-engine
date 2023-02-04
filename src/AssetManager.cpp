#include "..\include\AssetManager.h"

Engine::AssetManager::AssetManager()
{
}

Engine::AssetManager::~AssetManager()
{
}
//bool is repeated mahdollistaa saman texturen uudelleen käytön ilman että pitää kutsua erillistä id:tä samalle textuurille
void Engine::AssetManager::AddTexture(int id, const std::string& filePath, bool wantRepeated)
{
	auto texture = std::make_unique<sf::Texture>();
	if (texture->loadFromFile(filePath))
	{
		texture->setRepeated(wantRepeated);
		m_textures[id] = std::move(texture);
	}
}

//lataa fontin ja antaa sille unique id:n lataessa
//std::move liikuttaa fontin stackin ensimmäiseksi
void Engine::AssetManager::AddFont(int id, const std::string& filePath)
{
	auto font = std::make_unique<sf::Font>();
	if (font->loadFromFile(filePath))
	{
		m_fonts[id] = std::move(font);
	}
}
//palauttaa teksturen id:n stackkiin 
const sf::Texture& Engine::AssetManager::GetTexture(int id ) const
{
	return *(m_textures.at(id).get());
}
//palauttaa fontin id:n stackkiin
const sf::Font& Engine::AssetManager::GetFont(int id ) const
{
	return *(m_fonts.at(id).get());
}
