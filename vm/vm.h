#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"

# define NO_CHAMP	"missing champion"
# define OPEN_CHAMP	"failed to open .cor"
# define PARSE_CHAMP	"failed to read .cor"
# define SIZE_CHAMP	"champion size over max size"
# define MAX_CHAMPS	"too many champions"
# define VERBOSE	"verbosity level: 0, 1, 2, 4, 8, 16"

typedef struct	

typedef struct		s_opts
{
	unsigned int	aff_mode;
	unsigned int	n_cycles;
	unsigned int	s_cycles;
//	unsigned int	player_id;
	unsigned int	n_players;
	unsigned int	verbosity;
}			t_opts;

typedef struct		s_champ
{
	int		player_id;
	unsigned int	size;
	char		*name;
	char		*comment;
	unsigned short	*buffer;
};

void			parse_args(int ac, char **av, t_opts *opts);
void			display_intro(t_champ *champs, t_opts, opts);
void			verbose_zero(t_champ *champ);
void			verbose_one(t_champ *champs);
#endif