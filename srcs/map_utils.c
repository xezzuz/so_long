/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 16:15:41 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 14:00:59 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_map_dimensions(t_game_ctl *game_cp)
{
	if (!ft_columns(game_cp))
		return (0);
	if (!ft_rows(game_cp))
		return (0);
	if (game_cp->m_data.lines != game_cp->m_data.matrix_rows)
		return (0);
	return (1);
}

int	ft_columns(t_game_ctl *game_cp)
{
	int		columns_index;

	columns_index = 0;
	while (game_cp->m_data.matrix[0]
		&& game_cp->m_data.matrix[0][columns_index] != '\0')
		columns_index++;
	game_cp->m_data.matrix_columns = columns_index;
	game_cp->game_res.map_width = columns_index * 32;
	return (columns_index);
}

int	ft_rows(t_game_ctl *game_cp)
{
	int		i;
	int		row_len;

	i = 0;
	row_len = 0;
	while (game_cp->m_data.matrix[i])
	{
		row_len = ft_strlen(game_cp->m_data.matrix[i]);
		if (row_len != game_cp->m_data.matrix_columns)
			return (game_cp->m_data.matrix_rows = 0, 0);
		i++;
	}
	game_cp->m_data.matrix_rows = i;
	game_cp->game_res.map_height = i * 32;
	return (i);
}

void	ft_null_term_matrix(char **matrix)
{
	int		i;
	int		j;

	i = 0;
	while (matrix[i])
	{
		j = 0;
		while (matrix[i][j])
		{
			if (matrix[i][j] == '\n')
				matrix[i][j] = '\0';
			j++;
		}
		i++;
	}
}
