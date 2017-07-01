/*
** info.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:32:31 2017 Mathias
** Last update Sat Jul  1 13:33:32 2017 Mathias
*/

#include "calandar.h"

void info_meeting(char **tab, char *str, t_all *all)
{
  long int *intab;
  int i;

  i = -1;
  str[0] = str[0];
  while (tab[++i] != NULL);
  if (i > 1)
    {
      if (i == 2)
	intab = get_all_meet(all);
      else if (i > 2)
	intab = get_them_meet(all, tab);
      sort_it_meet(intab, all);
      i = -1;
      while (all->mtab[++i] != NULL && my_cmp_mod(tab[1], all->mtab[i]) != 0);
      if (all->mtab[i] != NULL)
	{
	  all->sortm[i](intab, all);
	  print_meet(all, intab);
	}
      free(intab);
    }
}

int is_alphanum(char *str)
{
  char *check;
  int i;
  int k;

  check = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-/ ";
  i = 0;
  k = 0;
  while (str[i] != '\0')
    {
      k = 0;
      while (check[k] != str[i] && check[k] != '\0')
	k += 1;
      if (check[k] != str[i])
	return (1);
      i += 1;
    }
  return (0);
}

void init_all_end(t_all *all)
{
  all->sorte[0] = &sorte_first_name;
  all->sorte[1] = &sorte_last_name;
  all->sorte[2] = &sorte_post;
  all->sorte[3] = &sorte_zipcode;
  all->sorte[4] = &sorte_id;
  all->sortm[0] = &sortm_date;
  all->sortm[1] = &sortm_zipcode;
  all->sortm[2] = &sortm_id;
  all->sortm[3] = NULL;
  all->sorte[5] = NULL;
  all->etab = malloc(sizeof(char *) * 6);
  all->mtab = malloc(sizeof(char *) * 4);
  all->etab[0] = strdup("sortByName");
  all->etab[1] = strdup("sortByForename");
  all->etab[2] = strdup("sortByJob");
  all->etab[3] = strdup("sortByZip");
  all->etab[4] = strdup("sortById");
  all->etab[5] = NULL;
  all->mtab[0] = strdup("sortByDate");
  all->mtab[1] = strdup("sortByZip");
  all->mtab[2] = strdup("sortById");
  all->mtab[3] = NULL;
}

void init_all_sequel(t_all *all)
{
  strcpy(all->com[0], "new_employee");
  strcpy(all->com[1], "new_meeting");
  strcpy(all->com[2], "invite");
  strcpy(all->com[3], "exclude");
  strcpy(all->com[4], "info_employees");
  strcpy(all->com[5], "info_meetings");
  strcpy(all->com[6], "cancel");
  strcpy(all->com[7], "fire");
  strcpy(all->com[8], "END");
  all->tab[0] = &new_employee;
  all->tab[1] = &new_meeting;
  all->tab[2] = &invite;
  all->tab[3] = &exclude;
  all->tab[4] = &info_employee;
  all->tab[5] = &info_meeting;
  all->tab[6] = &cancel;
  all->tab[7] = &fire;
  all->tab[8] = &end;
  all->tab[9] = NULL;
  init_all_end(all);
}

t_all *init_all(void)
{
  t_all *all;

  all = malloc(sizeof(t_all));
  all->emp = malloc(sizeof(*all->emp));
  all->meet = malloc(sizeof(*all->meet));
  all->emp[0] = NULL;
  all->meet[0] = NULL;
  all->com = malloc(sizeof(char *) * 10);
  all->com[0] = calloc(strlen("new_employee") + 2, sizeof(char));
  all->com[1] = calloc(strlen("new_meeting") + 2, sizeof(char));
  all->com[2] = calloc(strlen("invite") + 2, sizeof(char));
  all->com[3] = calloc(strlen("exclude") + 2, sizeof(char));
  all->com[4] = calloc(strlen("info_employees") + 2, sizeof(char));
  all->com[5] = calloc(strlen("info_meetings") + 2, sizeof(char));
  all->com[6] = calloc(strlen("cancel") + 2, sizeof(char));
  all->com[7] = calloc(strlen("fire") + 2, sizeof(char));
  all->com[8] = calloc(strlen("END") + 2, sizeof(char));
  all->com[9] = NULL;
  all->tab = malloc(sizeof(*all->tab) * 10);
  all->sorte = malloc(sizeof(*all->sorte) * 6);
  all->sortm = malloc(sizeof(*all->sortm) * 4);
  init_all_sequel(all);
  return (all);
}
