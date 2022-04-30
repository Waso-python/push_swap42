/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:28:38 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/30 20:42:35 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_push_swap
{
	long				content;
	size_t				index;
	int					flag;
	struct s_push_swap	*next;
}	t_push_swap;

size_t			ft_strlen(const char *s);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
int				ft_atoi(const char *str);
t_push_swap		*ft_lstnew(long content);
void			ft_lstadd_front(t_push_swap **lst, t_push_swap *new);
void			ft_lstadd_back(t_push_swap **lst, t_push_swap *new);
int				ft_lstsize(t_push_swap *lst);
t_push_swap		*ft_lstlast(t_push_swap *lst);

void			ft_free(char **paths);
void			sort_all(t_push_swap **st_a, t_push_swap **st_b);

void			print_list(t_push_swap *my_stack, char *mess);

int				check_params(char **argv, t_push_swap **stack_a);
int				check_string_params(char **argv, t_push_swap **stack_a);
void			make_stack_a(int val, t_push_swap **new);
int				check_duplicate(t_push_swap *stack_a);
void			free_list(t_push_swap **mystack);

void			sa_sb(t_push_swap **mystack, int num);
void			ra_rb(t_push_swap **mystack, int num);
void			rra_rrb(t_push_swap **mystack, int num);
void			pa_pb(t_push_swap **mystack1, t_push_swap **mystack2, int num);
void			ss(t_push_swap **mystack, t_push_swap **mystack2, int p);
void			rr(t_push_swap **mystack, t_push_swap **mystack2, int p);
void			rrr(t_push_swap **mystack, t_push_swap **mystack2, int p);
void			sort_3_el(t_push_swap **st_a, int lst);
void			sort_5_el(t_push_swap **st_a, t_push_swap **st_b);
void			main_sort(t_push_swap **st_a, t_push_swap **st_b);
int				arr_is_sorted(t_push_swap **st_a);
void			fill_index(t_push_swap **st_a);
void			quick_sort(t_push_swap **st_a, t_push_swap **st_b);
int				check_a(t_push_swap **st_a, t_push_swap **st_b, size_t *min);
int				check_a1(t_push_swap **st_a, t_push_swap **st_b, size_t *min);
void			move_part1(t_push_swap **st_a, t_push_swap **st_b);
int				check_b(t_push_swap **st_a, size_t med);

int				c_cm(char *s, t_push_swap **st_a, t_push_swap **st_b);
int				c_cm2(char *s, t_push_swap **st_a, t_push_swap **st_b);
int				c_cm3(char *s, t_push_swap **st_a, t_push_swap **st_b);

#endif