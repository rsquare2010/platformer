//
// Created by Rahul Ravindran on 2019-01-27.
//

#ifndef BREAKOUT_BREAKOUTSQUAD_SCORE_H
#define BREAKOUT_BREAKOUTSQUAD_SCORE_H

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
   * This method is used to get the current score.
   * @return the score.
   */
  int getScore();
  /**
   * This method is used to get the "SCORE" as a string from config file.
   * @param l the string whether it is english or french.
   * @return the word "Score" in english or french depending on the argument passed.
   */
  const char *getScoreString(string l);
  /**
   * This method is used to increment the score by 10.
   */
  void incrementScoreBy10();
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
   * This method is used to get the next Level.
   * @return the next level.
   */
  int nextLevel();
  /**
   * This method is used to get the current level.
   * @return the current level.
   */
  int currentLevel();
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
   * This method is used to get the "Lives" as string in either english or french.
   * @param l the option to choose from english or french.
   * @return the "Lives" as english or french.
   */
  const char *getLivesString(string l);
  /**
   * This method is used to get the status of the game in english or french.
   * @param l the option to choose from english or french.
   * @return status of the game in english or french.
   */
  const char *getStatusString(string l);
  /**
   * This method is used to go to the next higher level.
   */
  void levelUp();
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
   * This method is used to get the status of the game in english or french.
   * @param l the option to choose from english or french.
   * @return status of the game in english or french.
   */
  const char *getStatusString();
  /**
   * This method is used to display the various options and state of the game.
   * @param l the option to choose from english or french.
   * @return the meta string.
   */
  const char *getMetaString(string l);
  /**
   * This is to get the level of the game.
   * @return the game level.
   */
  const char *getKeyForCurrentLevel();
 private:
  int score;
  int lives;
  int level;
  bool isGamePaused = false;
  State() {

    score = 0;
    lives = 3;
    level = 1;
  };
};

#endif //BREAKOUT_BREAKOUTSQUAD_SCORE_H
