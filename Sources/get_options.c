/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_options.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 22:51:32 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/17 14:11:39 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_ls.h"

void	get_options(t_frame *frame)
{
	unsigned long	flags;

	if (!frame->argv_options)
		return ;
	flags = ft_options(frame->argv_options);
	fetch_options(frame, flags);
	options_error_check(frame, flags);
}