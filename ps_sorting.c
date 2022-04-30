/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:47:30 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 20:14:41 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_index(t_push_swap **st_a)
{
	t_push_swap	*temp;

	temp = *st_a;
	while (temp)
	{
		if (temp->index == 2147483647)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	fill_index(t_push_swap **st_a)
{
	t_push_swap	*temp;
	t_push_swap	*t_min;
	long		min;
	size_t		i;

	i = 0;
	while (check_index(st_a))
	{
		temp = *st_a;
		min = 2147483647;
		while (temp)
		{
			if (temp->content <= min && temp->index == 2147483647)
			{
				min = temp->content;
				t_min = temp;
			}
			temp = temp->next;
		}
		t_min->index = (long)i;
		i++;
	}
}

void	main_sort(t_push_swap **st_a, t_push_swap **st_b)
{
	fill_index(st_a);
	if (arr_is_sorted(st_a))
		exit (0);
	if (ft_lstsize(*st_a) == 3)
		sort_3_el(st_a, 0);
	else if (ft_lstsize(*st_a) == 5)
		sort_5_el(st_a, st_b);
	else
		quick_sort(st_a, st_b);
}

int	arr_is_sorted(t_push_swap **st_a)
{
	int			i;
	int			j;
	t_push_swap	*temp;

	temp = *st_a;
	if (!temp)
		return (0);
	j = 0;
	i = ft_lstsize(*st_a);
	while (temp)
	{
		if (temp->next)
			if (temp->content > temp->next->content)
				break ;
		j++;
		temp = temp->next;
	}
	if (i == j)
		return (1);
	return (0);
}

void	sort_3_el(t_push_swap **st_a, int lst)
{
	int			c;
	int			i;

	i = 0;
	c = arr_is_sorted(st_a);
	while (!c && *st_a)
	{
		if ((*st_a)->index > (*st_a)->next->index)
			sa_sb(st_a, lst);
		else if ((*st_a)->index < (*st_a)->next->index)
		{
			rra_rrb(st_a, lst);
		}
		c = arr_is_sorted(st_a);
	}
}
