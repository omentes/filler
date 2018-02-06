/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apakhomo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 13:02:30 by apakhomo          #+#    #+#             */
/*   Updated: 2018/02/03 13:02:31 by apakhomo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <unistd.h>
# include "../libft/include/libft.h"

typedef struct	s_fill
{
	char	xo;
	int		map_size[2];
	char	**map;
	int		bit_size[2];
	char	**bit;
}				t_fill;


void			start_filler(void);
void			start_play(t_fill *game);
void			read_map(t_fill *game);

#endif
