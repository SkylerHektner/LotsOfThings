#pragma once
#include <vector>
#include "Structs.h"
#include "Manager.h"

class DefaultProjectileTemplate : public EntityTemplate
{
public:
	rect uvs;
	sf::Vector2f scale;
};

class DefaultProjectileManager : public Manager
{
protected:
	RenderingData rd;
	std::vector<sf::Vector2f> deltas;

public:
	DefaultProjectileManager( sf::Texture* tex );
	virtual void Update( const float delta_time ) final;
	void Add( const sf::Vector2f& position, const sf::Vector2f& delta, const DefaultProjectileTemplate& et );
	virtual void Remove( int index ) final;

protected:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const final;
};