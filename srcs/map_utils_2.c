/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:19:09 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 00:02:55 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// CHECKS IF THE MAP IS VALID BY CHECKING MAP WALLS AND CHARACTERS
int	ft_map_objs(t_game_ctl *game_cp)
{
	if (ft_count_objs(game_cp) && ft_strange_objs(game_cp)
		&& ft_surr_walls(game_cp))
		return (1);
	return (0);
}

int	ft_count_objs(t_game_ctl *game_cp)
{
	int		i;

	i = 0;
	while (game_cp->m_data.matrix[i])
	{
		game_cp->game_objs_count.collectibles
			+= ft_count_chars(game_cp->m_data.matrix[i], COLLECTIBLE);
		game_cp->game_objs_count.exit
			+= ft_count_chars(game_cp->m_data.matrix[i], EXIT);
		game_cp->game_objs_count.player
			+= ft_count_chars(game_cp->m_data.matrix[i], PLAYER);
		game_cp->game_objs_count.enemies
			+= ft_count_chars(game_cp->m_data.matrix[i], GHOST);
		i++;
	}
	if (game_cp->game_objs_count.collectibles >= 1
		&& game_cp->game_objs_count.exit == 1
		&& game_cp->game_objs_count.player == 1
		&& game_cp->game_objs_count.enemies <= 6)
		return (1);
	return (0);
}

int	ft_count_chars(char *str, char c)
{
	int		count;

	count = 0;
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}

int	ft_strange_objs(t_game_ctl *game_cp)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (game_cp->m_data.matrix[i])
	{
		j = 0;
		while (game_cp->m_data.matrix[i][j])
		{
			c = game_cp->m_data.matrix[i][j];
			if (c != PLAYER && c != FLOOR && c != WALL
				&& c != EXIT && c != COLLECTIBLE && c != GHOST)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
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
	while (i < rows - 1)
	{
		if (game_cp->m_data.matrix[i][0] != WALL)
			return (0);
		if (game_cp->m_data.matrix[i][columns - 1] != WALL)
			return (0);
		i++;
	}
	return (1);
}
