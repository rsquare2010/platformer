//
// Created by Daniel Nachum on 2/7/19.
//

#include "../include/ResourceManager.h"

/**
 * This method is used to get the instance of the Resource manager class.
 * @return The instance of teh resource manager class.
 */
ResourceManager *ResourceManager::getInstance() {

  static auto *INSTANCE = new ResourceManager();
  return INSTANCE;
}

/**
 * This method is used to get the value of the resource map.
 * @param key the key to the map
 * @return the value to the key of the map.
 */
void *ResourceManager::getValue(string key) {
  return m_Resources[key];
}

/**
 * This basically acts as a substitute of the constructor.
 * @return  0 if everything is executed perfectly.
 */
int ResourceManager::startUp(SDL_Renderer *ren) {

  SDL_Surface *character = SDL_LoadBMP("./run.bmp");
  SDL_Surface *ground = SDL_LoadBMP("./Tiles.bmp");

  SDL_Texture *charTexture;
  SDL_Texture *groundTexture;
  if(ren == NULL) {
    std::cout<<"The renderer itself is null";
  }
  if(character==NULL || ground == NULL) {
    SDL_Log("Failed to allocate surface11");
  } else {
    // Create a texture from our surface
    charTexture = SDL_CreateTextureFromSurface(ren, character);
    groundTexture = SDL_CreateTextureFromSurface(ren, ground);
  }
  if(charTexture == NULL) {
    std::cout<<"CharTexture is not even getting created";
  }

  m_Resources.emplace(pair<string, void *>("Ground", groundTexture ));
  m_Resources.emplace(pair<string, void *>("Character", charTexture ));

  return 0;
}

int ResourceManager::musStartUp() {
  m_Resources.emplace(pair<string, void *>("Music", Mix_LoadMUS("media/Commando.mp3")));

  return 0;
}

/**
 * This is used to deallocate the Resource Manager.
 * @return  0 if everything is executed perfectly.
 */
int ResourceManager::shutDown() {
  return 0;
}

