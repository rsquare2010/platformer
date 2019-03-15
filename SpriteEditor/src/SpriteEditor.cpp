//
// Created by Rahul Ravindran on 2019-03-14.
//
#include "../include/SDLGraphicsProgram.h"

/**
 * This is the main method
 * @param argc the arg c.
 * @param argv  the arg v.
 * @return if the program exits successfully.
 */
int main(int argc, char** argv){
    // Create an instance of an object for a SDLGraphicsProgram
    SDLGraphicsProgram mySDLGraphicsProgram(200,200);
    // Run our program forever
    mySDLGraphicsProgram.loop();
    // When our program ends, it will exit scope, the
    // destructor will then be called and clean up the program.
    return 0;
}