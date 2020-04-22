#pragma once
#include "SFML/Graphics.hpp"
#include "Serializables.h"

class EntityTemplate
{

};

class Manager : public sf::Drawable
{
public:
	virtual void Update( const float delta_time ) {}
	virtual void Remove( int index ) {}

protected:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const override { };
};