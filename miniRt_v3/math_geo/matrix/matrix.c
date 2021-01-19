/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 05:40:26 by matraore          #+#    #+#             */
/*   Updated: 2020/12/13 00:03:30 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "matrix.h"

t_mat3x3		create_mat3x3(t_tuple a, t_tuple b, t_tuple c)
{
	t_mat3x3	result;

	result.c1 = a;
	result.c2 = b;
	result.c3 = c;
	return (result);
}

t_mat3x3		*malloc_mat3x3(t_tuple a, t_tuple b, t_tuple c)
{
	t_mat3x3	*result;

	result = malloc(sizeof(t_mat3x3));
	if (!result)
		return (NULL);
	*result = create_mat3x3(a, b, c);
	return (result);
}

void			destroy_mat3x3(t_mat3x3 to_destroy)
{
	free_tuple(&to_destroy.c1);
	free_tuple(&to_destroy.c2);
	free_tuple(&to_destroy.c3);
}

void			free_mat3x3(t_mat3x3 *to_free)
{
	destroy_mat3x3(*to_free);
	free(to_free);
}