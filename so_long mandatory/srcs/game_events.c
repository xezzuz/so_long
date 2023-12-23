/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:50:19 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/23 10:48:25 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_x_press(t_game_ctl *game_cp)
{
	game_cp->game_res.map_height += 0;
	ft_exit_program(105);
	return (1);
}

int	ft_key_action(int key, t_game_ctl *game_cp)
{
	if (key == UP)
		return (game_cp->g_objs.p = game_cp->g_objs.p_u,
			ft_refresh_matrix(game_cp, game_cp->game_pos.p_pos.x,
				game_cp->game_pos.p_pos.y - 1));
	else if (key == DOWN)
		return (game_cp->g_objs.p = game_cp->g_objs.p_d,
			ft_refresh_matrix(game_cp, game_cp->game_pos.p_pos.x,
				game_cp->game_pos.p_pos.y + 1));
	else if (key == RIGHT)
		return (game_cp->g_objs.p = game_cp->g_objs.p_r,
			ft_refresh_matrix(game_cp, game_cp->game_pos.p_pos.x + 1,
				game_cp->game_pos.p_pos.y));
	else if (key == LEFT)
		return (game_cp->g_objs.p = game_cp->g_objs.p_l,
			ft_refresh_matrix(game_cp, game_cp->game_pos.p_pos.x - 1,
				game_cp->game_pos.p_pos.y));
	else if (key == ESC)
		return (mlx_destroy_window(game_cp->mlx_ptr, game_cp->win_ptr),
			ft_exit_program(105));
	return (1);
}

int	ft_events(t_game_ctl *game_cp)
{
	ft_printf("Moves: 0\n");
	mlx_hook(game_cp->win_ptr, 17, 0, ft_x_press, game_cp);
	mlx_key_hook(game_cp->win_ptr, ft_key_action, game_cp);
	return (1);
}
