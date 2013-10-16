#include "TextureManager.h"

TextureManager::TextureManager()
{
}

map<string, sf::Texture*> TextureManager::textures;

// Get Length of Textures Array
int TextureManager::getLength(){
    return textures.size();
}

// Get Texture by Name
sf::Texture *TextureManager::getTexture(string name)
{
    
    // See if we have already loaded this texture
    if(textures.find(name) != textures.end()){
        return textures[name];
    } else {
        return NULL;
    }
}

// Assign a Texture a Name (for accessing via get) and path (to load from)
sf::Texture *TextureManager::loadTexture(string name, string path)
{
    // Haven't loaded it yet, time to create it
    sf::Texture *texture = new sf::Texture();
    
    if(texture->loadFromFile(path))
    {
        textures[name] = texture;
        return textures[name];
    }
    else
    {
        // Could not load the file
        delete texture;
        return NULL;
    }
    
}

TextureManager::~TextureManager()
{
    
    // Delete all of the textures we used
    sf::Texture *texture;
    map<string, sf::Texture*>::iterator iter = textures.begin();
    while(iter != textures.end())
    {
        texture = iter->second;
        delete texture;
        iter++;
    }
    
}
