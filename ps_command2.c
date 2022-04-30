/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 11:19:15 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 19:05:26 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_push_swap **mystack, t_push_swap **mystack2, int p)
{
	ra_rb(mystack, 3);
	ra_rb(mystack2, 3);
	if (p == 0)
		write(1, "rr\n", 3);
}

void	rrr(t_push_swap **mystack, t_push_swap **mystack2, int p)
{
	rra_rrb(mystack, 3);
	rra_rrb(mystack2, 3);
	if (p == 0)
		write(1, "rrr\n", 3);
}

int	check_b(t_push_swap **st_b, size_t med)
{
	t_push_swap	*temp;

	temp = *st_b;
	while (temp)
	{
		if (temp->index >= med)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	check_a1(t_push_swap **st_a, t_push_swap **st_b, size_t *min)
{
	int	i;

	i = 0;
	if ((*st_b) && (*st_b)->next && (*st_b)->next->index == *min)
	{
		sa_sb(st_b, 1);
		pa_pb(st_b, st_a, 0);
		i = 1;
	}
	if ((*st_a)->next->index == *min)
	{
		sa_sb(st_a, 0);
		i = 1;
	}
	return (i);
}
