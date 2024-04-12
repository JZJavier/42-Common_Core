# Cub3D

This project is inspired by the world-famous Wolfenstein 3D game,
which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to
make a dynamic view inside a maze, in which you’ll have to find your way.

<p align="center">
  <img src="https://github.com/JZJavier/42-Common_Core/assets/76801285/bfe3f3ff-d237-4c07-9d8b-9d7c1d32fc78" alt="game">
</p>

## Raycasting
<p align="center">
  <img src="https://github.com/JZJavier/42-Common_Core/assets/76801285/db3be633-d4e8-429e-a912-d24a3921bb16" alt="ray" align="left">
</p>
<br><br><br>
Raycasting is a technique used in computer graphics to render a 3D scene from a 2D perspective. It involves casting rays from the viewpoint (typically the camera) into the scene and determining what objects, if any, intersect with those rays. This technique is commonly used in applications such as rendering 3D environments in video games or simulating how light interacts with objects in a scene.
<br><br><br>

## Mandatory part
- The executable cub3d will receive a valid path to the map as the only argument.

- The W, A, S, and D keys must be used to move the main character.
- The ← and → move the camera.
- The player should be able to move in these 4 directions: up, down, left, right.

### Map requirements
The map we choose must follow these rules:

- The (N,S,E or W) represents the player’s start position and spawning orientation
- The 1 (Wall), 0 (Empty), will be the only accepted characters in our map (except if you add doors as bonus)
- The map must be closed, (surrounded by 1 (Walls))

- Wall identifiers: NO represents the (North Texture), and so forth with the EA, SO, WE.
- Color identifiers: C represents the (Ceiling Color) and F the (Floor Color).
- This identifiers can be followed by only empty lines.
  
If any of these checks fail, the game must end with Error\n followed by a custom message.

#### Map Example

```
EA ./texture/background/background_4.xpm

NO ./texture/background/background_3.xpm

SO ./texture/background/background_2.xpm

WE ./texture/background/background_1.xpm

F 184,113,39
C 51,198,227

1111  1  111     111
1011  1  10111111101
101   11110100010101
10111 10000100100001
10001 10111110100111
10001 100000001011
11111 1000W001001
    1 101110100011
111111101010100001
1010000110100000011
10100111001D11111101
1011101001101   101
1001101011001   101
1001101110011   101
1001001 1011   1101
1011001 101    1001
 110001 111  111001
1111101      100001
  1 111   1111101111
11            111 11
```

### Graphic Management
MiniLibX(42 graphic library) is a tiny graphics library which allows you to do the most basic things for rendering something to the screen.

- The use of the images of the MiniLibX is mandatory.
- The management of your window must remain smooth (changing to another window, minimizing, and so forth).
- Pressing ESC must close the window and quit the program in a clean way.

## Bonus

- Wall collisions.
- A minimap system.
- Doors which can open and close.
- Animated sprite.
- Rotate the point of view with the mouse.

- Some aditional bonus we made: be able to shot and kill grandpas, cows and sheeps.

## Team Work
This project was carried out in collaboration with `Yu Gao`.
For further information about him and his work, please refer to the links provided.

-   [Linkedin](https://www.linkedin.com/in/yuhong-g-71796925a/)
-   [GitHub](https://github.com/Gabri177)

## Grade
<p align="center">
<img width="210" alt="125" src="https://github.com/JZJavier/42/assets/76801285/9b5924a8-8876-4bce-b783-1e6b5da93252">
</p>
