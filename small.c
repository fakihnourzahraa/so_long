/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/18 20:35:10 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/24 18:26:44 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	error_message(void)
{
	ft_printf("Error\n");
}
void	nothinn(void)
{
	write(1, "", 0);
}
void	free_twod(char **g)
{
	int	i;

	i = 0;
	if (!g)
		return ;
	while(g[i])
	{
		free(g[i]);
		i++;
	}
	free(g);
}