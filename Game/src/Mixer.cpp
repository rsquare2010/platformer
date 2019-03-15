//
// Created by Daniel Nachum on 1/27/19.
//

#include <stdio.h>
#include <iostream>
#include "Mixer.h"
#include "ResourceManager.h"

/**
 * This method is used to load the sounds of the game. This method also handles error if there is any.
 */
void Mixer::loadSounds() {
  ResourceManager *rmMusic = ResourceManager::getInstance();
  int flags = MIX_INIT_MP3;
  int initialized = Mix_Init(flags);
  if ((flags & initialized)!=flags) {
    printf("Error: %s\n", Mix_GetError());
    exit(1);
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    printf("Error: %s\n", Mix_GetError());
  }

  rmMusic->musStartUp();

  bgm = (Mix_Music *) rmMusic->getValue("Music");
  //sfxPaddle = (Mix_Chunk *) rmMusic->getValue("Paddle SFX");
  //sfxBrick = (Mix_Chunk *) rmMusic->getValue("Brick SFX");
  //sfxWall = (Mix_Chunk *) rmMusic->getValue("Wall SFX");

  if (bgm==NULL || sfxPaddle==NULL || sfxBrick==NULL || sfxWall==NULL) {
    printf("Error: %s : noooooooooooo\n", Mix_GetError());
  }
}

/**
 * This method is used to play the music in the game.
 */
void Mixer::playMusic() {
  Mix_PlayMusic(bgm, -1);
}

/**
 * This method is used to pause the music.
 */
void Mixer::pauseMusic() {
  Mix_PauseMusic();
}

/**
 * This method is used to resume the paused music.
 */
void Mixer::resumeMusic() {
  Mix_ResumeMusic();
}

/**
 * This method is used to play the paddle sound effect.
 */
/*
void Mixer::playPaddle() {
  Mix_PlayChannel(-1, sfxPaddle, 0);
}
*/

