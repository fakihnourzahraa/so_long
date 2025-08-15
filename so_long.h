/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:01:34 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/15 22:11:32 by nfakih           ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"

typedef struct s_map
{
	char	**g;
	int		width;
	int		height;

	int		collec;

	int		ff_collec;
	char	**ff_grid;
	
	int		y;
	int		x;
}	t_map;



#endif