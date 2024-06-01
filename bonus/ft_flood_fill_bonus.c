/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood_fill_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 21:47:27 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/17 18:50:04 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

t_game	ft_flood_fill(char **read, int x, int y, int *count_e)
{
	t_game	lmnt;

	lmnt.c = 0;
	lmnt.e = 0;
	if (read[x][y] == '1' || read[x][y] == 'X')
		return (lmnt);
	if (read[x][y] == 'C')
	{
		lmnt.c++;
		read[x][y] = '1';
	}
	if (read[x][y] == 'E')
	{
		*count_e = 1;
		read[x][y] = '1';
	}
	read[x][y] = '1';
	lmnt.c += ft_flood_fill(read, x + 1, y, count_e).c;
	lmnt.c += ft_flood_fill(read, x - 1, y, count_e).c;
	lmnt.c += ft_flood_fill(read, x, y + 1, count_e).c;
	lmnt.c += ft_flood_fill(read, x, y - 1, count_e).c;
	return (lmnt);
}
