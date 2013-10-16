#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

using namespace std;

class TextureManager
{
   // The textures that are loaded
   static map<string, sf::Texture*> textures;
    
   // Manually keep track of the order in which textures were loaded, so you can get by index.
   static std::vector<string> order;

   // Constructor that is not used
   TextureManager();
public:
   // Destructor which deletes the textures previously loaded
   ~TextureManager();
    
   static int getLength();

   // Get texutre by name specified in loadTexture, or return null
   static sf::Texture *getTexture(string name);
    
   // Get texutre by index in map, or return null
   static sf::Texture *getTexture(int index);
    
   // Loads the texture and returns a pointer to it
   // If it is already loaded, this function just returns it
   // If it cannot find the file, returns NULL
   static sf::Texture *loadTexture(string name, string path);
};

#endif