/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 10:00:05 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/25 10:11:08 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void				get_path(t_ls *ls, t_args *args, char *path, char *name)
{
	char			*new_path;
	char			*tmp;

	if (!(args->item.str = ft_strdup(name)))
		args->item.str = ls->error;
	if (!(new_path = ft_strnew(ft_strlen(path) + ft_strlen(name) + 1)))
		args->item.path = ls->error;
	else
	{
		tmp = new_path;
		if (ft_strcmp(path, "."))
		{
			while (path && *path)
				*(tmp++) = *(path++);
			*(tmp++) = '/';
		}
		while (name && *name)
			*(tmp++) = *(name++);
		args->item.path = new_path;
	}
}