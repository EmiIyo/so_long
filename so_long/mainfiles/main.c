/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eiscan <eiscan@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 15:18:27 by eiscan            #+#    #+#             */
/*   Updated: 2022/07/25 13:22:22 by eiscan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	message(char *msg, t_game *game)
{
	printf("%s", msg);
	map_destroy(game);
	exit(0);
}

int	key_check(int key_code, t_game *game)
{
	if (key_code == ESC)
		destroy_window(game);
	if (key_code == UP)
		up(game);
	if (key_code == RIGHT)
		right(game);
	if (key_code == LEFT)
		left(game);
	if (key_code == DOWN)
		down(game);
	return (0);
}

void	baslangic(t_game *game)
{
	game->coincheck = 0;
	game->exitcheck = 0;
	game->player.coin = 0;
	game->player.hareket = 0;
	game->playercheck = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		printf (RED"Sadece 2 Arguman Girebilirsin!\n");
		exit(0);
	}
	ft_window_size(&game, argv);
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.size_x, game.size_y, "MNCRFT2");
	baslangic(&game);
	create_map_line(&game, argv);
	game_control(&game);
	mlx_hook(game.window, 17, 0, destroy_window, &game);
	mlx_key_hook(game.window, key_check, &game);
	mlx_loop(game.mlx);
}
