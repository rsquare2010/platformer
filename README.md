# Project 2 - Platformer!

NOTE:<br />
In order to properly run the "lab" executable, you must have the following frameworks installed in "Library/Frameworks":<br />
If it is unavailable, copy them over from the libs folder to /Library/Framework/
-SDL2<br />
-SDL2_ttf<br />
-SDL2_mixer<br />

## Team

Team Name: Sundays are fundays.

Team Members:
1. Daniel Nachum
2. Soumyadeep Sinha
3. Rahul Ravindran

Credits: Jesse M(https://twitter.com/Jsf23Art) for all the cool artwork used in the game.

Link to website: https://book-worms-server.herokuapp.com/JungleExplorer.html

The Special feature (Part 2 requirement) is Parallax scrolling.



## Sprite Editor:
go to the SpriteEditor folder.
run python buildSpriteEditor.py command
This will generate an executable which can be run by the ./spriteEditor command.

The sprite editor takes its input from a JSON config file situated in the media folder inside the SpriteEditor folder.

sample alternate config to try out the sprite editor(replace the contents of the folder with this):

{
  "file_name": "./media/sprite.bmp",
  "frame_width": 75,
  "frame_height": 87,
  "first_frame_x": 0,
  "first_frame_y": 0,
  "no_of_subsequent_frames": 6
}


## Tile Editor:
go to the TileEditor folder.
run python buildTileEditor.py command
This will generate an executable which can be run by the ./tileEditor command.

The default blue tile will be the background in the game.

There are tiles for character, enemy and ground tiles.

Save the tile map by pressing the 'S' button on the keyboard.

This generates a file called "example.txt". in the media folder inside the TileEditor.

## Game:
go to the Game folder.
run python buildGame.py command.
This will generate an executable which can be run by the ./game command.

Use Left/Right arrow keys to move the player.
Up for vertical jump.
Up + Right or Up + Left (Up and arrow keys pressed at the same time) for a parabolic jump.


Kill Enemies by jumping on them.... Warning! they might bounce off walls.


To use the map generated from the tile editor, copy the "example.txt" file from the media folder inside the TileEditor
package and paste it in the media folder inside the Game package. By doing this You will replace an already existing
"example.txt" file in the Game package and that is fine.


