/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 17:03:25 by ergrigor          #+#    #+#             */
/*   Updated: 2022/03/18 21:59:44 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int tmp)
{
	int	is_alnum;

	is_alnum = 0;
	if ((tmp >= 97 && tmp <= 122) || (tmp >= 65 && tmp <= 90))
	{
		is_alnum = 1;
	}
	else
	{
		if (tmp >= 48 && tmp <= 57)
		{
			is_alnum = 1;
		}
	}
	return (is_alnum);
}
