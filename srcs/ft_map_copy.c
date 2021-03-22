#include "../include/cub3d.h"

int		ft_map_copy(void *head, char *all, int len)
{
	int		i;
	char	*content;

	i = 0;
	content = (char *)head;
	while (i < len)
	{
		if (content && i > 0 && *content)
		{
			all[i++] = *content++;
			continue;
		}
		all[i] = ' ';
		i++;
	}
	return (1);
}
