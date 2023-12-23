/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 20:50:19 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 00:13:52 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_key_action(int key, t_game_ctl *game_cp)
{
	static int	i = 1;

	if (key == UP)
		i = ft_move_up(game_cp, i);
	else if (key == DOWN)
		i = ft_move_down(game_cp, i);
	else if (key == RIGHT)
		i = ft_move_right(game_cp, i);
	else if (key == LEFT)
		i = ft_move_left(game_cp, i);
	else if (key == ESC)
		ft_exit_program(game_cp, 105);
	return (1);
}

int	ft_events(t_game_ctl *game_cp)
{
	ft_enemy_dir_init(game_cp);
	mlx_string_put(game_cp->mlx_ptr, game_cp->win_ptr,
		7, 4, 0xFFFFFF, "Moves:0");
	mlx_loop_hook(game_cp->mlx_ptr, ft_enemy_patrol, game_cp);
	mlx_hook(game_cp->win_ptr, 17, 0, ft_x_press, game_cp);
	mlx_hook(game_cp->win_ptr, 2, 0, ft_key_action, game_cp);
	return (1);
}
