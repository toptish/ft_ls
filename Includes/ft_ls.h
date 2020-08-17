/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 17:43:03 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/17 14:11:47 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
#include "libft.h"

struct winsize		g_winsize;

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
	// unsigned char	x		: 1;
	// unsigned char	a_upper	: 1;
	// unsigned char	f_upper	: 1;
	// unsigned char	g_upper	: 1;
	// unsigned char	n_upper	: 1;
	unsigned char	r_upper	: 1;
	// unsigned char	s_upper	: 1;
	// unsigned char	t_upper	: 1;
	// unsigned char	u_upper	: 1;
	unsigned char	one		: 1;
	unsigned char	fill	: 2;
}					t_flags;

#endif
