/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:10:40 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/19 16:44:41 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int errors(t_map *map, int argc, char **argv)
{
	int fd;
	if (argc != 2 || !ft_strstr(argv[1], ".ber"))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (!read_and_parse(map, fd, argv[1]))
		return (-1);
	return (fd);
}
void	intialize(t_game *game)
{
	t_map	map;
	void	*mlx;
	void	*win;

	map = *(*game).map;
	mlx = mlx_init();
	if (!mlx)
		return (error_message(), nothinn());
	win = mlx_new_window(mlx, map.width * 64, map.height * 64, "so_long");
	if (!win)
		return (error_message(), nothinn());
	game->mlx = &mlx;
	game->wind = &win;
	game->img = mlx_new_image(game->mlx, 800, 600);
	get_image(game);
}
int	main(int argc, char **argv)
{
	t_map 	map;
	t_game	game;
	
	if (errors(&map, argc, argv) == -1)
		return (error_message(), 0);
	game.map = &map;
	intialize(&game);
	draw(&game);
	mlx_key_hook(game.wind, keys, &game);

	mlx_loop(game.mlx);
}
//mlx key hook, takes for the function within it (keys) param as the third parameter given
//17 0 for x