/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:04:05 by gdorcas           #+#    #+#             */
/*   Updated: 2019/09/16 14:32:36 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t my_len;

	if (*needle == '\0')
		return ((char *)haystack);
	my_len = ft_strlen(needle);
	while (*haystack && len >= my_len)
	{
		if (*haystack == *needle && ft_memcmp(haystack, needle, my_len) == 0)
			return ((char *)haystack);
		len--;
		haystack++;
	}
	return (NULL);
}
