/*
** sort_meet.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:31:06 2017 Mathias
** Last update Sat Jul  1 14:25:38 2017 Mathias
*/

#include "calandar.h"

void sort_it_meet(long int *tab, t_all *all)
{
  int i;
  int count;

  i = 0;
  while (tab[i] != -1)
    {
      count = 0;
      while (all->meet[count] != NULL)
	{
	  if (all->meet[count]->id == tab[i])
	    break;
	  count += 1;
	}
      tab[i] = count;
      i += 1;
    }
}

void sortm_id(long int *tab, t_all *all)
{
  int i;

  i = -1;
  while (tab[++i] != -1 && tab[i + 1] != -1)
    if (all->meet[tab[i]]->id > all->meet[tab[i + 1]]->id)
      switch_emp(tab, &i);
}

void sortm_zipcode(long int *tab, t_all *all)
{
  int i;
  int sv;

  i = -1;
  while (tab[++i] != -1 && tab[i + 1] != -1)
    if ((sv = my_cmp_date(all->meet[tab[i]]->place,
			  all->meet[tab[i + 1]]->place)) == 0)
      {
	if (all->meet[tab[i]]->id > all->meet[tab[i + 1]]->id)
	  switch_emp(tab, &i);
      }
    else if (sv == 1)
      switch_emp(tab, &i);
}

void sortm_date(long int *tab, t_all *all)
{
  int i;
  int sv;

  i = -1;
  while (tab[++i] != -1 && tab[i + 1] != -1)
    if ((sv = my_cmp_date(all->meet[tab[i]]->date,
			  all->meet[tab[i + 1]]->date)) == 0)
      {
	if (all->meet[tab[i]]->id > all->meet[tab[i + 1]]->id)
	  switch_emp(tab, &i);
      }
    else if (sv == 1)
      switch_emp(tab, &i);
}

void print_meet(t_all *all, long int *meet)
{
  int i;
  long int *mate;
  int count;

  i = 0;
  while (meet[i] != -1)
    {
      mate = copy_mate(all->meet[meet[i]]->members, -1);
      sort_it(mate, all);
      sorte_first_name(mate, all);
      count = 0;
      printf("******************************\n");
      printf("MEETING\ndate:  %s\nplace:  %s\nwith %s %s",
	     all->meet[meet[i]]->date, all->meet[meet[i]]->place,
	     all->emp[mate[count]]->last_name,
	     all->emp[mate[count]]->first_name);
      while (mate[++count] != -1)
	printf(", %s %s", all->emp[mate[count]]->last_name,
	       all->emp[mate[count]]->first_name);
      printf("\n");
      free(mate);
      i += 1;
    }
}
