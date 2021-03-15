/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:17:12 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:17:13 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	const char *c;

	c = src;
	if (dst == NULL || src == NULL)
		return (0);
	if (len == 0)
		return (ft_strlen(src));
	while ((size_t)(src - c) < len - 1 && *src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (ft_strlen(c));
}
