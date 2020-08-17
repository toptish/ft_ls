/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 14:03:37 by gdorcas           #+#    #+#             */
/*   Updated: 2019/09/13 14:46:17 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s)
{
	size_t	start;
	size_t	end;
	char	*result;
	size_t	len;

	if (!s)
		return (NULL);
	start = 0;
	while (ft_isspace(s[start]) == 1)
		start++;
	end = ft_strlen(s) - 1;
	while (ft_isspace(s[end]) == 1 && end)
		end--;
	len = 0;
	if (start < end)
		len = end - start + 1;
	if (!(result = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (start <= end && len)
		*result++ = s[start++];
	*result = '\0';
	return (result - len);
}
