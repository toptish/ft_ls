/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:43:03 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/20 14:37:35 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "../Libft/libft.h"
# include "../Libft/printf.h"
# include <time.h>
# include <sys/ioctl.h>
# include <dirent.h>
# include <time.h>

# define OPTIONS	"-GRalrtx1"
# define SIX_MONTHS	15768000
# define RL_BUFSIZE	1024

/*
** struct winsize
** {
**  unsigned short ws_row;		rows, in characters 
**  unsigned short ws_col;		columns, in characters 
**  unsigned short ws_xpixel;	horizontal size, pixels 
**  unsigned short ws_ypixel;	vertical size, pixels 
** };
*/

/*
** struct stat {
**    dev_t         st_dev;       устройство 
**    ino_t         st_ino;       inode 
**    mode_t        st_mode;      режим доступа 
**    nlink_t       st_nlink;     количество жестких ссылок 
**    uid_t         st_uid;       идентификатор пользователя-владельца 
**    gid_t         st_gid;       идентификатор группы-владельца 
**    dev_t         st_rdev;      тип устройства 
**                                (если это устройство) 
**    off_t         st_size;      общий размер в байтах 
**    blksize_t     st_blksize;   размер блока ввода-вывода 
**                                в файловой системе 
**    blkcnt_t      st_blocks;    количество выделенных блоков 
**    time_t        st_atime;     время последнего доступа 
**    time_t        st_mtime;     время последней модификации 
**    time_t        st_ctime;     время последнего изменения 
** };
*/

typedef struct		s_flags
{
	unsigned char	a		: 1;
	// unsigned char	c		: 1;
	// unsigned char	d		: 1;
	// unsigned char	f		: 1;
	// unsigned char	g		: 1;
	// unsigned char	i		: 1;
	unsigned char	l		: 1;
	// unsigned char	o		: 1;
	// unsigned char	p		: 1;
	unsigned char	r		: 1;
	unsigned char	t		: 1;
	// unsigned char	u		: 1;
	unsigned char	x		: 1;
	// unsigned char	a_upper	: 1;
	// unsigned char	f_upper	: 1;
	unsigned char	g_upper	: 1;
	// unsigned char	n_upper	: 1;
	unsigned char	r_upper	: 1;
	// unsigned char	s_upper	: 1;
	// unsigned char	t_upper	: 1;
	// unsigned char	u_upper	: 1;
	unsigned char	one		: 1;
	unsigned char	fill	: 2;
}					t_flags;

typedef struct		s_item
{
	char			*str;
	char			*path;

	int				len_of_str;

	unsigned char	no_file	: 1;
	unsigned char	fill	: 7;

	long long		ino;
	int				type;
	mode_t			mode;
	int				nlink;
	char			*user;
	char			*group;
	int				rdev;
	int				size;
	time_t			c_time;
	time_t			m_time_t;
	time_t			a_time_u;
	time_t			birth_time_up_u;
	char			sym_path[RL_BUFSIZE + 1];

	unsigned char	ifo		: 1;
	unsigned char	chr		: 1;
	unsigned char	dir		: 1;
	unsigned char	blk		: 1;
	unsigned char	reg		: 1;
	unsigned char	lnk		: 1;
	unsigned char	sock	: 1;
	unsigned char	wht		: 1;
}					t_item;

typedef struct		s_args
{
	t_item			item;
	struct s_args	*next;
}					t_args;

typedef struct		s_ls
{
	int				argc;
	char			**argv;
	char			**argv_options;
	char			*argv_opt_str;
	char			*error;
	// unsigned char	headers	: 1;
	// unsigned char	fill	: 7;
	time_t			cur_time;
	time_t			time_6;
	// int				len_ino;
	// int				len_links;
	// int				len_user;
	// int				len_group;
	// int				len_size;
	// int				len_file_name;
	// int				items_to_display;
	// int				total_blocks;
	int				width;
	int				number_of_columns;
	t_flags			flags;
	t_args			*args;
	t_args			*current_args;
	// t_args			*head;
	// t_args			*track;
	// bool			(*sort_function)(struct s_frame *frame);
}					t_ls;

/*
**	---------------- ft_ls.c ------------------
*/
t_ls			create_ls(int argc, char **argv);
void			ft_ls(t_ls *ls);
/*
**	---------------- parse.c ------------------
*/
void			set_opt_str(t_ls *ls, size_t options_num);
void			parse_options(t_ls *ls, int option);
void			parse_args(t_ls *ls, char **argv);
int				options_num(t_ls *ls);
void			ft_parse(t_ls *ls);
/*
**	---------------- parse_2.c ------------------
*/
t_args			*create_args(void);
/*
**	------------- set_options.c ---------------
*/
unsigned long	illegal_options(t_ls *ls);
void			check_options(t_ls *ls, unsigned long option_data);
void			set_options(t_ls *ls, unsigned long option_data);
void			get_set_options(t_ls *ls);
/*
**	------------ adjust_options.c -------------
*/
void			adjust_options(t_ls *ls);
/*
**	---------------- errors.c -----------------
*/
void			return_error(t_ls *ls, char *error);
/*
**	--------------- free_ls.c -----------------
*/
void			free_ls(t_ls *ls);
void			free_args(t_ls *ls, t_args **start);
void			free_arg(t_ls *ls, t_args *args);
/*
**	-------------- arrange.c ------------------
*/

/*
**	---------------- sort.c ------------------
*/

/*
**	---------------- print.c ------------------
*/
void			print_usage(t_ls *ls, unsigned long illegal_opt);
void			print_item(t_ls *ls, t_args *args);
#endif
