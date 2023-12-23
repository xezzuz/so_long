/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:19:09 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/22 22:53:19 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_set_player_pos(t_game_ctl *game_cp, int x, int y)
{
	game_cp->game_pos.p_pos.x = x;
	game_cp->game_pos.p_pos.y = y;
	return ;
}

// CHECKS IF THE MAP IS VALID BY CHECKING MAP WALLS AND CHARACTERS
int	ft_map_objs(t_game_ctl *game_cp)
{
	if (ft_valid_objs(game_cp) && ft_valid_objs_2(game_cp)
		&& ft_surr_walls(game_cp))
		return (1);
	return (0);
}

// CALCULATE THE MAP CHARACTERS
int	ft_valid_objs(t_game_ctl *game_cp)
{
	int		rw_i;
	int		i;

	rw_i = -1;
	while (++rw_i < game_cp->m_data.matrix_rows)
	{
		i = -1;
		while (++i < game_cp->m_data.matrix_columns)
		{
			if (game_cp->m_data.matrix[rw_i][i] == FLOOR)
				game_cp->game_objs_count.floor++;
			else if (game_cp->m_data.matrix[rw_i][i] == PLAYER)
			{
				game_cp->game_objs_count.player++;
				ft_set_player_pos(game_cp, i, rw_i);
			}
			else if (game_cp->m_data.matrix[rw_i][i] == COLLECTIBLE)
				game_cp->game_objs_count.collectibles++;
			else if (game_cp->m_data.matrix[rw_i][i] == EXIT)
				game_cp->game_objs_count.exit++;
			else if (game_cp->m_data.matrix[rw_i][i] != WALL)
				return (0);
		}
	}
	return (1);
}

// CHECKS FOR DUPLICATE CHARACTERS
int	ft_valid_objs_2(t_game_ctl *game_cp)
{
	if (game_cp->game_objs_count.collectibles >= 1
		&& game_cp->game_objs_count.exit == 1
		&& game_cp->game_objs_count.player == 1)
		return (1);
	return (0);
}

// CHECKS IF THE MAP IS SURROUNDED BY WALLS
int	ft_surr_walls(t_game_ctl *game_cp)
{
	int		i;
	int		rows;
	int		columns;

	rows = game_cp->m_data.matrix_rows;
	columns = game_cp->m_data.matrix_columns;
	i = 0;
	while (i < columns)
	{
		if (game_cp->m_data.matrix[0][i] != WALL)
			return (0);
		if (game_cp->m_data.matrix[rows - 1][i] != WALL)
			return (0);
		i++;
	}
	i = 1;
	while (i < rows - 2)
	{
		if (game_cp->m_data.matrix[i][0] != WALL)
			return (0);
		if (game_cp->m_data.matrix[i][columns - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}
