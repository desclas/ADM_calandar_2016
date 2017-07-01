/*
** exclude.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:21:53 2017 Mathias
** Last update Sat Jul  1 13:45:29 2017 Mathias
*/

#include "calandar.h"

void exclude(char **tab, char *str, t_all *all)
{
  int i;
  int k;
  int r;
  long int sv;

  i = -1;
  str[0] = str[0];
  while (tab[++i] != NULL);
  if (i >= 3 && it_exist(tab[1], all, 1) == 0 && (i = -1) < 0)
    {
      r = atoi(tab[1]);
      while (all->meet[++i] != NULL && all->meet[i]->id != r);
      r = i;
      i = 1;
      while (tab[++i] != NULL && (k = -1) < 0)
	{
	  sv = atol(tab[i]);
	  while (all->meet[r]->members[++k] != -1 &&
		 all->meet[r]->members[k] != sv);
	  k -= 1;
	  while (all->meet[r]->members[++k] != -1)
	    all->meet[r]->members[k] = all->meet[r]->members[k + 1];
	}
    }
}

void cancel(char **tab, char *str, t_all *all)
{
  int i;
  long int sv;
  int k;

  i = -1;
  str[0] = str[0];
  while (tab[++i] != NULL);
  if (i >= 2)
    {
      i = 0;
      while (tab[++i] != NULL)
	if (is_num(tab[i]) == 0)
	  {
	    sv = atol(tab[i]);
	    k = 0;
	    while (all->meet[++k] != NULL && all->meet[k]->id != sv);
	    if (all->meet[k] != NULL)
	      free_meeting(all, k);
	    k -= 1;
	    while (all->meet[++k] != NULL)
	      all->meet[k] = all->meet[k + 1];
	  }
    }
}

void free_emp(t_all *all, int i)
{
  free(all->emp[i]->first_name);
  free(all->emp[i]->last_name);
  free(all->emp[i]->zipcode);
  free(all->emp[i]->post);
  free(all->emp[i]);
}

void sub_emp(t_all *all, long int s)
{
  int i;
  int k;

  i = 0;
  while (all->meet[i] != NULL)
    {
      k = -1;
      while (all->meet[i]->members[++k] != -1 && all->meet[i]->members[k] != s);
      if (all->meet[i]->members[k] == s)
	{
	  k -= 1;
	  while (all->meet[i]->members[++k] != -1)
	    all->meet[i]->members[k] = all->meet[i]->members[k + 1];
	}
      i += 1;
    }
}

void fire(char **tab, char *str, t_all *all)
{
  int i;
  long int sv;
  int k;

  i = -1;
  str[0] = str[0];
  while (tab[++i] != NULL);
  if (i >= 2)
    {
      i = 0;
      while (tab[++i] != NULL)
	if (is_num(tab[i]) == 0)
	  {
	    sv = atol(tab[i]);
	    k = -1;
	    while (all->emp[++k] != NULL && all->emp[k]->id != sv);
	    if (all->emp[k] != NULL)
	      {
		free_emp(all, k);
		k -= 1;
		while (all->emp[++k] != NULL)
		  all->emp[k] = all->emp[k + 1];
		sub_emp(all, sv);
	      }
	  }
    }
}
