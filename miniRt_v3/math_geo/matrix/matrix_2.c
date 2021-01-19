/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 03:13:43 by matraore          #+#    #+#             */
/*   Updated: 2021/01/19 16:29:46 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

double      ft_sqr(double a)
{
    return (a * a);
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