/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:00:55 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/28 12:32:49 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_push_swap	*ft_lstnew(long content)
{
	t_push_swap	*new_list;

	new_list = malloc(sizeof(t_push_swap));
	if (!new_list)
		return (NULL);
	new_list->content = content;
	new_list->index = 2147483647;
	new_list->flag = 0;
	new_list->next = NULL;
	return (new_list);
}

int	ft_lstsize(t_push_swap *lst)
{
	size_t		i;
	t_push_swap	*temp;

	i = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_push_swap	*ft_lstlast(t_push_swap *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_push_swap **lst, t_push_swap *new)
{
	t_push_swap	*temp;

	if (!lst || !new)
		return ;
	if (lst && *lst)
	{
		temp = ft_lstlast(*lst);
		temp->next = new;
	}
	else if (lst)
		*lst = new;
}

void	ft_lstadd_front(t_push_swap **lst, t_push_swap *new)
{
	new->next = *lst;
	*lst = new;
}
