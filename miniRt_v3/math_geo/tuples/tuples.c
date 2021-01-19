/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:47:37 by matraore          #+#    #+#             */
/*   Updated: 2020/12/12 23:17:42 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tuples.h"
#include <math.h>


t_tuple		create_tuple(double p_x, double p_y, double p_z)
{
	t_tuple	result;

	result.x = p_x;
	result.y = p_y;
	result.z = p_z;
	return (result);
}

t_tuple		*malloc_tuple(double p_x, double p_y, double p_z)
{
	t_tuple	*result;

	result = malloc(sizeof(t_tuple));
	if (!result)
		return (NULL);
	*result = create_tuple(p_x, p_y, p_z);
	return (result);
}

void		destroy_tuple(t_tuple to_destroy)
{
	(void)to_destroy;
}

void		free_tuple(t_tuple *to_free)
{
	destroy_tuple(*to_free);
	free(to_free);
}
 
double		dot_tuple(t_tuple a, t_tuple b)
{
	return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
}

/*
** This function computes the cross product of two 3D vectors
*/

t_tuple		cross(t_tuple a, t_tuple b)
{
	t_tuple	result;

	result.x = (a.y * b.z) - (b.y * a.z);
	result.y = (a.z * b.x) - (b.z * a.x);
	result.z = (a.x * b.y) - (b.x * a.y);
	return (result);
}
