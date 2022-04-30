/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:47:30 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 20:41:37 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_a(t_push_swap **st_a, t_push_swap **st_b, size_t *min)
{
	int	i;

	i = 0;
	if ((*st_a)->index == *min)
	{
		(*st_a)->flag = -1;
		ra_rb(st_a, 0);
		(*min)++;
		i = 1;
	}
	if ((*st_b) && (*st_b)->index == *min)
	{
		pa_pb(st_b, st_a, 0);
		i = 1;
	}
	if ((*st_b) && ft_lstlast(*st_b)->index == *min)
	{
		rra_rrb(st_b, 1);
		pa_pb(st_b, st_a, 0);
		i = 1;
	}
	if (check_a1(st_a, st_b, min))
		i = 1;
	return (i);
}

int	check_a_b(t_push_swap **st_a, size_t *min)
{
	int	i;

	i = 0;
	if ((*st_a)->index == *min)
	{
		(*st_a)->flag = -1;
		ra_rb(st_a, 0);
		(*min)++;
		i = 1;
	}
	return (i);
}

void	work_a(t_push_swap **st_a, t_push_swap **st_b, int *fl, size_t *min)
{
	*fl = (*st_a)->flag;
	while ((*st_a)->flag == *fl && (*fl) >= 0)
	{
		if (!check_a(st_a, st_b, min))
			pa_pb(st_a, st_b, 1);
	}
}

void	work_b(t_push_swap **st_a, t_push_swap **st_b, int *flag, size_t *min)
{
	size_t		med;
	size_t		size_st;
	size_t		i;

	i = 0;
	(*flag)++;
	size_st = ft_lstsize(*st_b);
	med = size_st / 2 + *min;
	while (i++ <= size_st && check_b(st_b, med))
	{
		if ((*st_b) && (*st_b)->index == *min)
		{
			pa_pb(st_b, st_a, 0);
			check_a_b(st_a, min);
		}
		else if ((*st_b) && (*st_b)->index >= med)
		{
			(*st_b)->flag = *flag;
			pa_pb(st_b, st_a, 0);
			check_a_b(st_a, min);
		}
		else
			ra_rb(st_b, 1);
	}
}

void	quick_sort(t_push_swap **st_a, t_push_swap **st_b)
{
	int			fl;
	size_t		min;
	size_t		count;

	count = ft_lstsize(*st_a);
	min = 0;
	fl = 0;
	move_part1(st_a, st_b);
	while (min < count)
	{
		while (*st_b)
			work_b(st_a, st_b, &fl, &min);
		if (*st_a)
			work_a(st_a, st_b, &fl, &min);
	}
}
