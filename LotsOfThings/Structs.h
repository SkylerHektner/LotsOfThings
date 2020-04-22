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
	std::vector<float> rotations;
	std::vector<rect> uvs;
	sf::VertexArray v_array;
	sf::Texture* tex;

	RenderingData();
	void Remove( int i );
	void Add( sf::Vector2f position, sf::Vector2f scale, float rotation, const rect& uv );
};

