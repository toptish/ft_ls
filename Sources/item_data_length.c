/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_data_length.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:22:39 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/27 13:45:50 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void				len_ino(t_ls *ls, t_args *args)
{
	int				len;
	long long		num;

	len = 1;
	num = args->item.ino;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (len > ls->len_ino)
		ls->len_ino = len;
}

void				len_group(t_ls *ls, t_args *args)
{
	int				len;

	len = ft_strlen(args->item.group);
	if (len > ls->len_group)
		ls->len_group = len;
}

void				len_file_name(t_ls *ls, t_args *args)
{
	int				len;
	t_item			*item;

	item = &args->item;
	len = ft_strlen(item->str);
	item->len_of_str = len;
	// if (ls->flags.up_f && (item->dir || item->lnk || item->sock || item->wht
	// 			|| item->fifo || is_executeable(args)))
	// 	item->len_of_str++;
	// else if (ls->flags.p && item->dir)
	// 	item->len_of_str++;
	// if (ls->flags.up_f || ls->flags.p)
	// 	len++;
	if (len > ls->len_file_name)
		ls->len_file_name = len;
}

void				len_links(t_ls *ls, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->item.nlink;
	while (num >= 10)
	{
		num /= 10;
		len++;
	}
	if (len > ls->len_links)
		ls->len_links = len;
}

void				len_size(t_ls *ls, t_args *args)
{
	int				len;
	int				num;

	len = 1;
	num = args->item.size;
	if (args->item.chr)
		len = 8;
	else
		while (num >= 10)
		{
			num /= 10;
			len++;
		}
	if (len > ls->len_size)
		ls->len_size = len;
}