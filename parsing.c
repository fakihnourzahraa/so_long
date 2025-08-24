/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 21:16:41 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/24 17:49:09 by nfakih           ###   ########.fr       */
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

int	vars(t_map *map, char a)
{
	int		i;
	int		j;
	int		c;

	i = -1;
	c = 0;
	j = -1;
	if (!map->g)
	{
		printf("HUH");
		return 0;
	}
	while (map->g[++i])
	{
		j = -1;
		while (map->g[i][++j])
		{
			if (map->g[i][j] == a)
				c++;
			if (!(map->g[i][j] == '1' || map->g[i][j] == '0' || map->g[i][j] == 'E'
				|| map->g[i][j] == 'P' || map->g[i][j] == 'C'))
				return (0);
		}
	}
	if (a == 'C' && c >= 1)
		return (c);
	return (c == 1);
	return 0;
}

void	free_split(char **map)
{
	int	i = 0;

	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

int	add_lines(char *name, int fd, t_map *m)
{
	int		i;
	char	*add;

	i = 0;
	while (1)
	{
		add = get_next_line(fd);
		if (!add)
			break;
		free(add);
		i++;
	}
	free(add);
	close(fd);
	fd = open(name, O_RDONLY);
	if (fd == -1 || i == 0)
		return (0);
	m->g = malloc (sizeof(char *) * (i + 1));
	i = 0;
	add = get_next_line(fd);
	while (add)
	{
		if (!add)
			break;
		if (add && add[ft_strlen(add) - 1] == '\n')
			add[ft_strlen(add) - 1] = '\0';
		m->g[i++] = add;
		add = get_next_line(fd);
	}
	m->g[i++] = NULL;
	close(fd);
	return (1);
}
void	copy_grid(t_map *map)
{
	char	**og;
	char	**m;
	int		i;
	int		j;

	og = map->g;
	i = 0;
	while(og[i])
	{
		j = 0;
		while (og[i][j])
		{
			m[i][j] = og[i][j];
			j++;
		}
		i++;
	}
	map->ff_grid = m;
}
int	read_and_parse(t_map *m, int fd, char *name)
{
	int		c;

	m->width = 0;
	m->height = 0;
	if (!add_lines(name, fd, m))
		return (0);
	c = vars(m, 'C');
	if (!(vars(m, 'E') && vars(m, 'P') && c))
		return (0);
	m->collec = c;
	if (!get_height(m) || !get_width(m) || !check_len(m))
		return (0);
	get_e(m);
	update_p(m);
	copy_grid(m);
	flood_fill(m, m->p_x, m->p_y);
	if (m->g[m->e_x][m->e_y] == 'E' || m->ff_collec != m->collec)
		return (0);
	return (1);
}
