/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 13:48:24 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/30 13:00:22 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_char(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free (arr);
}

void	ft_exit(t_game *game, int flag)
{
	free_char(game->map);
	free(game->read);
	free(game);
	if (game->mlx_ptr)
	{
		free(game->c_img);
		mlx_close_window(game->mlx_ptr);
		mlx_terminate(game->mlx_ptr);
	}
	print_err(flag);
	if (flag == 0)
		exit(0);
	exit(1);
}

void	ft_close(void *param)
{
	t_game	*game;

	game = param;
	ft_exit(game, 9);
}

void	ft_free_img(t_game *game)
{
	mlx_delete_image(game->mlx_ptr, game->c_img[0]);
	mlx_delete_image(game->mlx_ptr, game->c_img[1]);
	mlx_delete_image(game->mlx_ptr, game->c_img[2]);
	mlx_delete_image(game->mlx_ptr, game->c_img[3]);
	mlx_delete_image(game->mlx_ptr, game->c_img[4]);
}
