/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrange.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 15:31:58 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/25 09:44:24 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void			get_sym_path(t_args *args)
{
	int				len;
	t_item			*item;

	item = &args->item;
	if ((len = readlink(item->path, item->sym_path, RL_BUFSIZE)) != -1)
		item->sym_path[len] = '\0';
}

void			get_type(t_args *args)
{
	int				type;

	type = args->item.type;
	if ((DT_LNK & type) == DT_LNK)
	{
		args->item.lnk = 1;
		get_sym_path(args);
	}
	else if ((DT_SOCK & type) == DT_SOCK)
		args->item.sock = 1;
	else if ((DT_REG & type) == DT_REG)
		args->item.reg = 1;
	else if ((DT_WHT & type) == DT_WHT)
		args->item.wht = 1;
	else if ((DT_FIFO & type) == DT_FIFO)
		args->item.fifo = 1;
	else if ((DT_CHR & type) == DT_CHR)
		args->item.chr = 1;
	else if ((DT_DIR & type) == DT_DIR)
		args->item.dir = 1;
	if ((DT_BLK & type) == DT_BLK)
		args->item.blk = 1;
}

void			get_user_group(t_ls *ls, t_args *args, struct stat *f)
{
	struct group	*group;
	struct passwd	*passwd;

	if ((passwd = getpwuid(f->st_uid)))
		(args->item.user = ft_strdup(passwd->pw_name));
	else
		args->item.user = ft_itoa(f->st_uid);
	if (!args->item.user)
		args->item.user = ls->error;
	if ((group = getgrgid(f->st_gid)))
		args->item.group = ft_strdup(group->gr_name);
	else
		args->item.group = ft_itoa(f->st_gid);
	if (!args->item.group)
		args->item.group = ls->error;
}

void			read_f(t_ls *ls, t_args *args, struct stat *f)
{
	ls->blocks += f->st_blocks;
	args->item.ino = f->st_ino;
	args->item.mode = f->st_mode;
	args->item.type = f->st_mode;
	args->item.nlink = f->st_nlink;
	get_user_group(ls, args, f);
	args->item.rdev = f->st_rdev;
	args->item.size = f->st_size;
	args->item.c_time = f->st_ctimespec.tv_sec;
	args->item.m_time_t = f->st_mtimespec.tv_sec;
	args->item.a_time_u = f->st_atimespec.tv_sec;
	args->item.birth_time_up_u = f->st_birthtimespec.tv_sec;
	get_type(args);
}

/*
** in:		t_ls
** out:		void
** desc:	initiates ls structure, allocates memory for it, sets time, gets window_size info
*/
void			arrange_ls_data(t_ls *ls)
{
	t_args			*args;
	struct stat		file;

	args = ls->current_args;
	while (args)
	{
		if (!lstat(args->item.path, &file))
			read_f(ls, args, &file);
		else
			args->item.no_file = 1;
		args = args->next;
	}
	ls->current_args = ls->args;
	sort(ls);
	ls->args = ls->current_args;
	// check_headers(ls);
	// distribution(ls);
}