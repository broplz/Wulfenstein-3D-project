/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:12:14 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:12:15 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t len)
{
	const unsigned char *dst;

	dst = s;
	if (len)
	{
		while (len--)
			if (*dst++ == (unsigned char)c)
				return ((void *)dst - 1);
	}
	return (NULL);
}
