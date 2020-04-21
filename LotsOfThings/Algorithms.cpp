#include "Algorithms.h"
#include "Defines.h"

void Algorithms::UpdateVertArray( RenderingData& rd)
{
	for( size_t i = 0; i < rd.positions.size(); i++ )
	{
		const rect& r = rd.uvs[i];
		float hdiv2 = r.h * 0.5f * rd.scales[i].y;
		float wdiv2 = r.w * 0.5f * rd.scales[i].x;

		sf::Vector2f off = { -wdiv2, -hdiv2 };
		Utilities::RotVec( off, rd.rotations[i] );
		rd.v_array[i * 4 + 0].position.x = rd.positions[i].x + off.x;
		rd.v_array[i * 4 + 0].position.y = rd.positions[i].y + off.y;
		rd.v_array[i * 4 + 0].texCoords.x = r.x;
		rd.v_array[i * 4 + 0].texCoords.y = r.y;

		off = { wdiv2, -hdiv2 };
		Utilities::RotVec( off, rd.rotations[i] );
		rd.v_array[i * 4 + 1].position.x = rd.positions[i].x + off.x;
		rd.v_array[i * 4 + 1].position.y = rd.positions[i].y + off.y;
		rd.v_array[i * 4 + 1].texCoords.x = r.x + r.w;
		rd.v_array[i * 4 + 1].texCoords.y = r.y;

		off = { wdiv2, hdiv2 };
		Utilities::RotVec( off, rd.rotations[i] );
		rd.v_array[i * 4 + 2].position.x = rd.positions[i].x + off.x;
		rd.v_array[i * 4 + 2].position.y = rd.positions[i].y + off.y;
		rd.v_array[i * 4 + 2].texCoords.x = r.x + r.w;
		rd.v_array[i * 4 + 2].texCoords.y = r.y + r.h;

		off = { -wdiv2, hdiv2 };
		Utilities::RotVec( off, rd.rotations[i] );
		rd.v_array[i * 4 + 3].position.x = rd.positions[i].x + off.x;
		rd.v_array[i * 4 + 3].position.y = rd.positions[i].y + off.y;
		rd.v_array[i * 4 + 3].texCoords.x = r.x;
		rd.v_array[i * 4 + 3].texCoords.y = r.y + r.h;
	}
}
