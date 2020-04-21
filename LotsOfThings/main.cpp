#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include "DefaultProjectileManager.h"
#include "PlayerManager.h"
#include "Utilities.h"
#include "ResourceManager.h"


static float FRAME_TIME = 1.0f / 60.0f;
static int SCREEN_W = 1280;
static int SCREEN_H = 720;

int main()
{

	Utilities::PrepSinCosCache();

	sf::RenderWindow window( sf::VideoMode( SCREEN_W, SCREEN_H ), "THATS A LOTTA DAMAGE" );
	sf::Clock game_clock;

	auto sprite_sheet = ResourceManager::Get().GetTexture( "Art/spritesheet.png" );
	DefaultProjectileManager proj_manager( sprite_sheet );
	PlayerManager player_manager( sprite_sheet );

	//for( float i = 0; i < 600; i++ )
	//{
	//	for( float j = 0; j < 600; j++ )
	//	{
	//		proj_manager.Add( { i, j }, { 3, 3 } );
	//	}
	//}

	/*proj_manager.Add( { 200, 200 }, { 10, 0 }, { 2, 2 } );
	proj_manager.Add( { 200, 200 }, { 0, 10 }, { 1, 2 } );
	proj_manager.Add( { 200, 200 }, { 10, 10 }, { 2, 1 } );
	proj_manager.Add( { 200, 200 }, { -10, 0 }, { 4, 2 } );
	proj_manager.Add( { 200, 200 }, { 0, -10 }, { 1, 1 } );
	proj_manager.Add( { 200, 200 }, { -10, -10 }, { 1, 6 } );
	proj_manager.Add( { 200, 200 }, { 10, -10 }, { 1, 3 } );
	proj_manager.Add( { 200, 200 }, { -10, 10 }, { 0.5f, 3 } );*/

	DefaultProjectileTemplate pt;
	pt.uvs = { 16, 192, 20, 7 };
	pt.scale = { 1.0f, 1.0f };

	proj_manager.Add( { 100, 100 }, { 10, 0 }, pt );
	proj_manager.Add( { 100, 100 }, { 0, 10 }, pt );
	proj_manager.Add( { 100, 100 }, { 10, 10 }, pt );
	proj_manager.Add( { 100, 100 }, { -10, 0 }, pt );
	proj_manager.Add( { 100, 100 }, { 0, -10 }, pt );
	proj_manager.Add( { 100, 100 }, { -10, -10 }, pt );
	proj_manager.Add( { 100, 100 }, { 10, -10 }, pt );
	proj_manager.Add( { 100, 100 }, { -10, 10 }, pt );

	player_manager.Add( { 200, 200 }, 0.0f, { 160, 34, 24, 30 } );

	sf::View camera( sf::FloatRect( 0.0f, 0.0f, SCREEN_W / 2, SCREEN_H / 2 ) );
	window.setView( camera );

	while( window.isOpen() )
	{
		float delta_time = game_clock.restart().asSeconds();

		sf::Event event;
		while( window.pollEvent( event ) )
		{
			if( event.type == sf::Event::Closed )
				window.close();
		}

		player_manager.Update( delta_time );
		proj_manager.Update( delta_time );

		window.clear( sf::Color::Blue );
		window.draw( proj_manager );
		window.draw( player_manager );
		window.display();

		std::cout << 1.0f / delta_time << std::endl;

		sf::Time sleep_duration = sf::seconds( FRAME_TIME ) - game_clock.getElapsedTime();
		if( sleep_duration > sf::Time::Zero ) sf::sleep( sleep_duration );
	}

	return 0;
}