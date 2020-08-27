/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 15:55:35 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/27 13:46:17 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int				sort_alpha(t_ls *ls)
{
	if (ft_strcmp(ls->sorting->item.str, ls->sorting->next->item.str) > 0)
		return (1);
	return (0);
}

int				sort_alpha_r(t_ls *ls)
{
	if (ft_strcmp(ls->sorting->item.str, ls->sorting->next->item.str) < 0)
		return (1);
	return (0);
}

int			    swap(t_ls *ls)
{
	t_item			tmp;

	if (ls->sorting_algo(ls))
	{
		tmp = ls->sorting->item;
		ls->sorting->item = ls->sorting->next->item;
		ls->sorting->next->item = tmp;
		return (1);
	}
	return (0);
}

void			do_sort(t_ls *ls)
{
	int				sorted;

	while (1)
	{
		ls->sorting = ls->head;
		sorted = 1;
		while (ls->sorting && ls->sorting->next)
		{
			if (swap(ls))
				sorted = 0;
			ls->sorting = ls->sorting->next;
		}
		if (sorted)
			break ;
	}
}

void			sort(t_ls *ls)
{
	int 			(*tmp)(struct s_ls *ls);

	// if (ls->flags.f)
	// 	return ;
	tmp = ls->sorting_algo;
	if (ls->flags.r)
		ls->sorting_algo = &sort_alpha_r;
	else
		ls->sorting_algo = &sort_alpha;
	ls->head = ls->current_args;
	do_sort(ls);
	ls->sorting_algo = tmp;
	if (tmp)
		do_sort(ls);
	ls->current_args = ls->head;
}
