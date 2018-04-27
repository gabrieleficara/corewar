#include "vm.h"

void	init_reg(t_champs *champs, t_opts *opts)
{
	int i;

	i = 0;
	champs[opts->n_players].registre[0] = champs[opts->n_players].player_id;
	while (++i < REG_NUMBER)
		champs[opts->n_players].registre[i] = 0;
}

int	parsing_arg_b(char *str, t_opts *opts, int *j, t_champs *champs)
{
	int	k;

	k = 0;
	if (str[k] == '-')
		k++;
	while (str[k] >= '0' && str[k] <= '9')
		k++;
	if (str[k] || (str[0] == '1' && k == 1))
		return (ft_printf("not a number\n"));
	if (*j == 1)
	{
		if (opts->s_cycles != 0)
			return (ft_printf("more than 1 dump command\n"));
		opts->s_cycles = ft_atoi(str);
		*j = 0;
	}
	else
	{
		champs[opts->n_players].player_id = ft_atoi(str);
		*j = -1;
	}
	return (0);
}

int parsing_arg_c(char *av, t_opts *opts, t_champs *champ, int *j)
{
	char *par;

	if (*j > 0)
	{
		if (parsing_arg_b(av, opts, j, champ))
			return (1);
	}
	else if (!ft_strcmp("-dump", av) && *j == 0)
		*j = 1;
	else if (!ft_strcmp("-n", av) && *j == 0)
		*j = 2;
	else if (ft_strcmp(av, ".cor") &&
			(par = ft_strstr(av, ".cor")) && *j < 1)
	{
		if (ft_strcmp(".cor",par) || par[-1] == '/')
			return(ft_printf("invalid player"));
		champ[opts->n_players].file_name = av;
		champ[opts->n_players].alive = 0;
		//champ[opts->n_players].op = g_optab[16];
		if (champ[opts->n_players].player_id == 0)
			champ[opts->n_players].player_id = 1 + opts->n_players;
		init_reg(champ, opts);
		opts->n_players++;
		if (opts->n_players> MAX_PLAYERS)
			return (ft_printf("too many player\n"));
		*j = 0;
	}
	else
		return (ft_printf("invalid player\n"));
	return (0);
}

int	parsing_arg_a(int ac, char **av, t_opts *opts, t_champs *champ)
{
	int	i;
	int j;


	i = 0;
	j = 0;
	while (++i < ac && opts->n_players < MAX_PLAYERS)
		if (parsing_arg_c(av[i], opts, champ, &j))
			return (1);
	if (1 == ac || opts->n_players == 0 || j != 0)
		return (ft_printf((j == 0) ? "no player\n" : "missing player"));
	return (0);
}

int	main(int ac, char **av)
{
	t_opts opts;
	t_champs champs[MAX_PLAYERS];
	t_vm vm;
	unsigned int i;
	int j;

	i = 0;
	j = -1;
	while (++j < MAX_PLAYERS)
		champs[j].player_id = 0;
	if (MAX_PLAYERS <= 0)
		ft_printf("MAX_PLAYERS not properly defined");
	opts.s_cycles = 0;
	opts.n_players = 0;
	if (parsing_arg_a(ac, av, &opts, champs))
		return (1);
	while (i < opts.n_players)
	{
		ft_printf("player %s id %d\n", champs[i].file_name, champs[i].player_id);
		i++;
	}
	ft_printf("number of player: %d\n", opts.n_players);
	if (oc_file(champs, &opts) > 0)
		return (fun_exit(NULL, champs, &opts));
	if (init_vm(champs, &opts, &vm))
		return (fun_exit(NULL, champs, &opts));
	return (0);
}
