/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:04:27 by matraore          #+#    #+#             */
/*   Updated: 2020/12/12 05:07:38 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tools/tools.h"
#include "tuples/tuples.h"
#include "matrix/matrix.h"
#include <stdio.h>


int main ()
{
	t_tuple *v = create_tuple(4, 5, 6);
	t_tuple *p = create_tuple(4, 9, 6);
	t_tuple *s = sub_tuple(v, p);
	t_tuple *n = normalize_tuple(v);
	double m = magnetude_tuple(v);
	printf("v (%.0f %.0f %.0f)\n", v->x, v->y, v->z);
	printf("%f\n", m);
	printf("s (%.0f %.2f %.0f)\n", n->x, n->y, n->z);

	destroy_tuple(&p);
	if (p == NULL)
		printf("Memoire liberee\n");
	//t_mat *mat = create_matrix(3);
	//printf("%.2f\n", mat->entries[0]);
	int i = 0;
	//while (mat->entries[i] != '\0')
	//	i++;
	//printf("%d\n", i);
	//printf("------------------------------------------\n");
	int j = 0;

	t_mat *mat = create_matrix(4, 4);
	set_cell_matrix(mat, 0, 0, 5);
	set_cell_matrix(mat, 2, 0, 3);
	set_cell_matrix(mat, 1, 2, 9);
	set_cell_matrix(mat, 0, 1, 1);
	set_cell_matrix(mat, 0, 2, 1);
	set_cell_matrix(mat, 2, 1, 8);

	t_mat *mat1 = matrix_clone(mat);
	t_mat *mat3 = submatrix(mat, 0, 0);
	double co = cofactor_matrix(mat, 1, 1);
	double deter = determinant_matrix(mat);
	printf("------------------------------------------cofactor\n");
	printf("m = %0.f\n", co);
	printf("determinat = %.0f \n", deter);

	printf("------------------------------------------AFFICHE 1\n");
	while (j < mat->row)
	{
		i = 0;
		while (i < mat->col)
		{
			printf("%.0f ", mat->entries[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}
	j = 0;
	// transpose_matrix(mat);
	// printf("------------------------------------------mat\n");
	// while (j < mat->row)
	// {
	// 	i = 0;
	// 	while (i < mat->col)
	// 	{
	// 		printf("%.0f ", mat->entries[j][i]);
	// 		i++;
	// 	}
	// 	j++;
	// 	printf("\n");
	// }
	// printf("------------------------------------------mat1\n");
	// j = 0;
	// while (j < mat1->row)
	// {
	// 	i = 0;
	// 	while (i < mat1->col)
	// 	{
	// 		printf("%.0f ", mat1->entries[j][i]);
	// 		i++;
	// 	}
	// 	j++;
	// 	printf("\n");
	// }

	// printf("------------------------------------------mat2\n");
	// t_mat *mat2  = multi_matrix(mat, mat1);
	// j = 0;
	// while (j < mat2->row)
	// {
	// 	i = 0;
	// 	while (i < mat2->col)
	// 	{
	// 		printf("%.0f ", mat2->entries[j][i]);
	// 		i++;
	// 	}
	// 	j++;
	// 	printf("\n");
	// }
	return(0);
}
