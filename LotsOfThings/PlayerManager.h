#pragma once
#include "Manager.h"
#include "Structs.h"

class PlayerManager : public Manager
{
protected:
	RenderingData rd;

public:
	PlayerManager( sf::Texture* tex );
	virtual void Update( const float delta_time ) final;
	void Add( const sf::Vector2f& position, const float rotation, const rect& uv );
	virtual void Remove( int index ) final;

protected:
	virtual void draw( sf::RenderTarget& target, sf::RenderStates states ) const final;
};

