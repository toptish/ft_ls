/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 00:13:33 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/05 19:50:17 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"

void			ft_hesh_oct(void)
{
	char		*num_hesh;
	int			i;

	i = 0;
	g_pfstr.hesh[1] = '\0';
	num_hesh = ft_strjoin(g_pfstr.hesh, g_pfstr.arr_num);
	while (num_hesh[i])
	{
		g_pfstr.arr_num[i] = num_hesh[i];
		i++;
	}
	g_pfstr.arr_num[i] = '\0';
	g_pfstr.sizeof_num = i;
}

unsigned long	ft_count_int(unsigned long long n, int base)
{
	int			i;

	i = 0;
	while (n)
	{
		n = n / base;
		i++;
		ft_count_int(n, base);
	}
	g_pfstr.sizeof_num = i;
	if (g_pfstr.n_value)
		g_pfstr.sizeof_num++;
	return (i);
}

void			ft_itoa_base(unsigned long long n, int base)
{
	int			i;
	char		mask_x[17];
	char		mask_xx[17];

	ft_strcpy(mask_x, "0123456789abcdef");
	ft_strcpy(mask_xx, "0123456789ABCDEF");
	i = ft_count_int(n, base);
	g_pfstr.arr_num[i] = '\0';
	i--;
	while (n)
	{
		if (g_pfstr.type_conv == 'X')
			g_pfstr.arr_num[i] = mask_xx[n % base];
		else
			g_pfstr.arr_num[i] = mask_x[n % base];
		i--;
		n /= base;
	}
	if (ft_check_is_flag('#') && g_pfstr.type_conv == 'o')
		ft_hesh_oct();
}
