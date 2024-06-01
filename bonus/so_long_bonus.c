/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:40:12 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/30 14:27:56 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_read_map(char *arg)
{
	int		fd;
	char	*read;
	char	*map;

	map = NULL;
	fd = open(arg, O_RDONLY);
	if (fd == -1)
		exit(write(2, "\033[0;31m[File not Found]\033[0m\n", 28));
	while (1)
	{
		read = get_next_line(fd);
		if (!read)
			break ;
		map = ft_strjoin(map, read);
		free(read);
	}
	close(fd);
	return (map);
}

bool	if_file_valid(char *arg, t_game *game)
{
	int		i;

	i = ft_strlen(arg);
	i -= 4;
	if (ft_strncmp(&arg[i], ".ber", 4) != 0 || arg[i + 4] != '\0' || i == 0)
		return (print_err(1), free(game), false);
	game->read = ft_read_map(arg);
	if (!(game->read))
		return (print_err(8), free(game), false);
	game->map = ft_split(game->read, '\n');
	game->c = 0;
	game->p = 0;
	game->e = 0;
	game->enemy = 0;
	if (!ft_check_border(game))
		return (false);
	game->map = ft_split(game->read, '\n');
	return (true);
}

void	ft_key_hook(mlx_key_data_t key, void *param)
{
	t_game	*game;

	game = param;
	if (game->map[(game->player->instances->y / 48)]
		[(game->player->instances->x / 48)] == 'E' && game->c_count == game->c)
		ft_exit(game, 0);
	if (game->map[(game->player->instances->y / 48)]
		[(game->player->instances->x / 48)] == 'X')
		ft_exit(game, 9);
	if ((key.key == MLX_KEY_ESCAPE || key.key == MLX_KEY_Q)
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		ft_exit(game, 9);
	else if ((key.key == MLX_KEY_W || key.key == MLX_KEY_UP)
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		move_up(game);
	else if ((key.key == MLX_KEY_A || key.key == MLX_KEY_LEFT)
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		move_left(game);
	else if ((key.key == MLX_KEY_S || key.key == MLX_KEY_DOWN)
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		move_down(game);
	else if ((key.key == MLX_KEY_D || key.key == MLX_KEY_RIGHT)
		&& (key.action == MLX_PRESS || key.action == MLX_REPEAT))
		move_right(game);
}

void	print_moves(t_game *game)
{
	char	*move;

	move = ft_itoa(++game->moves);
	mlx_delete_image(game->mlx_ptr, game->img);
	game->img = mlx_put_string (game->mlx_ptr, move, 60, 24);
	free(move);
}
