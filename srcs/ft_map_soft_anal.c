#include "../include/cub3d.h"

int 	ft_map_soft_anal(char *line, char *head)
{
	static int		anal;
	char			*right;

	anal = 0;
	while (*line)
	{
		right = head;
		while (*right && *right != *line)
		{
			if (anal > 1)
				return (0);
			if (*line == 'N' || *line == 'W' || *line == 'E' || *line == 'S')
			{
				anal += 1;
				break;
			}
			right++;
		}
		if (*right == '\0')
			return (0);
		line++;
	}
	return (1);
}