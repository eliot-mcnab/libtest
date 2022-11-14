/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message_equal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 13:41:12 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/14 10:14:30 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

/*
 * @brief Generates a message summarising the result of an equality test.
 *
 * @param str_var (t_str): string representation of the variable that was
 * 	tested.
 * @param str_val (t_str): string representation of the target value.
 * @param success (bool): true if [str_var] equaled [str_val].
 *
 * @return (t_str): " [str_var] should equal [str_val] - [str_success]"
 */
char	*ft_message_equal(t_str str_var, t_str str_val, bool success)
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
			LPURPLE, " ", WHITE, "\"", str_var, "\"", LGRAY, " should equal ",
			WHITE, "\"", str_val, "\"", LGRAY, " - ", str_success));
}
