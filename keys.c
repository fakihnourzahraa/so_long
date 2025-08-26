/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:33:16 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/26 13:36:51 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_left(t_game *g)
{
	char	t;

	if (g->map->p_y - 1 < 0)
		return ;
	t = g->map->g[g->map->p_x][g->map->p_y - 1];
	if (t == 'E' && g->map->collec == 0)
		escape_game(g);
	if (t == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
		g->map->p_y--;
		update(g);
	}
	else if (t == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
		g->map->p_y--;
		update(g);
	}
}

void	move_right(t_game *g)
{
	char	t;

	if (g->map->p_y + 1 >= g->map->width)
		return ;
	t = g->map->g[g->map->p_x][g->map->p_y + 1];
	if (t == 'E' && g->map->collec == 0)
		escape_game(g);
	if (t == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
		g->map->p_y++;
		update(g);
	}
	else if (t == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
		g->map->p_y++;
		update(g);
	}
}

void	move_up(t_game *g)
{
	char	t;

	if (g->map->p_x - 1 < 0)
		return ;
	t = g->map->g[g->map->p_x - 1][g->map->p_y];
	if (t == 'E' && g->map->collec == 0)
		escape_game(g);
	if (t == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
		g->map->p_x--;
		update(g);
	}
	else if (t == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
		g->map->p_x--;
		update(g);
	}
}

void	move_down(t_game *g)
{
	char	t;

	if (g->map->p_x + 1 >= g->map->height)
		return ;
	t = g->map->g[g->map->p_x + 1][g->map->p_y];
	if (t == 'E' && g->map->collec == 0)
		escape_game(g);
	if (t == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
		g->map->p_x++;
		update(g);
	}
	else if (t == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
		g->map->p_x++;
		update(g);
	}
}

int	keys(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	if (code == 65361)
		move_left(game);
	else if (code == 65363)
		move_right(game);
	else if (code == 65362)
		move_up(game);
	else if (code == 65364)
		move_down(game);
	else if (code == 65307)
		escape_game_no_update(game);
	return (0);
}
