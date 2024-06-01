/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 12:40:22 by adbouras          #+#    #+#             */
/*   Updated: 2024/05/31 10:24:25 by adbouras         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define GREEN "\e[0;32m"
# define RED "\033[0;31m"
# define RESET "\033[0m"

# include <stdlib.h>
# include <stdbool.h>
# include <fcntl.h>
# include "/Users/adbouras/MLX42/include/MLX42/MLX42.h"
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include "./get_next_line/get_next_line.h"

typedef struct s_game
{
	unsigned int	p;
	unsigned int	e;
	unsigned int	c;
	void			*mlx_ptr;
	mlx_image_t		*player;
	char			*read;
	char			**map;
	unsigned int	c_count;
	unsigned int	moves;
	int				e_x;
	int				e_y;
	int				x;
	int				y;
}					t_game;

/*********  MAP DRAWING		************************************/
mlx_image_t	*draw_lmnt(t_game *game, int i, int j, char *path);
void		draw_extra(t_game *game, int i, int j, char flag);
void		game_init(t_game *game);
void		ft_draw(t_game *game);

/*********  MAP CHECK	****************************************/
bool		if_file_valid(char *arg, t_game *game);
bool		ft_check_elements(t_game *game);
bool		ft_count_elements(t_game *game);
bool		ft_check_border(t_game *game);
bool		ft_call_ff(t_game *game);
int			*ft_find_pos(char *read);

/*********  GAME CONTROLS	************************************/
void		ft_key_hook(mlx_key_data_t key, void *param);
void		move_right(t_game *game);
void		move_down(t_game *game);
void		move_left(t_game *game);
void		move_up(t_game *game);

/*********  UTILS	********************************************/
t_game		ft_flood_fill(char **read, int x, int y, int *count_e);
char		*ft_read_map(char *arg);

/*********  FREE	********************************************/
void		ft_exit(t_game *game, int flag);
void		free_char(char **arr);
void		ft_close(void *param);

/*********  ERRORS	********************************************/
void		print_err(int flag);

#endif
