## so_long

This project is a very small 2D game. Its purpose is to make you work with textures, sprites,and some other very basic gameplay elements.

![Bonus](https://github.com/JZJavier/42/assets/76801285/592a4ff6-2980-4067-adaf-f8bf2b18fb62)
The player’s goal is to collect every collectible present on the map, then escape chosing the shortest possible route.

## Mandatory part
- The executable so_long will receive a valid path to the map as the only argument.

- The W, A, S, and D keys must be used to move the main character.
- The player should be able to move in these 4 directions: up, down, left, right.
- The player should not be able to move into walls.
- At every move, the current number of movements must be displayed in the shell.

### Map requirements
The map we choose must follow these rules:

- Only P (Player), 1 (Wall), 0 (Empty), C (Collectible), and E (Exit) will be accepted characters in our map (except if you add enemies as bonus)
- The map must be rectangular.
- All rows must have the same length.
- There must be at least 1 E(Exit), 1 P(Player), and 1 C(Collectible) on the map
- The map must be closed, (surrounded by 1 (Walls));

If any of these checks fail, the game must end with Error\n followed by a custom message.

### Graphic Management
MiniLibX(42 graphic library) is a tiny graphics library which allows you to do the most basic things for rendering something to the screen.

- The use of the images of the MiniLibX is mandatory.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.

## Bonus

-  Make the player lose when they touch an enemy patrol.
- Add some sprite animation.
- Display the movement count directly on screen instead of writing it in the shell.

## Grade
<p align="center">
<img width="210" alt="125" src="https://github.com/JZJavier/42/assets/76801285/9b5924a8-8876-4bce-b783-1e6b5da93252">
</p>
