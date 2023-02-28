/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movefastest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maria <maria@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 15:10:56 by mklimina          #+#    #+#             */
/*   Updated: 2023/02/28 01:45:36 by maria            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

algo_values max_pul(algo_values current)
{
    current.rr = 0;
    current.rrr = 0;

    if (current.rb > current.ra && current.ra > 0)
    {
        current.rr = current.ra;
        current.ra = 0;
        current.rb = current.rb - current.rr;
    }
    if (current.ra > current.rb && current.rb > 0)
    {
        current.rr = current.rb;
        current.rb = 0;
        current.ra = current.ra - current.rr;
    }
    if (current.ra == current.rb && (current.ra > 0 && current.rb > 0))
    {
        current.rr = current.rb;
        current.rb = 0;
        current.ra = 0;
    }
    
    // *********
    if (current.rrb > current.rra && current.rra > 0)
    {
        current.rrr = current.rra;
        current.rra = 0;
        current.rrb = current.rrb - current.rrr;
    }
    if (current.rra > current.rrb && current.rrb > 0)
    {
        current.rrr = current.rrb;
        current.rrb = 0;
        current.rra = current.rra - current.rrr;
    }
    if (current.rra == current.rrb && (current.rra > 0 && current.rrb > 0))
    {
        current.rrr = current.rrb;
        current.rrb = 0;
        current.rra = 0;
    }
    return(current);
}
void movefastest(algo_values current, head_a *a, head_a *b)
{

        current = max_pul(current);
        while (current.rr != 0)
        {
            rr(a, b);
            current.rr--;
        }
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
        while (current.rrr != 0)
        {
            rrr(a, b);
            current.rrr--;
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