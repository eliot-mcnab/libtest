/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_cequal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:59:38 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 10:13:49 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 * @brief Test the equality of a variable to a given value with a custom
 * 	equality function.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (t_any): the variable to test.
 * @param val (t_any): the value [var] must equal.
 * @param f_cmp (int(t_any, t_any)): comparison function used to check equality.
 *
 * @return (bool): true if the value of [var] equals [val] according to [f_cmp].
 */
bool	ft_test_cequal(t_unit *unit, t_any var, t_any val, t_f_cmp f_cmp)
{
	if (f_cmp(var, val) == 0)
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
