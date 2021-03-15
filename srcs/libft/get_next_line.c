/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:55:03 by hcherrie          #+#    #+#             */
/*   Updated: 2021/03/02 12:24:15 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t		i;
	size_t		j;
	char		*str;

	if (s == 0)
		return (NULL);
	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
			str[j++] = s[i];
		i++;
	}
	str[j] = 0;
	return (str);
}

char		*gnl_buff_fill(int fd, char *buffer)
{
	char	*tmp;
	int		len;

	len = 1;
	if (!(tmp = (char *)malloc(BUFFER_SIZE + 1)))
		return (NULL);
	if (!buffer)
	{
		if ((len = read(fd, tmp, BUFFER_SIZE)) < 0)
		{
			free(tmp);
			tmp = NULL;
			return (NULL);
		}
		tmp[len] = '\0';
		buffer = ft_strdup(tmp);
	}
	while (len && ft_strchr_gnl(buffer, '\n', 1) == 0)
	{
		len = read(fd, tmp, BUFFER_SIZE);
		tmp[len] = '\0';
		buffer = ft_strjoin_gnl(buffer, tmp);
	}
	free(tmp);
	return (buffer);
}

int			get_next_line(int fd, char **line)
{
	static char *buffer;
	int			count;
	int			len;
	char		*tmp;

	if (BUFFER_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!(buffer = gnl_buff_fill(fd, buffer)))
		return (-1);
	count = ft_strchr_gnl(buffer, '\n', 0);
	if (ft_strchr_gnl(buffer, '\n', 1))
	{
		tmp = buffer;
		*line = ft_substr_gnl(buffer, 0, count);
		len = ft_strlen_gnl(*line);
		buffer = ft_substr_gnl(buffer, count + 1, ft_strlen_gnl(buffer) - len);
		free(tmp);
		tmp = NULL;
		return (1);
	}
	*line = ft_substr_gnl(buffer, 0, count);
	free(buffer);
	buffer = NULL;
	return (0);
}
