/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:32:58 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/19 16:41:55 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

// int	start(t_map	map)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	int 	endian;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, map.width * 64, map.height * 64, "so_long");
// 	void *img = mlx_new_image(mlx, 800, 600);
// 	char *data=mlx_get_data_addr(img, 64, 7680, &endian);
// 	mlx_loop(mlx);
// }
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
	map = game->map;
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
