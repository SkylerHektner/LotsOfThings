#pragma once
#include "Structs.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include "Utilities.h"


namespace Algorithms
{
	template <class T>
	void ApplyDeltas( std::vector<T>& positions, const std::vector<T>& deltas, float delta_time )
	{
		for( size_t i = 0; i < positions.size(); i++ )
		{
			positions[i].x += deltas[i].x * delta_time;
			positions[i].y += deltas[i].y * delta_time;
		}
	}

	void UpdateVertArray( RenderingData& rd );
}