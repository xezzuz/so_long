/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 17:02:01 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/23 17:51:47 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_fill_die_frames(t_game_ctl *game_cp)
{
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[0], "./txts/D1.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[1], "./txts/D2.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[2], "./txts/D3.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[3], "./txts/D4.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[4], "./txts/D5.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[5], "./txts/D6.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[6], "./txts/D7.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[7], "./txts/D8.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[8], "./txts/D9.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[9], "./txts/D10.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_die_frames[10], "./txts/D11.xpm");
}

void	ft_init_die_frames(t_game_ctl *game_cp)
{
	int		i;

	i = 0;
	while (i < NUM_DIE_FRAMES)
		game_cp->g_objs.p_die_frames[i++] = NULL;
	ft_fill_die_frames(game_cp);
	i = 0;
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
