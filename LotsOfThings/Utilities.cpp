#include "Utilities.h"

static float sin_cache[360];
static float cos_cache[360];

namespace Utilities
{
	float CacheCos( int rot ) 
	{ 
		return cos_cache[rot]; 
	}
	float CacheSin( int rot ) 
	{ 
		return sin_cache[rot]; 
	}

	void RotVec( sf::Vector2f& vec, float rot )
	{
		rot *= RAD_2_DEG;
		if( rot < 0 ) rot += 360;
		if( rot > 360 ) rot = int( rot ) % 360;
		float x = vec.x * CacheCos( rot ) - vec.y * CacheSin( rot );
		float y = vec.x * CacheSin( rot ) + vec.y * CacheCos( rot );
		vec.x = x;
		vec.y = y;
	}

	float RotFromVec( const sf::Vector2f& vec )
	{
		return std::atan2f( vec.y, vec.x );
	}

	void PrepSinCosCache()
	{
		for( int i = 0; i < 360; i++ )
		{
			sin_cache[i] = std::sin( i * DEG_2_RAD );
			cos_cache[i] = std::cos( i * DEG_2_RAD );
		}
	}
}

