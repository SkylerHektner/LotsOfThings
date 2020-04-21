#include "Structs.h"

RenderingData::RenderingData()
{
	v_array.setPrimitiveType( sf::PrimitiveType::Quads );
}

void RenderingData::Remove( int i )
{
	assert( i < positions.size() );
	Utilities::SwapDeleteSingle( positions, i );
	Utilities::SwapDeleteSingle( scales, i );
	Utilities::SwapDeleteSingle( rotations, i );
	Utilities::SwapDeleteSingle( uvs, i );
	v_array.resize( positions.size() * 4 );
}

void RenderingData::Add( sf::Vector2f position, sf::Vector2f scale, float rotation, const rect& uv )
{
	positions.emplace_back( position );
	scales.emplace_back( scale );
	rotations.emplace_back( rotation );
	uvs.emplace_back( uv );
	v_array.resize( positions.size() * 4 );
}