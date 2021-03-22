#include "./include/cub3d.h"
#include <stdio.h> // TODO НЕ ЗАБЫТЬ УДАЛИТЬ ЭТУ СТРОЧКУ

int 	ft_map_anal(char *line, char *head)
{
	static int		anal;
	char			*right;

	anal = 0;
	while (*line)
	{
		right = head;
		while (*right && *right != *line)
		{
			if (*line == 'N' || *line == 'W' || *line == 'E' || *line == 'S')
			{
				anal += 1;
				break;
			}
			if (anal > 1)
				return (-1);
			right++;
		}
		if (*right == '\0')
			return (-1);
		line++;
	}
	return (1);
}

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

int 	ft_map_search(t_all *all, char *line)
{
	if (!line || *line == '\0')
		return (1);
	while (*line == ' ')
		line++;
	if ((*line) == '1')
		return (1 + (all->co.pflag = 2) - 2);
	else
		return (-1 + (all->co.pflag = -1) + 1);
}

int		ft_map_init(t_all *all, t_list *list, int len, int lst_size)
{
	int	i;

	i = 0;
	while (i < lst_size - 1)
	{
		if (i == 0)
			ft_map_copy(NULL, all->map.map[i], len);
		else
			if (i != 0 && list) {
				ft_map_copy(list->content, all->map.map[i], len);
				list = list->next;
			}
		i++;
	}
	ft_map_copy(NULL, all->map.map[i], len);
	return (1);
}

int		ft_map_vw(t_all *all)
{
	char	**array;
	int		i;
	int		j;

	i = 0;
	j = 0;
	array = all->map.map;
	while (i < all->map.lst_size)
	{
		while (j < all->map.len)
		{
			if (array[i][j] == ' ')
			{
				if (i != 0 && j != 0 && !(array[i - 1][j - 1] == ' ' || array[i - 1][j - 1] == '1' || array[i - 1][j - 1] == '\0'))
					return (-1);
				if (i != 0 && !(array[i - 1][j] == ' ' || array[i - 1][j] == '1' || array[i - 1][j] == '\0'))
					return (-1);
				if (i != 0 && !(array[i - 1][j + 1] == ' ' || array[i - 1][j + 1] == '1' || array[i - 1][j + 1] == '\0'))
					return (-1);
				if (j != 0 && !(array[i][j - 1] == ' ' || array[i][j - 1] == '1' || array[i][j - 1] == '\0'))
					return (-1);
				if (!(array[i][j + 1] == ' ' || array[i][j + 1] == '1' || array[i][j + 1] == '\0'))
					return (-1);
				if (i != all->map.lst_size - 1 && j != 0 && !(array[i + 1][j - 1] == ' ' || array[i + 1][j - 1] == '1' || array[i + 1][j - 1] == '\0'))
					return (-1);
				if (i != all->map.lst_size - 1 && !(array[i + 1][j] == ' ' || array[i + 1][j] == '1' || array[i + 1][j] == '\0'))
					return (-1);
				if (i != all->map.lst_size - 1 && !(array[i + 1][j + 1] == ' ' || array[i + 1][j + 1] == '1' || array[i + 1][j + 1] == '\0'))
					return (-1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int		ft_map_size(t_all *all, t_list *list)
{
	int		i;
	t_list	*head;

	i = 0;
	all->map.len = 0;
	all->map.lst_size = 0;
	all->map.lst_size = ft_lstsize(list) + 2;
	head = list;
	if (!(all->map.map = ft_calloc(all->map.lst_size + 1, sizeof(char *))))
		return (-1);
	while (list)
	{
		if (all->map.len < ft_strlen((char *)list->content))
			all->map.len = ft_strlen((char *)list->content);
		list = list->next;
	}
	all->map.len += 2;
	while (i < all->map.lst_size)
		if (!(all->map.map[i++] = ft_calloc(all->map.len + 1, sizeof(char))))
			return (-1);
	ft_map_init(all, head, all->map.len, all->map.lst_size);
	printf("VALID ===> %d", ft_map_vw(all));
	return (1);
}

int		ft_map_parse(t_all *all, int fd, t_list **list)
{
	char	*line;

	while (get_next_line(fd, &line)	&& (ft_map_search(all, line) > 0))
	{
		if (!(ft_map_anal(line, "012WESN \0")))
			return (all->co.pflag = 0);
		if (all->co.pflag == 2)
			ft_lstadd_back(list, ft_lstnew(line));
		else
			free(line);
	}
	if (all->co.pflag == 2)
		ft_lstadd_back(list, ft_lstnew(line));
	else
		free(line);
	ft_map_size(all, *list);
	for(int i = 0; i < all->map.lst_size; i++)
	{
		for (int j = 0; j < all->map.len; j++)
			printf("%c", all->map.map[i][j]);
		printf("\n");
	}
	return (1);
}

int		main(int argc, char **argv)
{
	argc = 2;
	argv[1] = "/home/broplz/cube3D/maps/2.cub";
	//TODO УБРАТЬ ЭТУ ХУЙНЮ
	t_all	all;
	int		fd;
	t_list *params;
	t_list *map;

	params = NULL;
	map = NULL;
	fd = open(argv[1], O_RDONLY);
//	if (argc == 1)
//	{
//		write(1, ERROR_NO_MAP, sizeof(ERROR_NO_MAP));
//		return (-1);
//	}
	ft_init_all(&all);
	ft_par_parse(&all, fd, &params);
	ft_map_parse(&all, fd, &map);

	int debug_stop; // TODO УДАЛИТЬ СТРОЧКУ ПОСЛЕ ВСЕХ ДЕЙСТВИЙ

	return (0);
}