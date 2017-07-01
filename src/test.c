/*
** test.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Thu Jun 29 13:34:30 2017 Mathias
** Last update Sat Jul  1 13:33:39 2017 Mathias
*/

#include "calandar.h"

int my_cmp(char *st, char *tr)
{
  int i;

  i = 0;
  while (st[i] != '\0' && tr[i] != '\0')
    {
      if (st[i] != tr[i])
	return (1);
      i += 1;
    }
  if (st[i] == '\0' && tr[i] == '\0')
    return (0);
  return (1);
}

void choice(t_all *all, char *str)
{
  char **tab;
  int i;

  if (is_alphanum(str) == 0)
    {
      i = 0;
      tab = split(str, ' ');
      while (all->com[i] != NULL && my_cmp(tab[0], all->com[i]) != 0)
	i += 1;
      if (all->com[i] != NULL && my_cmp(tab[0], all->com[i]) == 0)
	all->tab[i](tab, str, all);
      free_tab(tab, str, -1);
    }
}

int main(void)
{
  char *str;
  t_all *all;

  all = init_all();
  while ((str = my_gnl(0)) != NULL)
    choice(all, str);
  return (0);
}
