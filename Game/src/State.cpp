//
// Created by Rahul Ravindran on 2019-01-27.
//
#include "State.h"
#include "ResourceManager.h"

/**
 * This method is used to initialize the State to some default value.
 */
void State::setup() {
  lives = 1;
  level = 1;
}

/**
 * This method is used to reduce life.
 * @return the lives left.
 */
int State::reduceLife() {
  lives = lives - 1;
  return lives;
}

/**
 * This method returns the lives left.
 * @return the number of lives left.
 */
int State::livesLeft() {
  return lives;
}

/**
 * This method is used to get the current level.
 * @return the current level.
 */
int State::getCurrentLevel() {
  return level;
}

/**
 * This method is used to get the "Lives" as string.
 * @return the "Lives".
 */
string State::getLivesString(int lives) {
  string livesText;
  livesText = "Lives: ";
  livesText += to_string(lives);
  return livesText;
}

/**
 * This method is used to get the status of the game.
 * @return status of the game.
 */
string State::getStatusString(int lives, bool won) {
  string statusText;
  if (lives==0) {
    statusText = "You Lose!";
  } else if (won) {
    statusText = "You Win!";
  } else {
    if (level == 1) {
      statusText = "Level 1";
    }
  }
  return statusText;
}

/**
 * This method is used to reset the current level.
 */
void State::resetCurrentLevel() {
  lives = 1;
}

/**
 * This method is used to check if the game is lost.
 * @return true if game is lost else false.
 */
bool State::isGameLost() {
  if (State::getInstance().lives==0) {
    return true;
  }
  return false;
}

/**
 * This method is used to check if the game has been won.
 * @return true if game has been else false.
 */
bool State::isGameWon() {
  if (State::getInstance().level==3) {
    return true;
  }
  return false;
}

/**
 * This is to check if the game is currently paused.
 * @return true if the game is paused.
 */
bool State::getPauseState() {
  return isGamePaused;
}

/**
 * This is to set the the game state to pause.
 * @param pause true if the game needs to be paused.
 */
void State::setPauseState(bool pause) {
  isGamePaused = pause;
}


/**
 * This is to get the level of the game.
 * @return the game level.
 */
string State::getKeyForCurrentLevel() {
  switch (level) {
    case 1: return "level1";
    default: return "level1";
  }
}