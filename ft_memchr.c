/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:34:55 by ccalabro          #+#    #+#             */
/*   Updated: 2024/01/13 11:51:54 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	i;
	char	*str_ptr;

	if (str == NULL)
	{
		return (NULL);
	}
	i = 0;
	str_ptr = (char *)str;
	while (i < n)
	{
		if (str_ptr[i] == c)
		{
			return (&str_ptr[i]);
		}
		i++;
	}
	return (NULL);
}
