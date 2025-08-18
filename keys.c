/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:33:16 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/18 20:33:48 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	keys(int code, void *p)
{
	t_game	*game;

	game = (t_game *)p;
	
	if (code == 65361)
		move_left(game);
	else if (code == 65363)
		move_right(game);
	else if (code == 65363)
		move_up(game);
	else if (code == 65364)
		move_down(game);
	else if (code == 65307)
		escape_game(game);
}