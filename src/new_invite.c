/*
** new_invite.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:20:10 2017 Mathias
** Last update Sat Jul  1 14:18:56 2017 Mathias
*/

#include "calandar.h"

void new_meeting(char **tab, char *str, t_all *all)
{
  int i;

  i = -1;
  str[0] = str[0];
  while (tab[++i] != NULL);
  if (i >= 6)
    if (is_num(tab[3]) == 0)
      if (how_num(tab, 4, all) >= 2)
	append_meet(all, tab);
}

int not_in_it(t_all *all, int i, long int sv)
{
  int k;

  k = -1;
  while (all->meet[i]->members[++k] != -1)
    if (all->meet[i]->members[k] == sv)
      return (1);
  return (0);
}

void invite(char **tab, char *str, t_all *all)
{
  int i;
  int sv;

  i = -1;
  str[0] = str[0];
  while (tab[++i] != NULL);
  if (i >= 3)
    if (it_exist(tab[1], all, 1) == 0 && (i = -1) < 0)
      {
	sv = atol(tab[1]);
	while (all->meet[++i] != NULL && all->meet[i]->id != sv);
	sv = i;
	i = 2;
	while (tab[i] != NULL)
	  {
	    if (it_exist(tab[i], all, 0) == 0 && is_num(tab[i]) == 0 &&
		not_in_it(all, sv, atol(tab[i])) == 0)
	      append_int(all->meet[sv], atol(tab[i]));
	    i += 1;
	  }
      }
}

void free_meeting(t_all *all, int rank)
{
  free(all->meet[rank]->date);
  free(all->meet[rank]->place);
  free(all->meet[rank]->members);
  free(all->meet[rank]);
}

int check_meeting(t_all *all, long int rank)
{
  int i;

  i = -1;
  while (all->meet[rank]->members[++i] != -1);
  if (i <= 1)
    return (1);
  return (0);
}
