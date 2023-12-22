/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:15:41 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/17 20:17:12 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// CALCULATE MATRIX DIMENSIONS + CHECKS IF THE MAP IS RECTANGULAR
int	ft_map_dimensions(t_game_ctl *game_cp)
{
	int		rows;
	int		columns;

	columns = ft_columns(game_cp);
	if (!columns)
		return (0);
	game_cp->m_data.matrix_columns = columns;
	rows = ft_rows(game_cp);
	if (!rows)
		return (0);
	game_cp->m_data.matrix_rows = rows;
	game_cp->game_res.map_height = rows * 32;
	game_cp->game_res.map_width = columns * 32;
	return (1);
}

// CALCULATES MATRIX COLUMNS
int	ft_columns(t_game_ctl *game_cp)
{
	int		columns_index;

	columns_index = 0;
	while (game_cp->m_data.matrix[0]
		&& game_cp->m_data.matrix[0][columns_index] != '\n')
		columns_index++;
	return (columns_index);
}

// CALCULATE MATRIX ROWS + CHECKS IF THE MAP IS RECTANGULAR
int	ft_rows(t_game_ctl *game_cp)
{
	int		i;
	int		row_index;
	int		row_len;

	row_index = 0;
	while (game_cp->m_data.matrix[row_index] != NULL)
	{
		i = 0;
		while (game_cp->m_data.matrix[row_index][i]
			&& game_cp->m_data.matrix[row_index][i] != '\n')
			i++;
		row_len = i;
		if (row_len != game_cp->m_data.matrix_columns)
			return (game_cp->m_data.matrix_rows = 0, 0);
		game_cp->m_data.matrix_rows++;
		row_index++;
	}
	return (row_index);
}
