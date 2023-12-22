/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:32:37 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/17 14:01:42 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_putstr(char *str)
{
	int		i;
	int		return_value;

	i = 0;
	return_value = 0;
	if (!str)
	{
		i += ft_putstr("(null)");
		return (i);
	}
	while (str[i] != '\0')
	{
		return_value = ft_putchar(str[i]);
		if (return_value == -1)
			return (-1);
		i++;
	}
	return (i);
}
