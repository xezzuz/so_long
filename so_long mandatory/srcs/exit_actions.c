/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:19:58 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/24 14:15:01 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_exit_program(t_game_ctl *game_cp, int x)
{
	if (game_cp->m_data.matrix)
		ft_free_map(&game_cp->m_data.matrix);
	ft_free_imgs(game_cp);
	if (x == -3)
		ft_printf("ERROR: MAP IS NOT VALID :(\n");
	else if (x == -1)
		ft_printf("ERROR: MAP FILE EXTENSION IS NOT VALID :(\n");
	else if (x == 1)
		ft_printf("ERROR: ALLOCATION FAILED :(\n");
	else if (x == 2)
		ft_printf("ERROR: MAP OPEN FAILED :(\n");
	else if (x == 3)
		ft_printf("ERROR: MAP DOESN'T HAVE A VALID PATH\n");
	else if (x == 105)
		ft_printf("IS THIS GAME HARD? IQ < 0? XD\n");
	else if (x == 0)
		ft_printf("YOU WON! CONGRATULATIONS :)\n");
	if (game_cp->mlx_ptr != NULL)
		mlx_destroy_window(game_cp->mlx_ptr, game_cp->win_ptr);
	exit(0);
	return (1);
}
