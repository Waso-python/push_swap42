/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 13:58:15 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/28 22:43:12 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isdigit(int sym)
{
	if (sym <= 57 && sym >= 48)
		return (1);
	return (0);
}

static int	ft_atoi_result(int sign, unsigned long long out)
{
	if (out > 2147483647)
	{
		return (0);
	}
	return (out * sign);
}

int	ft_atoi(const char *str)
{
	int					sign;
	unsigned long long	out;

	sign = 1;
	out = 0;
	while ((*str == 32) | ((*str > 8) && (*str <= 13)))
		str++;
	if ((*str == '-') | (*str == '+'))
	{		
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			out = out * 10 + (*str - 48);
			str++;
		}
		else
			return (0);
	}
	return (ft_atoi_result(sign, out));
}
