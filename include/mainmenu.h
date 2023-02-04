#pragma once 
#include "State.h"
#include "Game.h"
#include <memory>
#include <SFML/Graphics/Text.hpp>
class MainMenu : public Engine::State
{
	//Context on pointterina funktion luonnille ett‰ se ei luo v‰‰r‰‰ funktiota tarvittaessa.
	//See also here for reference https://youtu.be/-oV8FZQSTA0?t=79
public: 
	MainMenu(std::shared_ptr<Context> &context);
	~MainMenu();
	//override ylikirjoittaa entisen void initin jonka State.h luo virtuaaliseksi
	//See also here for reference https://youtu.be/-oV8FZQSTA0?t=93
	 void Init() override;
	 void ProcessInputs() override;
	 void Update(sf::Time deltaTime) override;
	 void Draw() override;
	 void updateMousePosMain();
private:
	sf::Vector2i mousePoswindowMain;
	sf::Vector2f mousePosMain;
	std::shared_ptr<Context> m_context;
	sf::Text m_gameTitle;
	sf::Text m_playButton;
	sf::Text m_exitButton;
	bool m_isPlayButtonSelected;
	bool m_isPlayButtonPressed;
	//Napit exitille ja game startille 
	bool m_isExitButtonSelected;
	bool m_isExitButtonPressed;
};
