/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tholzheu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 10:55:08 by tholzheu          #+#    #+#             */
/*   Updated: 2019/01/31 14:49:24 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		init_inst_funct(t_inst_funct inst_functions[16])
{
	inst_functions[0] = &inst_live;
	inst_functions[1] = &inst_ld;
	inst_functions[2] = &inst_st;
	inst_functions[3] = &inst_add;
	inst_functions[4] = &inst_sub;
	inst_functions[5] = &inst_and;
	inst_functions[6] = &inst_or;
	inst_functions[7] = &inst_xor;
	inst_functions[8] = &inst_zjmp;
	inst_functions[9] = &inst_ldi;
	inst_functions[10] = &inst_sti;
	inst_functions[11] = &inst_fork;
	inst_functions[12] = &inst_lld;
	inst_functions[13] = &inst_lldi;
	inst_functions[14] = &inst_lfork;
	inst_functions[15] = &inst_aff;
}

void			loop(t_player *players, t_arena *arena)
{
	t_player		*cur;
	t_inst_funct	inst_functions[16];

	init_inst_funct(inst_functions);
	/*init arena if not initialized*/
	while (cycle_to_die >= 0)
	{
		cur = players;
		while (cur)
		{
			if (cur->inst->counter == -1) // if it's -1 it means to save inst
				save_inst(cur, arena);
			else if (cur->inst->counter == 0)
				inst_functions[cur->inst->op_code - 1](cur, arena);
			else
				cur->inst->counter--;
			cur = cur->next;
		}
		if (arena->cycle_counter == arena->cycle_to_die)
			if (live_checkup() == -1)
				return ;
		arena->cycle_counter++;
		arena->total_cycles++;
	}
}
