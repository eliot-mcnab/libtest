/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_beq.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:05:41 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/14 11:12:34 by emcnab           ###   ########.fr       */
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
 * @param success (bool): true if [str_var] and [str_val] were true or
 * 	[str_var] and [str_val] were false.
 *
 * @return (t_str): " [str_var] && [str_val] should have same boolean value - 
 * 	[str_success]"
 */
static char	*ft_message_beq(t_str str_var, t_str str_val, bool success)
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
			"\"", str_val, "\"", LGRAY, " should have same boolean value- ",
			str_success));
}

/*
 * @brief Tests variable boolean equality.
 *
 * @param unit (t_unit *): the unit to which the tests are applied.
 * @param var (int): variable to test.
 * @param val (int): value to test.
 *
 * @return (bool): true if [var] and [val] are true or [var] and [val] are 
 * 	false.
 */
bool	ft_test_beq(t_unit *unit, int var, int val)
{
	t_str	str_var;
	t_str	str_val;
	bool	sucess;

	str_var = ft_itoa(var);
	str_val = ft_itoa(val);
	if ((var && val) || (!var && !val))
	{
		ft_countpass(unit -> counter);
		sucess = true;
	}
	else
	{
		ft_countfail(unit -> counter);
		sucess = false;
	}
	ft_putendl_fd(ft_message_beq(str_var, str_val, sucess), STDOUT);
	return (sucess);
}
