#include "../include/cub3d.h"

int		ft_par_parse(t_all *all, int fd, t_list **list)
{
	char	*line;

	line = NULL;
	while (all->co.pflag && ft_get_valid(all) != 8 && get_next_line(fd, &line)
		   && ft_param_parser(all, line))
		ft_lstadd_back(list, ft_lstnew(line));
	ft_lstadd_back(list, ft_lstnew(line));
	return (1);
}
