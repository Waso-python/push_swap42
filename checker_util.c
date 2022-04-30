/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:29:53 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 19:09:29 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	c_cm(char *s, t_push_swap **st_a, t_push_swap **st_b)
{
	if (!(ft_strcmp("ra", s)))
	{
		ra_rb(st_a, 5);
		return (1);
	}
	if (!(ft_strcmp("rb", s)))
	{
		ra_rb(st_b, 5);
		return (1);
	}
	if (!(ft_strcmp("pa", s)))
	{
		pa_pb(st_b, st_a, 5);
		return (1);
	}
	if (!(ft_strcmp("pb", s)))
	{
		pa_pb(st_a, st_b, 5);
		return (1);
	}
	return (0);
}

int	c_cm2(char *s, t_push_swap **st_a, t_push_swap **st_b)
{	
	if (!(ft_strcmp("rr", s)))
	{
		rr(st_a, st_b, 5);
		return (1);
	}
	if (!(ft_strcmp("rra", s)))
	{
		rra_rrb(st_a, 5);
		return (1);
	}
	if (!(ft_strcmp("rrb", s)))
	{
		rra_rrb(st_b, 5);
		return (1);
	}
	if (!(ft_strcmp("rrr", s)))
	{
		rrr(st_a, st_b, 5);
		return (1);
	}
	return (0);
}

int	c_cm3(char *s, t_push_swap **st_a, t_push_swap **st_b)
{
	if (!(ft_strcmp("sa", s)))
	{
		sa_sb(st_a, 5);
		return (1);
	}
	if (!(ft_strcmp("sb", s)))
	{
		sa_sb(st_b, 5);
		return (1);
	}
	if (!(ft_strcmp("ss", s)))
	{
		ss(st_a, st_b, 5);
		return (1);
	}
	return (0);
}
