/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:25:43 by gdorcas           #+#    #+#             */
/*   Updated: 2019/09/16 12:48:54 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	if (!(result = (char *)malloc(sizeof(char) * (ft_strlen(s1)\
						+ ft_strlen(s2) + 1))))
		return (NULL);
	ft_memset(result, '\0', ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result = ft_strcat(result, s2);
	return (result);
}
