#include "vm.h"

int fun_exit(char *str, t_champs *champs, t_opts *opts)
{
	int i;

	i = -1;
	while ((unsigned int)++i < opts->n_players)
	{
		if (champs[i].name)
			ft_strdel(&champs[i].name);
		if (champs[i].comment)
			ft_strdel(&champs[i].comment);
		if (champs[i].instructions)
			ft_memdel((void**)&champs[i].instructions);
	}
	if (str)
		return (ft_printf("%s\n", str));
	return (1);
}

int	display_intro(t_champs *champs, t_opts opts)
{
	int i;
	int j;

	i = -1;
	j = 0;
	ft_putendl("Introducing contestants...");
	while ((unsigned)++i < opts.n_players)
	{
		ft_putstr("* Player ");
		ft_putnbr(champs[i].player_id);
		ft_putstr(", weighing ");
		ft_putnbr(champs[i].size);
		ft_putstr(" bytes, \"");
		ft_putstr(champs[i].name);
		ft_putstr("\" (\"");
		ft_putstr(champs[i].comment);
		ft_putendl("\") !");
	}
	return(0);
}

void	verbose_zero(t_champs *champ)
{
	ft_putstr("le joueur ");
	ft_putnbr(champ->player_id);
	ft_putstr(" (");
	ft_putstr(champ->name);
	ft_putchar(')');
	ft_putstr(" a gagne\n");	
}

void print_vm_mem(t_vm *vm)
{
    int i;
	int color;

    i = 0;
	color = 1;
    ft_putstr("0x");
    while (i < MEM_SIZE)
    {
        if (i % 64 == 0)
            ft_printf("%#.4x : ", i);
		if (vm->map[i])
			ft_printf("\x1B[3%dm", color);
        if (vm->map[i] < 16)
            ft_putchar('0');
        ft_printf("%hhx", vm->map[i]);
		ft_putstr("\x1B[0m");
        i++;
        if (i % 1 == 0)
            ft_putchar(' ');
        if (i % 64 == 0)
            ft_putchar('\n');
    }
}