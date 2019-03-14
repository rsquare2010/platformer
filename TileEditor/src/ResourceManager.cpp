//
// Created by Daniel Nachum on 2/7/19.
//

#include "ResourceManager.h"

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
int ResourceManager::startUp() {

  SDL_Surface* character = SDL_LoadBMP("./media/char.bmp");
  SDL_Surface* ground = SDL_LoadBMP("./media/Tiles.bmp");

  m_Resources.emplace(pair<string, void *>("Ground", ground ));
  m_Resources.emplace(pair<string, void *>("Character", character ));

  return 0;
}

/**
 * This is used to deallocate the Resource Manager.
 * @return  0 if everything is executed perfectly.
 */
int ResourceManager::shutDown() {
  return 0;
}

