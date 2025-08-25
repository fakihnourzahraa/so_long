// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   keys.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2025/08/18 20:33:16 by nfakih            #+#    #+#             */
// /*   Updated: 2025/08/24 16:47:50 by nfakih           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

# include "so_long.h"

void	move_left(t_game *g)
{
	char t;

	if (g->map->p_y - 1 < 0)
		return;
	t = g->map->g[g->map->p_x][g->map->p_y - 1];
	if (t == 'E' && g->map->collec == 0)
		escape_game(g, 1);
	if (t == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
		g->map->p_y--;
		g->count++;
		draw(g);
	}
	else if (t == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
		g->map->p_y--;
		g->count++;
		draw(g);
	}
}

void	move_right(t_game *g)
{
	char t;

	if (g->map->p_y + 1 >= g->map->width)
		return;	
	t = g->map->g[g->map->p_x][g->map->p_y + 1];
	if (t == 'E' && g->map->collec == 0)
		escape_game(g, 1);
	if (t == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
		g->map->p_y++;
		g->count++;
		draw(g);
	}
	else if (t == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
		g->map->p_y++;
		g->count++;
		draw(g);
	}
}

void	move_up(t_game *g)
{
	char t;

	if (g->map->p_x - 1 < 0)
		return;
	t = g->map->g[g->map->p_x - 1][g->map->p_y];
	if (t == 'E' && g->map->collec == 0)
		escape_game(g, 1);
	if (t == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
		g->map->p_x--;
		g->count++;
		draw(g);
	}
	else if (t == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
		g->map->p_x--;
		g->count++;
		draw(g);
	}
}

void	move_down(t_game *g)
{
	char t;

	if (g->map->p_x + 1 >= g->map->height)
		return ;
	t = g->map->g[g->map->p_x + 1][g->map->p_y];
	if (t == 'E' && g->map->collec == 0)
		escape_game(g, 1);
	if (t == '0')
	{
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
		g->map->p_x++;
		draw(g);
	}
	else if (t == 'C')
	{
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
		g->map->p_x++;
		draw(g);
	}
}
int	keys(int code, void *p)
{
	char	*n;
	t_game	*game;

	game = (t_game *)p;
	
	if (code == 65361 || code == 'A')
		move_left(game);
	else if (code == 65363 || code == 'D')
		move_right(game);
	else if (code == 65362 || code == 'W')
		move_up(game);
	else if (code == 65364 || code == 'S')
		move_down(game);
	else if (code == 65307 || code == 'q' || code == 'Q')
		escape_game(game, 0);
	n = ft_itoa(game->count);

	return (0);
}