/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:32:58 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/26 13:34:31 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	escape_game(t_game *game)
{
	update(game);
	free_twod(game->map->g);
	free_twod(game->map->ff_grid);
	mlx_destroy_window(game->mlx, game->w);
	mlx_destroy_image(game->mlx, (game)->txt.bg);
	mlx_destroy_image(game->mlx, (game)->txt.collec);
	mlx_destroy_image(game->mlx, (game)->txt.exit);
	mlx_destroy_image(game->mlx, (game)->txt.player);
	mlx_destroy_image(game->mlx, (game)->txt.wall);
	mlx_destroy_display(game->mlx);
	free(game->map);
	free(game->mlx);
	game->mlx = NULL;
	free(game);
	exit(0);
	return (1);
}

int	get_height(t_map *map)
{
	char	**grid;
	int		l;
	int		i;

	grid = (*map).g;
	(*map).height = 0;
	i = 0;
	l = ft_strlen(grid[0]) - 1;
	while (grid[i])
	{
		if (grid[i][l] != '1' || grid[i][0] != '1')
			return (0);
		i++;
	}
	(*map).height = i;
	return (1);
}

int	get_width(t_map *map)
{
	int		i;
	char	**grid;
	int		j;

	grid = (*map).g;
	i = 0;
	(*map).width = 0;
	j = ft_strlen(grid[0]);
	while (i < j)
	{
		if (grid[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (grid[(*map).height - 1][i] != '1')
			return (0);
		i++;
	}
	(*map).width = i - 1;
	return (1);
}
//get heigh get width also validate the walls
//we also need to make sure they're all equal
//(the first line could be the shortest)
// in case we reach a new line, so it doesn't set w[j] = 0;
