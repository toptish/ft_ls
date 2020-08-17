/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 17:12:49 by gdorcas           #+#    #+#             */
/*   Updated: 2019/09/16 15:32:47 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *dest;

	if (size + 1 == 0)
		return (NULL);
	if (!(dest = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	ft_memset(dest, 0, size + 1);
	return (dest);
}
