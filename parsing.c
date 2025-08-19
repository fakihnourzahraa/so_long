/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:16:41 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/19 15:29:54 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(t_map *map)
{
	char	**grid;
	int		l;
	int		i;

	grid = (*map).g;
	(*map).height = 0;
	i = 0;
	l = ft_strlen(grid[0]) - 1;
	while (grid[i])
	{
		if (grid[i][l] != '1' || grid[i][0] != '1')
			return (0);
		i++;
	}
	(*map).height = i;
	return (1);
}

int	get_width(t_map *map)
{
	int		i;
	char	**grid;
	int		j;

	grid = (*map).g;
	i = 0;
	(*map).width = 0;
	j = ft_strlen(grid[0]);
	while (i < j)
	{
		if (grid[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < j)
	{
		if (grid[(*map).height - 1][i] != '1')
			return (0);
		i++;
	}
	(*map).width = i - 1;
	return (1);
}
//get heigh get width also validate the walls
//we also need to make sure they're all equal
//(the first line could be the shortest)
// in case we reach a new line, so it doesn't set w[j] = 0;

int	vars(t_map map, char a)
{
	int		i;
	int		j;
	int		c;
	char	**grid;

	i = -1;
	c = 0;
	j = -1;
	grid = map.g;
	while (grid[++i])
	{
		j = -1;
		while (grid[i][++j])
		{
			if (grid[i][j] == a)
				c++;
			if (!(grid[i][j] == '1' || grid[i][j] == '0' || grid[i][j] == 'E'
				|| grid[i][j] == 'P' || grid[i][j] == 'C'))
				return (0);
		}
	}
	if (a == 'C' && c >= 1)
		return (c);
	return (c == 1);
}

int	add_lines(char *name, int fd, t_map *m)
{
	int		i;
	char	*add;
	char	**grid;
	t_map	map;

	i = 0;
	while (get_next_line(fd))
		i++;
	close(fd);
	fd = open(name, O_RDONLY);
	if (fd == -1 || i == 0)
		return (0);
	grid = malloc (sizeof(char *) * i + 1);
	i = 0;
	add = get_next_line(fd);
	while (add)
	{
		if (!add)
			return (0);
		if (add[ft_strlen(add) - 1] == '\n')
			add[ft_strlen(add) - 1] = '\0';
		grid[i++] = add;
		add = get_next_line(fd);
	}
	return (map.g = grid, *m = map, 1);
}

int	read_and_parse(t_map *m, int fd, char *name)
{
	t_map	map;
	int		c;

	map = *m;
	map.width = 0;
	map.height = 0;
	if (!add_lines(name, fd, &map))
		return (0);
	c = vars(map, 'C');
	if (!(vars(map, 'E') && vars(map, 'P') && c))
		return (0);
	map.collec = c;
	if (!get_height(&map) || !get_width(&map) || !check_len(&map))
		return (0);
	get_e(&map);
	update_p(&map);
	map.ff_grid = map.g;
	flood_fill(&map, map.p_x, map.p_y);
	if (map.g[map.e_x][map.e_y] == 'E' || map.ff_collec != map.collec)
		return (0);
	return (1);
}
