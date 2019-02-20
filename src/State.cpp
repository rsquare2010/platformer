//
// Created by Rahul Ravindran on 2019-01-27.
//
#include "State.h"
#include "ResourceManager.h"

/**
 * This method is used to initialize the State to some default value.
 */
void State::setup() {
  score = 0;
  lives = 3;
  level = 1;
}

/**
 * This method is used to get the current score.
 * @return the score.
 */
int State::getScore() {
  return score;
}

/**
 * This method is used to get the "SCORE" as a string from config file.
 * @param l the string whether it is english or french.
 * @return the word "Score" in english or french depending on the argument passed.
 */
const char *State::getScoreString(string l) {
  ResourceManager *language = ResourceManager::getInstance();
  //language->startUp();
  Json::Value lang = language->getLanguage();
  string scoreText;
  if (l=="e" || l=="E") {
    scoreText = lang["English"]["Score"].asString();
  } else if (l=="f" || l=="F") {
    scoreText = lang["French"]["Score"].asString();
  }
  return scoreText.c_str();
}

/**
 * This method is used to increment the score by 10.
 */
void State::incrementScoreBy10() {
  score += 10;
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
 * This method is used to get the next Level.
 * @return the next level.
 */
int State::nextLevel() {
  level = level + 1;
  return level;
}

/**
 * This method is used to get the current level.
 * @return the current level.
 */
int State::getCurrentLevel() {
  return level;
}

/**
 * This method is used to get the "Lives" as string in either english or french.
 * @param l the option to choose from english or french.
 * @return the "Lives" as english or french.
 */
const char *State::getLivesString(string l) {
  ResourceManager *language = ResourceManager::getInstance();
  //language->startUp();
  Json::Value lang = language->getLanguage();
  string livesText;
  switch (State::getInstance().livesLeft()) {
    case 0 :
      if (l=="e" || l=="E") {
        livesText = lang["English"]["Lives_0"].asString();
      } else if (l=="f" || l=="F") {
        livesText = lang["French"]["Lives_0"].asString();
      }
      break;
    case 1 :
      if (l=="e" || l=="E") {
        livesText = lang["English"]["Lives_1"].asString();
      } else if (l=="f" || l=="F") {
        livesText = lang["French"]["Lives_1"].asString();
      }
      break;
    case 2 :
      if (l=="e" || l=="E") {
        livesText = lang["English"]["Lives_2"].asString();
      } else if (l=="f" || l=="F") {
        livesText = lang["French"]["Lives_2"].asString();
      }
      break;
    case 3 :
      if (l=="e" || l=="E") {
        livesText = lang["English"]["Lives_3"].asString();
      } else if (l=="f" || l=="F") {
        livesText = lang["French"]["Lives_3"].asString();
      }
      break;
    default:
      if (l=="e" || l=="E") {
        livesText = lang["English"]["Lives_Error"].asString();
      } else if (l=="f" || l=="F") {
        livesText = lang["French"]["Lives_Error"].asString();
      }
  }
  return livesText.c_str();
}

/**
 * This method is used to get the status of the game in english or french.
 * @param l the option to choose from english or french.
 * @return status of the game in english or french.
 */
const char *State::getStatusString(string l) {
  ResourceManager *language = ResourceManager::getInstance();
  //language->startUp();
  Json::Value lang = language->getLanguage();
  string statusText;
  if (lives==0) {
    if (l=="e" || l=="E") {
      statusText = lang["English"]["Lose"].asString();
    } else if (l=="f" || l=="F") {
      statusText = lang["French"]["Lose"].asString();
    }
  } else if (level==3 && score==480) {
    if (l=="e" || l=="E") {
      statusText = lang["English"]["Win"].asString();
    } else if (l=="f" || l=="F") {
      statusText = lang["French"]["Win"].asString();
    }
  } else {
    if (level==1) {
      if (l=="e" || l=="E") {
        statusText = lang["English"]["Level-1"].asString();
      } else if (l=="f" || l=="F") {
        statusText = lang["French"]["Level-1"].asString();
      }
    } else if (level==2) {
      if (l=="e" || l=="E") {
        statusText = lang["English"]["Level-2"].asString();
      } else if (l=="f" || l=="F") {
        statusText = lang["French"]["Level-2"].asString();
      }
    } else if (level==3) {
      if (l=="e" || l=="E") {
        statusText = lang["English"]["Level-3"].asString();
      } else if (l=="f" || l=="F") {
        statusText = lang["French"]["Level-3"].asString();
      };
    }
  }
  return statusText.c_str();
}

/**
 * This method is used to reset the current level.
 */
void State::resetCurrentLevel() {
  score = 0;
  lives = 3;
}

/**
 * This method is used to go to the next higher level.
 */
void State::levelUp() {
  resetCurrentLevel();
  level += 1;
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
  if (State::getInstance().score==480 && State::getInstance().level==3) {
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
const char *State::getKeyForCurrentLevel() {
  switch (level) {
    case 1: return "level1";
    case 2: return "level2";
    case 3: return "level3";
    default: return "level1";
  }
}

/**
 * This method is used to display the various options and state of the game.
 * @param l the option to choose from english or french.
 * @return the meta string.
 */
const char *State::getMetaString(string l) {
  ResourceManager *language = ResourceManager::getInstance();
  //language->startUp();
  Json::Value lang = language->getLanguage();
  string metaText;
  if (isGameLost()) {
    if (l=="e" || l=="E") {
      return lang["English"]["Reset-Lose"].asString().c_str();
    } else if (l=="f" || l=="F") {
      return lang["French"]["Reset-Lose"].asString().c_str();
    }
  }
  if (isGameWon()) {
    if (l=="e" || l=="E") {
      return lang["English"]["Reset-Win"].asString().c_str();
    } else if (l=="f" || l=="F") {
      return lang["French"]["Reset-Win"].asString().c_str();
    }
  }

  if (getPauseState()) {
    if (l=="e" || l=="E") {
      return lang["English"]["Resume"].asString().c_str();
    } else if (l=="f" || l=="F") {
      return lang["French"]["Resume"].asString().c_str();
    }
  } else {
    if (l=="e" || l=="E") {
      return lang["English"]["Pause"].asString().c_str();
    } else if (l=="f" || l=="F") {
      return lang["French"]["Pause"].asString().c_str();
    }
  }
  return "hello";
}