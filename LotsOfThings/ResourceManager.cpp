#include "ResourceManager.h"

ResourceManager& ResourceManager::Get()
{
	static ResourceManager singleton_manager;
	return singleton_manager;
}

EntityTemplate* ResourceManager::GetEntityTemplate( const std::string& path )
{
	// TODO: insert return statement here
	return nullptr;
}

sf::Texture* ResourceManager::GetTexture( const std::string& path )
{
	if( texture_resource_map.count( path ) == 0 )
	{
		texture_resource_map[path] = std::make_shared<sf::Texture>();
		texture_resource_map[path]->loadFromFile( path );
	}
	return texture_resource_map[path].get();
}
