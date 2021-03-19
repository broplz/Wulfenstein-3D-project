#include "./include/cub3d.h"
#include <stdio.h>

int		ft_init_all(t_all *all)
{
	all->check.we = 0;
	all->check.sp = 0;
	all->check.so = 0;
	all->check.ea = 0;
	all->check.no = 0;
	all->check.c = 0;
	all->check.f = 0;
	all->check.r = 0;
	all->params.colors.fb = -1;
	all->params.colors.fg = -1;
	all->params.colors.fr = -1;
	all->params.colors.cr = -1;
	all->params.colors.cg = -1;
	all->params.colors.cb = -1;
	all->params.res.x = 0;
	all->params.res.y = 0;
	all->params.path.no = NULL;
	all->params.path.ea = NULL;
	all->params.path.so = NULL;
	all->params.path.sp = NULL;
	all->params.path.we = NULL;
	all->co.pflag = 1;
//	all->co.mflag = 1;
	all->co.i = 0;
	all->co.j = 0;
	return (1);
}

int		ft_get_valid(t_all *all)
{
	return (all->check.sp + all->check.so + all->check.ea + all->check.no +
	all->check.we + all->check.f + all->check.c + all->check.r);
}

int		t_space(char **str)
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

char	*ft_get_null(int *flag, int *pflag)
{
	*pflag = 0;
	*flag = 0;
	return (NULL);
}

int		ft_path_check(char *line)
{
	int fd;

	fd = open(line, O_RDONLY);
	if (fd < 0)
		return (-1);
	close(fd);
	return (1);
}

char 	*w_pth(int *flag, char **line, int *pflag)
{
	int	len;

	if (*flag == 1)
		return (ft_get_null(flag, pflag));
	len = ft_strlen(*line);
	if (line[0][0] == 'S' && line[0][1] != ' ' && line[0][1] != 'O')
		return (ft_get_null(flag, pflag));
	else if (line[0][0] != 'S' && line[0][1] != ' ' && line[0][2] != ' ')
		return (ft_get_null(flag, pflag));
	if (line[0][len - 1] == ' ')
		len--;
	if (line[0][--len] != 'm' || line[0][--len] != 'p' ||
		line[0][--len] != 'x' || line[0][--len] != '.' ||
		ft_isalnum(line[0][--len]) != 1)
		return (ft_get_null(flag, pflag));
	if (line[0][0] == 'S' && line[0][1] == ' ')
		(*line) += 2;
	else
		(*line) += 3;
	if (ft_path_check(*line) < 0)
		return (ft_get_null(flag, pflag));
	return (*line + ((*flag = 1) - 1));
}

int		p_pth(t_all *all, char **line)
{
	int *flag;

	flag = &all->co.pflag;
	if (line[0][0] == 'W' && line[0][1] == 'E')
		all->params.path.we = w_pth(&(all->check.we), line, flag);
	else if (line[0][0] == 'N' && line[0][1] == 'O')
		all->params.path.no = w_pth(&(all->check.no), line, flag);
	else if (line[0][0] == 'E' && line[0][1] == 'A')
		all->params.path.ea = w_pth(&(all->check.ea), line, flag);
	else if (line[0][0] == 'S' && line[0][1] == 'O')
		all->params.path.so = w_pth(&(all->check.so), line, flag);
	else if (line[0][0] == 'S' && line[0][1] == ' ')
		all->params.path.sp = w_pth(&(all->check.sp), line, flag);
	else
		return (-1);
	return (1);
}

int		ft_color_check(int r, int g, int b)
{
	if (!(r > -1 && r < 256))
		return (-1);
	if (!(g > -1 && r < 256))
		return (-1);
	if (!(b > -1 && r < 256))
		return (-1);
	return (1);
}

int 	f_clr(t_all *all, char **line)
{
	int com;

	com = 0;
	if (all->check.f == 1)
		return (-1 + (all->co.pflag = 0));
	while (*(*line))
	{
		if (ft_isdigit(*(*line)) == 1 && com == 0)
			all->params.colors.fr = ft_atoi(line);
		if (*(*line) == ' ')
			(*line)++;
		else if (*(*line) == ',' && com < 3)
		{
			com++;
			(*line)++;
		}
		if (ft_isdigit(*(*line)) == 1 && com == 1)
			all->params.colors.fg = ft_atoi(line);
		else if (ft_isdigit(*(*line)) == 1 && com == 2)
			all->params.colors.fb = ft_atoi(line);
	}
	if ((ft_color_check(all->params.colors.fr,
					all->params.colors.fg, all->params.colors.fb)) < 0)
		return (-1 + (all->co.pflag = 0));
	return (all->check.f = 1);
}

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

int		p_cls(t_all *all, char **line)
{
	if (**line == 'F')
	{
		if (*(++(*line)) != ' ')
			return (-1);
		else
		{
			(*line)++;
			return (f_clr(all, line));
		}
	}
	else if (**line == 'C')
	{
		if (*(++(*line)) != ' ')
			return (-1);
		else
		{
			(*line)++;
			return (c_clr(all, line));
		}
	}
}

int		p_res(t_all *all, char **line)
{
	if (*(++(*line)) != ' ' || all->check.r == 1)
		return (-1 + (all->co.pflag = 0));
	if (ft_isdigit(*(++(*line))) == 1)
		all->params.res.x = ft_atoi(line);
	else
		return (-1 + (all->co.pflag = 0));
	if (ft_isdigit(*(++(*line))) == 1)
		all->params.res.y = ft_atoi(line);
	else
		return (-1 + (all->co.pflag = 0));
	while (*line && **line == ' ')
		(*line)++;
	if (**line)
		return (-1 + (all->co.pflag = 0));
	if (all->params.res.y < 1 || all->params.res.x < 1)
		return (-1 + (all->co.pflag = 0));
	return (all->check.r = 1);
}

int		ft_param_parser(t_all *all, char *line)
{
	t_space(&line);
	if (ft_strlen(line) == 1)
		return (-1);
	while (line && *line)
	{
		if (*line == ' ')
			line++;
		else if (*line == 'R')
			return (p_res(all, &line));
		else if (*line == 'F' || *line == 'C')
			return (p_cls(all, &line));
		else if (*line == 'N' || *line == 'W' || *line == 'E')
			return (p_pth(all, &line));
		else if (*line == 'S')
		{
			if (*(line + 1) == 'O' || *(line + 1) == ' ')
				return (p_pth(all, &line));
			else
				return (-1 + (all->co.pflag = 0));
		} else
			return (-1 + (all->co.pflag = 0));
	}
	return (1);
}

int		ft_free_mem(t_list *list)
{
	t_list	*temp;

	if (list == NULL)
		return (-1);
	while (list->next)
	{
		temp = list;
		list = list->next;
		free(temp->content);
		free(temp);
	}
	free(list->content);
	free(list);
	return (1);
}

int		main(int argc, char **argv)
{
	argc = 2;
	argv[1] = "/home/broplz/cube3D/maps/1.cub";
	t_all	all;
	int		fd;
	char	*line;
	t_list	*list;

	list = NULL;
	fd = open(argv[1], O_RDONLY);
	if (argc == 1)
	{
		write(1, ERROR_NO_MAP, sizeof(ERROR_NO_MAP));
		return (-1);
	}
	ft_init_all(&all);
	while (all.co.pflag && get_next_line(fd, &line) && ft_get_valid(&all) != 8)
	{
		ft_lstadd_back(&list, ft_lstnew(line));
		ft_param_parser(&all, line);
//		printf("%s\t\t = %d\n", line, ft_param_parser(&all, line));
	}
	int asd;
	ft_free_mem(list);
	return (0);
}