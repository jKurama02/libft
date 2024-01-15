/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:26:04 by anmedyns          #+#    #+#             */
/*   Updated: 2024/01/12 17:27:00 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	count_words(const char	*s, char c)
{
	size_t	count;
	size_t	i;
	size_t	flag;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		flag = 0;
		while (s[i] != '\0' && s[i] == c)
		{
			i++;
		}
		while (s[i] != '\0' && s[i] != c)
		{
			if (flag == 0)
			{
				count++;
				flag = 1;
			}
			i++;
		}
	}
	return (count);
}

int	memory_check(char	**array, int position, size_t	len)
{
	int	i;

	i = 0;
	array[position] = malloc(len);
	if (array[position] == NULL)
	{
		while (i < position)
		{
			free(array[i]);
			i++;
		}
		free(array);
		return (1);
	}
	return (0);
}

int	fill_array(char **array, const char	*s, char c)
{
	size_t	len;
	size_t	i;
	size_t	position;

	i = 0;
	position = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] != '\0' && s[i] == c)
			i++;
		while (s[i] != '\0' && s[i] != c)
		{
			len++;
			i++;
		}
		if (len > 0)
		{
			if (memory_check(array, position, len + 1))
				return (1);
		}
		ft_strlcpy(array[position], s + i - len, len + 1);
		position++;
	}
	return (0);
}

char	**ft_split(const char	*s, char c)
{
	size_t	words;
	char	**array;

	if (s == NULL)
		return (NULL);
	words = count_words(s, c);
	array = malloc((words + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array[words] = NULL;
	if (fill_array(array, s, c) == 1)
		return (NULL);
	return (array);
}
