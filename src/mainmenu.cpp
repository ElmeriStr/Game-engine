#include "..\include\MainMenu.h"
#include <SFML/Window/Event.hpp>
//TODO: Kommentoi niin vitusti

MainMenu::MainMenu(std::shared_ptr<Context>& context)
//initialisoidaan context ja napit pelille 
//m_isplaybuttonSelected on ainoa true jotta koodi tiet‰‰ miss‰ pelaajan input on aloitushetkell‰ 
//jos luo lis‰‰ nappeja mainmenuu pit‰‰ tehd‰ uusia bool arvoja ja muokata switchi‰ alhaalla
	:m_context(context), m_isPlayButtonSelected(true),
	m_isPlayButtonPressed(false), m_isExitButtonSelected(false),
	m_isExitButtonPressed(false)
{

}

MainMenu::~MainMenu()
{
}

void MainMenu::Init()
{
	/// <summary>
	/// Kutsuu fonttia ja tallentaa sen m_assetteihin ja  asseteissa antaa sille id:n ja id:n antaa contextille 
	/// </summary>							//../ lis‰tty niin ottaa buildin ulkopuolelta
	m_context->m_assets->AddFont(MAIN_FONT, "../assets/Fonts/Mukta-ExtraBold.ttf");
	m_gameTitle.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_gameTitle.setString("Tile Editor");
	
	//Scripti joka laittaa tekstin keskelle ruutua hakemalla window sizen ja jakamalla sen x ja y kahdella
	//toimii vaikka resoluutiota vaihtaa isommaksi tai pienemm‰ksi
	//See also for reference https://youtu.be/-oV8FZQSTA0?list=PLiZZKL9HLmWMF8PlzvZu2WOC9kjs1zzhm&t=340
	m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
		m_gameTitle.getLocalBounds().height / 2);
	m_gameTitle.setPosition(m_context->m_window->getSize().x/2,
						m_context->m_window->getSize().y / 2 - 150.f);


	//Play button
	
	m_playButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_playButton.setString("Play");

	m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
		m_playButton.getLocalBounds().height / 2);
	m_playButton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 - 25.f);
	m_playButton.setCharacterSize(30);


	////Exit button

	m_exitButton.setFont(m_context->m_assets->GetFont(MAIN_FONT));
	m_exitButton.setString("Exit");

	m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
		m_exitButton.getLocalBounds().height / 2);
	m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
		m_context->m_window->getSize().y / 2 + 25.f);
	m_exitButton.setCharacterSize(30);
}

void MainMenu::ProcessInputs()
{	//Hiiren positio ruudulla p‰ivitys kutsu
	updateMousePosMain();

	/*if ()
	{
	if ();
		{
			m_isPlayButtonPressed = true;
		}
		*/


		//eventtej‰ napeille 
		//v‰rj‰‰ napin kun on kohdalla ja isontaa sen fonttia
		//t‰nne muutosta jos lis‰‰ nappeja 
		//t‰ll‰ hetkell‰ bool tapainen v‰rj‰ys ja valinta systeemi, jos lis‰‰ nappeja pit‰‰ muuttaa 
		//See also for reference https://youtu.be/-oV8FZQSTA0?list=PLiZZKL9HLmWMF8PlzvZu2WOC9kjs1zzhm&t=476
	sf::Event event;
	while (m_context->m_window->pollEvent(event))
	{
		if (event.type == sf::Event::Closed)
		{
			m_context->m_window->close();
		}
		
			if (m_playButton.getGlobalBounds().contains(this->mousePosMain.x, this->mousePosMain.y))
			{
				m_isPlayButtonSelected = true;
				m_isExitButtonSelected = false;
				if ( event.type == sf::Event::MouseButtonPressed)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						m_isPlayButtonPressed = true;
					}

				}
			}
			if (m_exitButton.getGlobalBounds().contains(this->mousePosMain.x, this->mousePosMain.y))
			{
				m_isPlayButtonSelected = false;
				m_isExitButtonSelected = true;
				if (event.type == sf::Event::MouseButtonPressed)
				{
					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						m_isExitButtonPressed = true;
					}

				}
			}
		
	
		//if (event.type == sf::Event::MouseButtonPressed) {
		//	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {							// SHOOT
		//	}
		//}
		else if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code)
			{
			case sf::Keyboard::Escape:
			{
				m_context->m_window->close();
				break;
			}
			case sf::Keyboard::Up:
			{
				if (!m_isPlayButtonSelected)
				{

					m_isPlayButtonSelected = true;
					m_isExitButtonSelected = false;

				}
				break;
			}
			case sf::Keyboard::Down:
			{
				if (!m_isExitButtonSelected)
				{


					m_isPlayButtonSelected = false;
					m_isExitButtonSelected = true;

				}
				break;
			}
			case sf::Keyboard::W:
			{
				if (!m_isPlayButtonSelected)
				{

					m_isPlayButtonSelected = true;
					m_isExitButtonSelected = false;

				}
				break;

			}
			case sf::Keyboard::S:
			{
				if (!m_isExitButtonSelected)
				{

					m_isPlayButtonSelected = false;
					m_isExitButtonSelected = true;

				}
				break;
			}
			//entteri toimmii menussa
			case sf::Keyboard::Return:
			{
				m_isPlayButtonPressed = false;
				m_isExitButtonPressed = false;
				if (m_isPlayButtonSelected)
				{
					m_isPlayButtonPressed = true;
				}
				else
				{
					m_isExitButtonPressed = true;
				}
				break;

			default:
				break;
			}
			}
		}
	}
}

void MainMenu::Update(sf::Time deltaTime)
{
	if (m_isPlayButtonSelected)
	{
		m_playButton.setCharacterSize(38);
		m_playButton.setFillColor(sf::Color::Yellow);
		m_exitButton.setFillColor(sf::Color::White);
		m_exitButton.setCharacterSize(30);
	}
	else
	{
		m_playButton.setCharacterSize(30);
		m_exitButton.setFillColor(sf::Color::Yellow);
		m_playButton.setFillColor(sf::Color::White);
		m_exitButton.setCharacterSize(38);
	}
	if (m_isPlayButtonPressed)
	{
		//START GAME
		//atm sulkee pelin koska ei oo funktiota mit‰ kutsua
		m_context->m_window->close();
	}
	else if(m_isExitButtonPressed)
	{
		//Sulje peli
		m_context->m_window->close();
	}

}

void MainMenu::Draw()
{
	//piirto menetelm‰ 
	m_context->m_window->clear();
	m_context->m_window->draw(m_gameTitle);
	m_context->m_window->draw(m_playButton);
	m_context->m_window->draw(m_exitButton);
	m_context->m_window->display();

}

void MainMenu::updateMousePosMain()
{
	this->mousePoswindowMain = sf::Mouse::getPosition(*this->m_context->m_window);
	//koska window on pointter pit‰‰ k‰ytt‰‰ *this funktiolla dereferenssin‰
	this->mousePosMain = this->m_context->m_window->mapPixelToCoords(this->mousePoswindowMain);
}
