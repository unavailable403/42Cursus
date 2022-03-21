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
