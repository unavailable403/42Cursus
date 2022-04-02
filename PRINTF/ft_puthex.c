/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:14:09 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/02 23:35:07 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void ft_puthex(int n)
{	
	char	*hex;

	hex= "abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n < 10)
		ft_putchar(n + '0');
	if (n < 16)
		ft_putchar(hex[n - 10]);
	else
	{
		ft_puthex(n / 10);
		ft_puthex(n % 10);
	}
}
