/*
** append.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:16:11 2017 Mathias
** Last update Sat Jul  1 13:17:31 2017 Mathias
*/

#include "calandar.h"

char **append_chartab(char **tab, char *str)
{
  int i;

  i = -1;
  while (tab[++i] != NULL);
  tab = realloc(tab, sizeof(char *) * (i + 2));
  tab[i] = str;
  tab[i + 1] = NULL;
  return (tab);
}

char **split(char *str, char del)
{
  char **tab;
  char *res;
  int i;

  i = -1;
  tab = malloc(sizeof(char *));
  tab[0] = NULL;
  res = calloc(1, sizeof(char));
  while (str[++i] != '\0')
    if (str[i] == del)
      {
	tab = append_chartab(tab, res);
	res = calloc(1, sizeof(char));
	while (str[++i] == del);
	i -= 1;
      }
    else
      res = append_char(res, str[i]);
  if (res[0] != '\0')
    return (append_chartab(tab, res));
  else
    {
      free(res);
      return (tab);
    }
}

int is_num(char *str)
{
  int i;

  i = 0;
  while (str[i] != '\0')
    {
      if (!(str[i] <= 57 && str[i] >= 47))
	return (1);
      i += 1;
    }
  return (0);
}

void append_emp(t_all *all, char **tab)
{
  int i;

  i = -1;
  while (all->emp[++i] != NULL);
  all->emp = realloc(all->emp, sizeof(*all->emp) * (i + 2));
  all->emp[i] = malloc(sizeof(**all->emp));
  all->emp[i]->first_name = strcpy(calloc(strlen(tab[1]) + 2,
					  sizeof(char)), tab[1]);
  all->emp[i]->last_name = strcpy(calloc(strlen(tab[2]) + 2,
					 sizeof(char)), tab[2]);
  all->emp[i]->post = strcpy(calloc(strlen(tab[3]) + 2, sizeof(char)), tab[3]);
  all->emp[i]->zipcode = strcpy(calloc(strlen(tab[4]) + 2,
				       sizeof(char)), tab[4]);
  all->emp[i]->id = atol(tab[5]);
  all->emp[i + 1] = NULL;
}

void new_employee(char **tab, char *str, t_all *all)
{
  int i;

  i = -1;
  str[0] = str[0];
  while (tab[++i] != NULL);
  if (i == 6)
    if (is_num(tab[5]) == 0)
      append_emp(all, tab);
}
