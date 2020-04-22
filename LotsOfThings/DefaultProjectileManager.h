#pragma once
#include <vector>
#include "Structs.h"
#include "Manager.h"

class DefaultProjectileTemplate : public EntityTemplate
{
public:
	SPrimitive<float> s1 = { 1.0f, "test" };
	SPrimitiveArray<float, 2> scale = { {1.0f, 1.0f}, "scale" };
	SPrimitiveArray<int, 4> uvs = { {0, 0, 1, 1}, "uvs" };
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