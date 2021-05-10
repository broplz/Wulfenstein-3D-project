/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:17:06 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 00:47:57 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dst[i] && i < len)
		i++;
	while (src[j] && i + j + 1 < len)
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i != len)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
