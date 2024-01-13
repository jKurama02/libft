/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 19:20:56 by anmedyns          #+#    #+#             */
/*   Updated: 2024/01/13 11:57:30 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	tot;

	tot = count * size;
	if (count + size < count || count + size < size || tot > 2147483424)
	{
		return (NULL);
	}
	ptr = malloc(tot);
	if (!ptr)
	{
		return (NULL);
	}
	while (tot--)
		((char *)ptr)[tot] = 0;
	return (ptr);
}
