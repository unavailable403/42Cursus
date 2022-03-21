int	ft_atoi(const char *str)
{
	int	is_negative;
	int	res;

	res = 0;
	is_negative = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		is_negative *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + *str - '0';
		str++;
	}
	return (res * is_negative);
}
