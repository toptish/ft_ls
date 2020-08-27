/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_data_length2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 16:27:15 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/27 13:45:53 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void				calc_len_user(t_ls *ls, t_args *args)
{
	int				len;

	len = ft_strlen(args->item.user);
	if (len > ls->len_user)
		ls->len_user = len;
}

void				calculate_number_of_columns(t_ls *ls)
{
	int				column_width;

	column_width = ls->len_file_name + 1;
	// if (ls->flags.i)
	// 	column_width += ls->len_ino + 1;
	ls->number_of_columns = ls->width / column_width;
}