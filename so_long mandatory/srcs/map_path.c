/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:23:13 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/22 22:44:47 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_exit_pos(t_game_ctl *game_cp)
{
	int		i;
	int		j;

	i = 0;
	while (game_cp->m_data.matrix[i])
	{
		j = 0;
		while (game_cp->m_data.matrix[i][j])
		{
			if (game_cp->m_data.matrix[i][j] == PLAYER)
			{
				game_cp->game_pos.p_pos.x = j;
				game_cp->game_pos.p_pos.y = i;
			}
			else if (game_cp->m_data.matrix[i][j] == EXIT)
			{
				game_cp->game_pos.e_pos.x = j;
				game_cp->game_pos.e_pos.y = i;
			}
			j++;
		}
		i++;
	}
}

int	ft_check_e_c(char **matrix_cpy, t_game_ctl *game_cp)
{
	int		i;

	i = 0;
	while (i < game_cp->m_data.matrix_rows)
	{
		if (ft_strchr(matrix_cpy[i], EXIT))
			return (0);
		if (ft_strchr(matrix_cpy[i], COLLECTIBLE))
			return (0);
		i++;
	}
	return (1);
}

void	ft_flood_fill_e_c(char ***map, t_game_ctl *game_cp, int i, int j)
{
	if ((*map)[i][j] != '1' && (*map)[i][j] != 'F')
	{
		(*map)[i][j] = 'F';
		ft_flood_fill_e_c(map, game_cp, i + 1, j);
		ft_flood_fill_e_c(map, game_cp, i, j + 1);
		ft_flood_fill_e_c(map, game_cp, i - 1, j);
		ft_flood_fill_e_c(map, game_cp, i, j - 1);
	}
	return ;
}

char	**ft_duplicate_matrix(t_game_ctl *game_cp, char **matrix_cpy)
{
	int		i;
	int		j;

	i = 0;
	matrix_cpy = malloc((game_cp->m_data.matrix_rows + 1) * sizeof(char *));
	if (!matrix_cpy)
		ft_exit_program(1);
	while (i < game_cp->m_data.matrix_rows)
	{
		matrix_cpy[i] = malloc(game_cp->m_data.matrix_columns);
		j = 0;
		while (j < game_cp->m_data.matrix_columns)
		{
			matrix_cpy[i][j] = game_cp->m_data.matrix[i][j];
			j++;
		}
		matrix_cpy[i][j] = '\0';
		i++;
	}
	matrix_cpy[i] = NULL;
	return (matrix_cpy);
}

int	ft_valid_path(t_game_ctl *game_cp)
{
	char	**matrix_cpy;
	int		p_pos_x;
	int		p_pos_y;

	matrix_cpy = NULL;
	get_player_exit_pos(game_cp);
	p_pos_x = game_cp->game_pos.p_pos.x;
	p_pos_y = game_cp->game_pos.p_pos.y;
	matrix_cpy = ft_duplicate_matrix(game_cp, matrix_cpy);
	ft_flood_fill_e_c(&matrix_cpy, game_cp, p_pos_y, p_pos_x);
	if (!ft_check_e_c(matrix_cpy, game_cp))
		return (ft_exit_program(3), 0); // ft_free_map
	return (1); // ft_free_map
}
