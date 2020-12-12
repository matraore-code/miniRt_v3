/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuple_and_matrice.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 05:40:08 by matraore          #+#    #+#             */
/*   Updated: 2020/12/12 06:16:40 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat		*tuple_to_matrix(t_tuple p)
{
	t_mat	*mat;

	m = create_matrix(4, 1);
	mat->d[0][0] = p.x;
	mat->d[1][0] = p.y;
	mat->d[2][0] = p.z;
	mat->d[3][0] = p.w;
	return (mat);
}

t_tuple		*matrix_to_tuple(t_mat *mat)
{
	t_tuple	*p;

	p = create_tuple(mat->d[0][0], mat->d[1][0], mat->d[2][0], mat->d[3][0]);
	return (p);
}

t_tuple		*matrix_x_tuple(t_mat *mat, t_tuple p)
{
	t_tuple	*v;
	t_mat	*tmp;
	t_mat	*m;

	tmp = tuple_to_matrix(p);
	m = multi_matrix(mat, tmp);
	destroy_matrix(tmp);
	v = matrix_to_tuple(m);
	destroy_matrix(m);
	return (v);
}

t_tuple		*transformation(t_tuple *pt, t_mat a, t_mat b, t_mat c)
{
	t_tuple	*tuple;
	t_mat	*t;
	t_mat	*p;

	t = multi_matrix(b, a);
	p = multi_matrix(C, T);
	tuple = matrix_x_tuple(p, pt);
	return (tuple);
}
