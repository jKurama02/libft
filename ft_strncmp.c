/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:58:25 by anmedyns          #+#    #+#             */
/*   Updated: 2024/01/14 18:35:15 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	c1;
	unsigned char	c2;

	if (n == 0)
		return (0);
	n++;
	while (*s1 && *s2 && --n > 0)
	{
		c1 = (unsigned char)(*s1);
		c2 = (unsigned char)(*s2);
		if (c1 != c2)
			return (c1 - c2);
		s1++;
		s2++;
	}
	if (n > 0)
		return ((unsigned char)(*s1) - (unsigned char)(*s2));
	return (0);
}
