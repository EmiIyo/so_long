/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiscan <eiscan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:18:53 by eiscan            #+#    #+#             */
/*   Updated: 2022/07/04 15:18:55 by eiscan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update(t_game *game, int x, int y)
{
	t_image	image;

	image.relative_path = "./img/so_long_zemin.xpm";
	image.wlx = *game;
	put_image(image, game->player.x, game->player.y);
	put_image(image, x, y);
}

void	right(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/so_long_karakter.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x + 50;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"Hareket sayısı = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	left(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/so_long_karakter.xpm";
	image.wlx = *game;
	i = game->player.y;
	j = game->player.x - 50;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"Hareket sayısı = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	up(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/so_long_karakter.xpm";
	image.wlx = *game;
	i = game->player.y - 50;
	j = game->player.x;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"Hareket sayısı = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}

void	down(t_game *game)
{
	int		i;
	int		j;
	t_image	image;

	image.relative_path = "./img/so_long_karakter.xpm";
	image.wlx = *game;
	i = game->player.y + 50;
	j = game->player.x;
	if ((move_check(game, (i / 50), (j / 50)) != 1))
	{
		game->player.hareket++;
		printf(GREEN"Hareket sayısı = %d\n"ENDC, game->player.hareket);
		update(game, j, i);
		game->player.y = i;
		game->player.x = j;
		put_image(image, j, i);
	}
}
