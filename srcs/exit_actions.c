/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:19:58 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/23 17:15:32 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_you_won(void)
{
	ft_printf("%s\n\n██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗\n",
		"\033[0;32m");
	ft_printf("╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║\n");
	ft_printf("░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║\n");
	ft_printf("░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║\n");
	ft_printf("░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║\n");
	ft_printf("░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n\n\n");
}

void	ft_game_over(void)
{
	ft_printf("%s\n\n░██████╗░░█████╗░███╗░░░███╗███████╗", "\033[0;31m");
	ft_printf("  ░█████╗░██╗░░░██╗███████╗██████╗░\n");
	ft_printf("██╔════╝░██╔══██╗████╗░████║██╔════╝");
	ft_printf("  ██╔══██╗██║░░░██║██╔════╝██╔══██╗\n");
	ft_printf("██║░░██╗░███████║██╔████╔██║█████╗░░");
	ft_printf("  ██║░░██║╚██╗░██╔╝█████╗░░██████╔╝\n");
	ft_printf("██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░");
	ft_printf("  ██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗\n");
	ft_printf("╚██████╔╝██║░░██║██║░╚═╝░██║███████╗");
	ft_printf("  ╚█████╔╝░░╚██╔╝░░███████╗██║░░██║\n");
	ft_printf("░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝");
	ft_printf("  ░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n\n\n");
}

int	ft_exit_program(t_game_ctl *game_cp, int x)
{
	// mlx_ptr - win_ptr
	if (game_cp->m_data.matrix)
		ft_free_map(&game_cp->m_data.matrix);
	ft_free_imgs(game_cp);
	if (x == -3)
		ft_printf("ERROR: MAP IS NOT VALID :(\n");
	else if (x == -2)
		ft_printf("ERROR: MAP FILE IS MISSING :(\n");
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
		ft_you_won();
	else if (x == -42)
		ft_game_over();
	exit(x);
	return (1);
}
