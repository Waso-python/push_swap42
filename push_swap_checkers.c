/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checkers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 20:01:41 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 21:56:09 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_string_params(char **argv, t_push_swap **stack_a)
{
	char	**tmp;
	size_t	i;

	tmp = ft_split(argv[1], ' ');
	if (!tmp)
		exit(0);
	i = 0;
	while (tmp[i])
	{
		if (ft_strcmp(tmp[i], "0") == 0 || ft_atoi(tmp[i]) != 0)
		{
			make_stack_a(ft_atoi(tmp[i]), stack_a);
		}
		else
		{
			free_list(stack_a);
			ft_free(tmp);
			exit(write(1, "Error\n", 6));
		}
		i++;
	}
	ft_free(tmp);
	return (0);
}

int	check_params(char **argv, t_push_swap **stack_a)
{
	argv++;
	while (*argv)
	{
		if (ft_strcmp(*argv, "0") == 0 || ft_atoi(*argv) != 0)
		{
			make_stack_a(ft_atoi(*argv), stack_a);
		}
		else
		{
			free_list(stack_a);
			exit(write(1, "Error\n", 6));
		}
		argv++;
	}
	return (0);
}

int	check_el_in_list(t_push_swap *stack_a, long m, long j)
{
	long		i;
	long		k;
	t_push_swap	*temp;

	i = 0;
	k = 0;
	temp = stack_a;
	while (i < ft_lstsize(stack_a))
	{
		k = temp->content;
		if (k == m && i != j)
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}

int	check_duplicate(t_push_swap *stack_a)
{
	long		i;
	long		k;
	t_push_swap	*temp;

	i = 0;
	k = 0;
	if (!stack_a)
		return (1);
	temp = stack_a;
	while (i < ft_lstsize(stack_a))
	{
		k = temp->content;
		if (check_el_in_list(stack_a, k, i))
			return (1);
		temp = temp->next;
		i++;
	}
	return (0);
}
