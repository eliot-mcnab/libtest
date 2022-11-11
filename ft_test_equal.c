/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:06:24 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 09:12:46 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Test equality of a variable.
 *
 * @param var (size_t): the variable to test.
 * @param val (size_t): the value the variable should be equal to.
 *
 * @return (bool): true if the value of [var] matches [val], false otherwise.
 */
bool	ft_test_equal(t_unit *unit, size_t var, size_t val)
{
	if (var == val)
	{
		(unit -> passed)++;
		return (true);
	}
	else
	{
		(unit -> failed)++;
		return (false);
	}
}
