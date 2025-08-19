/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:33:16 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/19 16:39:18 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	move_left(t_game *g)
{
	if (g->map->g[g->map->p_x][g->map->p_y - 1] == 'E')
	{
		if (g->map->collec == 0)
			escape_game(g, 1);
		return ;
	}
	if (g->map->g[g->map->p_x][g->map->p_y - 1] == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
	}
	else if (g->map->g[g->map->p_x][g->map->p_y - 1] == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
	}
	update_p(g->map);
}
void	move_right(t_game *g)
{
	if (g->map->g[g->map->p_x][g->map->p_y + 1] == 'E')
	{
		if (g->map->collec == 0)
			escape_game(g, 1);
		return ;
	}
	if (g->map->g[g->map->p_x][g->map->p_y + 1] == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
	}
	else if (g->map->g[g->map->p_x][g->map->p_y + 1] == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
	}
	update_p(g->map);
}
void	move_down(t_game *g)
{
	if (g->map->g[g->map->p_x + 1]
		&& g->map->g[g->map->p_x + 1][g->map->p_y] == 'E')
	{
		if (g->map->collec == 0)
			escape_game(g, 1);
		return ;
	}
	else if (g->map->g[g->map->p_x + 1]
		&& g->map->g[g->map->p_x + 1][g->map->p_y] == '0')
	{
		g->map->g[g->map->p_x + 1][g->map->p_y] = '0';
		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
	}
	else if (g->map->g[g->map->p_x + 1]
		&& g->map->g[g->map->p_x + 1][g->map->p_y] == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x + 1][g->map->p_y] = '0';
		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
	}
	update_p(g->map);
}
void	move_up(t_game *g)
{
	if (g->map->g[g->map->p_x - 1]
		&& g->map->g[g->map->p_x - 1][g->map->p_y] == 'E')
	{
		if (g->map->collec == 0)
			escape_game(g, 1);
		return ;
	}
	else if (g->map->g[g->map->p_x - 1]
		&& g->map->g[g->map->p_x - 1][g->map->p_y] == '0')
	{
		g->map->g[g->map->p_x - 1][g->map->p_y] = '0';
		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
	}
	else if (g->map->g[g->map->p_x - 1]
		&& g->map->g[g->map->p_x - 1][g->map->p_y] == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x - 1][g->map->p_y] = '0';
		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
	}
	update_p(g->map);
}

int	keys(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	
	if (code == 65361 || code == 'A')
		move_left(game);
	else if (code == 65363 || code == 'D')
		move_right(game);
	else if (code == 65363 || code == 'W')
		move_up(game);
	else if (code == 65364 || code == 'S')
		move_down(game);
	else if (code == 65307 || code == 'q' || code == 'Q')
		escape_game(game, 0);
	return (0);
}
