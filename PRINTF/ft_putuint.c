/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 13:56:08 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/03 14:37:14 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putuint(unsigned int n)
{
	int	count;

	count = counter(n);
	if (n < 10)
		ft_putchar(n + '0');
	else
	{
		ft_putuint(n / 10);
		ft_putuint(n % 10);
	}
	return (count);
}
