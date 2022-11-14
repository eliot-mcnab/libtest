/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_true.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:09:28 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/14 10:30:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Test boolean equality of a variable.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (int): the variable to test.
 *
 * @return (bool): true if the value of [var] is true, false otherwise.
 */
bool	ft_test_true(t_unit *unit, int var)
{
	t_str	str_var;
	bool	success;

	str_var = ft_itoa(var);
	if (var != 0)
	{
		ft_countpass(unit -> counter);
		success = true;
	}
	else
	{
		ft_countfail(unit -> counter);
		success = false;
	}
	ft_putendl_fd(ft_message_true(str_var, success), STDOUT);
	return (success);
}
