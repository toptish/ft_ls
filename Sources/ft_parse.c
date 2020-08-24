/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 10:19:18 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/24 15:26:28 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void		set_opt_str(t_ls *ls, size_t options_num)
{
	char			**argv_options;
	char			*str;
	char			*argv_opt_str;

	argv_options = ls->argv_options + 1;
	if (!(argv_opt_str = (char *)malloc((options_num + 1))))
		return_error(ls, "Malloc Error");
	ls->argv_opt_str = argv_opt_str;
	while (*argv_options)
	{
		str = *argv_options;
		str++;
		while (*str)
		{
			*argv_opt_str = *str;
			str++;
			argv_opt_str++;
		}
		argv_options++;
	}
	*argv_opt_str = 0;
}

void		parse_options(t_ls *ls, int option)
{
	char			**argv;
	char			**argv_options;
	size_t			options_num;

	if (!option)
		return ;
	if (!(ls->argv_options = (char **)malloc(sizeof(char *) * (option + 2))))
		return_error(ls, "Malloc Error");
	options_num = 0;
	*ls->argv_options = *ls->argv;
	argv = ls->argv + 1;
	argv_options = ls->argv_options + 1;
	while (*argv && **argv == '-' && argv[0][1])
	{
		*argv_options = *argv;
		options_num += ft_strlen(*argv_options) - 1;
		argv++;
		argv_options++;
	}
	*argv_options = NULL;
	set_opt_str(ls, options_num);
}

void		parse_args(t_ls *ls, char **argv)
{
	t_args			*args;
	t_args			*last_args;

	if (*argv)
		argv++;
	if (!*argv)
	{
		if (!(ls->args = create_args()))
			return_error(ls, "Malloc Error");
		if (!(ls->args->item.str = ft_strdup("."))
				|| !(ls->args->item.path = ft_strdup(".")))
			return_error(ls, "Malloc Error");
	}
	while (*argv)
	{
		if (!(args = create_args()))
			return_error(ls, "Malloc Error");
		// path(ls, args, ".", *argv);
		if (!ls->args)
			ls->args = args;
		else
			last_args->next = args;
		last_args = args;
		argv++;
	}
}

int			options_num(t_ls *ls)
{
	char			**argv;
	int				options;

	options = 0;
	argv = ls->argv + 1;
	while (*argv && **argv == '-' && argv[0][1])
	{
		options++;
		if (!ft_strcmp(*argv, "--"))
			break ;
		argv++;
	}
	return (options);
}

void		ft_parse(t_ls *ls)
{
	int				options_n;

	options_n = options_num(ls);
	parse_options(ls, options_n);
	parse_args(ls, ls->argv + options_n);
	get_set_options(ls);
	adjust_options(ls);
}