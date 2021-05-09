#include "libft.h"

char	**ft_run_atol(char **str)
{
	while (**str && (**str == ' ' || **str == '\n' || **str == '\t' ||
		**str == '\v' || **str == '\f' || **str == '\r'))
		++(*str);
	return (str);
}

long			ft_atol(char **str)
{
	unsigned long	res;

	str = ft_run_atol(str);
	res = 0;
	while (**str && **str >= '0' && **str <= '9')
	{
		if (res < 21474836)
		{
			res = res * 10 + (**str - 48);
			if ((res) > MAX_LONG)
				return (-1);
			if ((res) < 0)
				return (-1);
		}
		++(*str);
	}
	return (res);
}
