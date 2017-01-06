# Light-Out

### Introduction
Light Out is a game consists of a 5 by 5 grid of lights. When the game starts, a random number or a stored pattern of these lights is switched on. Pressing any of the lights will toggle it and the adjacent lights. The goal of the puzzle is to switch all the lights off, preferably in as few button presses as possible.
<br /> More information see https://en.wikipedia.org/wiki/Lights_Out_(game)

### Commands
**new n** : Creates a new nxn grid, where n greater or equal to 1. <br />
**init**  : Enter initialization mode. Read pairs of r c and set the row r and column c as on. The coordinatesx -1 -1 exits initialization mode. <br />
**game g** : Once the board has been initialized, this command starts a new game, with a commitment to solve the game in g moves or fewer.<br />
**switch r c** : Within a game, switches the cell at row r, column c on or off, and then redisplays the grid.

### Sample Interaction
```
new 5
init
1 2
2 2
3 2
-1 -1
_____
__X__
__X__
__X__
_____
game 3
3 moves left
...
```
