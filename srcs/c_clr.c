#include "../include/cub3d.h"

int 	c_clr(t_all *all, char **line)
{
	int com;

	com = 0;
	if (all->check.c == 1)
		return (-1 + (all->co.pflag = 0));
	while (*(*line))
	{
		if (ft_isdigit(*(*line)) == 1 && com == 0)
			all->params.colors.cr = ft_atoi(line);
		if (*(*line) == ' ')
			(*line)++;
		else if (*(*line) == ',' && com < 3)
		{
			com++;
			(*line)++;
		}
		if (ft_isdigit(*(*line)) == 1 && com == 1)
			all->params.colors.cg = ft_atoi(line);
		else if (ft_isdigit(*(*line)) == 1 && com == 2)
			all->params.colors.cb = ft_atoi(line);
	}
	if ((ft_color_check(all->params.colors.cr,
						all->params.colors.cg, all->params.colors.cb)) < 0)
		return (-1 + (all->co.pflag = 0));
	return (all->check.c = 1);
}