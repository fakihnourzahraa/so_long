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

// void	move_left(t_game *g)
// {
// 	if (g->map->g[g->map->p_x][g->map->p_y - 1] == 'E')
// 	{
// 		if (g->map->collec == 0)
// 			escape_game(g, 1);
// 		return ;
// 	}
// 	if (g->map->g[g->map->p_x][g->map->p_y - 1] == '0')
// 	{
// 		g->map->g[g->map->p_x][g->map->p_y] = '0';
// 		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
// 		draw(g);
// 	}
// 	else if (g->map->g[g->map->p_x][g->map->p_y - 1] == 'C')
// 	{
// 		g->map->collec--;
// 		g->map->g[g->map->p_x][g->map->p_y] = '0';
// 		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
// 		draw(g);
// 	}
// 	update_p(g->map);
// }
// void	move_right(t_game *g)
// {
// 	if (g->map->g[g->map->p_x][g->map->p_y + 1] == 'E')
// 	{
// 		if (g->map->collec == 0)
// 			escape_game(g, 1);
// 		return ;
// 	}
// 	if (g->map->g[g->map->p_x][g->map->p_y + 1] == '0')
// 	{
// 		g->map->g[g->map->p_x][g->map->p_y] = '0';
// 		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
// 		draw(g);
// 	}
// 	else if (g->map->g[g->map->p_x][g->map->p_y + 1] == 'C')
// 	{
// 		g->map->collec--;
// 		g->map->g[g->map->p_x][g->map->p_y] = '0';
// 		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
// 		draw(g);
// 	}
// 	update_p(g->map);
// }
// void	move_down(t_game *g)
// {
// 	if (g->map->g[g->map->p_x + 1]
// 		&& g->map->g[g->map->p_x + 1][g->map->p_y] == 'E')
// 	{
// 		if (g->map->collec == 0)
// 			escape_game(g, 1);
// 		return ;
// 	}
// 	else if (g->map->g[g->map->p_x + 1]
// 		&& g->map->g[g->map->p_x + 1][g->map->p_y] == '0')
// 	{
// 		g->map->g[g->map->p_x + 1][g->map->p_y] = '0';
// 		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
// 		draw(g);
// 	}
// 	else if (g->map->g[g->map->p_x + 1]
// 		&& g->map->g[g->map->p_x + 1][g->map->p_y] == 'C')
// 	{
// 		g->map->collec--;
// 		g->map->g[g->map->p_x + 1][g->map->p_y] = '0';
// 		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
// 		draw(g);
// 	}
// 	update_p(g->map);
// }
// void	move_up(t_game *g)
// {
// 	if (g->map->g[g->map->p_x - 1]
// 		&& g->map->g[g->map->p_x - 1][g->map->p_y] == 'E')
// 	{
// 		if (g->map->collec == 0)
// 			escape_game(g, 1);
// 		return ;
// 	}
// 	else if (g->map->g[g->map->p_x - 1]
// 		&& g->map->g[g->map->p_x - 1][g->map->p_y] == '0')
// 	{
// 		g->map->g[g->map->p_x - 1][g->map->p_y] = '0';
// 		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
// 		draw(g);
// 	}
// 	else if (g->map->g[g->map->p_x - 1]
// 		&& g->map->g[g->map->p_x - 1][g->map->p_y] == 'C')
// 	{
// 		g->map->collec--;
// 		g->map->g[g->map->p_x - 1][g->map->p_y] = '0';
// 		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
// 		draw(g);
// 	}
// 	update_p(g->map);
// }


// Replace all your movement functions with these safe versions:

void	move_left(t_game *g)
{
	if (!g || !g->map || !g->map->g)
	{
		//printf("ERROR: Invalid pointers in move_left\n");
		return;
	}
	
	//printf("Moving left from (%d, %d)\n", g->map->p_x, g->map->p_y);
	
	// Check bounds
	if (g->map->p_y - 1 < 0)
	{
		//printf("Can't move left - at edge\n");
		return;
	}
	
	char next_tile = g->map->g[g->map->p_x][g->map->p_y - 1];
	//printf("Next tile: '%c'\n", next_tile);
	
	if (next_tile == 'E')
	{
		if (g->map->collec == 0)
		{
			//printf("Victory! You collected all items!\n");
			escape_game(g, 1);
			exit(0);
		}
		//printf("Need to collect %d more items\n", g->map->collec);
		return;
	}
	
	if (next_tile == '0')
	{
		//printf("Moving to empty space\n");
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
		g->map->p_y--;
		draw(g);
	}
	else if (next_tile == 'C')
	{
		//printf("Collecting item! (%d left)\n", g->map->collec - 1);
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y - 1] = 'P';
		g->map->p_y--;
		draw(g);
	}
	else
	{
		//printf("Can't move there - blocked by '%c'\n", next_tile);
	}
}

void	move_right(t_game *g)
{
	if (!g || !g->map || !g->map->g)
	{
		//printf("ERROR: Invalid pointers in move_right\n");
		return;
	}
	
	//printf("Moving right from (%d, %d)\n", g->map->p_x, g->map->p_y);
	
	// Check bounds
	if (g->map->p_y + 1 >= g->map->width)
	{
		//printf("Can't move right - at edge\n");
		return;
	}
	
	char next_tile = g->map->g[g->map->p_x][g->map->p_y + 1];
	//printf("Next tile: '%c'\n", next_tile);
	
	if (next_tile == 'E')
	{
		if (g->map->collec == 0)
		{
			//printf("Victory! You collected all items!\n");
			escape_game(g, 1);
			exit(0);
		}
		//printf("Need to collect %d more items\n", g->map->collec);
		return;
	}
	
	if (next_tile == '0')
	{
		//printf("Moving to empty space\n");
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
		g->map->p_y++;
		draw(g);
	}
	else if (next_tile == 'C')
	{
		//printf("Collecting item! (%d left)\n", g->map->collec - 1);
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x][g->map->p_y + 1] = 'P';
		g->map->p_y++;
		draw(g);
	}
	else
	{
		//printf("Can't move there - blocked by '%c'\n", next_tile);
	}
}

void	move_up(t_game *g)
{
	if (!g || !g->map || !g->map->g)
	{
		//printf("ERROR: Invalid pointers in move_up\n");
		return;
	}
	
	//printf("Moving up from (%d, %d)\n", g->map->p_x, g->map->p_y);
	
	// Check bounds
	if (g->map->p_x - 1 < 0)
	{
		//printf("Can't move up - at edge\n");
		return;
	}
	
	char next_tile = g->map->g[g->map->p_x - 1][g->map->p_y];
	//printf("Next tile: '%c'\n", next_tile);
	
	if (next_tile == 'E')
	{
		if (g->map->collec == 0)
		{
			//printf("Victory! You collected all items!\n");
			escape_game(g, 1);
			exit(0);
		}
		//printf("Need to collect %d more items\n", g->map->collec);
		return;
	}
	
	if (next_tile == '0')
	{
		//printf("Moving to empty space\n");
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
		g->map->p_x--;
		draw(g);
	}
	else if (next_tile == 'C')
	{
		//printf("Collecting item! (%d left)\n", g->map->collec - 1);
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x - 1][g->map->p_y] = 'P';
		g->map->p_x--;
		draw(g);
	}
	else
	{
		//printf("Can't move there - blocked by '%c'\n", next_tile);
	}
}

void	move_down(t_game *g)
{
	if (!g || !g->map || !g->map->g)
	{
		//printf("ERROR: Invalid pointers in move_down\n");
		return;
	}
	
	//printf("Moving down from (%d, %d)\n", g->map->p_x, g->map->p_y);
	
	// Check bounds
	if (g->map->p_x + 1 >= g->map->height)
	{
		//printf("Can't move down - at edge\n");
		return;
	}
	
	char next_tile = g->map->g[g->map->p_x + 1][g->map->p_y];
	//printf("Next tile: '%c'\n", next_tile);
	
	if (next_tile == 'E')
	{
		if (g->map->collec == 0)
		{
			//printf("Victory! You collected all items!\n");
			escape_game(g, 1);
			exit(0);
		}
		//printf("Need to collect %d more items\n", g->map->collec);
		return;
	}
	
	if (next_tile == '0')
	{
		//printf("Moving to empty space\n");
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
		g->map->p_x++;
		draw(g);
	}
	else if (next_tile == 'C')
	{
		//printf("Collecting item! (%d left)\n", g->map->collec - 1);
		g->map->collec--;
		g->map->g[g->map->p_x][g->map->p_y] = '0';
		g->map->g[g->map->p_x + 1][g->map->p_y] = 'P';
		g->map->p_x++;
		draw(g);
	}
	else
	{
		//printf("Can't move there - blocked by '%c'\n", next_tile);
	}
}
int	keys(int code, void *p)
{
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
	return (0);
}