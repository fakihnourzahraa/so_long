/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:16:41 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/16 16:47:02 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(t_map *map)
{
	char	**grid;
	int		l;
	int		i;
	
	grid = (*map).g;
		(*map).y = 0;
	i = 0;
	l = ft_strlen(grid[0]) - 1;
	while (grid[i])
	{
		if (grid[i][l] != '1' || grid[i][0] != '1')
			return (0);
		i++;
	}
	(*map).y = i;
	return (1);
}

int	get_width(t_map *map)
{
	int		i;
	char	**grid;
	int		j;

	grid = (*map).g;
	i = 0;
	(*map).x = 0;
	j = ft_strlen(grid[0]);
	while(i < j)
	{
		if (grid[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (grid[(*map).y - 1][i] != '1')
			return (0);
		i++;
	}
	(*map).x = i + 1;
	return (1);
}
//get heigh get width also validate the walls
//we also need to make sure they're all equal (the first line could be the shortest)
// in case we reach a new line, so it doesn't set w[j] = 0;

int	vars(t_map map, char a)
{
	int		i;
	int		j;
	int		c;
	char **grid;

	i = -1;
	c = 0;
	j = -1;
	grid = map.g;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (grid[i][j] == 'P')
			{
				map.x = i;
				map.y = j;
			}
			if (grid[i][j] == a)
				c++;
			if (!(grid[i][j] == '1' || grid[i][j] == '0' || grid[i][j] == 'E'
				|| grid[i][j] == 'P' || grid[i][j] == 'C'))
					return (0);
		}
	}
	if (a == 'C' && c >= 1)
		return (c);
	if (c == 1)
		return (1);
	return (0);
}
int	add_lines(char *name, int fd, t_map *m)
{
	int 	i;
	char	*add;
	char	**grid;
	t_map	map;

	i = 0;
	while (get_next_line(fd))
		i++;
	close(fd);
	fd = open(name, O_RDONLY);
	grid = malloc (sizeof(char *) * i + 1);
	i = 0;
	while (add = get_next_line(fd))
	{
		if (add[ft_strlen(add) - 1] == '\n')
			add[ft_strlen(add) - 1] = '\0';
		grid[i] = malloc (sizeof(char) * (ft_strlen(add) + 1));
		grid[i] = add;
		i++;
	}
	map.x = 50;
	map.g = grid;
	*m = map;
}
int	read_and_parse(int fd, char *name)
{
	t_map	map;
	int		i;
	int		c;
	
	i = 0;
	map.x = 0;
	map.y = 0;
	add_lines(name, fd, &map);
	c = vars(map, 'C');
	if (!( vars(map, 'E') && vars(map, 'P') && c ))
		return (0);
	map.collec = c;
	//make sure all edges exist
	get_height(&map);
	get_width(&map);
	if (!map.x || !map.y || (map.y == map.x))
		return (0);
	return (1);
}