#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huweber <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/27 14:01:11 by huweber           #+#    #+#              #
#    Updated: 2017/02/27 14:04:15 by huweber          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= fractol
SRC		= main.c hook.c utils.c draw.c
OBJ		= $(addprefix $(OBJD),$(SRC:.c=.o))
MLX		= -L ./mlx -l mlx -framework OpenGL -framework AppKit
LIBFT	= -L ./libft -l ft
OBJD	= ./obj/
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror $(INC)
INC		= -I ./includes/ -I ./libft/includes/ -I ./mlx/

all			: obj $(NAME)

obj			:
	mkdir -p $(OBJD)

$(OBJD)%.o	: ./srcs/%.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME)		: $(OBJ)	
	make -C libft/
	make -C mlx/
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)

clean		:
	rm -rf $(OBJD)
	make clean -C ./libft
	make clean -C ./mlx

fclean		: clean
	rm -rf $(NAME)
	make fclean -C ./libft

re:	fclean all
