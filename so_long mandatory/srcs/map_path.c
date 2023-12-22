/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 15:23:13 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/21 19:23:10 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_e_c(char **matrix_cpy, t_game_ctl *game_cp)
{
	int		i;
	int		j;

	i = 0;
	while (i < game_cp->m_data.matrix_rows)
	{
		j = 0;
		while (j < game_cp->m_data.matrix_columns)
		{
			if (matrix_cpy[i][j] == 'E' || matrix_cpy[i][j] == 'C')
				return (0);
			j++;
		}
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

void	print_matrix(char **matrix)
{
	int i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
}

char	**ft_duplicate_matrix(t_game_ctl *game_cp, char **matrix_cpy)
{
	int		i;
	int		j;

	i = 0;
	while (i < game_cp->m_data.matrix_rows)
	{
		matrix_cpy[i] = malloc(game_cp->m_data.matrix_columns);
		j = 0;
		while (j < game_cp->m_data.matrix_columns)
		{
			matrix_cpy[i][j] = game_cp->m_data.matrix[i][j];
			printf("%c ", matrix_cpy[i][j]);
			j++;
		}
		// matrix_cpy[i][j] = '\0';
		printf("\n");
		i++;
	}
	matrix_cpy[i] = NULL;
	print_matrix(matrix_cpy);
	return (matrix_cpy);
}

int	ft_valid_path(t_game_ctl *game_cp)
{
	char	**matrix_cpy;
	int		p_pos_x;
	int		p_pos_y;

	p_pos_x = game_cp->game_pos.p_pos.x;
	p_pos_y = game_cp->game_pos.p_pos.y;
	matrix_cpy = malloc((game_cp->m_data.matrix_rows + 1) * sizeof(char *));
	if (!matrix_cpy)
		return (ft_exit_program(1), 0);
	matrix_cpy = ft_duplicate_matrix(game_cp, matrix_cpy);
	ft_flood_fill_e_c(&matrix_cpy, game_cp, p_pos_y, p_pos_x);
	if (!ft_check_e_c(matrix_cpy, game_cp))
		return (ft_exit_program(3), 0);
		
	return (1);
}
