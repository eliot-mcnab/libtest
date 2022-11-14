/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:06:24 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/14 10:14:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Test equality of a variable.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (int): the variable to test.
 * @param val (int): the value the variable should be equal to.
 *
 * @return (bool): true if the value of [var] matches [val], false otherwise.
 */
bool	ft_test_equal(t_unit *unit, int var, int val)
{
	t_str	str_var;
	t_str	str_val;
	bool	success;

	str_var = ft_itoa(var);
	str_val = ft_itoa(val);
	if (var == val)
	{
		ft_countpass(unit -> counter);
		success = true;
	}
	else
	{
		ft_countfail(unit -> counter);
		success = false;
	}
	ft_putendl_fd(ft_message_equal(str_var, str_val, success), STDOUT);
	return (success);
}
