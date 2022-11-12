/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tests_success.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:16:43 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 16:07:39 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Calculates the ratio of successful tests a unit passed.
 *
 * @param unit (t_unit*): the unit that was tested.
 *
 * @return (double): the success ratio of the unit's tests.
 */
double	ft_tests_success(t_unit *unit)
{
	double	tests_total;

	tests_total = ft_countotal(unit -> counter);
	return (unit -> counter -> passed / tests_total);
}
