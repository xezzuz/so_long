# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 16:34:08 by nazouz            #+#    #+#              #
#    Updated: 2023/12/24 18:40:32 by nazouz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

NAME_BONUS		=	so_long_bonus

CC				=	cc

CFLAGS			=	-Wall -Wextra -Werror

MLXFLAGS		=	-lmlx -framework OpenGL -framework AppKit

INCLUDES		=	./includes/so_long.h

INCLUDES_BONUS	=	./includes/so_long_bonus.h

RM				=	rm -f

SRCS				=	\
					./srcs/libft/ft_calloc.c \
					./srcs/libft/ft_strncmp.c \
					./srcs/libft/ft_strlen.c \
					./srcs/libft/ft_strjoin.c \
					./srcs/libft/ft_strdup.c \
					./srcs/libft/ft_strlcpy.c \
					./srcs/libft/ft_memcpy.c \
					./srcs/libft/ft_strchr.c \
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
					./srcs/free.c \
					./srcs/main.c

SRCS_BONUS				=	\
					./srcs/libft/ft_calloc.c \
					./srcs/libft/ft_strncmp.c \
					./srcs/libft/ft_strlen.c \
					./srcs/libft/ft_strjoin.c \
					./srcs/libft/ft_strdup.c \
					./srcs/libft/ft_strlcpy.c \
					./srcs/libft/ft_memcpy.c \
					./srcs/libft/ft_strchr.c \
					./srcs/libft/ft_itoa.c \
					./srcs/ft_printf/ft_printf.c \
					./srcs/ft_printf/ft_print_add.c \
					./srcs/ft_printf/ft_printhex.c \
					./srcs/ft_printf/ft_printu.c \
					./srcs/ft_printf/ft_putchar.c \
					./srcs/ft_printf/ft_putnbr.c \
					./srcs/ft_printf/ft_putstr.c \
					./srcs/get_next_line/get_next_line.c \
					./srcs_bonus/map.c \
					./srcs_bonus/map_utils.c \
					./srcs_bonus/map_utils_2.c \
					./srcs_bonus/map_path.c \
					./srcs_bonus/game_start.c \
					./srcs_bonus/game_start_utils.c \
					./srcs_bonus/game_events.c \
					./srcs_bonus/game_events_utils.c \
					./srcs_bonus/game_events_moves.c \
					./srcs_bonus/exit_actions.c \
					./srcs_bonus/free.c \
					./srcs_bonus/enemy_patrol.c \
					./srcs_bonus/animations.c \
					./srcs_bonus/main.c


OBJS			=	$(SRCS:.c=.o)

OBJS_BONUS		=	$(SRCS_BONUS:.c=.o)

all : $(NAME)

%.o : %.c $(INCLUDES) $(INCLUDES_BONUS)
	$(CC) -c $(CFLAGS) $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(MLXFLAGS) $(OBJS) -o $@

bonus : $(NAME_BONUS)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(MLXFLAGS) $(OBJS_BONUS) -o $@

clean :
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean : clean
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all