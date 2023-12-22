/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:01:39 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/17 20:12:10 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_panel_init(t_game_ctl *game_cp)
{
	t_game_objs		*game_objects;

	*game_cp = (t_game_ctl){0};
	game_cp->mlx_ptr = NULL;
	game_cp->win_ptr = NULL;
	game_cp->game_res.win_name = NULL;
	game_cp->game_res.map_name = NULL;
	game_cp->m_data.matrix = NULL;
	game_objects = malloc(sizeof(t_game_objs));
	if (!game_objects)
	{
		ft_exit_program(1);
		return ;
	}
	game_cp->g_objs = *game_objects;
}

int	main(int argc, char **argv)
{
	int				fd;
	t_game_ctl		game_cp;

	if (argc != 2)
		return (ft_exit_program(-2));
	fd = open (argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_exit_program(2), 0);
	game_cp.game_res.map_name = argv[1];
	ft_panel_init(&game_cp);
	if (!ft_read_map(argv[1], &game_cp))
		return (close(fd), ft_exit_program(0), 0);
	ft_start_game(&game_cp);
	return (1);
}
