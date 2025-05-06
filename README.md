# cub3D

Together with @Ellen Steiner[https://github.com/EllenMusik] i've worked on the Wolfenstein 3D inspired project cub3D by 42 Wolfsburg. The project provides an opportunity to explore the fundamentals of raycasting, textures rendering, and basic game mechanics. It is written in C and utilizes 42's [MinilibX graphics library](https://github.com/42Paris/minilibx-linux).

## Elements
- Raycasting: Utilizes raycasting techniques to create a 3D perspective effect from a 2D map
- Textured Walls and Floors: Implements textured walls and floors to enhance the visual appeal of the game
- Basic Game Mechanics: Movement, collision detection, and simple game interactions (open portals)
- Minimap: Track your location on the map
- Sprite Rendering: Includes basic sprite object animations for the villager
- Map Parsing: Reads map data from a .cub file to generate the game environment
- Error Management: Handles various error scenarios gracefully 


## How to run the game
Clone the repository:
```
git clone https://github.com/frbeyer1/cub3d.git
```

Inside the repository run the game by typing:
```
./cub3d ./maps/working/maze.cub
```

## Keyboard/mouse control

| Key | Action |
| --- | --- |
| W | Move forward |
| A | Move left |
| S | Move backward|
| D | Move right |
| E | Open portal |
| Left Arrow | Rotate camera left |
| Right Arrow | Rotate camera right |
| Move mouse | Rotate camera left/right|
| Esc | Close the game |
