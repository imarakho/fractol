#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imarakho <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/18 15:33:46 by imarakho          #+#    #+#              #
#    Updated: 2017/02/24 13:52:32 by imarakho         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
SRC = main.c \
    mandel.c \
    julia.c \
    draw.c \
    burnship.c \
	fish.c \
	trees.c \

LIB = libft/libft.a
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
MLX_F = -g -lmlx -framework OpenGL -framework AppKit
all: $(NAME)
$(NAME): $(OBJ)
	@make -C libft/ && make -C libft/ clean
	@clang $(FLAGS) $(MLX_F) $(LIB) $(OBJ) -o $(NAME)
	@echo "Compilation done!"
%.o: %.c
	@clang -c $(FLAGS) -o $@ $<
lldb:
	@clang -g $(FLAGS) $(MLX_F) $(LIB) $(SRC) -o debug
	@echo "Use 'debug' for lldb."
lclean:
	@rm -f debug
	@echo "'debug' removed!"
clean:
	@rm -f $(OBJ)
	@echo "Objects removed!"
fclean: clean
	@rm -f $(NAME)
	@echo "Executable removed!"
re: fclean all
