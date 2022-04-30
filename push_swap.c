/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:32:19 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 20:08:29 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_push_swap	*stack_a;
	t_push_swap	*stack_b;

	stack_b = NULL;
	if (argc < 2)
		return (1);
	if (argc == 2)
		check_string_params(argv, &stack_a);
	else
		check_params(argv, &stack_a);
	if (check_duplicate(stack_a))
		exit(write(1, "Error\n", 6));
	main_sort(&stack_a, &stack_b);
	free_list(&stack_a);
}
