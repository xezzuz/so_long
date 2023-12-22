/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:53:38 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/22 21:32:59 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

void	a(void)
{
	system ("leaks a.out");
}

int	main(void)
{
	void	*mlx_ptr;

	atexit(a);
	mlx_ptr = mlx_init();
	exit (0);
}
