/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:27:38 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/23 16:14:57 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_image_check(t_game_ctl *game_cp, void **img, char *path)
{
	int		d1;
	int		d2;

	*img = mlx_xpm_file_to_image(game_cp->mlx_ptr, path, &d1, &d2);
	if (*img == NULL)
		ft_exit_program(1);
}

void	ft_image_init(t_game_ctl *game_cp)
{
	ft_image_check(game_cp, &game_cp->g_objs.collectible,
		"./txts/COLL.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.floor,
		"./txts/FLOOR.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.wall,
		"./txts/WALL.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.exit_c,
		"./txts/EX_C.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.exit_o,
		"./txts/EX_O.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p,
		"./txts/P.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_r,
		"./txts/P.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_u,
		"./txts/P_U.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_d,
		"./txts/P_D.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_l,
		"./txts/P_L.xpm");
}

void	ft_put_image(t_game_ctl *game_cp, int i, int j)
{
	if (game_cp->m_data.matrix[i][j] == PLAYER)
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.p, j * SQ, i * SQ);
	else if (game_cp->m_data.matrix[i][j] == EXIT)
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.exit_c, j * SQ, i * SQ);
	else if (game_cp->m_data.matrix[i][j] == WALL)
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.wall, j * SQ, i * SQ);
	else if (game_cp->m_data.matrix[i][j] == FLOOR)
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.floor, j * SQ, i * SQ);
	else if (game_cp->m_data.matrix[i][j] == COLLECTIBLE)
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.collectible, j * SQ, i * SQ);
}

int	ft_game_init(t_game_ctl *game_cp)
{
	int		i;
	int		j;

	game_cp->mlx_ptr = mlx_init();
	if (!game_cp->mlx_ptr)
		ft_exit_program(1);
	game_cp->win_ptr
		= mlx_new_window(game_cp->mlx_ptr, game_cp->game_res.map_width,
			game_cp->game_res.map_height, "PACMAN");
	ft_image_init(game_cp);
	i = 0;
	while (i < game_cp->m_data.matrix_rows)
	{
		j = 0;
		while (j < game_cp->m_data.matrix_columns)
			ft_put_image(game_cp, i, j++);
		i++;
	}
	return (1);
}

int	ft_start_game(t_game_ctl *game_cp)
{
	ft_game_init(game_cp);
	ft_events(game_cp);
	mlx_loop(game_cp->mlx_ptr);
	return (1);
}
