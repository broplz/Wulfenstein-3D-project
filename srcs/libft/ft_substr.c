/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:18:12 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/18 20:12:39 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_safe_malloc(const char *s, unsigned int start, size_t len)
{
	char		*head;
	char const	*end;

	end = s;
	while (*end++)
		;
	if ((size_t)(end - &s[start]) >= len)
		head = (char *)malloc(sizeof(char *) * (len + 1));
	else
		head = (char *)malloc(sizeof(char *) * (end - &s[start] + 1));
	return (head);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
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
