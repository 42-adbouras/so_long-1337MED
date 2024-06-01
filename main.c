/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:40:12 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/31 10:35:15 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (1);
	game = malloc(sizeof(t_game));
	if (!if_file_valid(av[1], game))
		return (1);
	ft_printf("%s[MAP VALID]%s\n", GREEN, RESET);
	game_init(game);
	ft_draw(game);
	game->moves = 0;
	game->c_count = 0;
	mlx_key_hook(game->mlx_ptr, &ft_key_hook, game);
	mlx_close_hook(game->mlx_ptr, &ft_close, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
