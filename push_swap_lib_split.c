/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarr <sdarr@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 21:12:52 by sdarr             #+#    #+#             */
/*   Updated: 2022/01/23 14:30:06 by sdarr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mem_free(char **str, int size)
{
	while (size--)
		free(str[size]);
	return (-1);
}

static int	count_w(const char *str, unsigned char set)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i + 1] == set || str[i + 1] == '\0') == 1 \
				&& (str[i] == set || str[i] == '\0') == 0)
			words++;
		i++;
	}
	return (words);
}

static void	write_w(char *dest, const char *src, unsigned char set)
{
	int	i;

	i = 0;
	while ((src[i] == set || src[i] == '\0') == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

static int	write_split(char **split, const char *str, unsigned char set)
{
	int		i;
	int		j;
	int		word;

	word = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] == set || str[i] == '\0') == 1)
			i++;
		else
		{
			j = 0;
			while ((str[i + j] == set || str[i + j] == '\0') == 0)
				j++;
			split[word] = malloc(sizeof(char) * (j + 1));
			if (split[word] == NULL)
				return (mem_free(split, word - 1));
			write_w(split[word], str + i, set);
			i = i + j;
			word++;
		}
	}
	return (0);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	int		words;

	if (!str)
		return (NULL);
	words = count_w(str, (unsigned char)c);
	res = malloc(sizeof(char *) * (words + 1));
	if (res == NULL)
		return (NULL);
	res[words] = 0;
	if (write_split(res, str, (unsigned char)c) == -1)
		return (NULL);
	return (res);
}
