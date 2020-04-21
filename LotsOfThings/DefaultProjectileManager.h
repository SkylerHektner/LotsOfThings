#pragma once
#include <vector>
#include "Structs.h"
#include "Manager.h"

class DefaultProjectileManager : public Manager
{
protected:
	RenderingData rd;
	std::vector<sf::Vector2f> deltas;

public:
	DefaultProjectileManager( sf::Texture* tex );
	virtual void Update( const float delta_time ) final;
	void Add( const sf::Vector2f& position, const sf::Vector2f& delta, const rect& uv );
	void Add( const sf::Vector2f& position, const sf::Vector2f& delta, const rect& uv, const sf::Vector2f& scale );
	virtual void Remove( int index ) final;

protected:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const final;
};