/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:27:38 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/19 16:40:35 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_image_init(t_game_ctl *game_cp)
{
	int		d1;
	int		d2;

	game_cp->g_objs.p
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/PL.xpm", &d1, &d2);
	game_cp->g_objs.p_r
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/PL.xpm", &d1, &d2);
	game_cp->g_objs.p_u
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/PL_U.xpm", &d1, &d2);
	game_cp->g_objs.p_d
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/PL_D.xpm", &d1, &d2);
	game_cp->g_objs.p_l
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/PL_L.xpm", &d1, &d2);
	game_cp->g_objs.floor
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/FLOOR.xpm", &d1, &d2);
	game_cp->g_objs.exit_c
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/EX_C.xpm", &d1, &d2);
	game_cp->g_objs.exit_o
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/EX_O.xpm", &d1, &d2);
	game_cp->g_objs.collectible
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/COLL.xpm", &d1, &d2);
	game_cp->g_objs.wall
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/WALL.xpm", &d1, &d2);
}

void	ft_put_image_2(t_game_ctl *game_cp, int i, int j)
{
	if (game_cp->m_data.matrix[i][j] == PLAYER)
	{
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.floor, j * SQ, i * SQ);
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.p, j * SQ, i * SQ);
		game_cp->game_pos.p_pos.x = j;
		game_cp->game_pos.p_pos.y = i;
	}
	else if (game_cp->m_data.matrix[i][j] == EXIT)
	{
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.exit_c, j * SQ, i * SQ);
		game_cp->game_pos.e_pos.x = j;
		game_cp->game_pos.e_pos.y = i;
	}
}

void	ft_put_image(t_game_ctl *game_cp, int i, int j)
{
	if (game_cp->m_data.matrix[i][j] == WALL)
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.wall, j * SQ, i * SQ);
	else if (game_cp->m_data.matrix[i][j] == FLOOR)
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.floor, j * SQ, i * SQ);
	else if (game_cp->m_data.matrix[i][j] == COLLECTIBLE)
	{
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.floor, j * SQ, i * SQ);
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.collectible, j * SQ, i * SQ);
	}
	else if (game_cp->m_data.matrix[i][j] == EXIT
		|| game_cp->m_data.matrix[i][j] == PLAYER)
		ft_put_image_2(game_cp, i, j);
}

int	ft_game_init(t_game_ctl *game_cp)
{
	int		i;
	int		j;

	game_cp->game_res.win_name = "PACBOY";
	game_cp->mlx_ptr = mlx_init();
	game_cp->win_ptr
		= mlx_new_window(game_cp->mlx_ptr, game_cp->game_res.map_width,
			game_cp->game_res.map_height, game_cp->game_res.win_name);
	ft_image_init(game_cp);
	i = 0;
	while (i < game_cp->m_data.matrix_rows)
	{
		j = 0;
		while (j < game_cp->m_data.matrix_columns)
		{
			ft_put_image(game_cp, i, j);
			j++;
		}
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
