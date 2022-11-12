/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:06:24 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 15:48:12 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Test equality of a variable.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (size_t): the variable to test.
 * @param val (size_t): the value the variable should be equal to.
 *
 * @return (bool): true if the value of [var] matches [val], false otherwise.
 */
bool	ft_test_equal(t_unit *unit, size_t var, size_t val)
{
	t_str	str_var;
	t_str	str_val;
	bool	success;

	str_var = ft_itoa(var);
	str_val = ft_itoa(val);
	if (var == val)
	{
		(unit -> passed)++;
		success = true;
	}
	else
	{
		(unit -> failed)++;
		success = false;
	}
	ft_putendl_fd(ft_test_message(str_var, str_val, success), STDOUT);
	return (success);
}
