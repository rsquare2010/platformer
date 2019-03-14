//
// Created by Daniel Nachum on 2/7/19.
//

#ifndef BREAKOUT_BREAKOUTSQUAD_RESOURCEMANAGER_H
#define BREAKOUT_BREAKOUTSQUAD_RESOURCEMANAGER_H

#include <iostream>
#include <map>
//#include "Mixer.h"
//#include "Fonts.h"
//#include "json/json.h"
#include <fstream>
#include <SDL.h>
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
  int startUp(SDL_Renderer *ren);
  /**
   * This is used to deallocate the Resource Manager.
   * @return  0 if everything is executed perfectly.
   */
  int shutDown();
  /**
   * This method is used to get the game configuration.
   * @return the game configuration.
   */
//  Json::Value getConfig();
  /**
   * This method is used to get the language configuration.
   * @return the language configuration.
   */
//  Json::Value getLanguage();

 private:
//  Json::Value gameConfig;

//  Json::Value language;

  /**
   * This is the private constructor.
   */
  ResourceManager() {

//    Json::Value config;
//    std::ifstream config_file("Media/configuration.json", std::ifstream::binary);
//    config_file >> config;
//
//    gameConfig = config;
//
//    Json::Value language;
//    std::ifstream language_file("Media/language.json", std::ifstream::binary);
//    language_file >> language;
//
//    this->language = language;

  };

  ResourceManager(ResourceManager const &);

  void operator=(ResourceManager const &);

  map<string, void *> m_Resources;
};

#endif //BREAKOUT_BREAKOUTSQUAD_RESOURCEMANAGER_H
