# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timargar <timargar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 16:27:45 by hrahovha          #+#    #+#              #
#    Updated: 2024/06/04 19:06:45 by timargar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minirt

GCC = gcc

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
IFLAGS = -Ilibs/mlx -Ilibs/libft/libft.a -Iinclude
LFLAGS = -Llibs/libft -lft -Llibs/mlx -lmlx -framework OpenGL -framework AppKit

SRCDIR = src
OBJDIR = obj

SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRCS))

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(OBJDIR)
	$(GCC) $(CFLAGS) $(IFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	make -s -C ./libs/libft
	make -s -C ./libs/mlx
	$(GCC) $(CFLAGS) $(IFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)

fclean: clean
	rm -rf $(NAME)

clean:
	@make clean -C ./libs/libft
	@make clean -C ./libs/mlx
	rm -rf $(OBJDIR)

re: fclean all

.PHONY: all clean fclean re
