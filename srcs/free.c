/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 14:15:08 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 14:15:56 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_map(char ***matrix)
{
	int		i;

	if (*matrix == NULL)
		return ;
	i = 0;
	while ((*matrix)[i])
	{
		free ((*matrix)[i]);
		i++;
	}
	free (*matrix);
}

void	ft_free_imgs(t_game_ctl *game_cp)
{
	if (game_cp->g_objs.p_r)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.p_r);
	if (game_cp->g_objs.p_u)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.p_u);
	if (game_cp->g_objs.p_d)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.p_d);
	if (game_cp->g_objs.p_l)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.p_l);
	if (game_cp->g_objs.floor)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.floor);
	if (game_cp->g_objs.exit_c)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.exit_c);
	if (game_cp->g_objs.exit_o)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.exit_o);
	if (game_cp->g_objs.collectible)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.collectible);
	if (game_cp->g_objs.wall)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.wall);
}
