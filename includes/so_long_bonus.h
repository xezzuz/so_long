/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:25:16 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 18:36:12 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# define BUFFER_SIZE 5
# define NUM_DIE_FRAMES 11
# define MAX_ENEMIES 6
# define SQ 32

//	OBJECTS
# define WALL '1'
# define FLOOR '0'
# define PLAYER 'P'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define GHOST 'G'

//	KEYS
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2

# include <mlx.h>
# include <unistd.h>
# include <time.h>
# include <limits.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_enemy
{
	int		x;
	int		y;
	int		dir_x;
}	t_enemy;

typedef struct s_game_objs
{
	void	*p;
	void	*p_r;
	void	*p_u;
	void	*p_d;
	void	*p_l;
	void	*p_c;
	void	*p_r_c;
	void	*p_u_c;
	void	*p_d_c;
	void	*p_l_c;
	void	*ghost;
	void	*wall;
	void	*floor;
	void	*collectible;
	void	*exit_c;
	void	*exit_o;
	void	*p_die_frames[NUM_DIE_FRAMES];
}	t_game_objs;

typedef struct s_game_objs_count
{
	int		player;
	int		collectibles;
	int		moves;
	int		exit;
	int		enemies;
}	t_game_objs_count;

typedef struct s_game_resolution
{
	int		map_width;
	int		map_height;
}	t_game_resolution;

typedef struct s_coordinates
{
	int		x;
	int		y;
}	t_coordinates;

typedef struct s_game_position
{
	t_coordinates	p_pos;
	t_coordinates	e_pos;
}	t_game_position;

typedef struct s_matrix_data
{
	int					lines;
	int					matrix_rows;
	int					matrix_columns;
	char				**matrix;
}	t_matrix_data;

typedef struct s_game_ctl
{
	void				*mlx_ptr;
	void				*win_ptr;
	unsigned long		last_mv_time;
	t_enemy				enemies[MAX_ENEMIES];
	t_game_objs			g_objs;
	t_game_objs_count	game_objs_count;
	t_game_resolution	game_res;
	t_game_position		game_pos;
	t_matrix_data		m_data;
}	t_game_ctl;

int		main(int argc, char **argv);
int		ft_read_map(char *map_name, t_game_ctl *game_cp);
int		ft_map_objs(t_game_ctl *game_cp);
int		ft_map_dimensions(t_game_ctl *game_cp);
int		ft_columns(t_game_ctl *game_cp);
int		ft_rows(t_game_ctl *game_cp);
int		ft_surr_walls(t_game_ctl *game_cp);
int		ft_start_game(t_game_ctl *game_cp);
int		ft_events(t_game_ctl *game_cp);
void	ft_image_init(t_game_ctl *game_cp);
int		ft_refresh_matrix(t_game_ctl *game_cp, int x_new, int y_new);
int		ft_exit_program(t_game_ctl *game_cp, int x);
int		ft_valid_path(t_game_ctl *game_cp);
int		ft_x_press(t_game_ctl *game_cp);
int		ft_move_right(t_game_ctl *game_cp, int i);
int		ft_move_left(t_game_ctl *game_cp, int i);
int		ft_move_up(t_game_ctl *game_cp, int i);
int		ft_move_down(t_game_ctl *game_cp, int i);
void	ft_free_map(char ***matrix);
void	ft_free_imgs(t_game_ctl *game_cp);
void	ft_animate_die(t_game_ctl *game_cp);
int		ft_count_objs(t_game_ctl *game_cp);
int		ft_strange_objs(t_game_ctl *game_cp);
int		ft_count_chars(char *str, char c);
void	ft_anim_image_init(t_game_ctl *game_cp);
void	ft_image_check(t_game_ctl *game_cp, void **img, char *path);
void	ft_init_die_frames(t_game_ctl *game_cp);
void	ft_null_term_matrix(char **matrix);
int		ft_enemy_patrol(t_game_ctl *game_cp);
void	ft_ghosts(t_game_ctl *game_cp);
void	ft_enemy_dir_init(t_game_ctl *game_cp);

//	LIBFT
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	*ft_calloc(size_t count, size_t size);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);
char	*ft_strchr(const char *s, int c);

//	GET_NEXT_LINE
char	*get_next_line(int fd);

//	PRINTF
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int n);
int		ft_printhex(unsigned int n, char *hex);
int		ft_printu(unsigned int n);
int		ft_print_add(void *ptr);
int		ft_printf(const char *format, ...);

#endif