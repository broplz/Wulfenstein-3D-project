#include "../include/cub3d.h"

int		ft_t_space(char **str)
{
	int    i;
	int    k;

	i = 0;
	k = 0;

	if (*str == NULL)
		return (-1);
	while ((*str)[i])
	{
		(*str)[k] = (*str)[i];
		if ((*str)[i] == ' ')
		{
			while ((*str)[i + 1] == ' ')
				i++;
		}
		k++;
		i++;
	}
	(*str)[k] = '\0';
	return (1);
}