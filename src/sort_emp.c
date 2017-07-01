/*
** sort_emp.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:28:00 2017 Mathias
** Last update Sat Jul  1 13:29:07 2017 Mathias
*/

#include "calandar.h"

void sorte_zipcode(long int *tab, t_all *all)
{
  int i;
  int sv;

  i = -1;
  while (tab[++i] != -1 && tab[i + 1] != -1)
    if ((sv = my_cmp_mod(all->emp[tab[i]]->zipcode,
			 all->emp[tab[i + 1]]->zipcode)) == 0)
      {
	if ((sv = my_cmp_mod(all->emp[tab[i]]->last_name,
			     all->emp[tab[i + 1]]->last_name)) == 0)
	  {
	    if ((sv = my_cmp_mod(all->emp[tab[i]]->first_name,
				 all->emp[tab[i + 1]]->first_name)) == 0)
	      {
		if (all->emp[tab[i]]->id > all->emp[tab[i + 1]]->id)
		  switch_emp(tab, i);
	      }
	    else if (sv == 1)
	      switch_emp(tab, i);
	  }
	else if (sv == 1)
	  switch_emp(tab, i);
      }
    else if (sv == 1)
      switch_emp(tab, i);
}

void sorte_post(long int *tab, t_all *all)
{
  int i;
  int sv;

  i = -1;
  while (tab[++i] != -1 && tab[i + 1] != -1)
    if ((sv = my_cmp_mod(all->emp[tab[i]]->post,
			 all->emp[tab[i + 1]]->post)) == 0)
      {
	if ((sv = my_cmp_mod(all->emp[tab[i]]->last_name,
			     all->emp[tab[i + 1]]->last_name)) == 0)
	  {
	    if ((sv = my_cmp_mod(all->emp[tab[i]]->first_name,
				 all->emp[tab[i + 1]]->first_name)) == 0)
	      {
		if (all->emp[tab[i]]->id > all->emp[tab[i + 1]]->id)
		  switch_emp(tab, i);
	      }
	    else if (sv == 1)
	      switch_emp(tab, i);
	  }
	else if (sv == 1)
	  switch_emp(tab, i);
      }
    else if (sv == 1)
      switch_emp(tab, i);
}

void sorte_last_name(long int *tab, t_all *all)
{
  int i;
  int sv;

  i = -1;
  while (tab[++i] != -1 && tab[i + 1] != -1)
    if ((sv = my_cmp_mod(all->emp[tab[i]]->last_name,
			 all->emp[tab[i + 1]]->last_name)) == 0)
      {
	if ((sv = my_cmp_mod(all->emp[tab[i]]->first_name,
			     all->emp[tab[i + 1]]->first_name)) == 0)
	  {
	    if (all->emp[tab[i]]->id > all->emp[tab[i + 1]]->id)
	      switch_emp(tab, i);
	  }
	else if (sv == 1)
	  switch_emp(tab, i);
      }
    else if (sv == 1)
      switch_emp(tab, i);
}

void sorte_first_name(long int *tab, t_all *all)
{
  int i;
  int sv;

  i = -1;
  while (tab[++i] != -1 && tab[i + 1] != -1)
    if ((sv = my_cmp_mod(all->emp[tab[i]]->first_name,
			 all->emp[tab[i + 1]]->first_name)) == 0)
      {
	if ((sv = my_cmp_mod(all->emp[tab[i]]->last_name,
			     all->emp[tab[i + 1]]->last_name)) == 0)
	  {
	    if (all->emp[tab[i]]->id > all->emp[tab[i + 1]]->id)
	      switch_emp(tab, i);
	  }
	else if (sv == 1)
	  switch_emp(tab, i);
      }
    else if (sv == 1)
      switch_emp(tab, i);
}

long int *copy_mate(long int *tab, long int no)
{
  int i;
  long int *res;
  int count;

  i = -1;
  while (tab[++i] != -1);
  res = malloc(sizeof(long int) * (i + 1));
  i = count =0;
  while (tab[i] != -1)
    {
      if (tab[i] != no)
	res[count] = tab[i];
      else
	count -= 1;
      i += 1;
      count += 1;
    }
  res[count] = -1;
  return (res);
}
