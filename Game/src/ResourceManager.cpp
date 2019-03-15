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

  SDL_Surface *characterRun = SDL_LoadBMP("./media/Run.bmp");
  SDL_Surface *idleSprite = SDL_LoadBMP("./media/idle.bmp");
  SDL_Surface *enemySheet = SDL_LoadBMP("./media/enemy.bmp");
  SDL_Surface *enemyDeathSheet = SDL_LoadBMP("./media/death.bmp");
  SDL_Surface *ground = SDL_LoadBMP("./media/Tiles.bmp");
  SDL_Surface *backgroundLayer1 = SDL_LoadBMP("./media/1.bmp");
  SDL_Surface *backgroundLayer2 = SDL_LoadBMP("./media/2.bmp");
  SDL_Surface *backgroundLayer3 = SDL_LoadBMP("./media/3.bmp");
  SDL_Surface *backgroundLayer4 = SDL_LoadBMP("./media/4.bmp");

  if(ren == NULL) {
    std::cout<<"The renderer itself is null";
  }
  if(characterRun==NULL || idleSprite == NULL) {
    SDL_Log("Failed to allocate player surfaces");
  }else {
    // Create a texture from our surface
    charRunTexture = SDL_CreateTextureFromSurface(ren, characterRun);
    charIdleTexture = SDL_CreateTextureFromSurface(ren, idleSprite);
  }
  if(charRunTexture == NULL || charIdleTexture == NULL) {
    std::cout<<"Player Texture is not even getting created";
  }

  if(enemySheet==NULL || enemyDeathSheet == NULL) {
    SDL_Log("Failed to allocate enemy surfaces");
  }else {
    // Create a texture from our surface
    enemyTexture = SDL_CreateTextureFromSurface(ren, enemySheet);
    enemyDeathTexture = SDL_CreateTextureFromSurface(ren, enemyDeathSheet);
  }
  if(enemyTexture == NULL || enemyDeathTexture == NULL) {
    std::cout<<"Enemy Texture is not even getting created";
  }


  if(ground==NULL) {
    SDL_Log("Failed to allocate enemy surfaces");
  }else {
    // Create a texture from our surface
    groundTexture = SDL_CreateTextureFromSurface(ren, ground);
  }
  if(ground == NULL) {
    std::cout<<"Ground Texture is not even getting created";
  }

  if(backgroundLayer1==NULL || backgroundLayer2 == NULL || backgroundLayer3 == NULL||backgroundLayer4 == NULL) {
    SDL_Log("Failed to allocate background surfaces");
  }else {
    // Create a texture from our surface
    backgroundLayer1Texture = SDL_CreateTextureFromSurface(ren, backgroundLayer1);
    backgroundLayer2Texture = SDL_CreateTextureFromSurface(ren, backgroundLayer2);
    backgroundLayer3Texture = SDL_CreateTextureFromSurface(ren, backgroundLayer3);
    backgroundLayer4Texture = SDL_CreateTextureFromSurface(ren, backgroundLayer4);
  }
  if(backgroundLayer1Texture == NULL || backgroundLayer2Texture == NULL || backgroundLayer3Texture == NULL
  || backgroundLayer4Texture == NULL) {

    std::cout<<"Background Texture is not even getting created";
  }


  m_Resources.emplace(pair<string, void *>("Run", charRunTexture ));
  m_Resources.emplace(pair<string, void *>("Idle", charIdleTexture ));
  m_Resources.emplace(pair<string, void *>("Enemy", enemyTexture ));
  m_Resources.emplace(pair<string, void *>("Death", enemyDeathTexture ));
  m_Resources.emplace(pair<string, void *>("Ground", groundTexture ));
  m_Resources.emplace(pair<string, void *>("Background1", backgroundLayer1Texture ));
  m_Resources.emplace(pair<string, void *>("Background2", backgroundLayer2Texture ));
  m_Resources.emplace(pair<string, void *>("Background3", backgroundLayer3Texture ));
  m_Resources.emplace(pair<string, void *>("Background4", backgroundLayer4Texture ));

  SDL_FreeSurface(characterRun);
  SDL_FreeSurface(idleSprite);
  SDL_FreeSurface(enemySheet);
  SDL_FreeSurface(enemyDeathSheet);
  SDL_FreeSurface(ground);
  SDL_FreeSurface(backgroundLayer1);
  SDL_FreeSurface(backgroundLayer2);
  SDL_FreeSurface(backgroundLayer3);
  SDL_FreeSurface(backgroundLayer4);
  characterRun = NULL;
  idleSprite = NULL;
  enemySheet = NULL;
  enemyDeathSheet = NULL;
  ground = NULL;
  backgroundLayer1 = NULL;
  backgroundLayer2 = NULL;
  backgroundLayer3 = NULL;
  backgroundLayer4 = NULL;
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
  SDL_DestroyTexture(charRunTexture);
  SDL_DestroyTexture(charIdleTexture);
  SDL_DestroyTexture(enemyTexture);
  SDL_DestroyTexture(enemyDeathTexture);
  SDL_DestroyTexture(groundTexture);
  SDL_DestroyTexture(backgroundLayer1Texture);
  SDL_DestroyTexture(backgroundLayer2Texture);
  SDL_DestroyTexture(backgroundLayer3Texture);
  SDL_DestroyTexture(backgroundLayer4Texture);
  return 0;
}