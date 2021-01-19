/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 03:13:43 by matraore          #+#    #+#             */
/*   Updated: 2020/12/13 03:18:26 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

void			cpy_mat3x3(t_mat3x3 *dst, t_mat3x3 src)
{
	cpy_tuple(&(dst->c1), src.c1);
	cpy_tuple(&(dst->c2), src.c2);
	cpy_tuple(&(dst->c3), src.c3);
}

/*
** This function creates a 3x3 identity matrix
*/

t_mat3x3		identity_mat3x3(void)
{
	t_mat3x3	result;

	result.c1 = create_tuple(1.0, 0.0, 0.0);
	result.c2 = create_tuple(0.0, 1.0, 0.0);
	result.c3 = create_tuple(0.0, 0.0, 1.0);
	return (result);
}