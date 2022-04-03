/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 23:14:09 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/03 12:38:02 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_puthex(int n, char x)
{	
	char	*hex;

	hex = "abcdef";
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n < 10)
		ft_putchar(n + '0');
	if (n < 16 && x == 'X')
		ft_putchar((char)(ft_toupper(hex[n - 10])));
	else if (n < 16 && x == 'x')
		ft_putchar(hex[n - 10]);
	else
	{
		ft_puthex(n / 16, x);
		ft_puthex(n % 16, x);
	}
}
