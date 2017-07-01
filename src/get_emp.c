/*
** get_emp.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:24:41 2017 Mathias
** Last update Sat Jul  1 14:11:03 2017 Mathias
*/

#include "calandar.h"

long int *append_intl(long int *tab, long int nb)
{
  int i;

  i = -1;
  while (tab[++i] != -1);
  tab = realloc(tab, sizeof(long int) * (i + 2));
  tab[i] = nb;
  tab[i + 1] = -1;
  return (tab);
}

long int *get_all_emp(t_all * all)
{
  long int *tab;
  int i;

  tab = malloc(sizeof(long int));
  tab[0] = -1;
  i = 0;
  while (all->emp[i] != NULL)
    {
      tab = append_intl(tab, all->emp[i]->id);
      i += 1;
    }
  return (tab);
}

long int *get_them_emp(t_all *all, char **emp)
{
  long int *tab;
  int i;

  tab = malloc(sizeof(long int));
  tab[0] = -1;
  i = 2;
  while (emp[i] != NULL)
    {
      if (is_num(emp[i]) == 0 && it_exist(emp[i], all, 0) == 0)
	tab = append_intl(tab, atol(emp[i]));
      i += 1;
    }
  return (tab);
}

void sort_it(long int *tab, t_all *all)
{
  int i;
  int count;

  i = 0;
  while (tab[i] != -1)
    {
      count = 0;
      while (all->emp[count] != NULL)
	{
	  if (all->emp[count]->id == tab[i])
	    break;
	  count += 1;
	}
      tab[i] = count;
      i += 1;
    }
}

long int *get_emp_meet(t_all *all, long int id)
{
  int i;
  long int *tab;
  int count;

  tab = malloc(sizeof(long int));
  tab[0] = -1;
  i = 0;
  while (all->meet[i] != NULL)
    {
      count = 0;
      while (all->meet[i]->members[count] != -1)
	{
	  if (all->meet[i]->members[count] == id)
	    break;
	  count += 1;
	}
      if (all->meet[i]->members[count] == id)
	tab = append_intl(tab, i);
      i += 1;
    }
  return (tab);
}
