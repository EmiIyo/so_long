/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiscan <eiscan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:19:41 by eiscan            #+#    #+#             */
/*   Updated: 2022/07/25 13:29:48 by eiscan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	destroy_window(t_game *game)
{
	mlx_destroy_window(game->mlx, game->window);
	message(BOLDRED"Oyun Sonlandırıldı.\n"ENDC, game);
	map_destroy(game);
	exit(0);
}

void	ft_window_size(t_game *data, char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf (RED"Error\nDosya Bulunamadı!\n"ENDC);
		exit(0);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf (RED"Error\nHaritan .ber Uzantılı Degil!\n"ENDC);
		exit(0);
	}
	data->size_x = (ft_line_length(fd) * 50);
	data->size_y = ft_count_lines(fd) * 50;
}
