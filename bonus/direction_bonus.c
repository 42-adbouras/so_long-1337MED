/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 10:16:14 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/30 10:10:23 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	move_up(t_game *game)
{
	draw_lmnt(game, game->player->instances->y
		/ 48, game->player->instances->x / 48, "./textures/0.png");
	draw_lmnt(game, game->e_x, game->e_y, "./textures/E.png");
	game->player = draw_lmnt(game, game->player->instances->y
			/ 48, game->player->instances->x / 48, "./textures/PU.png");
	if (game->map[(game->player->instances->y / 48) - 1]
		[(game->player->instances->x / 48)] != '1')
	{
		game->player->instances->y -= 48;
		print_moves(game);
	}
}

void	move_left(t_game *game)
{
	draw_lmnt(game, game->player->instances->y
		/ 48, game->player->instances->x / 48, "./textures/0.png");
	draw_lmnt(game, game->e_x, game->e_y, "./textures/E.png");
	game->player = draw_lmnt(game, game->player->instances->y
			/ 48, game->player->instances->x / 48, "./textures/PL.png");
	if (game->map[(game->player->instances->y / 48)]
		[(game->player->instances->x / 48) - 1] != '1')
	{
		game->player->instances->x -= 48;
		print_moves(game);
	}
}

void	move_down(t_game *game)
{
	draw_lmnt(game, game->player->instances->y
		/ 48, game->player->instances->x / 48, "./textures/0.png");
	draw_lmnt(game, game->e_x, game->e_y, "./textures/E.png");
	game->player = draw_lmnt(game, game->player->instances->y
			/ 48, game->player->instances->x / 48, "./textures/P.png");
	if (game->map[(game->player->instances->y / 48) + 1]
		[(game->player->instances->x / 48)] != '1')
	{
		game->player->instances->y += 48;
		print_moves(game);
	}
}

void	move_right(t_game *game)
{
	draw_lmnt(game, game->player->instances->y
		/ 48, game->player->instances->x / 48, "./textures/0.png");
	draw_lmnt(game, game->e_x, game->e_y, "./textures/E.png");
	game->player = draw_lmnt(game, game->player->instances->y
			/ 48, game->player->instances->x / 48, "./textures/PR.png");
	if (game->map[(game->player->instances->y / 48)]
		[(game->player->instances->x / 48) + 1] != '1')
	{
		game->player->instances->x += 48;
		print_moves(game);
	}
}
