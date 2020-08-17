/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:57:00 by gdorcas           #+#    #+#             */
/*   Updated: 2019/09/09 17:19:20 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char *temp;

	temp = (char *)str + ft_strlen(str);
	while (*temp != c)
	{
		if (temp == str)
			return (NULL);
		temp--;
	}
	return (temp);
}
