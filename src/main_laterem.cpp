#include <iostream>
#include <Windows.h>
#include "mainmenu.h"
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "..\include\Scene.h"

//ei tarvi std kirjottaa
using namespace std;
int main() {
	setlocale(LC_ALL, "fi-FI");
	printf("Hyv‰‰ p‰iv‰‰.\n");
	printf("No p‰iv‰‰ suomen kansa.\n");
   //kutsutaan game luokkaa ja luodaan paikallinen funktio jotta voi kutsua run();


	//huuda scene konstruktori t‰ss‰ nyt v‰liaikasesti debugia varten



	//t‰‰ kaikki on vaa debug poistetaan meneen kun t‰‰ pistet‰‰n game state systeemiin kiin
	sf::RenderWindow window(sf::VideoMode(800, 600), "stage editor v0.02");

	Scene sceeen = Scene(window.getSize().y);
	while (window.isOpen())
	{
		// check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{
			// "close requested" event: we close the window
			if (event.type == sf::Event::Closed)
				window.close();
		}
		// clear the window with black color
		window.clear(sf::Color::Black);
		window.draw(sceeen);

		// draw everything here...
		// window.draw(...);
		// end the current frame
		window.display();
	}
	//END DEBUG

	//Game game;
	//game.Run();
	return 0;
	}

   
    //mainmenu kutsu
     