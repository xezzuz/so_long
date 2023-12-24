/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 13:45:36 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 11:32:00 by nazouz           ###   ########.fr       */
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

void	ft_free_dying_frames(t_game_ctl *game_cp)
{
	int		i;

	i = 0;
	while (i < NUM_DIE_FRAMES)
	{
		if (game_cp->g_objs.p_die_frames[i])
			mlx_destroy_image(game_cp->mlx_ptr,
				game_cp->g_objs.p_die_frames[i]);
		i++;
	}
}

void	ft_free_imgs_2(t_game_ctl *game_cp)
{
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
	if (game_cp->g_objs.ghost)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.ghost);
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
	if (game_cp->g_objs.p_c)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.p_c);
	if (game_cp->g_objs.p_l_c)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.p_l_c);
	if (game_cp->g_objs.p_d_c)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.p_d_c);
	if (game_cp->g_objs.p_u_c)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.p_u_c);
	if (game_cp->g_objs.p_r_c)
		mlx_destroy_image(game_cp->mlx_ptr, game_cp->g_objs.p_r_c);
	ft_free_imgs_2(game_cp);
	ft_free_dying_frames(game_cp);
}
