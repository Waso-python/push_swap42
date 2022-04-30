/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lib_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 14:26:13 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/23 14:28:14 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (*ss1 == 0 || *ss2 == 0)
		return (*ss1 - *ss2);
	while (*ss1 || *ss2)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		ss1++;
		ss2++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	len;
	char			*ptr;
	char			*res;

	if (!s2 || !s1)
		return (0);
	len = 0;
	ptr = (char *)s1;
	while (*ptr++)
		len++;
	ptr = (char *)s2;
	while (*ptr++)
		len++;
	ptr = (char *)malloc((len + 1) * sizeof(char));
	if (ptr == 0)
		return (0);
	res = ptr;
	while (*s1)
		*ptr++ = *s1++;
	while (*s2)
		*ptr++ = *s2++;
	*ptr = 0;
	return (res);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
