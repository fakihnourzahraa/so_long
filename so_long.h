/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:01:34 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/19 20:38:02 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../minilibx-linux/mlx.h"

# include "ft_printf/ft_printf.h"

typedef struct s_map
{
	char	**g;
	int		width;
	int		height;

	int		collec;

	int		ff_collec;
	char	**ff_grid;

	int		p_x;
	int		p_y;
	int		e_x;
	int		e_y;
}	t_map;

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_textures {
	void	*bg;
	void	*player;
	void	*collec;
	void	*exit;
	void	*wall;
}			t_txt;

typedef struct s_game {

	t_txt		txt;
	t_map	*map;
	void	**mlx;
	void	*wind;
	int		count;
	void	*img;
}			t_game;



int		read_and_parse(t_map *map, int fd, char	*name);
void	flood_fill(t_map *map, int i, int j);
void	update_p(t_map *map);
void	get_e(t_map *map);
int		check_len(t_map *map);

int		keys(int code, void *p);
void	draw(t_game *g);
void	get_image(t_game *game);
int		cleanup(int key, void *p);
void	escape_game(t_game *game, int a);
void	error_message(void);
void	nothinn(void);

void	free_split(char **map);

#endif