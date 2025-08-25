/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:32:58 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/25 18:58:27 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	escape_game(t_game *game, int a)
{
	game->count++;
	if (a && game->map->collec != 0)
		return (0);
	escape(game);
	return (0);
}

int	escape(t_game *game)
{
	free_twod(game->map->g);
	free_twod(game->map->ff_grid);
	mlx_destroy_window(game->mlx, game->wind);
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
