#include "DefaultProjectileManager.h"
#include "Utilities.h"
#include "Algorithms.h"

void DefaultProjectileManager::draw( sf::RenderTarget& target, sf::RenderStates states ) const
{
	Manager::draw( target, states );
	states.texture = rd.tex;
	target.draw( rd.v_array, states );
}

DefaultProjectileManager::DefaultProjectileManager( sf::Texture* tex ) : Manager::Manager()
{
	rd.tex = tex;
}

void DefaultProjectileManager::Update( const float delta_time )
{
	Manager::Update( delta_time );
	Algorithms::ApplyDeltas( rd.positions, deltas, delta_time );
	Algorithms::UpdateVertArray( rd );
}

void DefaultProjectileManager::Add( const sf::Vector2f& position, const sf::Vector2f& delta, const rect& uv )
{
	Add( position, delta, uv, sf::Vector2f( 1, 1 ) );
}

void DefaultProjectileManager::Add( const sf::Vector2f& position, const sf::Vector2f& delta, const rect& uv, const sf::Vector2f& scale )
{
	deltas.emplace_back( delta );
	rd.Add( position, scale, Utilities::RotFromVec( delta ), uv );
}

void DefaultProjectileManager::Remove( int index )
{
	Utilities::SwapDeleteSingle( deltas, index );
	rd.Remove( index );
}
