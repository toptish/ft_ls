/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:19:40 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/25 09:43:54 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

/*
** in:		int argc, char **argv
** out:		t_ls ls
** desc:	initiates ls structure, allocates memory for it, sets time, gets window_size info
*/
t_ls		create_ls(int argc, char **argv)
{
	t_ls	ls;
	struct winsize	window_size;

	ft_bzero(&ls, sizeof(ls));
	ls.argc = argc;
	ls.argv = argv;
	if (!(ls.error = ft_strdup("Memory allocation error")))
	 	exit(1);
	time(&ls.cur_time);
	ls.time_6 = ls.cur_time - SIX_MONTHS;
	// if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &window_size) == -1)
	// 	ls.flags.one = 1;
	if (ioctl(0, TIOCGWINSZ, &window_size) == -1)
		ls.flags.one = 1;
	ls.width = window_size.ws_col;
	return (ls);
}

int			main(int argc, char **argv)
{
	t_ls	ls;

	ls = create_ls(argc, argv);
	ft_parse(&ls);
	arrange_ls_data(&ls);
	free_ls(&ls);
	return (0);
}
