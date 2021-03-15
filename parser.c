#include "./include/cub3d.h"
#include <stdio.h>

int  t_space(char **str)
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

char 	*w_pth(char **line)
{
	int	len;

	len = ft_strlen(*line);
	if (line[0][0] == 'S' && line[0][1] != ' ' && line[0][1] != 'O')
		return (NULL);
	else if (line[0][0] != 'S' && line[0][1] != ' ' && line[0][2] != ' ')
		return (NULL);
	if (line[0][len - 1] == ' ')
		len--;
	if (line[0][--len] != 'm' || line[0][--len] != 'p' ||
		line[0][--len] != 'x' || line[0][--len] != '.' ||
		ft_isalnum(line[0][--len]) != 1)
		return (NULL);
	if (line[0][0] == 'S' && line[0][1] == ' ')
		(*line) += 2;
	else
		(*line) += 3;
	return (*line);
}

int		p_pth(t_all *all, char **line)
{
	if (line[0][0] == 'W' && line[0][1] == 'E')
		all->params.path.we = w_pth(line);
	else if (line[0][0] == 'N' && line[0][1] == 'O')
		all->params.path.no = w_pth(line);
	else if (line[0][0] == 'E' && line[0][1] == 'A')
		all->params.path.ea = w_pth(line);
	else if (line[0][0] == 'S' && line[0][1] == 'O')
		all->params.path.so = w_pth(line);
	else if (line[0][0] == 'S' && line[0][1] == ' ')
		all->params.path.sp = w_pth(line);
	else
		return (-1);
	return (1);
}

int 	f_clr(t_all *all, char **line)
{
	int com;

	com = 0;
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
	return (1);
}

int 	c_clr(t_all *all, char **line)
{
	int com;

	com = 0;
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
	return (1);
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
			f_clr(all, line);
		}
	}
	else if (**line == 'C')
	{
		if (*(++(*line)) != ' ')
			return (-1);
		else
		{
			(*line)++;
			c_clr(all, line);
		}
	}
	return (1);
}

int		p_res(t_all *all, char **line)
{
	if (*(++(*line)) != ' ')
		return (-1);
	if (ft_isdigit(*(++(*line))) == 1)
		all->params.res.x = ft_atoi(line);
	else
		return (-1);
	if (ft_isdigit(*(++(*line))) == 1)
		all->params.res.y = ft_atoi(line);
	else
		return (-1);
	while (*line && **line == ' ')
		(*line)++;
	if (**line)
		return (-1);
	if (all->params.res.y < 1 || all->params.res.x < 1)
		return (-1);
	return (1);
}

int		ft_param_parser(t_all *all, char *line)
{
	t_space(&line);
	if (ft_strlen(line) == 1)
		return (-1);
	while (line && *line) {
		if (*line == ' ')
			line++;
		else if (*line == 'R')
			return (p_res(all, &line));
		else if (*line == 'F' || *line == 'C')
			return (p_cls(all, &line));
		else if (*line == 'N' || *line == 'W' || *line == 'E')
			return (p_pth(all, &line));
		else if (*line == 'S') {
			if (*(line + 1) == 'O' || *(line + 1) == ' ')
				return (p_pth(all, &line));
			else
				return (-1);
		} else
			return (-1);
	}
//	printf("'%s' =======> WE\n", all->params.path.we);
//	printf("'%s' =======> SO\n", all->params.path.so);
//	printf("'%s' =======> EA\n", all->params.path.ea);
//	printf("'%s' =======> NO\n", all->params.path.no);
//	printf("'%s' =======> Sprite\n", all->params.path.sp);
	return (0);
}

int		main(int argc, char **argv)
{
	argc = 2;
	argv[1] = "/home/broplz/cube3D/maps/1.cub";
	t_all	all;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	if (argc == 1) {
		write(1, ERROR_NO_MAP, sizeof(ERROR_NO_MAP));
		return (-1);
	}
	while (get_next_line(fd, &line))
	{
		printf("%s\t\t = %d\n", line, ft_param_parser(&all, line));
//		free(line);
	}

	return (0);
}