/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 16:53:04 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/22 17:01:15 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_image_check(t_game_ctl *game_cp, void **img, char *path)
{
	int		d1;
	int		d2;

	*img = mlx_xpm_file_to_image(game_cp->mlx_ptr, path, &d1, &d2);
	if (*img == NULL)
		ft_exit_program(game_cp, 1);
}

void	ft_image_init(t_game_ctl *game_cp)
{
	ft_image_check(game_cp, &game_cp->g_objs.collectible,
		"./txts/COLL.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.floor,
		"./txts/FLOOR.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.wall,
		"./txts/WALL.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.ghost,
		"./txts/GH.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.exit_c,
		"./txts/EX_C.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.exit_o,
		"./txts/EX_O.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p,
		"./txts/P.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_r,
		"./txts/P.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_u,
		"./txts/P_U.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_d,
		"./txts/P_D.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_l,
		"./txts/P_L.xpm");
}

void	ft_anim_image_init(t_game_ctl *game_cp)
{
	ft_image_check(game_cp, &game_cp->g_objs.p_c,
		"./txts/P_C.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_r_c,
		"./txts/P_C.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_u_c,
		"./txts/P_U_C.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_d_c,
		"./txts/P_D_C.xpm");
	ft_image_check(game_cp, &game_cp->g_objs.p_l_c,
		"./txts/P_L_C.xpm");
}
