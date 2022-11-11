/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:10:12 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 09:51:15 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTEST_H
# define LIBTEST_H

# include "libft.h"

typedef struct s_runner
{
	t_list	*units_head;
	t_list	*units_last;
}	t_runner;

typedef struct s_unit
{
	t_str	name;
	bool	(*f_tests)(struct s_unit *);
	size_t	passed;
	size_t	failed;
}	t_unit;

typedef bool	(*t_tests)(t_unit*);

t_runner	*ft_runner_create(void);
void		ft_unit_add(t_runner *runner, t_str unit_name, t_tests f_unit_test);
bool		ft_test_equal(t_unit *unit, size_t var, size_t val);
bool		ft_test_strequal(t_unit *unit, t_str var, t_str val);

#endif
