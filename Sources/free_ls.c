/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ls.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 10:21:09 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/24 18:38:11 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void			free_arg(t_ls *ls, t_args *args)
{
	if (args->item.str != ls->error && args->item.str)
		free(args->item.str);
	if (args->item.path != ls->error && args->item.path)
		free(args->item.path);
	if (args->item.user != ls->error && args->item.user)
		free(args->item.user);
	if (args->item.group != ls->error && args->item.group)
		free(args->item.group);
}

void			free_args(t_ls *ls, t_args **start)
{
	t_args		*args;
	t_args		*tmp;

	args = *start;
	while (args)
	{
		tmp = args;
		free_arg(ls, args);
		args = args->next;
		free(tmp);
	}
	*start = NULL;
}

void			free_ls(t_ls *ls)
{
	free_args(ls, &ls->args);
	if (ls->argv_options)
		free(ls->argv_options);
	if (ls->argv_opt_str)
		free(ls->argv_opt_str);
	if (ls->error)
		free(ls->error);
}