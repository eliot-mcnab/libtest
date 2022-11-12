/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coverage.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:33:09 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 16:39:10 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Determies test coverage as logged by a [counter].
 *
 * @param counter (t_counter *): the counter which counted successful tests.
 *
 * @return (double): test coverage as counted by [counter].
 */
double	ft_coverage(t_counter *counter)
{
	double	tests_total;

	tests_total = ft_countotal(counter);
	return (counter -> passed / tests_total);
}
