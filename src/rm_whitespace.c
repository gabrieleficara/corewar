/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slynn-ev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:38:54 by slynn-ev          #+#    #+#             */
/*   Updated: 2018/03/10 19:39:21 by slynn-ev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*rm_lead_space(char	*line)
{
	int		i;
	int		j;
	char	*dst;

	j = 0;
	i = 0;
	if (line == NULL)
		return (NULL);
	while ((line[i] == ' ' || line[i] == '\t') && line[i])
		i++;
	if (!(dst = malloc((ft_strlen(line) - i + 1))))
		return (NULL);
	while (line[i])
		dst[j++] = line[i++];
	dst[j] = '\0';
	free(line);
	return(dst);
}

void	remove_leading_whitespaces(t_am *a)
{
	int	i;

	i = 0;
	while (i < a->lc)
	{
		a->lines[i] = rm_lead_space(a->lines[i]);
		i++;
	}
}

