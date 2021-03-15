/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:16:15 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:16:16 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *srcs, size_t len)
{
	unsigned char		*dst;
	unsigned const char	*src;

	dst = dest;
	src = srcs;
	if (dst == 0 && dst == src)
		return (NULL);
	if (dst < src)
		while (len--)
			*dst++ = *src++;
	else
	{
		dst += len - 1;
		src += len - 1;
		while (len--)
			*dst-- = *src--;
	}
	return (dest);
}
