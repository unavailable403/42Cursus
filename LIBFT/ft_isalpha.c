int	ft_isalpha(int x)
{
	if ((x >= 'A' && x <= 'Z') || (x >= 'a' && x <= 'z'))
		return (1);
	return (0);
}
