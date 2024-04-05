/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groka <groka@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:17:05 by groka             #+#    #+#             */
/*   Updated: 2024/04/02 21:55:02 by groka            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/matrices.h"
#include <stdio.h>

bool	is_equal_matrix(t_matrix a, t_matrix b)
{
	int	i;
	int	j;

	if (a.size != b.size)
		return (false);
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			if (a.matrix[i][j] != b.matrix[i][j])
				return (false);
			++j;
		}
		++i;
	}
	return (true);
}

t_matrix	multiply_matrix(t_matrix a, t_matrix b)
{
	t_matrix	res;
	int			i;
	int			j;
	int			k;

	res.size = a.size;
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			k = 0;
			while (k < a.size)
			{
				res.matrix[i][j] += a.matrix[i][k] * b.matrix[k][j];
				++k;
			}
			++j;
		}
		++i;
	}
	return (res);
}

t_tuple	multiply_matrix_tuple(t_matrix a, t_tuple b)
{
	double			res[4];
	const double	tmp[4] = {b.x, b.y, b.z, b.w};
	int				i;
	int				j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		res[i] = 0;
		while (j < 4)
		{
			res[i] += a.matrix[i][j] * tmp[j];
			++j;
		}
		++i;
	}
	return ((t_tuple){res[0], res[1], res[2], res[3]});
}

t_matrix	identity_matrix(void)
{
	const t_matrix	res = {4,
	{1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1}};

	return (res);
}

t_matrix	transpose_matrix(t_matrix a)
{
	t_matrix	res;
	int			i;
	int			j;
	
	res.size = a.size;
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			res.matrix[j][i] = a.matrix[i][j];
			++j;
		}
		++i;
	}
	return (res);
}

double	determinant_matrix(t_matrix a)
{
	if (a.size == 2)
		return (a.matrix[0][0] * a.matrix[1][1] - a.matrix[0][1] * a.matrix[1][0]);
	
	return (0);
}

t_matrix	submatrix(t_matrix a, int row, int col)
{
	t_matrix	res;
	int			i;
	int			j;

	res.size = a.size - 1;
	i = 0;
	while (i < res.size)
	{
		j = 0;
		while (j < res.size)
		{
			if (i < row && j < col)
				res.matrix[i][j] = a.matrix[i][j];
			else if (i < row && j >= col)
				res.matrix[i][j] = a.matrix[i][j + 1];
			else if (i >= row && j < col)
				res.matrix[i][j] = a.matrix[i + 1][j];
			else if (i >= row && j >= col)
				res.matrix[i][j] = a.matrix[i + 1][j + 1];
			++j;
		}
		++i;
	}
	return (res);
}

double	minor_matrix(t_matrix a, int x, int y)
{
	return (determinant_matrix(submatrix(a, x, y)));
}

/// @brief //////////////////////
/// @param a 
void	print_matrix(t_matrix a)
{
	int	i;
	int	j;

	printf("matrix:\n");
	i = 0;
	while (i < a.size)
	{
		j = 0;
		while (j < a.size)
		{
			printf("%f ", a.matrix[i][j]);
			++j;
		}
		printf("\n");
		++i;
	}
}

void	print_tuple(t_tuple a)
{
	printf("%f %f %f %f\n", a.x, a.y, a.z, a.w);
}

int main()
{
	t_matrix a = {4, {1, 2, 3, 4, 2, 3, 4, 5, 3, 4, 5, 6, 4, 5, 6, 7}};
	t_matrix b = {4, {0, 1, 2, 4, 1, 2, 4, 8, 2, 4, 8, 16, 4, 8, 16, 32}};
	t_matrix c = {4, {1, 2, 3, 4, 2, 4, 4, 2, 8, 6, 4, 1, 0, 0, 0, 1}};
	t_matrix d = {4, {0, 9, 3, 0, 9, 8, 0, 8, 1, 8 , 5, 3, 0 , 0, 5, 8}};

	print_matrix(multiply_matrix(a, b));
	print_matrix(c);
	print_tuple(multiply_matrix_tuple(c, (t_tuple){1, 2, 3, 1}));
	print_matrix(a);
	print_matrix(multiply_matrix(a, identity_matrix()));
	print_matrix(d);
	print_matrix(transpose_matrix(d));
	print_matrix(d);
	print_matrix(submatrix(d, 0, 0));
	print_matrix(submatrix(submatrix(d, 0, 0), 0 ,0));

	t_matrix e = {3, {3, 5, 0, 0, 2, -1, -7, 0, 6, -1, 5, 0}};
	print_matrix(e);
	printf("%f\n", minor_matrix(e, 1, 0));
}
