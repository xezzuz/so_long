/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_moves.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:30:33 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/22 21:28:58 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_move_right(t_game_ctl *game_cp, int i)
{
	if (game_cp->m_data.matrix[game_cp->game_pos.p_pos.y]
		[game_cp->game_pos.p_pos.x + 1] == WALL)
		return (i);
	if (i++ == 0)
		game_cp->g_objs.p = game_cp->g_objs.p_r;
	else if (i != 0)
	{
		game_cp->g_objs.p = game_cp->g_objs.p_r_c;
		i = 0;
	}
	ft_refresh_matrix(game_cp, game_cp->game_pos.p_pos.x + 1,
		game_cp->game_pos.p_pos.y);
	return (i);
}

int	ft_move_left(t_game_ctl *game_cp, int i)
{
	if (game_cp->m_data.matrix[game_cp->game_pos.p_pos.y]
		[game_cp->game_pos.p_pos.x - 1] == WALL)
		return (i);
	if (i++ == 0)
		game_cp->g_objs.p = game_cp->g_objs.p_l;
	else if (i != 0)
	{
		game_cp->g_objs.p = game_cp->g_objs.p_l_c;
		i = 0;
	}
	ft_refresh_matrix(game_cp, game_cp->game_pos.p_pos.x - 1,
		game_cp->game_pos.p_pos.y);
	return (i);
}

int	ft_move_up(t_game_ctl *game_cp, int i)
{
	if (game_cp->m_data.matrix[game_cp->game_pos.p_pos.y - 1]
		[game_cp->game_pos.p_pos.x] == WALL)
		return (i);
	if (i++ == 0)
		game_cp->g_objs.p = game_cp->g_objs.p_u;
	else if (i != 0)
	{
		game_cp->g_objs.p = game_cp->g_objs.p_u_c;
		i = 0;
	}
	ft_refresh_matrix(game_cp, game_cp->game_pos.p_pos.x,
		game_cp->game_pos.p_pos.y - 1);
	return (i);
}

int	ft_move_down(t_game_ctl *game_cp, int i)
{
	if (game_cp->m_data.matrix[game_cp->game_pos.p_pos.y + 1]
		[game_cp->game_pos.p_pos.x] == WALL)
		return (i);
	if (i++ == 0)
		game_cp->g_objs.p = game_cp->g_objs.p_d;
	else if (i != 0)
	{
		game_cp->g_objs.p = game_cp->g_objs.p_d_c;
		i = 0;
	}
	ft_refresh_matrix(game_cp, game_cp->game_pos.p_pos.x,
		game_cp->game_pos.p_pos.y + 1);
	return (i);
}
