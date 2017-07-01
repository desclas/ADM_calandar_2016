/*
** free_and_gnl.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:14:18 2017 Mathias
** Last update Sat Jul  1 13:15:42 2017 Mathias
*/

#include "calandar.h"

char **free_tab(char **tab, char *str, int ex)
{
  int i;

  i = 0;
  if (str != NULL)
    free(str);
  if (tab != NULL)
    {
      while (tab[i] != NULL)
	{
	  free(tab[i]);
	  i += 1;
	}
      free(tab);
    }
  if (ex < 0)
    return (NULL);
  exit(ex);
}

void free_all_sequel(t_all * all)
{
  free(all->meet);
  free_tab(all->com, NULL, -1);
  free(all->tab);
  free_tab(all->etab, NULL, -1);
  free_tab(all->mtab, NULL, -1);
  free(all->sorte);
  free(all->sortm);
}

void free_all(t_all *all)
{
  int i;

  i = 0;
  while (all->emp[i] != NULL)
    {
      free(all->emp[i]->first_name);
      free(all->emp[i]->last_name);
      free(all->emp[i]->post);
      free(all->emp[i]->zipcode);
      free(all->emp[i]);
      i += 1;
    }
  free(all->emp);
  i = -1;
  while (all->meet[++i] != NULL)
    {
      free(all->meet[i]->place);
      free(all->meet[i]->date);
      free(all->meet[i]->members);
      free(all->meet[i]);
    }
  free_all_sequel(all);
  free(all);
}

char *append_char(char *str, char c)
{
  int i;

  i = strlen(str);
  str = realloc(str, sizeof(char) * (i + 2));
  str[i] = c;
  str[i + 1] = '\0';
  return (str);
}

char *my_gnl(int fd)
{
  int k;
  char *res;
  char c;

  res = calloc(1, sizeof(char));
  c = '\0';
  while (1)
    {
      k = read(fd, &c, 1);
      if (k < 1 || c <= 0 || c == '\n')
	break;
      res = append_char(res, c);
    }
  if (c < 0 || (c == '\n' && res[0] == '\0') || res[0] == '\0')
    {
      free(res);
      return (NULL);
    }
  return (res);
}
