/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:10:12 by emcnab            #+#    #+#             */
/*   Updated: 2022/11/11 10:23:32 by emcnab           ###   ########.fr       */
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
typedef int		(*t_f_cmp)(t_any, t_any);

t_runner	*ft_runner_create(void);
void		ft_unit_add(t_runner *runner, t_str unit_name, t_tests f_unit_test);
bool		ft_test_equal(t_unit *unit, size_t var, size_t val);
bool		ft_test_strequal(t_unit *unit, t_str var, t_str val);
bool		ft_test_cequal(t_unit *unit, t_any var, t_any val, t_f_cmp f_cmp);
bool		ft_test_success(t_unit *unit);

#endif
