#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <assert.h>
#include "Utilities.h"

struct rect {
	int x, y, w, h;
};

struct RenderingData{
	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> scales;
	sf::Texture* tex;
	std::vector<rect> uvs;
	std::vector<float> rotations;
	sf::VertexArray v_array;

	RenderingData();
	void Remove( int i );
	void Add( sf::Vector2f position, sf::Vector2f scale, float rotation, const rect& uv );
};

