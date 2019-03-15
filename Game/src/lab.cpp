// Support Code written by Michael D. Shah
// Last Updated: 1/29/19
// Please do not redistribute without asking permission.
// We decided to reuse Professor Shah's class because it's quite Classy.
// P.S do we get bonus points for bad jokes?


#include "SDLGraphicsProgram.h"

int main(int argc, char** argv){
	// Create an instance of an object for a SDLGraphicsProgram
	SDLGraphicsProgram mySDLGraphicsProgram(1280,720);
	// Run our program forever
	mySDLGraphicsProgram.loop();
	// When our program ends, it will exit scope, the
	// destructor will then be called and clean up the program.
	return 0;
}
