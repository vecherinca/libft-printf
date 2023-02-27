/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefastest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:10:56 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/27 03:22:48 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void movefastest(algo_values current, head_a *a, head_a *b)
{
        // if (current.ra == current.rb)
        // {
        //     int rr_val;
        //     rr_val = current.ra;
        //     while (rr_val != 0)
        //     {
        //         rr(a, b);
        //         rr_val--;
        //     }
        // }
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