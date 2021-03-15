/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:15:36 by hcherrie          #+#    #+#             */
/*   Updated: 2020/11/17 01:15:37 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char *g;

	g = (char *)str;
	while (*str)
		str++;
	while (str != g - 1)
	{
		if (*str == ch)
			return ((char *)str);
		str--;
	}
	return (0);
}
