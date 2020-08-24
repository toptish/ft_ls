/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:16:15 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/24 18:38:24 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	print_usage(t_ls *ls, unsigned long illegal_opt)
{
	// char	*illegal_options;
	char	*argv_opt;
	
	argv_opt = ls->argv_opt_str;
	while (*argv_opt)
	{
		if (!ft_strchr(OPTIONS, *argv_opt))
		{
			ft_printf("ft_ls illegal option -- %c\nusage: ft_ls: [", *argv_opt);
			ft_printf(OPTIONS);
			ft_printf("] [file ...]\n");
		}
		argv_opt++;
	}
	illegal_opt = 0;
	return_error(ls, "");
}

void	print_item(t_ls *ls, t_args *args)
{
	t_item	*item;

	item = &args->item;
	// print_ino(ls, args);
	// if (ls->flags.l)
	// {
	// 	print_type(ls, args);
	// 	print_links(ls, args);
	// 	print_user_and_group(ls, args);
	// 	print_size(ls, args);
	// 	print_time(ls, args);
	// }
	// print_file_name(ls, args);
	ft_printf(ls->argv_opt_str);
}
