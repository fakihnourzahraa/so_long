# so_long

-> parsing
-> validation
	-> rectangle
	-> surronded by walls
	-> 1 exit
	-> 1 start
	-> at least 1 collectible
	-> valid path
	_. make sure width != height

seg fault with x
	ESC key is pressed, your window should close.
window is resized, you should print something in your terminal.
the red cross is clicked, your window should close.
you press a key longer than x seconds, you should print something in your terminal.
mouse enters the window, you should print Hello! in your terminal, when it leaves, you should print Bye!.
 ->background, map, collectible, player

 int key_handler(int keycode, t_env *env)
{
    if (keycode == 53)
        ft_printf("ESCAPE");
    else if (keycode == 0 || keycode == 123)
        ft_printf("LEFT (A / ARROW_LEFT)");
    else if (keycode == 2 || keycode == 124)
        ft_printf("RIGHT (D / ARROW_RIGHT)");
    else if (keycode == 1 || keycode == 125)
        ft_printf("DOWN (S / ARROW_DOWN)");
    else if (keycode == 13 || keycode == 126)
        ft_printf("LEFT (A / ARROW_LEFT)");
    else
        ft_printf("%d\n", keycode);
    return (0);
}