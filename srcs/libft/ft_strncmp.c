/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:18:06 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:18:07 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t len)
{
	int r;

	if (len == 0)
		return (0);
	while (len-- != 0)
	{
		if (*s1 != *s2++)
		{
			r = (*(const unsigned char *)s1 - *(const unsigned char *)(s2 - 1));
			return (r);
		}
		if (*s1++ == 0)
			break ;
	}
	return (0);
}
