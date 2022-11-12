/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coverage_reached.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:32:02 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 16:41:33 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Determines if a counter reached its required threshold of test
 * 	coverage.
 *
 * @param counter (t_counter *): the counter which counted the tests.
 *
 * @return (bool): true if the counter reached its required coverage threshold,
 * 	false otherwise.
 */
bool	ft_coverage_reached(t_counter *counter)
{
	return (ft_coverage(counter) > counter -> threshold);
}
