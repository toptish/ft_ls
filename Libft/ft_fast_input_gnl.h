/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fast_input_gnl.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdorcas <gdorcas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/14 16:08:46 by gdorcas           #+#    #+#             */
/*   Updated: 2020/08/14 16:09:58 by gdorcas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FAST_INPUT_GNL_H
# define FT_FAST_INPUT_GNL_H

# define FAST_INPUT_GNL_BUFF_SIZE 8192

typedef struct		s_buff_info
{
	char			*start;
	int				len;
}					t_buff_info;

int					ft_fast_input_gnl(char **line);

#endif