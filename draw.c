/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:34:22 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/19 15:21:23 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	get_image(t_game *game)
{
	int	w;
	int	h;
	void	*m;

	m = game->mlx;
	(game)->txt.bg = mlx_xpm_file_to_image(m, "textures/bg.xpm", &w, &h);
	(game)->txt.collec = mlx_xpm_file_to_image(m, "texture/collec.xpm", &w, &h);
	(game)->txt.exit = mlx_xpm_file_to_image(m, "textures/exit.xpm", &w, &h);
	(game)->txt.player = mlx_xpm_file_to_image(m, "textures/batman.xpm", &w, &h);
	(game)->txt.wall = mlx_xpm_file_to_image(m, "textures/wall.xpm", &w, &h);
}

void	draw_map(t_game *g)
{
	char	**grid;
	void	*m;
	int		i;
	int		j;
	
	i = -1;
	m = g->mlx;
	grid = g->map->g;
	while (grid[++i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == '1')
				mlx_put_image_to_window(m, g->wind, g->txt.wall, i * 64, j * 64);
			else if (grid[i][j] == 'E')
				mlx_put_image_to_window(m, g->wind, g->txt.exit, i * 64, j * 64);
			else if (grid[i][j] == 'C')
				mlx_put_image_to_window(m, g->wind, g->txt.collec, i * 64, j * 64);
			j++;
			}
	}
}
void	draw_player(t_game *g)
{
	char	**grid;
	void	*m;
	int		i;
	int		j;
	
	i = -1;
	m = g->mlx;
	grid = g->map->g;
	while (grid[++i])
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == 'P')
				mlx_put_image_to_window(m, g->wind, g->txt.player, i * 64, j * 64);
			j++;
		}
		i++;
	}
}
void	draw(t_game *g)
{
	char	**grid;
	void	*m;
	int		i;
	int		j;
	
	i = -1;
	m = g->mlx;
	grid = g->map->g;
	while (grid[++i])
	{
		j = 0;
		while (grid[i][j])
		{
			mlx_put_image_to_window(m, g->wind, g->txt.bg, i * 64, j * 64);
			j++;
		}
		i++;
	}
	draw_map(g);
	draw_player(g);
}