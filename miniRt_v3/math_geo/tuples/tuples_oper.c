/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_oper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:58:41 by matraore          #+#    #+#             */
/*   Updated: 2020/12/11 05:35:46 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"

t_tuple		add_tuple(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x + b.x;
	result.y = a.y + b.y;
	result.z = a.z + b.z;
	return (result);
}

/*
** This function subtracts two 3D vectors
*/

t_tuple		sub_tuple(t_tuple a, t_tuple b)
{
	return (add_tuple(a, rev_dir_tuple(b)));
}

/*
** This function multiplies two 3D vectors
*/

t_tuple		mult_tuple(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x * b.x;
	result.y = a.y * b.y;
	result.z = a.z * b.z;
	return (result);
}

/*
** This function divides two 3D vectors
*/

t_tuple		div_tuple(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = a.x / b.x;
	result.y = a.y / b.y;
	result.z = a.z / b.z;
	return (result);
}

/*
** This function scales a 3D vector
*/

t_tuple		scale_tuple(double scalar, t_tuple v)
{
	t_tuple	result;

	result.x = scalar * v.x;
	result.y = scalar * v.y;
	result.z = scalar * v.z;
	return (result);
}

