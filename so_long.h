/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:01:34 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/18 20:36:01 by nfakih           ###   ########.fr       */
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
# include <mlx.h>

# include "ft_printf/ft_printf.h"

typedef struct s_map
{
	char	**g;
	int		width;
	int		height;

	int		collec;

	int		ff_collec;
	char	**ff_grid;

	int		p_y;
	int		p_x;
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

typedef struct s_game {

	txt	txt;
	t_map		*map;
	void		**mlx;
	void		*wind;
}			t_game;

typedef struct s_textures {
	void	*bg;
	void	*player;
	void	*collec;
	void	*exit;
	void	*entrance;
	void	*wall;
}			txt;

int		read_and_parse(t_map *map, int fd, char	*name);
void	flood_fill(t_map *map, int i, int j);
void	get_p(t_map *map);
void	get_e(t_map *map);
int		check_len(t_map *map);
void	nothinn(void);
void	keys(int code, void *p);
void	draw(t_game *g);

void	error_message(void);
void	nothinn(void);
#endif