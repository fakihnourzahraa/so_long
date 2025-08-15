/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:16:41 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/15 22:45:37 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(t_map map)
{
	char	**grid;
	int		l;
	int		i;
	
	grid = map.g;
	i = 0;
	l = ft_strlen(grid[0]) - 1;
	while (grid[i])
	{
		if (!grid[i][l])
			return (0);
		i++;
	}
}

int	get_width(t_map *map)
{

}
//get heigh get width also validate the walls
//we also need to make sure they're all equal (the first line could be the shortest)
// in case we reach a new line, so it doesn't set w[j] = 0;

int	vars(t_map map, char ** grid, char a)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	c = 0;
	j = -1;
	while (grid[++i])
	{
		while (grid[i][++j])
		{
			if (grid[i][j] == 'P')
			{
				map.x = i;
				map.y = j;
			}
			if (grid[i][j] == 'a')
				c++;
			if (grid[i] != '1' || grid[i] != '0' || grid[i] != 'E'
				|| grid[i] != 'P' || grid[i] != 'C')
					return (0);
		}
	}
	return (c);
}
int	read_and_parse(int fd)
{
	t_map	map;
	char	*add;
	int		i;
	int		c;
	
	i = 0;
	add = get_next_line(fd);
	while (add)
	{
		if (add[ft_strlen(add) - 1] == '\n')
			add[ft_strlen(add) - 1] = '\0';
		map.g[i] = add;
		i++;
		add = get_next_line(fd);
	}
	c = vars(map, map.g, 'C');
	if (!(vars(map, map.g, 'E') && vars(map, map.g, 'P') && c))
		return (0);
	map.collec = c;
	return (1);
}
