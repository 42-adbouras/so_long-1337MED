/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 10:31:53 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/18 12:59:40 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_wasted(void)
{
	ft_printf("%s\t\t _       _____   _____________________ \n", RED);
	ft_printf("\t\t| |     / /   | / ___/_  __/ ____/ __ \\\n");
	ft_printf("\t\t| | /| / / /| | \\__ \\ / / / __/ / / / /\n");
	ft_printf("\t\t| |/ |/ / ___ |___/ // / / /___/ /_/ / \n");
	ft_printf("\t\t|__/|__/_/  |_/____//_/ /_____/_____/  \n%s", RESET);
}

void	print_win(void)
{
	ft_printf("%s\t\t\t   ______ ______\n", GREEN);
	ft_printf("\t\t\t  / ____// ____/\n");
	ft_printf("\t\t\t / / __ / / __  \n");
	ft_printf("\t\t\t/ /_/ // /_/ /  \n");
	ft_printf("\t\t\t\\____/ \\____/   %s\n\n", RESET);
}

void	print_err(int flag)
{
	if (flag == 1)
		write (2, "\033[0;31m[Invalid Map Name]\033[0m\n", 30);
	else if (flag == 2)
		write (1, "\033[0;31m[Elements Error]\n\033[0m\n", 29);
	else if (flag == 3)
		write (2, "\033[0;31m[Border Error]\n\033[0m\n", 27);
	else if (flag == 4)
		write (2, "\033[0;31m[Unknown Character]\033[0m\n", 31);
	else if (flag == 5)
		write (1, "\033[0;31m[Consecutive New Line]\033[0m\n", 34);
	else if (flag == 6)
		write(1, "\033[0;31m[Path Invalid]\033[0m\n", 26);
	else if (flag == 7)
		write(1, "\033[0;31m[Error Loading Image]\033[0m\n", 34);
	else if (flag == 8)
		write(1, "\033[0;31m[File Empty]\033[0m\n", 24);
	else if (flag == 10)
		write(1, "\033[0;31m[Big Map For Display]\033[0m\n", 33);
	else if (flag == 9)
		print_wasted();
	else if (flag == 0)
		print_win();
}
