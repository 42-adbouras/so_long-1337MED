/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:12:47 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/30 12:58:42 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_frames(void *param)
{
	int static	t;
	t_game		*game;

	game = param;
	t++;
	if (t == 10)
		change_c(game, 1);
	else if (t == 20)
		change_c(game, 2);
	else if (t == 30)
		change_c(game, 1);
	else if (t == 40)
		change_c(game, 0);
	else if (t == 50)
		change_c(game, 3);
	else if (t == 60)
		change_c(game, 4);
	else if (t == 70)
		change_c(game, 3);
	else if (t == 80)
		change_c(game, 0);
	else if (t == 81)
		t = 0;
}

void	change_c(t_game *game, int flag)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'C')
			{
				if (game->map[(game->player->instances->y / 48)]
					[(game->player->instances->x / 48)] == 'C')
				{
					game->map[(game->player->instances->y / 48)]
					[(game->player->instances->x / 48)] = '0';
					game->c_count += 1;
				}
				ft_flag(game, x, y, flag);
			}
			x++;
		}
		y++;
	}
}

void	ft_flag(t_game *game, int x, int y, int flag)
{
	if (flag == 0)
	{
		mlx_image_to_window(game->mlx_ptr, game->c_img[0], x * 48, y * 48);
		ft_free_img(game);
		free(game->c_img);
		load_anime(game);
	}
	else if (flag == 1)
		mlx_image_to_window(game->mlx_ptr, game->c_img[1], x * 48, y * 48);
	else if (flag == 2)
		mlx_image_to_window(game->mlx_ptr, game->c_img[2], x * 48, y * 48);
	else if (flag == 3)
		mlx_image_to_window(game->mlx_ptr, game->c_img[3], x * 48, y * 48);
	else if (flag == 4)
		mlx_image_to_window(game->mlx_ptr, game->c_img[4], x * 48, y * 48);
}

mlx_image_t	*load_txt(t_game *game, char *path)
{
	mlx_texture_t	*txt;
	mlx_image_t		*img;

	txt = mlx_load_png(path);
	if (!txt)
		ft_exit(game, 7);
	img = mlx_texture_to_image(game->mlx_ptr, txt);
	if (!img)
		ft_exit(game, 7);
	mlx_delete_texture(txt);
	return (img);
}

void	load_anime(t_game *game)
{
	game->c_img = malloc(sizeof(mlx_image_t) * 6);
	game->c_img[0] = load_txt(game, "./textures/C.png");
	game->c_img[1] = load_txt(game, "./textures/anime/1.png");
	game->c_img[2] = load_txt(game, "./textures/anime/2.png");
	game->c_img[3] = load_txt(game, "./textures/anime/3.png");
	game->c_img[4] = load_txt(game, "./textures/anime/4.png");
	game->c_img[5] = NULL;
}
