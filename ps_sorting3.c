/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:47:30 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 20:41:47 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	short_way(t_push_swap **st_a, size_t val)
{
	int			i;
	t_push_swap	*temp;

	i = 0;
	temp = *st_a;
	while (temp)
	{
		if (temp->index == val)
			return (i);
		++i;
		temp = temp->next;
	}
	return (0);
}

void	sort_5_el(t_push_swap **st_a, t_push_swap **st_b)
{
	int			i;

	i = 0;
	while (*st_a && i < 2 )
	{
		if ((*st_a)->index == 0 || (*st_a)->index == 1)
		{
			pa_pb(st_a, st_b, 1);
			++i;
		}
		else if (short_way(st_a, 0) > 2 || short_way(st_a, 1) > 2)
			rra_rrb(st_a, 0);
		else
			ra_rb(st_a, 0);
	}
	sort_3_el(st_a, 0);
	if ((*st_b) && (*st_b)->next && (*st_b)->next->index > (*st_b)->index)
		sa_sb(st_b, 1);
	pa_pb(st_b, st_a, 0);
	pa_pb(st_b, st_a, 0);
}

void	move_part1(t_push_swap **st_a, t_push_swap **st_b)
{
	size_t	med;
	size_t	i;
	size_t	size_st;

	i = 0;
	size_st = ft_lstsize(*st_a);
	med = (size_st - 1) / 2;
	while (i < size_st)
	{
		if (((*st_a)->index <= med))
			pa_pb(st_a, st_b, 1);
		else
			ra_rb(st_a, 0);
		i++;
	}
}
