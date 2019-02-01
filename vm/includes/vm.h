/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcruz-y- <jcruz-y-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:56:52 by jcruz-y-          #+#    #+#             */
/*   Updated: 2019/02/01 14:58:28 by tholzheu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "../../assembler/includes/op.h"
# include "../../assembler/includes/assembler.h"
# include <ncurses.h>

typedef struct		s_flag
{
	int				dump_bl;
	int				cycles;
	int				n_bl;
	int				n_num;
	int				interactive;
}					t_flag;

typedef struct		s_inst
{
	int 			counter;
	int				op_code;
	unsigned char	ebyte;
	int				args[3];
}					t_inst;

typedef struct		s_player
{
	int				reg[16];
	int				carry;
	int				life_bl;
	int				dead;
	int				xy[2];   //start location
	int				pc;
	int				pnum;
	
	t_inst			*inst;
	int				prog_size;
	char			*name;
	char			*comment;
	char			*prog;
	struct s_player *nx;
}					t_player;

typedef struct	s_arena
{
	//char		arena[64][MEM_SIZE / 64];
	char		memory[MEM_SIZE];
	int			num_plys;
	int			cycle_to_die;
	int			total_cycles;
	int			cycle_counter;
	int			checkup_counter;
	int			live_counter;
	t_flag		*flags;
	int			last_alive;
	
}				t_arena;

typedef struct			s_windows
{
	WINDOW				*win;
	struct s_windows	*next;
}						t_windows;

typedef			int t_inst_funct(t_player *player, t_arena *arena);

/*
**	save_inst
*/
int				save_inst(t_player *player, t_arena *arena);

#endif
