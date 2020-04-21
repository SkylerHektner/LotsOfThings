#include "PlayerManager.h"
#include "Utilities.h"
#include "Algorithms.h"

PlayerManager::PlayerManager( sf::Texture* tex ) : Manager::Manager()
{
	rd.tex = tex;
}

void PlayerManager::Update( const float delta_time )
{
	Manager::Update( delta_time );
	Algorithms::UpdateVertArray( rd );
}

void PlayerManager::Add( const sf::Vector2f& position, const float rotation, const rect& uv )
{
	rd.Add( position, sf::Vector2f( 1, 1 ), rotation, uv );
}

void PlayerManager::Remove( int index )
{
	rd.Remove( index );
}

void PlayerManager::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	Manager::draw( target, states );
	states.texture = rd.tex;
	target.draw( rd.v_array, states );
}
