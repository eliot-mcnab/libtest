/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_runner_success.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 11:11:23 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 11:20:38 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Calculates the ratio of units in a runner whose tests were all
 * 	successful.
 *
 * @param runner (t_runner*): the runner containing the units.
 *
 * @return (double): the success ratio of the units in the runner.
 */
double	ft_runner_success(t_runner *runner)
{
	double	units_total;

	units_total = runner -> passed + runner -> failed;
	return (units_total / runner -> failed);
}
