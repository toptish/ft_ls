/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:51:32 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/25 13:18:51 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

unsigned long	illegal_options(t_ls *ls)
{
	char			**legal_options;
	unsigned long	illegal_opt;

	if (!(legal_options = (char **)malloc(sizeof(char *) * 3)))
		return_error(ls, "Malloc error");
	legal_options[0] = NULL;
	legal_options[2] = NULL;
	if (!(legal_options[1] = ft_strdup(OPTIONS)))
	{
		free(legal_options);
		return_error(ls, "Malloc error");
	}
	illegal_opt = ~ft_options(legal_options);
	// ft_printf("illegal_opt %ld", illegal_opt);
	free(legal_options[1]);
	free(legal_options);
	return (illegal_opt);
}

void			check_options(t_ls *ls, unsigned long flags)
{
	char			**argv;
	unsigned long	illegal_opt;

	argv = ls->argv;
	illegal_opt = illegal_options(ls);
	// ft_printf("illegal_opt %ld\n", illegal_opt);
	// ft_printf("legal_opt %ld", flags);
	// if ((option_data = option_data & not_used_opt))
	// 	print_usage(ls, option_data &= not_used_opt);
	if ((flags = flags & illegal_opt))
		print_usage(ls, flags);
}

/*
** ft_options - sets bits in unsigned long for options (flags) used
** 0-25 bits - for a-z
** 26-51 bits for A-Z
** 52-62 for 0-9
** 63 for other possible characters used
*/
void			set_options(t_ls *ls, unsigned long flags)
{
	unsigned long	one;

	one = 1;
	ls->flags.a = (flags & (one << ('a' - 97))) ? 1 : 0;
	// ls->flags.c = (option_data & (one << ('c' - 97))) ? 1 : 0;
	// ls->flags.d = (option_data & (one << ('d' - 97))) ? 1 : 0;
	// ls->flags.f = (option_data & (one << ('f' - 97))) ? 1 : 0;
	// ls->flags.g = (option_data & (one << ('g' - 97))) ? 1 : 0;
	// ls->flags.i = (option_data & (one << ('i' - 97))) ? 1 : 0;
	ls->flags.l = (flags & (one << ('l' - 97))) ? 1 : 0;
	// ls->flags.o = (option_data & (one << ('o' - 97))) ? 1 : 0;
	// ls->flags.p = (option_data & (one << ('p' - 97))) ? 1 : 0;
	ls->flags.r = (flags & (one << ('r' - 97))) ? 1 : 0;
	ls->flags.t = (flags & (one << ('t' - 97))) ? 1 : 0;
	// ls->flags.u = (option_data & (one << ('u' - 97))) ? 1 : 0;
	// ls->flags.x = (option_data & (one << ('x' - 97))) ? 1 : 0;
	// ls->flags.a_upper = (option_data & (one << ('A' - 39))) ? 1 : 0;
	// ls->flags.f_upper = (option_data & (one << ('F' - 39))) ? 1 : 0;
	ls->flags.g_upper = (flags & (one << ('G' - 39))) ? 1 : 0;
	// ls->flags.n_upper = (option_data & (one << ('N' - 39))) ? 1 : 0;
	ls->flags.r_upper = (flags & (one << ('R' - 39))) ? 1 : 0;
	// ls->flags.s_upper = (option_data & (one << ('S' - 39))) ? 1 : 0;
	// ls->flags.t_upper = (option_data & (one << ('T' - 39))) ? 1 : 0;
	// ls->flags.u_upper = (option_data & (one << ('U' - 39))) ? 1 : 0;
	ls->flags.one = (flags & (one << ('1' + 4))) ? 1 : 0;
}

void			get_set_options(t_ls *ls)
{
	unsigned long	flags;

	if (!ls->argv_options)
		return ;
	ft_printf("%s\n", ls->argv_options[1]);
	flags = ft_options(ls->argv_options);
	ft_printf("flag = %ld\n", flags);
	set_options(ls, flags);
	check_options(ls, flags);
}
