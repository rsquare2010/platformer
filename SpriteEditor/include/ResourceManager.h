//
// Created by Daniel Nachum on 2/7/19.
//

#ifndef BREAKOUT_BREAKOUTSQUAD_RESOURCEMANAGER_H
#define BREAKOUT_BREAKOUTSQUAD_RESOURCEMANAGER_H

#include <iostream>
#include <map>
#include "json/json.h"
#include <fstream>
#include "SDL.h"
using namespace std;
/**
 * This is the resource manager.
 */
class ResourceManager {

 public:
  /**
   * This method is used to get the instance of the Resource manager class.
   * @return The instance of teh resource manager class.
   */
  static ResourceManager *getInstance();
  /**
   * This method is used to get the value of the resource map.
   * @param key the key to the map
   * @return the value to the key of the map.
   */
  void *getValue(string key);
  /**
   * This basically acts as a substitute of the constructor.
   * @return  0 if everything is executed perfectly.
   */
  int startUp(string fileName);
  /**
   * This is used to deallocate the Resource Manager.
   * @return  0 if everything is executed perfectly.
   */
  int shutDown();
  /**
   * This method is used to get the game configuration.
   * @return the game configuration.
   */
  Json::Value getConfig();

 private:
  Json::Value spriteConfig;

  /**
   * This is the private constructor.
   */
  ResourceManager() {

    Json::Value config;
    std::ifstream config_file("Media/configuration.json", std::ifstream::binary);
    config_file >> config;

    spriteConfig = config;

  };

  ResourceManager(ResourceManager const &);

  void operator=(ResourceManager const &);

  map<string, void *> m_Resources;
};

#endif //BREAKOUT_BREAKOUTSQUAD_RESOURCEMANAGER_H
