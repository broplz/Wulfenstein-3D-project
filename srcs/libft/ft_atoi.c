/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcherrie <hcherrie@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 01:07:59 by hcherrie          #+#    #+#             */
/*   Updated: 2021/05/10 14:01:15 by hcherrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_run(char **str)
{
	while (**str && (**str == ' ' || **str == '\n' || **str == '\t' ||
				**str == '\v' || **str == '\f' || **str == '\r'))
		++(*str);
	return (str);
}

int		ft_atoi(char **str)
{
	long	res;
	long	negative;

	str = ft_run(str);
	negative = 1;
	res = 0;
	if (**str == '-')
		negative = -1;
	if (**str == '-' || **str == '+')
		++(*str);
	while (**str && **str >= '0' && **str <= '9')
	{
		res = res * 10 + (**str - 48);
		++(*str);
		if ((res * negative) > MAX_LONG)
			return (-1);
		if ((res * negative) < MIN_INT)
			return (-1);
	}
	return (res * negative);
}
