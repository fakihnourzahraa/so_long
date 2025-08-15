/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfakih <nfakih@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 15:10:40 by nfakih            #+#    #+#             */
/*   Updated: 2025/08/15 21:16:49 by nfakih           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_message()
{
	ft_printf("Error\n");
}
int	main(int argc, char **argv)
{
	int	fd;

	if (argc != 2 || !ft_strstr(argv[1], ".ber"))
		return (error_message(), 1);
	fd = open(argv[1], O_RDONLY);
	if (!fd || !read_and_parse(fd))
		return (error_message(), 1);
}

