# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 16:34:08 by nazouz            #+#    #+#              #
#    Updated: 2023/12/19 15:43:52 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror -g

MLXFLAGS		=	-lmlx -framework OpenGL -framework AppKit

INCLUDES		=	./includes/so_long.h

RM				=	rm -rf

SRCS			=	\
					./srcs/libft/ft_calloc.c \
					./srcs/libft/ft_strncmp.c \
					./srcs/libft/ft_strlen.c \
					./srcs/libft/ft_strjoin.c \
					./srcs/libft/ft_strdup.c \
					./srcs/libft/ft_strlcpy.c \
					./srcs/libft/ft_memcpy.c \
					./srcs/ft_printf/ft_printf.c \
					./srcs/ft_printf/ft_print_add.c \
					./srcs/ft_printf/ft_printhex.c \
					./srcs/ft_printf/ft_printu.c \
					./srcs/ft_printf/ft_putchar.c \
					./srcs/ft_printf/ft_putnbr.c \
					./srcs/ft_printf/ft_putstr.c \
					./srcs/get_next_line/get_next_line.c \
					./srcs/map.c \
					./srcs/map_utils.c \
					./srcs/map_utils_2.c \
					./srcs/map_path.c \
					./srcs/game_start.c \
					./srcs/game_events.c \
					./srcs/game_events_utils.c \
					./srcs/exit_actions.c \
					./srcs/main.c

OBJS			=	$(SRCS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDES)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	$(CC) -g $(MLXFLAGS) $(OBJS) -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all