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
int ResourceManager::startUp(string fileName) {

  SDL_Surface *spriteSheet = SDL_LoadBMP(fileName.c_str());
  m_Resources.emplace(pair<string, void *>("Sprite", spriteSheet));
  return 0;
}

/**
 * This is used to deallocate the Resource Manager.
 * @return  0 if everything is executed perfectly.
 */
int ResourceManager::shutDown() {
  return 0;
}

/**
 * This method is used to get the game configuration.
 * @return the game configuration.
 */
Json::Value ResourceManager::getConfig() {
  return spriteConfig;
}