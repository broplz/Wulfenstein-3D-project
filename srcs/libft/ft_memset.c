/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:12:21 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:12:22 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int c, size_t len)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = dst;
	if (len != 0)
	{
		while (i < len)
		{
			d[i] = c;
			i++;
		}
	}
	return (dst);
}
