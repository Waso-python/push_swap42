/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_command1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:35:45 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 19:05:36 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_push_swap **mystack, int num)
{
	t_push_swap	*temp;
	t_push_swap	*temp2;

	if (!(*mystack) || !(*mystack)->next)
		return ;
	temp = (*mystack);
	temp2 = temp->next;
	temp->next = temp2->next;
	*mystack = temp2;
	temp2->next = temp;
	if (num == 0)
		write(1, "sa\n", 3);
	else if (num == 1)
		write(1, "sb\n", 3);
}

void	ra_rb(t_push_swap **mystack, int num)
{
	t_push_swap	*temp;
	t_push_swap	*temp2;

	if (!(*mystack) || !(*mystack)->next)
		return ;
	temp2 = ft_lstlast(*mystack);
	temp = *mystack;
	temp2->next = temp;
	*mystack = (*mystack)->next;
	temp->next = NULL;
	if (num == 0)
		write(1, "ra\n", 3);
	else if (num == 1)
		write(1, "rb\n", 3);
}

void	rra_rrb(t_push_swap **mystack, int num)
{
	t_push_swap	*temp;
	t_push_swap	*temp2;
	t_push_swap	*prev;

	if (!*mystack || !(*mystack)->next)
		return ;
	temp = *mystack;
	prev = *mystack;
	temp2 = ft_lstlast(*mystack);
	while (prev->next->next)
		prev = prev->next;
	prev->next = NULL;
	*mystack = temp2;
	temp2->next = temp;
	if (num == 0)
		write(1, "rra\n", 4);
	else if (num == 1)
		write(1, "rrb\n", 4);
}

void	pa_pb(t_push_swap **mystack1, t_push_swap **mystack2, int num)
{
	t_push_swap	*temp;

	if (!*mystack1)
		return ;
	temp = *mystack1;
	*mystack1 = (*mystack1)->next;
	temp->next = NULL;
	if (!(*mystack2))
		ft_lstadd_back(mystack2, temp);
	else
		ft_lstadd_front(mystack2, temp);
	if (num == 0)
		write(1, "pa\n", 3);
	else if (num == 1)
		write(1, "pb\n", 3);
}

void	ss(t_push_swap **mystack, t_push_swap **mystack2, int p)
{
	sa_sb(mystack, 3);
	sa_sb(mystack2, 3);
	if (p == 0)
		write(1, "ss\n", 3);
}
