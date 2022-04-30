/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 11:00:24 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 21:57:13 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sorted(t_push_swap **st_a, t_push_swap **st_b)
{
	if (!arr_is_sorted(st_a))
		return (0);
	if (*st_b)
		return (0);
	return (1);
}

int	get_next_line(char **line)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	buf = (char *)malloc(10000);
	if (!buf)
		exit(0);
	j = read(0, &buf[i], 1);
	while (j == 1 && buf[i] != '\n' && buf[i] != '\0')
	{
		i++;
		j = read(0, &buf[i], 1);
	}
	buf[i] = '\0';
	*line = buf;
	return (j);
}

void	run_list(t_push_swap **st_a, t_push_swap **st_b, char *str)
{
	if (!c_cm(str, st_a, st_b) && !c_cm2(str, st_a, st_b)
		&& !c_cm3(str, st_a, st_b))
		exit (write(2, "Error\n", 6));
}

void	checker(t_push_swap **st_a, t_push_swap **st_b)
{
	char		*line;

	while (get_next_line(&line) > 0)
		run_list(st_a, st_b, line);
	if (check_sorted(st_a, st_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(line);
}

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
	checker(&stack_a, &stack_b);
	free_list(&stack_a);
	return (0);
}
