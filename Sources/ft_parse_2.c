/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:37:52 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/24 18:38:21 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

t_args		*create_args(void)
{
	t_args	*args;

	if (!(args = (t_args *)malloc(sizeof(t_args))))
		return (NULL);
	ft_bzero(args, sizeof(*args));
	return (args);
}
