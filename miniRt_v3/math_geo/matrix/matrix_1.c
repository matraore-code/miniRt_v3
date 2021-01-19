/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/12 00:52:53 by matraore          #+#    #+#             */
/*   Updated: 2020/12/13 05:04:01 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat3x3		transpose_mat3x3(t_mat3x3 mat)
{
	t_mat3x3	result;

	result.c1.x = mat.c1.x;
	result.c1.y = mat.c2.x;
	result.c1.z = mat.c3.x;
	result.c2.x = mat.c1.y;
	result.c2.y = mat.c2.y;
	result.c2.z = mat.c3.y;
	result.c3.x = mat.c1.z;
	result.c3.y = mat.c2.z;
	result.c3.z = mat.c3.z;
	return (result);
}

/*
** This function inverts a 3x3 matrix
**
** [Rx, Ux, Fx]
** [Ry, Uy, Fy]
** [Rz, Uz, Fz]
*/

t_mat3x3		invert_mat3x3(t_mat3x3 mat)
{
	t_mat3x3	result;
	t_tuple		v_x;
	t_tuple		v_y;
	t_tuple		v_z;

	v_x = create_tuple(mat.c1.x, mat.c2.x, mat.c3.x);
	v_x = scale_tuple((1 / ft_sqr(norm_tuple(v_x))), v_x);
	v_y = create_tuple(mat.c1.y, mat.c2.y, mat.c3.y);
	v_y = scale_tuple((1 / ft_sqr(norm_tuple(v_y))), v_y);
	v_z = create_tuple(mat.c1.z, mat.c2.z, mat.c3.z);
	v_z = scale_tuple((1 / ft_sqr(norm_tuple(v_z))), v_z);
	result.c1 = create_tuple(v_x.x, v_x.y, v_x.z);
	result.c2 = create_tuple(v_y.x, v_y.y, v_y.z);
	result.c3 = create_tuple(v_z.x, v_z.y, v_z.z);
	return (result);
}

/*
** This function multiplies a 3x3 matrix and a 3D vector producing a 3D vector
*/

t_tuple			mult_mat3x3_tuple(t_mat3x3 mat, t_tuple v)
{
	t_tuple		result;
	t_mat3x3	tmp_mat;

	tmp_mat = transpose_mat3x3(mat);
	result.x = dot_tuple(tmp_mat.c1, v);
	result.y = dot_tuple(tmp_mat.c2, v);
	result.z = dot_tuple(tmp_mat.c3, v);
	return (result);
}

/*
** This function multiplies two 3x3 matrices producing a 3x3 matrix
*/

t_mat3x3		mult_mat3x3_mat3x3(t_mat3x3 mat1, t_mat3x3 mat2)
{
	t_mat3x3	result;

	result.c1 = mult_mat3x3_tuple(mat1, mat2.c1);
	result.c2 = mult_mat3x3_tuple(mat1, mat2.c2);
	result.c3 = mult_mat3x3_tuple(mat1, mat2.c3);
	return (result);
}

/*
** This function scales a 3x3 matrix
*/

t_mat3x3		scale_mat3x3(double scalar, t_mat3x3 mat)
{
	t_mat3x3	result;

	result.c1 = scale_tuple(scalar, mat.c1);
	result.c2 = scale_tuple(scalar, mat.c2);
	result.c3 = scale_tuple(scalar, mat.c3);
	return (result);
}
