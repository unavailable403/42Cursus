/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ergrigor <ergrigor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 12:13:41 by ergrigor          #+#    #+#             */
/*   Updated: 2022/04/03 15:57:23 by ergrigor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <unistd.h>
# include <stdio.h>

int		ft_putchar(char c);
int		ft_putstr(const char *str);
size_t	ft_strlen(const char *str);
int		ft_putnbr(int n);
int		ft_puthex(unsigned int n, char x);
int		ft_toupper(int c);
int		counter(int n);
int		ft_putuint(unsigned int n);
int		ft_putptr(void *x);

#endif