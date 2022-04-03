/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:14:09 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/03 14:36:37 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_puthex(unsigned int n, char x)
{	
	char	*hex;
	int		count;

	count = counter(n);
	hex = "abcdef";
	if (n < 10)
		ft_putchar(n + '0');
	else if (n < 16 && x == 'X')
		ft_putchar((char)(ft_toupper(hex[n - 10])));
	else if (n < 16 && x == 'x')
		ft_putchar(hex[n - 10]);
	else
	{
		ft_puthex(n / 16, x);
		ft_puthex(n % 16, x);
	}
	return (count);
}
