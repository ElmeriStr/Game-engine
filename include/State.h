#pragma once 
#include <SFML/System/Time.hpp>
namespace Engine 
{
	//State on tila check missä funktio on tällä hetkellä 
	class State
	{
	public:
		//kaikki on virtual des ja cons koska tässä ei vielä alusteta conssia ja destruktoria vaan 
		//luodaan ne valmiiksi virtuaaliseksi ennen kuin ne initialisoidaan
		//nopeuttaa processin luomista 
		State() {};
		virtual~State() {};
		virtual void Init() = 0;
		virtual void ProcessInputs() = 0;
		virtual void Update(sf::Time deltaTime) = 0;
		virtual void Draw() = 0;


		virtual void Pause() {};
		virtual void Start() {};
	private:

	};

}