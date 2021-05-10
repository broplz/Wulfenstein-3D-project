/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:13:42 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 00:47:57 by broplz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, void *src, int c, size_t len)
{
	unsigned char	*pdest;
	unsigned char	*psrc;
	size_t			i;

	i = 0;
	pdest = dst;
	psrc = src;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < len)
	{
		pdest[i] = psrc[i];
		if (psrc[i] == (unsigned char)c)
			return ((void *)&pdest[i + 1]);
		i++;
	}
	return (NULL);
}
