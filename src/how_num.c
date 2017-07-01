/*
** how_num.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:18:13 2017 Mathias
** Last update Sat Jul  1 13:19:24 2017 Mathias
*/

#include "calandar.h"

void end(char **tab, char *str, t_all *all)
{
  free_all(all);
  free_tab(tab, str, 0);
}

int it_exist(char *str, t_all *all, int ch)
{
  long int nb;
  int i;

  i = 0;
  nb = atol(str);
  if (ch == 0)
    while (all->emp[i] != NULL)
      {
	if (all->emp[i]->id == nb)
	  return (0);
	i += 1;
      }
  else
    while (all->meet[i] != NULL)
      {
	if (all->meet[i]->id == nb)
	  return (0);
	i += 1;
      }
  return (1);
}

int how_num(char **tab, int i, t_all *all)
{
  int count;

  count = 0;
  while (tab[i] != NULL)
    {
      if (is_num(tab[i]) == 0 && it_exist(tab[i], all, 0) == 0)
	count += 1;
      i += 1;
    }
  return (count);
}

void append_int(t_meeting *all, long int nb)
{
  int i;

  i = -1;
  while (all->members[++i] != -1);
  all->members = realloc(all->members, sizeof(long int) * (i + 2));
  all->members[i] = nb;
  all->members[i + 1] = -1;
}

void append_meet(t_all *all, char **tab)
{
  int i;
  int k;

  i = -1;
  while (all->meet[++i] != NULL);
  all->meet = realloc(all->meet, sizeof(*all->meet) * (i + 2));
  all->meet[i] = malloc(sizeof(**all->meet));
  all->meet[i]->place = strcpy(calloc(strlen(tab[1]) + 2,
				      sizeof(char)), tab[1]);
  all->meet[i]->date = strcpy(calloc(strlen(tab[2]) + 2, sizeof(char)), tab[2]);
  all->meet[i]->id = atol(tab[3]);
  all->meet[i + 1] = NULL;
  all->meet[i]->members = malloc(sizeof(long int));
  all->meet[i]->members[0] = -1;
  k = 4;
  while (tab[k] != NULL)
    {
      if (is_num(tab[k]) == 0 && it_exist(tab[k], all, 0) == 0)
	append_int(all->meet[i], atol(tab[k]));
      k += 1;
    }
}
