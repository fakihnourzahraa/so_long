/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:35:10 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/26 13:35:54 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message(void)
{
	ft_printf("Error\n");
}

void	nothinn(void)
{
	write(1, "", 0);
}

void	free_twod(char **g)
{
	int	i;

	i = 0;
	if (!g)
		return ;
	while (g[i])
	{
		free(g[i]);
		i++;
	}
	free(g);
}

void	update(t_game *game)
{
	game->count++;
	ft_printf("count: %d\n", game->count);
	draw_map(game);
	draw_player(game);
}

int	escape_game_no_update(t_game *game)
{
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
