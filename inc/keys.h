/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aannara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 13:26:48 by aannara           #+#    #+#             */
/*   Updated: 2019/11/25 16:38:27 by aannara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# include "rt.h"

void	key_left_right(int key, t_mlx *m);
void	key_up_down(int key, t_mlx *m);
void	key_i_k_j_l(int key, t_mlx *m);
void	key_z_x_c_v(int key, t_mlx *m);
void	num_plus(int key, t_mlx *m);

#endif
