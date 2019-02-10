## Add any additional notes here

*your additional notes, or things TA's and instructors should know*

## Project Hieararchy

In the future, other engineers may take on our project, so we have to keep it organized given the following requirements below. Forming some good organization habits now will help us later on when our project grows as well. These are the required files you should have 

### ./Game Directory Organization

- Docs 
    - Source Code Documentation
- Assets
    - Art assets (With the Sub directories music, sound, images, and anything else)
- src
    - source code(.cpp files) The make file or any build scripts that automate the building of your project should reside here.
- include
    - header files(.h files)
- lib
    - libraries (.so, .dll, .a, .dylib files). Note this is a good place to put SDL
- temp
    - This is the directory where your built executable(.exe for windows, .app for Mac, or a.out for Linux) and any additional generated files are put after each build.
- GameBuild
    - Your final deliverable. One should be able to copy and paste this directory, and only this directory onto another machine and be able to run the game.
- ThirdParty
    - Code that you have not written if any.

**Note:** that src should only contain ".cpp" or ".h" files. Why? It makes it very fast to do a backup of your src directory as one example. Secondly, binary files that are generated often clutter up directories. I should not see any binaries in your repository, you may use a '.gitignore' file to help prevent this automatically. 
