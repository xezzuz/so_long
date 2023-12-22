/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:19:58 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/19 16:36:00 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_exit_program(int x)
{
	if (x == -2)
		ft_printf("ERROR: MAP FILE IS MISSING :(\n");
	else if (x == -1)
		ft_printf("ERROR: MAP FILE EXTENSION IS NOT VALID :(\n");
	else if (x == 0)
		ft_printf("ERROR: MAP IS NOT VALID :(\n");
	else if (x == 1)
		ft_printf("ERROR: ALLOCATION FAILED :(\n");
	else if (x == 2)
		ft_printf("ERROR: MAP OPEN FAILED :(\n");
	else if (x == 3)
		printf("ERROR: MAP DOESN'T HAVE A VALID PATH\n");
	else if (x == 105)
		ft_printf("IS THIS GAME HARD? IQ < 0? XD\n");
	else if (x == 999)
		ft_printf("YOU WON! CONGRATULATIONS :)\n");
	exit(x);
	return (1);
}
