/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:32:58 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/24 16:51:04 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int		cleanup(int key, void *p)
{
	t_game	*game;
	
	(void)key;
	game = (t_game *)p;
	escape_game(game, 0);
	return (0);
}

void	escape_game(t_game *game, int a)
{
	t_map	*map;
	char	**grid;
	int		i;

	i = 0;
	if (game)
	{
		if (game->map)
			map = game->map;
	}
	grid = map->g;
	if (a && game->map->collec != 0)
		return ;
	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
	mlx_destroy_window(game->mlx, game->wind);
	mlx_destroy_image(game->mlx, (game)->txt.bg);
	mlx_destroy_image(game->mlx, (game)->txt.collec);
	mlx_destroy_image(game->mlx, (game)->txt.exit);
	mlx_destroy_image(game->mlx, (game)->txt.player); 
	mlx_destroy_image(game->mlx, (game)->txt.wall);
	free(game->mlx);
}
