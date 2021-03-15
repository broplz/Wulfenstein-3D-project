/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:18:14 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:18:14 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_free(char **res, size_t i)
{
	while ((int)i >= 0)
	{
		free(res[i]);
		res[i] = NULL;
		i--;
	}
	free(res);
	res = NULL;
	return (res);
}

size_t			ft_len_help(const char *s, char ch)
{
	const char	*h;

	h = s;
	while (*s != ch && *s != '\0')
		s++;
	return (s - h);
}

size_t			ft_wcount(const char *s, char ch)
{
	size_t		i;
	size_t		f;
	size_t		j;

	i = 0;
	f = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == ch && f == 1)
			f = 0;
		if (s[i] != ch && f == 0)
		{
			f = 1;
			j++;
		}
		i++;
	}
	return (j);
}

char			**ft_split(char const *s, char ch)
{
	char		**res;
	size_t		wc;
	size_t		i;

	if (!s)
		return (NULL);
	i = 0;
	wc = ft_wcount(s, ch);
	res = (char **)malloc(sizeof(char *) * (wc + 1));
	if (!res)
		return (NULL);
	while (wc--)
	{
		while (*s == ch && *s != '\0')
			s++;
		res[i] = ft_substr(s, 0, ft_len_help(s, ch));
		if (!res[i])
			return (ft_free(res, i));
		s = s + ft_len_help(s, ch);
		i++;
	}
	res[i] = NULL;
	return (res);
}
