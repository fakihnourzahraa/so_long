/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:10:40 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/21 20:33:36 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int errors(t_map *map, int argc, char **argv)
{
	int fd;

	if (argc != 2 || !ft_strstr(argv[1], ".ber"))
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !read_and_parse(map, fd, argv[1]))
		return (0);
	return (1);
}
void	intialize(t_game *game)
{
	t_map	map;

	map = *(game)->map;
	printf("hi %s", map.g[0]);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_message(), nothinn());
	game->wind = mlx_new_window(game->mlx, map.width * 64, map.height * 64, "so_long");
	if (!game->wind)
		return (error_message(), nothinn());
	get_image(game);
}
int	main(int argc, char **argv)
{
	t_map 	*map;
	t_game	game;
	
	map = malloc(sizeof(t_map));
	map->g = NULL;
	if (!errors(map, argc, argv))
	{
		int i = 0;
		while (map->g && map->g[i])
		{
			free (map->g[i]);
			i++;
		}
		if (map->g)
			free(map->g);
		free(map);
		return (error_message(), 0);
	}
	game.map = map;
	intialize(&game);
	draw(&game);
	mlx_key_hook(game.wind, keys, &game);
	mlx_hook(game.wind, 17, 0, cleanup, &game);
	mlx_loop(game.mlx);
	free(map);
}
	// int	i = 0;
	// while (map->g[i])
	// {
	// 	free(map->g[i]);
	// 	i++;
	// }
	// free(map->g);
//mlx key hook, takes for the function within it (keys) param as the third parameter given
//17 0 for x