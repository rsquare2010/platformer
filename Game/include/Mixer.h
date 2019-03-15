//
// Created by Daniel Nachum on 1/27/19.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_MIXER_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_MIXER_H

#include <SDL_mixer.h>
#include <stdio.h>
#include <iostream>
using namespace std;
/**
 * This class is used to play music in the game.
 */
class Mixer {

 public:
  /**
   * This method is used to load the sounds of the game. This method also handles error if there is any.
   */
  void loadSounds();
  /**
   * This method is used to play the music in the game.
   */
  void playMusic();
  /**
   * This method is used to pause the music.
   */
  void pauseMusic();
  /**
   * This method is used to resume the paused music.
   */
  void resumeMusic();
  /**
   * This method is used to play the paddle sound effect.
   */
  void playPaddle();
  /**
   * This method is used to play the brick sound effect.
   */
  void playBrick();
  /**
   * This method is used to play the sound effect of the wall.
   */
  void playWall();

  Mix_Music *bgm;
  Mix_Chunk *sfxPaddle;
  Mix_Chunk *sfxBrick;
  Mix_Chunk *sfxWall;
};

#endif
