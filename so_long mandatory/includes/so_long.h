/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:25:16 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/19 15:44:31 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define BUFFER_SIZE 5
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ESC 53
# define SQ 32

# include "mlx.h"
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>

//	IMAGES
typedef struct s_game_objs
{
	void	*p;
	void	*p_r;
	void	*p_u;
	void	*p_d;
	void	*p_l;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit_c;
	void	*exit_o;
	int		img_width;
	int		img_height;
}	t_game_objs;

//	OBJECTS COUNT
typedef struct s_game_objs_count
{
	int		player;
	int		collectibles;
	int		wall;
	int		floor;
	int		moves;
	int		exit;
}	t_game_objs_count;

//	GAME RESOLUTION
typedef struct s_game_resolution
{
	int		map_width;
	int		map_height;
	char	*win_name;
	char	*map_name;
}	t_game_resolution;

typedef struct s_coordinates
{
	int		x;
	int		y;
}	t_coordinates;

//	PLAYER & EXIT POSITION
typedef struct s_game_position
{
	t_coordinates	p_pos;
	t_coordinates	e_pos;
}	t_game_position;

//	MATRIX DATA
typedef struct s_matrix_data
{
	int					lines;
	int					matrix_rows;
	int					matrix_columns;
	char				**matrix;
}	t_matrix_data;

//	GAME CONTROL CENTER
typedef struct s_game_ctl
{
	void				*mlx_ptr;
	void				*win_ptr;
	int					exit_status;
	t_game_objs			g_objs;
	t_game_objs_count	game_objs_count;
	t_game_resolution	game_res;
	t_game_position		game_pos;
	t_matrix_data		m_data;
}	t_game_ctl;

int		main(int argc, char **argv);
void	ft_panel_init(t_game_ctl *game_cp);
int		ft_read_map(char *map_name, t_game_ctl *game_cp);
int		ft_check_map_x(char *map_name);
int		ft_count_lines(char *map_name);
int		ft_read_and_stock(int fd, t_game_ctl *game_cp);
int		ft_is_valid_map(t_game_ctl *game_cp);
int		ft_map_objs(t_game_ctl *game_cp);
int		ft_valid_objs(t_game_ctl *game_cp);
int		ft_valid_objs_2(t_game_ctl *game_cp);
int		ft_map_dimensions(t_game_ctl *game_cp);
int		ft_columns(t_game_ctl *game_cp);
int		ft_rows(t_game_ctl *game_cp);
int		ft_surr_walls(t_game_ctl *game_cp);
int		ft_start_game(t_game_ctl *game_cp);
int		ft_events(t_game_ctl *game_cp);
void	ft_image_init(t_game_ctl *game_cp);
int		ft_refresh_matrix(t_game_ctl *game_cp, int x_new, int y_new);
int		ft_refresh_matrix_2(t_game_ctl *game_cp, int x_new, int y_new);
char	*read_buff(int fd, char **buffer);
int		check_nl(char (*buffer));
void	ft_bzero(void *s, size_t n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*get_next_line(int fd);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_printhex(unsigned int n, char *hex);
int		ft_printu(unsigned int n);
int		ft_print_add(void *ptr);
int		ft_printf(const char *format, ...);
int		ft_exit_program(int x);
int		ft_valid_path(t_game_ctl *game_cp);

#endif