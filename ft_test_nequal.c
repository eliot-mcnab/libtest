/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_nequal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:39:08 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/12 17:45:52 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Test NON equality of a variable.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (int): the variable to test.
 * @param val (int): the value the variable should NOT be equal to.
 *
 * @return (bool): true if the value of [var] DOES NOT match [val],
 * 	false otherwise.
 */
bool	ft_test_nequal(t_unit *unit, int var, int val)
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
	ft_test_message(str_var, str_val, success);
	return (success);
}
