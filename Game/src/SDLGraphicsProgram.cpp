#include "SDLGraphicsProgram.h"
#include "Tile.h"
#include "Background1.h"
#include "Character.h"
#include "GroundTile.h"
#include "Rectangle.h"
// I recommend a map for filling in the resource manager
#include <map>
#include <string>
#include <memory>
#include <iterator>
#include "World.h"
#define FPS 6



// Global array to create our characters
//Sprite characters[CHARACTERS];

Background1 background;
//Character character;
World* world;
Character* character;
vector<Enemy *> enemyArray;
GroundTile groundTile;
// Create a TileMap
TileMap* myTileMap;
Rectangle *banner;
Uint32 startTick;



int cWidth = 1200;
int cHeight = 640;


void detectEnemyCollisionWithWallY1(Enemy *b, World* wall);
void detectCollisionWithWallY1(Character *b, World* wall);
void detectSideCollisionWithWallY1(Character *b, World* wall);
bool checkCollision1(Coordinates *obj1,
                     int obj1Height,
                     int obj1Width,
                     Coordinates *obj2,
                     int obj2Height,
                     int obj2Width);

bool checkSideCollision1(Coordinates *obj1,
                         int obj1Height,
                         int obj1Width,
                         Coordinates *obj2,
                         int obj2Height,
                         int obj2Width);



//2560

// Initialization function
// Returns a true or false value based on successful completion of setup.
// Takes in dimensions of window.
SDLGraphicsProgram::SDLGraphicsProgram(int w, int h):screenWidth(w),screenHeight(h){
  	// Initialize random number generation.
   	srand(time(NULL));

	 // Initialization flag
	 bool success = true;
	 // String to hold any errors that occur.
	 std::stringstream errorStream;
	 // The window we'll be rendering to
	 gWindow = NULL;
	 // Render flag

	// Initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING)< 0){
		errorStream << "SDL could not initialize! SDL Error: " << SDL_GetError() << "\n";
		success = false;
	}
	else{
		//Create window
		gWindow = SDL_CreateWindow( "Jungle Explorer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, cWidth, cHeight, SDL_WINDOW_SHOWN );

		// Check if Window did not create.
		if( gWindow == NULL ){
			errorStream << "Window could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}

		//Create a Renderer to draw on
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		// Check if Renderer did not create.
		if( gRenderer == NULL ){
			errorStream << "Renderer could not be created! SDL Error: " << SDL_GetError() << "\n";
			success = false;
		}
	}

    // Move object
//    characters[0].init(128,448,getSDLRenderer());

	background.init(0,0, getSDLRenderer());
	//character.init(getSDLRenderer());
	groundTile.init(getSDLRenderer());

    // Setup our TileMap
   // myTileMap = new TileMap("./Tiles.bmp",8,8,40,40,12,10,getSDLRenderer());


  // If initialization did not work, then print out a list of errors in the constructor.
  if(!success){
    	errorStream << "Failed to initialize!\n";
    	std::string errors=errorStream.str();
    	std::cout << errors << "\n";
  }else{
    	std::cout << "No SDL errors Detected in during init\n\n";
  }
}




// Proper shutdown and destroy initialized objects
SDLGraphicsProgram::~SDLGraphicsProgram(){
    // Destroy Renderer
    SDL_DestroyRenderer(gRenderer);
    //Destroy window
    SDL_DestroyWindow( gWindow );
    // Point gWindow to NULL to ensure it points to nothing.
    gRenderer = NULL;
    gWindow = NULL;
    // Destroy our tilemap
    delete myTileMap;
    //Quit SDL subsystems
    SDL_Quit();
}

// Return Input
void SDLGraphicsProgram::input(bool *quit){
    // Event handler that handles various events in SDL
    // that are related to input and output
    SDL_Event e;
    // Enable text input
    SDL_StartTextInput();
      //Handle events on queue
      while(SDL_PollEvent( &e ) != 0){
        // User posts an event to quit
        // An example is hitting the "x" in the corner of the window.
        if(e.type == SDL_QUIT){
          *quit = true;
        }
        character->handleEvent(e);
      }
}

// Update SDL
void SDLGraphicsProgram::update()
{
    static int frame =0 ;
    frame++;
    if(frame>6){frame=0;}

    character->update(frame);
  for (int i = 0; i < enemyArray.size(); i++) {

    enemyArray[i]->update(frame);
  }

    background.update();
}


// Render
// The render function gets called once per loop
void SDLGraphicsProgram::render(int x, int y){


//    SDL_SetRenderDrawColor(gRenderer, 110, 130,170,0xFF);
  banner->updateColor(29, 119, 116, 0);

  for (int i = 0; i < enemyArray.size(); i++) {

    detectEnemyCollisionWithWallY1(enemyArray[i], world);
  }

    detectCollisionWithWallY1(character, world);
    SDL_RenderClear(gRenderer);
    background.render(x, y, getSDLRenderer());

    character->render(x, y, getSDLRenderer());
//    myTileMap->render(getSDLRenderer());
    for (int i = 0; i < enemyArray.size(); i++) {

      enemyArray[i]->render(x, y, getSDLRenderer());
    }

    groundTile.render(x, getSDLRenderer());
  banner->draw();






  SDL_RenderPresent(gRenderer);
}



//Loops forever!
void SDLGraphicsProgram::loop(){
    // Main loop flag
    // If this is quit = 'true' then the program terminates.
    bool quit = false;

    world = new World(getSDLRenderer());
    world->loadArtifacts(&groundTile);

    enemyArray = world->returnEnemies();
    character = world->returnCharacter();

  banner = new Rectangle(getSDLRenderer(), 0, 0, cWidth, 90);
    SDL_Rect camera = { 0, 0, cWidth, cHeight };
    // While application is running
    while(!quit){
      // Get user input
      input(&quit);


//      std::cout<<"posX"<<character->getCoordinates()->getX()<<"Width/2"<<40 / 2<<"xWidth/2"<< cWidth/2<<std::endl;
      camera.x = (character->getPosX() + 40 / 2) - cWidth / 2;

      if( camera.x < 0 ) {
          camera.x = 0;
      }

      if( camera.x > 2560 - camera.w ) {
          camera.x = 2560 - camera.w;
      }
      // If you have time, implement your frame capping code here
      // Otherwise, this is a cheap hack for this lab.
      startTick = SDL_GetTicks();
      // Update our scene
      update();
      // Render using OpenGL
      render(camera.x, camera.y);

      //frame capping.
      if ((1000/FPS) > (SDL_GetTicks() - startTick)) {
       // cout<<"frame capping\n";
        SDL_Delay((1000/FPS - (SDL_GetTicks() - startTick)));
      }
      //Update screen of our specified window
    }
    //Disable text input
    SDL_StopTextInput();
}

// Get Pointer to Window
SDL_Window* SDLGraphicsProgram::getSDLWindow(){
  return gWindow;
}

// Get Pointer to Renderer
SDL_Renderer* SDLGraphicsProgram::getSDLRenderer(){
  return gRenderer;
}

void detectCollisionWithWallY1(Character *b, World* wall) {

    Coordinates *coorBall = new Coordinates(b->getPosX(), b->getPosY());

//    vector < GroundTile* > test = wall->returnGround();
    std::vector<Coordinates *> coordinates = groundTile.getCoordinates();

    bool didCollide = false;
    bool didSideCollide = false;

    for (int i = 0; i < coordinates.size(); i++) {

        if (checkCollision1(coorBall, 40, 22, coordinates[i], 40, 40)) {

            didCollide = true;

            if (checkSideCollision1(coorBall, 40, 22, coordinates[i], 40, 40)) {

                didSideCollide = true;

            }
            break;

        }


    }

    if(didSideCollide){
      //  cout<<"hey there inside side collision\n";
      b->stopMovingInXDir();
    }else{

      b->startMovingInXDir();


    }


    if(didCollide){

        //b->stopFalling();

    } else{

        b->startFalling();
    }




}

void detectEnemyCollisionWithWallY1(Enemy *b, World* wall) {

  Coordinates *coorBall = new Coordinates(b->getPosX(), b->getPosY());

//    vector < GroundTile* > test = wall->returnGround();
  std::vector<Coordinates *> coordinates = groundTile.getCoordinates();

  bool didCollide = false;
  bool didSideCollide = false;

  for (int i = 0; i < coordinates.size(); i++) {

    if (checkCollision1(coorBall, 40, 40, coordinates[i], 40, 40)) {

      didCollide = true;

      if (checkSideCollision1(coorBall, 40, 40, coordinates[i], 40, 40)) {

        didSideCollide = true;

      }
      break;

    }


  }

  if(didSideCollide){
    //  cout<<"hey there inside side collision\n";
     b->stopMovingInXDir();
  }else{

    //b->startMovingInXDir();


  }


  if(didCollide){

    //b->stopFalling();

  } else{

    b->startFalling();
  }




}







bool checkCollision1(Coordinates *obj1,
                     int obj1Height,
                     int obj1Width,
                     Coordinates *obj2,
                     int obj2Height,
                     int obj2Width) {

if(obj1->getX()+obj1Width >= obj2->getX()&&
obj2->getX()+obj2Width >= obj1->getX()&&
obj1->getY()+obj1Height>=obj2->getY()&&
obj2->getY()+obj2Height>=obj1->getY()){
  return  true;
}





    return false;
}

bool checkSideCollision1(Coordinates *obj1,
                         int obj1Height,
                         int obj1Width,
                         Coordinates *obj2,
                         int obj2Height,
                         int obj2Width) {

    bool sideCollision = false;


    if (obj1->getX() + obj1Width - obj2->getX() < obj2->getX() + obj2Width - obj1->getX()
        && obj1->getX() + obj1Width - obj2->getX() < obj1->getY() + obj1Height - obj2->getY()
        && obj1->getX() + obj1Width - obj2->getX() < obj2->getY() + obj2Height - obj1->getY()) {
            cout<<"side colliding 1\n";
        sideCollision = true;
    }

    if (obj2->getX() + obj2Width - obj1->getX() < obj1->getX() + obj1Width - obj2->getX()
        && obj2->getX() + obj2Width - obj1->getX() < obj1->getY() + obj1Height - obj2->getY()
        && obj2->getX() + obj2Width - obj1->getX() < obj2->getY() + obj2Height - obj1->getY()) {
        cout<<"side colliding 2\n";
        sideCollision = true;
    }

    return  sideCollision;
}
