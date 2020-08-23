/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_options.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:12:32 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/22 12:36:30 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

static void			set_options_var(char c, unsigned long *options)
{
	unsigned long	one;

	one = 1;
	if (c >= 'a' && c <= 'z')
		*options |= (one << (c - 97));
	else if (c >= 'A' && c <= 'Z')
		*options |= (one << (c - 39));
	else if (c >= '0' && c <= '9')
		*options |= (one << (c + 4));
	else
		*options |= (one << 63);
}

unsigned long		ft_options(char **argv)
{
	unsigned long	options;
	char			*str;

	options = 0;
	argv++;
	while (*argv)
	{
		str = *argv;
		if (!ft_strcmp(*argv, "--"))
			break ;
		else if (*str == '-')
		{
			str++;
			while (*str)
			{
				set_options_var(*str, &options);
				str++;
			}
		}
		argv++;
	}
	return (options);
}