/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:19:58 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/22 21:27:15 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_you_won(void)
{
	printf("%s\n\n██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗\n",
		"\033[0;32m");
	printf("╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║\n");
	printf("░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║\n");
	printf("░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║\n");
	printf("░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║\n");
	printf("░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n\n\n");
}

void	ft_game_over(void)
{
	printf("%s\n\n░██████╗░░█████╗░███╗░░░███╗███████╗", "\033[0;31m");
	printf("  ░█████╗░██╗░░░██╗███████╗██████╗░\n");
	printf("██╔════╝░██╔══██╗████╗░████║██╔════╝");
	printf("  ██╔══██╗██║░░░██║██╔════╝██╔══██╗\n");
	printf("██║░░██╗░███████║██╔████╔██║█████╗░░");
	printf("  ██║░░██║╚██╗░██╔╝█████╗░░██████╔╝\n");
	printf("██║░░╚██╗██╔══██║██║╚██╔╝██║██╔══╝░░");
	printf("  ██║░░██║░╚████╔╝░██╔══╝░░██╔══██╗\n");
	printf("╚██████╔╝██║░░██║██║░╚═╝░██║███████╗");
	printf("  ╚█████╔╝░░╚██╔╝░░███████╗██║░░██║\n");
	printf("░╚═════╝░╚═╝░░╚═╝╚═╝░░░░░╚═╝╚══════╝");
	printf("  ░╚════╝░░░░╚═╝░░░╚══════╝╚═╝░░╚═╝\n\n\n");
}
	// if (game_cp != NULL)
	// 	ft_free_imgs(game_cp);

int	ft_exit_program(t_game_ctl *game_cp, int x)
{
	if (game_cp != NULL)
		ft_free_map(&game_cp->m_data.matrix);
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
		printf("ERROR: MAP DOESN'T HAVE A VALID PATH\n");
	else if (x == 105)
		ft_printf("IS THIS GAME HARD? IQ < 0? XD\n");
	else if (x == 0)
		ft_you_won();
	else if (x == -42)
		ft_game_over();
	exit(x);
	return (1);
}