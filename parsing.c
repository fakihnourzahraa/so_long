/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:16:41 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/15 22:17:36 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	vars(t_map map, char a, int d)
// {
// 	int		i;
// 	int		c;
// 	char	**grid;

// 	grid = map.g;
// 	i = 0;
// 	c = 0;
// 	while (grid[i])
// 	{
// 		if (grid[i] == a)
// 		{
// 			c++;
// 			if (a == 'P')
// 			{
// 				i++;
// 			}
// 		}
// 		if (grid[i] != '1' || grid[i] != '0' || grid[i] != 'E'
// 			|| grid[i] != 'P' || grid[i] != 'C')
// 				return (0);
// 		i++;
// 	}
// 	if (d == 1)
// 	{
// 		if (c != 1)
// 			return (0);
// 	}
// 	else if (d == 2)
// 		if (c < 1)
// 			return (0);
// 	return (1);
// }

int	height(char *map)
{
	int	i;
	int	j;
	int	*h;

	i = -1;
	j = -1;
	h = NULL;
	while (map[++i] != '\n')
		h[++j] = 1;
	while (map[i] && map[i] != '\n')
	{
		j = 0;
		h[++j] = 0;
		while (map[i] != '\n')
		{
			i++;
			j++;
			h[j]++;
		}
		i++;
	}
	i = j;
	while (h[i])
	{
		if (h[i] != h[j])
			return (0);
		i--;
	}
	return (1);
}

int	width(char *map)
{
	int	i;
	int	j;
	int	*w;

	i = 0;
	j = -1;
	w = NULL;
	while (map[i] && map[i] != '\n')
	{
		w[++j] = 0;
		while (map[i] != '\n')
		{
			i++;
			w[j]++;
		}
		i++;
	}
	i = j;
	while (w[i])
	{
		if (w[i] != w[j])
			return (0);
		i--;
	}
	return (1);
}
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

// int	read_and_parse(int fd)
// {
// 	t_map	m;
// 	char	*add;
// 	int		i;
	
// 	i = 0;
// 	add = get_next_line(fd);
// 	while (add)
// 	{
// 		if (add[ft_strlen(add) - 1] == '\n')
// 			add[ft_strlen(add) - 1] = '\0';
// 		m.g[i] = add;
// 		i++;
// 		add = get_next_line(fd);
// 	}
// 	if (!(vars(m, 'E', 1) && vars(m, 'P', 1) && vars(m, 'C', 2)))
// 		return (0);
// 	return (1);
// }
