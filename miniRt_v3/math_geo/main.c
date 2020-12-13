/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matraore <matraore@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 04:04:27 by matraore          #+#    #+#             */
/*   Updated: 2020/12/13 05:05:01 by matraore         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_geo.h"
#include <stdio.h>


int main ()
{
	t_tuple *v = create_tuple(4, 5, 6);
	t_tuple *p = create_tuple(4, 9, 6);
	t_tuple *s = sub_tuple(v, p);
	t_tuple *n = normalize_tuple(v);
	double m = magnetude_tuple(v);
	// printf("v (%.0f %.0f %.0f)\n", v->x, v->y, v->z);
	// printf("%f\n", m);
	// printf("s (%.0f %.2f %.0f)\n", n->x, n->y, n->z);

	// destroy_tuple(&p);
	// if (p == NULL)
	// 	printf("Memoire liberee\n");
	// //t_mat *mat = create_matrix(3);
	//printf("%.2f\n", mat->entries[0]);
	int i = 0;
	//while (mat->entries[i] != '\0')
	//	i++;
	//printf("%d\n", i);
	printf("------------------------------------------\n");
	int j = 0;

	t_mat *mat = create_matrix(4, 4);
	//ROW 0
	set_cell_matrix(mat, 0, 0, 5);
	set_cell_matrix(mat, 0, 1, 1);
	set_cell_matrix(mat, 0, 2, 1);
	set_cell_matrix(mat, 0, 3, 6);
	//ROW 1
	set_cell_matrix(mat, 1, 0, 6);
	set_cell_matrix(mat, 1, 1, 8);
	set_cell_matrix(mat, 1, 2, -5);
	set_cell_matrix(mat, 1, 3, 1);
	//ROW2
	set_cell_matrix(mat, 2, 0, 3);
	set_cell_matrix(mat, 2, 1, 8);
	set_cell_matrix(mat, 2, 2, 4);
	set_cell_matrix(mat, 2, 3, 7);
	//ROW 3
	set_cell_matrix(mat, 3, 2, 7);
	set_cell_matrix(mat, 3, 1, 4);
	set_cell_matrix(mat, 3, 0, 2);
	set_cell_matrix(mat, 3, 3, 6);

	t_mat *mat1 = submatrix(mat, 0, 0);
	t_mat *mat3 = submatrix(mat, 0, 0);
	t_mat *mat6 = matrix_adjoint(mat);
	double inv = is_inversible(mat);
	t_mat *mat4 = inverse_matrix(mat);
 	double co = cofactor_matrix(mat1, 1, 1);
	double deter = determinant_matrix(mat);
	printf("%f \n", inv);
	printf("------------------------------------------Inverse\n");
	while (j < mat4->row)
	{
		i = 0;
		while (i < mat4->col)
		{
			printf("%.5f ", mat4->entries[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}
	printf("------------------------------------------cofactor\n");
	//printf("m = %0.f\n", co);
	printf("determinat = %.0f \n", deter);
	j = 0;
	printf("------------------------------------------ Mat\n");
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
	transpose_matrix(mat);
	printf("------------------------------------------ Transposemat\n");
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
	printf("------------------------------------------mat1\n");
	j = 0;
	while (j < mat1->row)
	{
		i = 0;
		while (i < mat1->col)
		{
			printf("%.0f ", mat1->entries[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}

	printf("------------------------------------------matadjoint\n");
	j = 0;
	while (j < mat6->row)
	{
		i = 0;
		while (i < mat6->col)
		{
			printf("%.0f ", mat6->entries[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}

	printf("------------------------------------------ identity\n");
	v->w = 0;
	t_mat *matrice0 = matrix_identity(4);

	j = 0;
	while (j < matrice0->row)
	{
		i = 0;
		while (i < matrice0->col)
		{
			printf("%.2f ", matrice0->entries[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}

	printf("------------------------------------------ Rotation X\n");
	v->w = 0;
	t_mat *matrice = rotation_x(0.5);

	j = 0;
	while (j < matrice->row)
	{
		i = 0;
		while (i < matrice->col)
		{
			printf("%.2f ", matrice->entries[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}

	printf("------------------------------------------ Rotation Y\n");
	v->w = 0;

	t_mat *matrice1 = rotation_y(0.6);

	j = 0;
	while (j < matrice1->row)
	{
		i = 0;
		while (i < matrice1->col)
		{
			printf("%.2f ", matrice1->entries[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}
	printf("------------------------------------------ Rotation Z\n");
	v->w = 0;

	t_mat *matrice2 = rotation_z(0.78);
	j = 0;
	while (j < matrice2->row)
	{
		i = 0;
		while (i < matrice2->col)
		{
			printf("%.2f ", matrice2->entries[j][i]);
			i++;
		}
		j++;
		printf("\n");
	}

	return(0);
}
