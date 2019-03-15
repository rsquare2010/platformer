//
// Created by Rahul Ravindran on 2019-03-14.
//

#include "../include/SDLGraphicsProgram.h"



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
        gWindow = SDL_CreateWindow( "SpriteEditor", 100, 100, screenWidth, screenHeight, SDL_WINDOW_SHOWN );

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
//    ResourceManager::getInstance().shutDown();
    ResourceManager::getInstance()->shutDown();
    // Destroy Renderer
    SDL_DestroyRenderer(gRenderer);
    //Destroy window
    SDL_DestroyWindow( gWindow );
    // Point gWindow to NULL to ensure it points to nothing.
    gRenderer = NULL;
    gWindow = NULL;
    //Quit SDL subsystems
    SDL_Quit();
}



// Update OpenGL
void SDLGraphicsProgram::update()
{
    static int frame =0 ;
    frame++;
//    if(frame>6){frame=0;}
    // Nothing yet!
    sprite->update(frame);
//    for(int i =0; i < CHARACTERS; i++){
//        characters[0].update(20,20, frame);
//    }
}


// Render
// The render function gets called once per loop
void SDLGraphicsProgram::render(){

    SDL_SetRenderDrawColor(gRenderer, 0x22,0x22,0x22,0xFF);
    SDL_RenderClear(gRenderer);

    sprite->render(gRenderer);
    SDL_RenderPresent(gRenderer);
}



//Loops forever!
void SDLGraphicsProgram::loop(){
    // Main loop flag
    // If this is quit = 'true' then the program terminates.

    SDL_Event e;
    // Enable text input
    SDL_StartTextInput();

    bool quit = false;

    ResourceManager *rmConfig = ResourceManager::getInstance();

    Json::Value spriteCnfg = rmConfig->getConfig();

    string file_name = spriteCnfg["file_name"].asString();
    int frame_width = spriteCnfg["frame_width"].asInt();
    int frame_height = spriteCnfg["frame_height"].asInt();
    int first_frame_x = spriteCnfg["first_frame_x"].asInt();
    int first_frame_y = spriteCnfg["first_frame_y"].asInt();
    int no_of_subsequent_frames = spriteCnfg["no_of_subsequent_frames"].asInt();

    rmConfig->startUp(file_name);

    sprite = new Sprite(frame_width, frame_height, first_frame_x, first_frame_y, no_of_subsequent_frames);



    sprite->init(gRenderer);
    // While application is running
    while(!quit){
        while(SDL_PollEvent( &e ) != 0){
            // User posts an event to quit
            if(e.type == SDL_QUIT){
                quit = true;
            }
        }

        SDL_Delay(250);

        // Update our scene
        update();
        // Render using OpenGL
        render();
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
