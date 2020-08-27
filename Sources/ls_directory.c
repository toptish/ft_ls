/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_directory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 16:10:35 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/27 17:23:18 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

int				read_directory(t_dir *read_dir)
{
	if ((read_dir->ls->flags.up_a && (ft_strcmp(read_dir->file->d_name, ".")
					&& ft_strcmp(read_dir->file->d_name, "..")))
			|| (read_dir->ls->flags.a && read_dir->file->d_name[0] == '.')
			|| (read_dir->file->d_name[0] != '.'))
	{
		if (!(read_dir->tmp = create_args()))
		{
			free_args(read_dir->ls, &read_dir->head);
			return (0);
		}
		path(read_dir->ls, read_dir->tmp, read_dir->args->item.path,
				read_dir->file->d_name);
		if (!read_dir->head)
			read_dir->head = read_dir->tmp;
		else
			read_dir->last_args->next = read_dir->tmp;
		read_dir->last_args = read_dir->tmp;
	}
	return (1);
}

t_args			*get_directory_contents(t_ls *ls, t_args *args)
{
	t_dir		read_dir;

	read_dir.ls = ls;
	read_dir.args = args;
	read_dir.head = NULL;
	if (!(read_dir.directory = opendir(read_dir.args->item.path)))
	{
		ft_printf("ft_ls: %s: Permission denied\n", read_dir.args->item.str);
		return (NULL);
	}
	while ((read_dir.file = readdir(read_dir.directory)))
	{
		if (!read_directory(&read_dir))
			return (NULL);
	}
	closedir(read_dir.directory);
	return (read_dir.head);
}

void	    		check_headers(t_ls *ls, t_args *head)
{
	t_args			*args;

	args = head;
	while (args && !ls->headers)
	{
		// if (ls->flags.r_upper && args->item.dir && !ls->flags.d)
		// 	ls->headers = 1;
		if (ls->flags.r_upper && args->item.dir)
			ls->headers = 1;
		args = args->next;
	}
}

void				do_ls(t_ls *ls, t_args *args)
{
	t_args			*head;
	t_args			*tmp;

	check_headers(ls, args);
	print_path(ls, args, 1);
	if (!(head = get_directory_contents(ls, args)))
		return ;
	ls->current_args = head;
	get_attributes(ls);
	sort(ls);
	head = ls->current_args;
	loop_valid_dir(ls, head);
	if (ls->flags.r_upper)
	{
		tmp = head;
		while (tmp)
		{
			if (tmp->item.dir && ft_strcmp(tmp->item.str, ".")
					&& ft_strcmp(tmp->item.str, ".."))
				do_ls(ls, tmp);
			tmp = tmp->next;
		}
	}
	free_args(ls, &head);
}