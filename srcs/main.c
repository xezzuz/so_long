/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:01:39 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 13:41:31 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_die_panel_init(t_game_ctl *game_cp)
{
	int		i;

	i = 0;
	while (i < NUM_DIE_FRAMES)
		game_cp->g_objs.p_die_frames[i++] = NULL;
}

void	ft_panel_init(t_game_ctl *game_cp)
{
	game_cp->g_objs.collectible = NULL;
	game_cp->g_objs.exit_c = NULL;
	game_cp->g_objs.exit_o = NULL;
	game_cp->g_objs.floor = NULL;
	game_cp->g_objs.ghost = NULL;
	game_cp->g_objs.p = NULL;
	game_cp->g_objs.p_c = NULL;
	game_cp->g_objs.p_d = NULL;
	game_cp->g_objs.p_d_c = NULL;
	game_cp->g_objs.p_l = NULL;
	game_cp->g_objs.p_l_c = NULL;
	game_cp->g_objs.p_r = NULL;
	game_cp->g_objs.p_r_c = NULL;
	game_cp->g_objs.p_u = NULL;
	game_cp->g_objs.p_u_c = NULL;
	game_cp->g_objs.wall = NULL;
	game_cp->game_objs_count.collectibles = 0;
	game_cp->game_objs_count.enemies = 0;
	game_cp->game_objs_count.exit = 0;
	game_cp->game_objs_count.moves = 0;
	game_cp->game_objs_count.player = 0;
	game_cp->last_mv_time = 0;
	game_cp->m_data.matrix = NULL;
	game_cp->mlx_ptr = NULL;
	game_cp->win_ptr = NULL;
}

int	main(int argc, char **argv)
{
	int				fd;
	t_game_ctl		game_cp;

	ft_panel_init(&game_cp);
	ft_die_panel_init(&game_cp);
	if (argc != 2)
		ft_exit_program(&game_cp, 2);
	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit_program(&game_cp, 2);
	close(fd);
	ft_read_map(argv[1], &game_cp);
	ft_start_game(&game_cp);
}
