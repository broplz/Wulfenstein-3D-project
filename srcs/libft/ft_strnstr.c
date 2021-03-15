/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:13:36 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:13:38 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *str, const char *find, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!*find)
		return ((char *)str);
	i = ft_strlen(find);
	while (ft_strncmp(&str[j], find, i) != 0)
	{
		if (!str[j] || j >= (len - i))
			return (NULL);
		++j;
	}
	if (i > len)
		return (NULL);
	return ((char *)&str[j]);
}
