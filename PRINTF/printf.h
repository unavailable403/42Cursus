/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:13:41 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/03 12:13:43 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(const char *str);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);
void	ft_puthex(int n, char x);
int		ft_toupper(int c);

#endif