/*
** print_emp.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:29:31 2017 Mathias
** Last update Sat Jul  1 13:41:11 2017 Mathias
*/

#include "calandar.h"

void print_emp_meet(t_all *all, long int *meet, long int no)
{
  int i;
  long int *mate;
  int count;

  i = 0;
  while (meet[i] != -1)
    {
      if (check_meeting(all, meet[i]) == 0)
	{
	  mate = copy_mate(all->meet[meet[i]]->members, no);
	  sort_it(mate, all);
	  sorte_first_name(mate, all);
	  printf("meeting on %s, %s, with", all->meet[meet[i]]->date,
		 all->meet[meet[i]]->place);
	  count = -1;
	  while (mate[++count] != -1)
	    printf(" %s %s", all->emp[mate[count]]->last_name,
		   all->emp[mate[count]]->first_name);
	  printf("\n");
	  free(mate);
	}
      i += 1;
    }
}

void print_emp(t_all *all, long int *tab)
{
  int i;
  long int *meet;

  i = 0;
  while (tab[i] != -1)
    {
      printf("******************************\n%s %s\n",
	     all->emp[tab[i]]->last_name, all->emp[tab[i]]->first_name);
      printf("positioni:  %s\ncity:  %s\n",
	     all->emp[tab[i]]->post, all->emp[tab[i]]->zipcode);
      meet = get_emp_meet(all, all->emp[tab[i]]->id);
      sort_emp_meet(meet, all);
      print_emp_meet(all, meet, all->emp[tab[i]]->id);
      free(meet);
      i += 1;
    }
}

void info_employee(char **tab, char *str, t_all *all)
{
  long int *intab;
  int i;

  i = -1;
  str[0] = str[0];
  while (tab[++i] != NULL);
  if (i > 1)
    {
      if (i == 2)
	intab = get_all_emp(all);
      else if (i > 2)
	intab = get_them_emp(all, tab);
      sort_it(intab, all);
      i = -1;
      while (all->etab[++i] != NULL && my_cmp_mod(tab[1], all->etab[i]) != 0);
      if (all->etab[i] != NULL)
	{
	  all->sorte[i](intab, all);
	  print_emp(all, intab);
	}
      free(intab);
    }
}

long int *get_all_meet(t_all *all)
{
  long int *tab;
  int i;

  i = 0;
  tab = malloc(sizeof(long int));
  tab[0] = -1;
  while (all->meet[i] != NULL)
    {
      tab = append_intl(tab, all->meet[i]->id);
      i += 1;
    }
  return (tab);
}

long int *get_them_meet(t_all *all, char **meet)
{
  long int *tab;
  int i;

  tab = malloc(sizeof(long int));
  tab[0] = -1;
  i = 2;
  while (meet[i] != NULL)
    {
      if (is_num(meet[i]) == 0 && it_exist(meet[i], all, 1) == 0)
	tab = append_intl(tab, atol(meet[i]));
      i += 1;
    }
  return (tab);
}
