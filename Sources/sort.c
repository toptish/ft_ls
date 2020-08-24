/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:29:13 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/24 18:38:49 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int				sort_time(t_ls *ls)
{
	// if (ls->flags.c)
	// {
	// 	if (ls->sorting->item.c_time < ls->sorting->next->item.c_time)
	// 		return (1);
	// 	return (0);
	// }
	// if (ls->flags.u)
	// {
	// 	if (ls->sorting->item.u_time < ls->sorting->next->item.u_time)
	// 		return (1);
	// 	return (0);
	// }
	// if (ls->flags.up_u)
	// {
	// 	if (ls->sorting->item.up_u_time < ls->sorting->next->item.up_u_time)
	// 		return (1);
	// 	return (0);
	// }
	// else
	// {
		if (ls->sorting->item.m_time_t < ls->sorting->next->item.m_time_t)
			return (1);
		return (0);
	// }
}

int				sort_time_r(t_ls *ls)
{
	// if (ls->flags.c)
	// {
	// 	if (ls->sorting->item.c_time > ls->sorting->next->item.c_time)
	// 		return (1);
	// 	return (0);
	// }
	// if (ls->flags.u)
	// {
	// 	if (ls->sorting->item.u_time > ls->sorting->next->item.u_time)
	// 		return (1);
	// 	return (0);
	// }
	// if (ls->flags.up_u)
	// {
	// 	if (ls->sorting->item.up_u_time > ls->sorting->next->item.up_u_time)
	// 		return (1);
	// 	return (0);
	// }
	// else
	// {
		if (ls->sorting->item.m_time_t > ls->sorting->next->item.m_time_t)
			return (1);
		return (0);
	// }
}

int				sort_size(t_ls *ls)
{
	if (ls->sorting->item.size < ls->sorting->next->item.size)
		return (1);
	return (0);
}

int				sort_size_r(t_ls *ls)
{
	if (ls->sorting->item.size > ls->sorting->next->item.size)
		return (1);
	return (0);
}