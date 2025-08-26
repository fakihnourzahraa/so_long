/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 17:11:33 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/26 12:59:39 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_len(t_map *map)
{
	int		l;
	int		i;
	char	**grid;

	grid = (*map).g;
	i = 0;
	l = ft_strlen(grid[0]);
	while (grid[i])
	{
		if ((int)ft_strlen(grid[i]) != l)
			return (0);
		i++;
	}
	return (1);
}

void	get_e(t_map *map)
{
	int		i;
	int		j;
	char	**grid;

	i = -1;
	grid = (*map).g;
	(*map).ff_collec = 0;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (grid[i][j] == 'E')
			{
				(*map).e_x = i;
				(*map).e_y = j;
				return ;
			}
		}
	}
}

void	update_p(t_map *map)
{
	int		i;
	int		j;
	char	**grid;

	i = -1;
	grid = (*map).g;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (grid[i][j] == 'P')
			{
				(*map).p_x = i;
				(*map).p_y = j;
				return ;
			}
		}
	}
}

void	free_grid(char **grid, int i)
{
	while (i)
	{
		free(grid[i]);
		i--;
	}
	free(grid);
}

void	flood_fill(t_map *map, int i, int j)
{
	char	**grid;

	grid = map->ff_grid;
	if (i < 0 || j < 0 || !grid[i] || !grid[i][j]
		|| grid[i][j] == '1' || grid[i][j] == '2')
		return ;
	else if (grid[i][j] == 'C')
	{
		(*map).ff_collec++;
		grid[i][j] = '2';
	}
	else if (grid[i][j] == '0')
		grid[i][j] = '2';
	else if (grid[i][j] == 'P')
		grid[i][j] = '2';
	else if (grid[i][j] == 'E')
		return (grid[i][j] = '1', nothinn());
	if (grid[i][j] == '2')
	{
		flood_fill(map, i + 1, j);
		flood_fill(map, i, j + 1);
		flood_fill(map, i - 1, j);
		flood_fill(map, i, j - 1);
	}
}
//for sure theres a p and c