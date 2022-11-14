/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:33:52 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/14 10:48:08 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Generates a message summarising the result of a boolean test.
 *
 * @param str_var (t_str): string representation of the variable that was
 * 	tested.
 * @oaram str_val (t_str): string representation of the variable that was
 * 	tested.
 * @param success (bool): true if [str_var] and [str_val] were true.
 *
 * @return (t_str): " [str_var] && [str_val] should be true - [str_success]"
 */
static char	*ft_message_and(t_str str_var, t_str str_val, bool success)
{
	t_str	str_success;

	if (success)
	{
		str_success = SUCCEESS;
	}
	else
	{
		str_success = FAILURE;
	}
	return (ft_strnjoin(15,
			LPURPLE, " ", WHITE, "\"", str_var, "\"", LGRAY, " && ", WHITE,
			"\"", str_val, "\"", LGRAY, " should be true - ", str_success));
}

/*
 * @brief Tests variable boolean equality.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (int): variable to test.
 * @param val (int): value to test.
 *
 * @return (bool): true if [var] and [val] are true.
 */
bool	ft_test_and(t_unit *unit, int val, int var)
{
	t_str	str_var;
	t_str	str_val;
	bool	sucess;

	str_var = ft_itoa(var);
	str_val = ft_itoa(val);
	if (val && var)
	{
		ft_countpass(unit -> counter);
		sucess = true;
	}
	else
	{
		ft_countfail(unit -> counter);
		sucess = true;
	}
	ft_putendl_fd(ft_message_and(str_var, str_val, sucess), STDOUT);
	return (sucess);
}
