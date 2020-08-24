/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjust_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:42:13 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/24 15:32:06 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

// static void		config(t_ls *ls)
// {
// 	// if (ls->flags.d)
// 	// 	ls->flags.up_r = 0;
// 	// if (ls->flags.f)
// 	// 	ls->flags.a = 1;
// 	// if (ls->flags.s_upper)
// 	// 	ls->flags.t = 0;
// 	// if (ls->flags.l)
// 	// 	ls->flags.x = 0;
// 	if (ls->flags.one)
// 	{
// 		ls->flags.l = 0;
// 		// ls->flags.x = 0;
// 	}
// }

void			adjust_options(t_ls *ls)
{
	// config(ls);
	if (ls->flags.l)
		ls->flags.x = 0;
	if (ls->flags.one)
	{
		ls->flags.l = 0;
		ls->flags.x = 0;
	}
	// assign_sort(ls);
}