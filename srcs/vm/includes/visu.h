#ifndef VISU_H
# define VISU_H

#include <locale.h>
#include <stdint.h>
#include <stdlib.h>

# include "corewar.h"

typedef struct s_win t_win;
typedef struct s_visu_env t_visu_env;
typedef struct s_coord t_coord;

#define HEX_DIGIT "0123456789ABCDEF"

# define F_RELOAD	0x01
# define F_QUIT		0x02

#define T_1		L"┌─┐┌─┐┬─┐┌─┐┬ ┬┌─┐┬─┐"
#define T_2		L"│  │ │├┬┘├┤ │││├─┤├┬┘"
#define T_3		L"└─┘└─┘┴└─└─┘└┴┘┴ ┴┴└─"
#define T_4		L"2018 fchanal dlavaury sdjeghba"

#define H_1		",d88b.d88b,"
#define H_2		"88888888888"
#define H_3		"`Y8888888Y'"
#define H_4		"  `Y888Y'"
#define H_5		"    `Y'"

#define COLOR_P1	COLOR_RED
#define COLOR_P2	COLOR_BLUE
#define COLOR_P3	COLOR_GREEN
#define COLOR_P4	COLOR_CYAN

struct s_coord
{
	int		y;
	int		x;
};

struct s_win
{
	WINDOW *title;
	WINDOW *usages;
	WINDOW *stats;
	WINDOW *states;
	WINDOW *arena;
};

struct s_visu_env
{
	int		event_flag;
	t_coord	w_size;
	t_win	w;

};

void	draw_basics(t_visu_env *env);
void	fill_arena(t_core *c, t_visu_env *env); // make proper
void	fill_title(t_visu_env *env);
void	fill_states(t_core *c, t_visu_env *env);

char	*ft_get_hex_memory(void *m, size_t mem_size);
void	ft_bzero(void *m, size_t len);

#endif
