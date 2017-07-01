/*
** cmp.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:26:20 2017 Mathias
** Last update Sat Jul  1 13:27:35 2017 Mathias
*/

#include "calandar.h"

int my_cmp_mod(char *st, char *tr)
{
  int i;

  i = 0;
  while (st[i] != '\0' && tr[i] != '\0')
    {
      if (st[i] > tr[i])
	return (1);
      else if (st[i] < tr[i])
	return (-1);
      i += 1;
    }
  return (0);
}

int my_cmp_date(char *date, char *cmp)
{
  int i;
  int sv;

  i = strlen(date) - 4;
  if ((sv = my_cmp_mod(&date[i], &cmp[i])) == 0)
    if ((sv = my_cmp_mod(&date[i - 3], &cmp[i - 3])) == 0)
      return (my_cmp_mod(date, cmp));
    else
      return (sv);
  else
    return (sv);
}

void sort_emp_meet(long int *tab, t_all *all)
{
  int i;
  long int tmp;
  int sv;

  i = -1;
  while (tab[++i] != -1 && tab[i + 1] != -1)
    if ((sv = my_cmp_date(all->meet[tab[i]]->date,
			  all->meet[tab[i + 1]]->date)) == 1)
      {
	tmp = tab[i];
	tab[i] = tab[i + 1];
	tab[i + 1] = tmp;
	i = -1;
      }
    else if (sv == 0)
      if ((sv = my_cmp_mod(all->meet[tab[i]]->place,
			   all->meet[tab[i + 1]]->place)) == 1)
	{
	  tmp = tab[i];
	  tab[i] = tab[i + 1];
	  tab[i + 1] = tmp;
	  i = -1;
	}
}

void switch_emp(long int *tab, int i)
{
  long int tmp;

  tmp = tab[i];
  tab[i] = tab[i + 1];
  tab[i + 1] = tmp;
  i = -1;
}

void sorte_id(long int *tab, t_all *all)
{
  int i;

  i = -1;
  while (tab[++i] != -1 && tab[i + 1] != -1)
    if (all->emp[tab[i]]->id > all->emp[tab[i + 1]]->id)
      switch_emp(tab, i);
}
