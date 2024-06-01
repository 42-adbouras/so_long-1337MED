/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:42:49 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/29 19:15:26 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	*ft_find_pos(char *read)
{
	char	**arr;
	int		i;
	int		j;
	int		*pos;

	i = 0;
	arr = ft_split(read, '\n');
	pos = malloc(sizeof(int) * 2);
	while (arr[i])
	{
		j = -1;
		while (arr[i][++j])
			if (arr[i][j] == 'P')
				break ;
		if (arr[i][j] == 'P')
			break ;
		i++;
	}
	pos[0] = i;
	pos[1] = j;
	return (free_char(arr), pos);
}

bool	ft_call_ff(t_game *game)
{
	int		*pos;
	int		e_count;
	t_game	node;

	e_count = 0;
	pos = ft_find_pos(game->read);
	node = ft_flood_fill(game->map, pos[0], pos[1], &e_count);
	if (node.c != game->c || e_count != 1)
		return (false);
	free_char(game->map);
	free(pos);
	return (true);
}

bool	ft_count_elements(t_game *game)
{
	int		i;

	i = 0;
	while (game->read[i])
	{
		if (game->read[i] == 'P')
			game->p++;
		else if (game->read[i] == 'C')
			game->c++;
		else if (game->read[i] == 'E')
			game->e++;
		else if (game->read[i] == 'X')
			game->enemy++;
		i++;
	}
	if (game->p != 1 || game->e != 1 || game->c <= 0 || game->enemy <= 0)
		return (ft_exit(game, 2), false);
	return (true);
}

bool	ft_check_border(t_game *game)
{
	int		i;
	int		j;
	size_t	len;

	game->mlx_ptr = NULL;
	if (!ft_check_elements(game) || !ft_count_elements(game))
		return (false);
	len = ft_strlen(game->map[0]);
	j = 0;
	while (game->map[j])
	{
		if (len != ft_strlen(game->map[j]))
			return (ft_exit(game, 3), false);
		if (game->map[j][0] != '1' || game->map[j][len - 1] != '1')
			return (ft_exit(game, 3), false);
		j++;
	}
	i = 0;
	while (game->map[0][i] && game->map[j - 1][i])
		if (game->map[0][i] != '1' || game->map[j - 1][i++] != '1')
			return (ft_exit(game, 3), false);
	if (!ft_call_ff(game))
		return (ft_exit(game, 6), false);
	return (true);
}

bool	ft_check_elements(t_game *game)
{
	int	i;

	i = 0;
	while (game->read[i])
	{
		if (game->read[i] == '\n')
			if (game->read[i + 1] == '\n')
				return (ft_exit(game, 5), false);
		if (!ft_strchr("01CEPX\n", game->read[i]))
			return (ft_exit(game, 4), false);
		i++;
	}
	return (true);
}
