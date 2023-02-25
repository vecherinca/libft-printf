/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefastest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:10:56 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/24 03:20:44 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void movefastest(algo_values current, head_a *a, head_a *b)
{
    if (current.ra == current.rb)
    {
        while(current.ra != 0 && current.rb != 0)
        {
            rr(a, b);
            current.ra--;
            current.rb--;
        }
    }
    if (current.rra == current.rrb)
    {
        while(current.rra != 0 && current.rrb != 0)
        {
            rrr(a, b);
            current.rra--;
            current.rrb--;
        }
    }
    else
        while (current.ra != 0)
        {
            ra(a, 1);
            current.ra--;
        }   
        while (current.rb != 0)
        {
            rb(b, 1);
            current.rb--;
        }
        while (current.rra != 0)
        {
            rra(a, 1);
            current.rra--;
        }
        while (current.rrb != 0)
        {
            rrb(b, 1);
            current.rrb--;
        }
}