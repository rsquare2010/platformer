//
// Created by Rahul Ravindran on 2019-01-27.
//

#ifndef PLATFORMER_SUNDAYS_ARE_FUNDAYS_STATE_H
#define PLATFORMER_SUNDAYS_ARE_FUNDAYS_STATE_H

#include <iostream>

using namespace std;
/**
 * This class maintains the state of the game.
 */
class State {

 public:
  static State &getInstance() {

    static State *instance = new State();
    return *instance;
  }
/**
 * This method is used to initialize the State to some default value.
 */
  void setup();
  /**
   * This method is used to reduce life.
   * @return the lives left.
   */
  int reduceLife();
  /**
   * This method returns the lives left.
   * @return the number of lives left.
   */
  int livesLeft();
  /**
   * This method is used to get the current level.
   * @return the current level.
   */
  int getCurrentLevel();

  /**
   * This method is used to reset the current level.
   */
  void resetCurrentLevel();
  /**
   * This method is used to get the "Lives" as string.
   * @return the "Lives".
   */
  string getLivesString(int lives);
  /**
   * This method is used to get the status of the game.
   * @return status of the game.
   */
  string getStatusString(int lives, bool won);
  /**
   * This method is used to check if the game is lost.
   * @return true if game is lost else false.
   */
  bool isGameLost();
  /**
   * This method is used to check if the game has been won.
   * @return true if game has been else false.
   */
  bool isGameWon();
  /**
   * This is to check if the game is currently paused.
   * @return true if the game is paused.
   */
  bool getPauseState();
  /**
   * This is to set the the game state to pause.
   * @param pause true if the game needs to be paused.
   */
  void setPauseState(bool pause);
  /**
   * This is to get the level of the game.
   * @return the game level.
   */
  string getKeyForCurrentLevel();
 private:
  int lives;
  int level;
  bool isGamePaused = false;
  State() {
    lives = 1;
    level = 1;
  };
};

#endif
