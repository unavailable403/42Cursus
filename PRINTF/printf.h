#ifndef PRINTF_H
#define PRINTF_H

# include <unistd.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(const char *str);
size_t	ft_strlen(const char *str);
void	ft_putnbr(int n);
void	ft_puthex(int n);

#endif