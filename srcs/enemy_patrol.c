/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_patrol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/23 22:35:35 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 13:24:26 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_enemy_dir_init(t_game_ctl *game_cp)
{
	int		i;

	i = 0;
	while (i < game_cp->game_objs_count.enemies)
		game_cp->enemies[i++].dir_x = 1;
}

void	ft_update_put(t_game_ctl *game_cp, int x_pos, int y_pos, int n_x_pos)
{
	if (game_cp->m_data.matrix[y_pos][n_x_pos] == FLOOR)
	{
		game_cp->m_data.matrix[y_pos][x_pos] = FLOOR;
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.floor, x_pos * SQ, y_pos * SQ);
	}
	if (game_cp->m_data.matrix[y_pos][n_x_pos] == COLLECTIBLE)
	{
		game_cp->m_data.matrix[y_pos][x_pos] = COLLECTIBLE;
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.collectible, x_pos * SQ, y_pos * SQ);
	}
}

void	ft_move_enemy(t_game_ctl *game_cp, t_enemy *enemy)
{
	int		x_pos;
	int		y_pos;
	int		n_x_pos;

	x_pos = enemy->x;
	y_pos = enemy->y;
	n_x_pos = x_pos + enemy->dir_x;
	if (game_cp->m_data.matrix[y_pos][n_x_pos] == FLOOR
		|| game_cp->m_data.matrix[y_pos][n_x_pos] == COLLECTIBLE)
	{
		ft_update_put(game_cp, x_pos, y_pos, n_x_pos);
		game_cp->m_data.matrix[y_pos][n_x_pos] = GHOST;
		mlx_put_image_to_window(game_cp->mlx_ptr, game_cp->win_ptr,
			game_cp->g_objs.ghost, n_x_pos * SQ, y_pos * SQ);
	}
	else if (game_cp->m_data.matrix[y_pos][n_x_pos] == PLAYER)
		ft_ghosts(game_cp);
	else
		enemy->dir_x *= -1;
}

void	ft_locate_enemy(t_game_ctl *game_cp)
{
	int		i;
	int		j;
	int		en_index;

	en_index = 0;
	i = 0;
	while (game_cp->m_data.matrix[i])
	{
		j = 0;
		while (game_cp->m_data.matrix[i][j])
		{
			if (game_cp->m_data.matrix[i][j] == GHOST)
			{
				game_cp->enemies[en_index].x = j;
				game_cp->enemies[en_index].y = i;
				en_index++;
			}
			j++;
		}
		i++;
	}
}

int	ft_enemy_patrol(t_game_ctl *game_cp)
{
	int					i;
	unsigned long		current_time;

	current_time = clock();
	i = 0;
	if (current_time - game_cp->last_mv_time >= 70000)
	{
		ft_locate_enemy(game_cp);
		while (i < game_cp->game_objs_count.enemies)
		{
			ft_move_enemy(game_cp, &game_cp->enemies[i]);
			i++;
		}
		game_cp->last_mv_time = current_time;
	}
	return (0);
}
