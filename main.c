/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:10:40 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/26 13:37:03 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//drawing.c keys.c main.c parsing.c data.c small.c validation.c so_long.h

int	parse(t_map *map, int argc, char **argv)
{
	int		fd;
	char	**a;

	a = NULL;
	map->g = a;
	map->ff_grid = a;
	if (argc != 2 || !ft_strstr(argv[1], ".ber"))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !read_and_parse(map, fd, argv[1]))
		return (-1);
	return (1);
}

void	intialize(t_game *game, t_map *map)
{
	game->map = map;
	game->count = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_message(), nothinn());
	game->w = mlx_new_window(game->mlx, (game->map->width + 1) * 64,
			game->map->height * 64, "so_long");
	if (!game->w)
		return (error_message(), nothinn());
	get_image(game);
}

int	main(int argc, char **argv)
{
	t_map	*map;
	t_game	*game;

	map = malloc(sizeof(t_map));
	if (parse(map, argc, argv) == -1)
	{
		if (map->g)
			free_twod(map->g);
		if (map->ff_grid)
			free_twod(map->ff_grid);
		free(map);
		return (error_message(), 0);
	}
	game = malloc (sizeof(t_game));
	intialize(game, map);
	draw_map(game);
	draw_player(game);
	mlx_key_hook(game->w, keys, game);
	mlx_hook(game->w, 17, 0, escape_game_no_update, game);
	mlx_loop(game->mlx);
}

//mlx key hook, takes for the function within it (keys) param as
// the third parameter given
//17 0 for x