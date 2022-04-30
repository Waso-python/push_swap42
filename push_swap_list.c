/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:05:41 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 19:30:32 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	make_stack_a(int val, t_push_swap **new)
{
	ft_lstadd_back(new, ft_lstnew(val));
}

void	ft_free(char **paths)
{
	int	i;

	i = 0;
	if (!paths)
		exit(write(1, "error: no data for free\n", 16));
	while (paths[i])
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	free_list(t_push_swap **mystack)
{
	t_push_swap	*temp;

	if (!mystack && !*mystack)
		return ;
	while (*mystack && mystack)
	{
		temp = (*mystack)->next;
		(*mystack)->content = 0;
		free(*mystack);
		*mystack = temp;
	}
}
