/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 17:05:44 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/30 12:56:25 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_game *game)
{
	int	w;
	int	h;

	w = ft_strlen(game->map[0]) * 48;
	h = 0;
	while (game->map[h])
		h++;
	h *= 48;
	if (w > 2560 || h > 1440)
		ft_exit(game, 10);
	game->mlx_ptr = mlx_init(w, h, "so_long", true);
	if (!game->mlx_ptr)
		exit(1);
}

mlx_image_t	*draw_lmnt(t_game *game, int i, int j, char *path)
{
	mlx_texture_t	*txt;
	mlx_image_t		*img;

	txt = mlx_load_png(path);
	if (!txt)
		ft_exit(game, 7);
	img = mlx_texture_to_image(game->mlx_ptr, txt);
	if (!img)
		ft_exit(game, 7);
	if (mlx_image_to_window(game->mlx_ptr, img, j * 48, i * 48) < 0)
		ft_exit(game, 7);
	mlx_delete_texture(txt);
	return (img);
}

void	draw_extra(t_game *game, int i, int j, char flag)
{
	if (flag == 'E')
	{
		draw_lmnt(game, i, j, "./textures/E.png");
		game->e_x = i;
		game->e_y = j;
	}
	else if (flag == 'P')
	{
		draw_lmnt(game, i, j, "./textures/0.png");
		game->x = i;
		game->y = j;
	}
}

void	ft_draw(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '1')
				draw_lmnt(game, i, j, "./textures/1.png");
			else if (game->map[i][j] == '0')
				draw_lmnt(game, i, j, "./textures/0.png");
			else if (game->map[i][j] == 'C')
				draw_lmnt(game, i, j, "./textures/C.png");
			else if (game->map[i][j] == 'E')
				draw_extra(game, i, j, 'E');
			else if (game->map[i][j] == 'P')
				draw_extra(game, i, j, 'P');
			j++;
		}
		i++;
	}
	game->player = draw_lmnt(game, game->x, game->y, "./textures/P.png");
}
