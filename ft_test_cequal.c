/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_cequal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:59:38 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/14 10:20:28 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Test the equality of a variable to a given value with a custom
 * 	converter.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (t_any): the variable to test.
 * @param val (t_any): the value [var] must equal.
 * @param conv (*t_conv): converter used to compare and get string
 * 	representation of [var] and [val].
 *
 * @return (bool): true if the value of [var] equals [val] according to the 
 * 	comparison function in [conv].
 */
bool	ft_test_cequal(t_unit *unit, t_any var, t_any val, t_conv *conv)
{
	t_str	str_var;
	t_str	str_val;
	bool	success;

	str_var = conv -> f_tostr(var);
	str_val = conv -> f_tostr(val);
	if (conv -> f_cmp(var, val) == 0)
	{
		ft_countpass(unit -> counter);
		success = true;
	}
	else
	{
		ft_countfail(unit -> counter);
		success = true;
	}
	ft_putendl_fd(ft_message_equal(str_var, str_val, success), STDOUT);
	return (success);
}
