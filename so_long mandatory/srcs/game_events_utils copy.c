/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_events_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:54:55 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/23 12:37:28 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_matrix(char **matrix)
{
	int		i;

	i = 0;
	while (matrix[i])
	{
		printf("%s\n", matrix[i]);
		i++;
	}
	printf("*******************\n");
}

int	ft_refresh_matrix_2(t_game_ctl *game_cp, int x_new, int y_new)
{
	// if (game_cp->m_data.matrix[y_new][x_new] != EXIT)
	// 	game_cp->m_data.matrix[y_new][x_new] = PLAYER;
	mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
		game_cp->g_objs.p, x_new * SQ, y_new * SQ);
	if (game_cp->m_data.matrix[game_cp->game_pos.p_pos.y]
		[game_cp->game_pos.p_pos.x] == EXIT)
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.exit_c, game_cp->game_pos.p_pos.x * SQ,
			game_cp->game_pos.p_pos.y * SQ);
	else
	{
		game_cp->m_data.matrix[game_cp->game_pos.p_pos.y]
		[game_cp->game_pos.p_pos.x] = FLOOR;
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.floor, game_cp->game_pos.p_pos.x * SQ,
			game_cp->game_pos.p_pos.y * SQ);
	}
	game_cp->game_pos.p_pos.x = x_new;
	game_cp->game_pos.p_pos.y = y_new;
	print_matrix(game_cp->m_data.matrix);
	return (1);
}

int	ft_refresh_matrix(t_game_ctl *game_cp, int x_new, int y_new)
{
	if (game_cp->m_data.matrix[y_new][x_new] == WALL)
		return (0);
	ft_printf("Moves: %d\n", ++game_cp->game_objs_count.moves);
	if (game_cp->m_data.matrix[y_new][x_new] == EXIT
		&& game_cp->game_objs_count.collectibles == 0)
		return (mlx_destroy_window(game_cp->mlx_ptr,
				game_cp->win_ptr), ft_exit_program(999));
	if (game_cp->m_data.matrix[y_new][x_new] == COLLECTIBLE)
	{
		game_cp->game_objs_count.collectibles--;
		if (game_cp->game_objs_count.collectibles == 0)
			mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
				game_cp->g_objs.exit_o, game_cp->game_pos.e_pos.x * SQ,
				game_cp->game_pos.e_pos.y * SQ);
	}
	return (ft_refresh_matrix_2(game_cp, x_new, y_new));
}
