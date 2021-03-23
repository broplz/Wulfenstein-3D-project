#include "../include/cub3d.h"

int		ft_map_hard_anal(t_all *all, char **array, int i, int j)
{
	if (i != 0 && j != 0 && !(array[i - 1][j - 1] == ' '
	|| array[i - 1][j - 1] == '1' || array[i - 1][j - 1] == '\0'))
		return (-1);
	if (i != 0 && !(array[i - 1][j] == ' '
	|| array[i - 1][j] == '1' || array[i - 1][j] == '\0'))
		return (-1);
	if (i != 0 && !(array[i - 1][j + 1] == ' '
	|| array[i - 1][j + 1] == '1' || array[i - 1][j + 1] == '\0'))
		return (-1);
	if (j != 0 && !(array[i][j - 1] == ' '
	|| array[i][j - 1] == '1' || array[i][j - 1] == '\0'))
		return (-1);
	if (!(array[i][j + 1] == ' ' || array[i][j + 1] == '1'
	|| array[i][j + 1] == '\0'))
		return (-1);
	if (i != all->map.lst_size - 1 && j != 0
	&& !(array[i + 1][j - 1] == ' ' || array[i + 1][j - 1] == '1'
	|| array[i + 1][j - 1] == '\0'))
		return (-1);
	if (i != all->map.lst_size - 1 && !(array[i + 1][j] == ' '
	|| array[i + 1][j] == '1' || array[i + 1][j] == '\0'))
		return (-1);
	if (i != all->map.lst_size - 1 && !(array[i + 1][j + 1] == ' '
	|| array[i + 1][j + 1] == '1' || array[i + 1][j + 1] == '\0'))
		return (-1);
	return (1);
}
