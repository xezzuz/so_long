/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nazouz <nazouz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:44:19 by nazouz            #+#    #+#             */
/*   Updated: 2023/12/17 14:01:36 by nazouz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	ft_putnbr(int n)
{
	int		count;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += ft_putchar('-');
		if (count == -1)
			return (-1);
		n = -n;
	}
	if (n < 10)
	{
		count += ft_putchar(n + 48);
		return (count);
	}
	count += ft_putnbr(n / 10);
	if (count < 0)
		return (-1);
	count += ft_putnbr(n % 10);
	return (count);
}
