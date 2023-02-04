#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>
#include <SFML/System.hpp>
#include "AssetManager.h"
#include "StateManager.h"
//T‰ll‰ hetkell‰ vain fontilla on ID mutta t‰h‰n structiin lis‰‰ nimen ja int id:n assetille
enum AssetID
{
	MAIN_FONT = 0
};

//Toinen structi luotu ett‰ saa unique pointterit Objecteille 
struct Context
{
	std::unique_ptr<Engine::AssetManager> m_assets;
	std::unique_ptr<Engine::StateManager> m_states;
	std::unique_ptr<sf::RenderWindow> m_window;
	Context()
	{
		m_assets = std::make_unique < Engine::AssetManager>();
		m_states = std::make_unique < Engine::StateManager>();
		m_window = std::make_unique < sf::RenderWindow>();
	}
};
class Game
{
public:
	
	Game();
	~Game();
	//void run on p‰‰kutsu funktio jolla mainmenu pyˆrii 
	void Run();
private:
	//Shared ptr contextille koska m_assets,m_states ja m_window kaikki vet‰‰ samasta contextin id:st‰ 
	//eli jos haluaa luoda funktion eri parametreill‰ tekee vain uuden Context structin ja shared ptr privateen
	std::shared_ptr<Context> m_context;
	const sf::Time TIME_PER_FRAME = sf::seconds(1.f / 60.f);
	
	
};

