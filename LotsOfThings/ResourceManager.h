#pragma once
#include <unordered_map>
#include <memory>
#include "SFML/Graphics.hpp"
#include <string>
#include "Manager.h"

class ResourceManager
{
public:
	static ResourceManager& Get();
	EntityTemplate* GetEntityTemplate( const std::string& path );
	sf::Texture* GetTexture( const std::string& path );

private:
	std::unordered_map<std::string, std::shared_ptr<sf::Texture>> texture_resource_map;
	std::unordered_map<std::string, EntityTemplate> entity_resource_map;
};