#include "..\include\Game.h"

#include "MainMenu.h"
Game::Game() :m_context(std::make_shared<Context>())
{                                                                 //titlebar nimen ikkunalle,style close antaa ruksin oikeaan yläkulmaan
	m_context->m_window->create (sf::VideoMode(1280, 720), "TileEditor v0.02",  sf::Style::Titlebar|sf::Style::Close);
    m_context->m_states->Add(std::make_unique<MainMenu>(m_context));
}

Game::~Game()
{
}

void Game::Run()
{
   //clock mahdollistaa pelin pyörimisen samalla fps:llä millä tahansa koneella laskemalla sekunnit/60
    sf::Clock clock;
    //resetaa kellon kun funktio kutsutaan 
    sf::Time timeSinceLastFrame = sf::Time::Zero;

    //Event running eli ruutu on päällä
    //kun ruutu on päällä kutsuu funktiota fps limiterin  mukaan, jotta funktiot ei toteudu liian nopeasti 
    while (m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();
        while (timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame -= TIME_PER_FRAME;

            

            m_context->m_states->ProcessStateChange();
            m_context->m_states->GetCurrent()->ProcessInputs();
            m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
            m_context->m_states->GetCurrent()->Draw();



        }
    }
}
