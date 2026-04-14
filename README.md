# so_long

A small 2D top-down game built in C using the **MiniLibX** graphics library, made as part of the 42 school curriculum.

---

## About

The player navigates a map, collects all items, and reaches the exit. The map is read from a `.ber` file and must pass strict validation before the game launches. Movement is tracked and displayed in the terminal after each step.

---

## Features

- Map parsing from `.ber` files
- Full map validation (walls, dimensions, reachability via flood fill)
- Player movement with arrow keys
- Step counter printed to terminal on each move
- Clean exit on ESC or window close
- XPM texture support for walls, floor, collectibles, player, and exit

---

## Controls

| Key | Action |
|-----|--------|
| Arrow keys | Move player |
| ESC | Quit game |
| Window close (×) | Quit game |

---

## Map Rules

A valid `.ber` map must:

- Be a **rectangle** fully surrounded by `1` (walls)
- Contain **exactly one** `P` (player start)
- Contain **exactly one** `E` (exit)
- Contain **at least one** `C` (collectible)
- Have a **valid path** from `P` to all `C`s and to `E`
- Use only the characters `0`, `1`, `P`, `E`, `C`

---

## How to Run

```bash
make
./so_long maps/easy.ber
```

> The binary expects exactly one argument: a path to a valid `.ber` map file.

---

## Project Structure

```
so_long/
├── main.c          # Entry point, initialization
├── parsing.c       # Map reading and validation logic
├── validation.c    # Flood fill, position tracking
├── data.c          # Height/width checks, cleanup
├── drawing.c       # XPM loading, map and player rendering
├── keys.c          # Keyboard input and movement
├── small.c         # Utilities: error, free, update, escape
├── so_long.h       # Shared structs and prototypes
├── Libft/          # Custom C standard library
├── ft_printf/      # Custom printf implementation
├── get_next_line/  # Custom GNL implementation
├── minilibx-linux/ # MiniLibX graphics library
└── txt/            # XPM textures (bg, wall, player, exit, collectible)
```

---

## Dependencies

- **GCC / cc**
- **make**
- **X11** (`libX11`, `libXext`) — required for MiniLibX on Linux
- MiniLibX is bundled in `minilibx-linux/` and built automatically

Install X11 on Debian/Ubuntu:
```bash
sudo apt-get install gcc make xorg libxext-dev libbsd-dev
```

---

## Build

```bash
make        # Build the game
make clean  # Remove object files
make fclean # Remove objects and binary
make re     # Full rebuild
```

---

## Maps Included

| File | Description |
|------|-------------|
| `easy.ber` | Small 5×13 map, quick to complete |
| `medium.ber` | Wider map with obstacles |
| `hard.ber` | Large open map with many collectibles |

---

*Made with lots of coffee and debugging at 42 Beirut*