/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/17 19:32:58 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/17 19:35:38 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	start(t_map	map)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = mlx_new_image(mlx, 1920, 1080);
	mlx_loop(mlx);
}