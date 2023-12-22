/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:02:01 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/22 20:24:03 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_initialize_die_frames(t_game_ctl *game_cp)
{
	int	d1;
	int	d2;

	game_cp->g_objs.p_die_frames[0]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D1.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[1]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D2.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[2]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D3.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[3]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D4.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[4]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D5.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[5]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D6.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[6]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D7.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[7]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D8.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[8]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D9.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[9]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D10.xpm", &d1, &d2);
	game_cp->g_objs.p_die_frames[10]
		= mlx_xpm_file_to_image(game_cp->mlx_ptr, "./txts/D11.xpm", &d1, &d2);
}

void	ft_display_die_frame(t_game_ctl *game_cp, int frame)
{
	mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
		game_cp->g_objs.floor,
		game_cp->game_pos.p_pos.x * SQ,
		game_cp->game_pos.p_pos.y * SQ);
	mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
		game_cp->g_objs.p_die_frames[frame],
		game_cp->game_pos.p_pos.x * SQ,
		game_cp->game_pos.p_pos.y * SQ);
}

void	ft_animate_die(t_game_ctl *game_cp)
{
	int		frame;

	frame = 0;
	while (frame < NUM_DIE_FRAMES)
	{
		ft_display_die_frame(game_cp, frame);
		mlx_do_sync(game_cp->mlx_ptr);
		usleep(100000);
		frame++;
	}
}
