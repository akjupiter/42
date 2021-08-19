/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajupiter <ajupiter@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 17:58:17 by ajupiter          #+#    #+#             */
/*   Updated: 2021/08/13 18:02:34 by ajupiter         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

static void	heapify(int *arr, int n, int i)
{
	int	largest;
	int	l;
	int	r;

	largest = i;
	l = 2 * i + 1;
	r = 2 * i + 2;
	if (l < n && arr[l] > arr[largest])
		largest = l;
	if (r < n && arr[r] > arr[largest])
		largest = r;
	if (largest != i)
	{
		swap(&arr[i], &arr[largest]);
		heapify(arr, n, largest);
	}
}

void	ft_heapsort(int *arr, int n)
{
	int	i;

	i = n / 2 - 1;
	while (i >= 0)
		heapify(arr, n, i--);
	i = n - 1;
	while (i > 0)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i--, 0);
	}
}
