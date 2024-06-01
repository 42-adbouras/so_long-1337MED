# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adbouras <adbouras@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 12:41:57 by adbouras          #+#    #+#              #
#    Updated: 2024/05/31 10:24:43 by adbouras         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


GREEN	= \033[1;92m
YELLOW	= \033[0;93m
RED		= \033[1;91m
RESET	= \033[0;39m

NAME	= so_long

BNS_NAME	= so_long_bonus

CFLAGS	= -Wextra -Wall -Werror -Wunreachable-code -Ofast

LIBMLX	= /Users/adbouras/MLX42

LIBFT	= libft/libft.a
 
PRINTF	= ft_printf/libftprintf.a

HEADERS	= -I ./include -I $(LIBMLX)/include

LIBS	= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

SRCS	= main.c so_long.c errors.c  ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	ft_free.c ft_flood_fill.c map_check.c drawing_map.c direction.c  \

BNS_SRCS	= ./bonus/direction_bonus.c ./bonus/ft_flood_fill_bonus.c ./bonus/map_check_bonus.c ./bonus/drawing_map_bonus.c \
	./bonus/ft_free_bonus.c ./bonus/so_long_bonus.c ./bonus/errors_bonus.c ./bonus/main_bonus.c \
	./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
	./bonus/animation_bonus.c \

OBJS	= $(SRCS:.c=.o)

BOBJECT	= $(BNS_SRCS:.c=.o)

all: libmlx $(NAME)

bonus: libmlx $(BNS_NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJS)
	@echo "\n$(YELLOW)[Compiling Libft]$(RESET)"
	@make -C libft
	@echo "$(GREEN)[Libft Compiled]$(RESET)"
	@echo "$(YELLOW)[Compiling ft_printf]$(RESET)"
	@make -C ft_printf
	@echo "$(GREEN)[ft_print Compiled]$(RESET)"
	@echo "$(YELLOW)[Compiling so_long]$(RESET)"
	@$(CC) $(OBJS) $(LIBS) $(HEADERS) $(LIBFT) $(PRINTF) -o $(NAME)
	@echo "$(GREEN)[so_long Compiled]$(RESET)"

$(BNS_NAME): $(BOBJECT)
	@echo "\n$(YELLOW)[Compiling Libft]$(RESET)"
	@make -C libft
	@echo "$(GREEN)[Libft Compiled]$(RESET)"
	@echo "$(YELLOW)[Compiling ft_printf]$(RESET)"
	@make -C ft_printf
	@echo "$(GREEN)[ft_print Compiled]$(RESET)"
	@echo "$(YELLOW)[Compiling Bonus]$(RESET)"
	@$(CC) $(BOBJECT) $(LIBS) $(HEADERS) $(LIBFT) $(PRINTF) -o $(BNS_NAME)
	@echo "$(YELLOW)[Bonus Compiled]$(RESET)"

clean:
	@make clean -C libft
	@make clean -C ft_printf
	@rm -rf $(OBJS) $(BOBJECT)
	@rm -rf $(LIBMLX)/build
	@echo "$(RED)[Objects Cleaned]$(RESET)"

fclean: clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -rf $(NAME) $(BNS_NAME)
	@echo "$(RED)[EXEs Cleaned]$(RESET)"

re: fclean all

.PHONY: all, clean, fclean, re, libmlx