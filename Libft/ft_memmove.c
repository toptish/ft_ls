/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 19:56:14 by gdorcas           #+#    #+#             */
/*   Updated: 2019/09/06 21:27:25 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	const unsigned char	*source;

	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (source == dest)
		return (dst);
	if (source < dest)
	{
		source = source + len - 1;
		dest = dest + len - 1;
		while (len--)
		{
			*dest = *source;
			dest--;
			source--;
		}
	}
	else
		ft_memcpy(dest, source, len);
	return (dst);
}
