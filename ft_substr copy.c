/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmedyns <anmedyns@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:26:04 by anmedyns          #+#    #+#             */
/*   Updated: 2024/01/12 17:38:30 by anmedyns         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char	*s, unsigned int start, size_t	len)
{
	size_t	i;
	char	*substr;

	if (s == NULL)
		return (NULL);
	i = 0;
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == NULL)
		return (NULL);
	while (i < len)
		substr[i] = s[start + i];
	i++;

	substr[i] = '\0';
	return (substr);
}
