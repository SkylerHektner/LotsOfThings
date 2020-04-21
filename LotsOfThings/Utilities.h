#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "Defines.h"
#include "Structs.h"

namespace Utilities
{
	template <class T>
	void SwapDeleteSingle( std::vector<T>& vec, int index )
	{
		vec[index] = vec[vec.size() - 1];
		vec.pop_back();
	}

	template <class T>
	void SwapDeleteSet( std::vector<T> vec, int index, int chunk_size )
	{
		for( size_t i = 0; i < chunk_size; i++ )
		{
			vec[index + i] = vec[vec.size() - ( chunk_size - i )];
		}
		for( size_t i = 0; i < chunk_size; i++ ) vec.pop_back();
	}

	float RotFromVec( const sf::Vector2f& vec );
	
	void PrepSinCosCache();
	// takes degrees returns radians
	float CacheCos( int rot );
	// takes degrees returns radians
	float CacheSin( int rot );

	// takes radians
	void RotVec( sf::Vector2f& vec, float rot );
}