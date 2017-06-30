/*
** requirement.c for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Fri Jun 30 10:17:18 2017 Mathias
** Last update Fri Jun 30 10:34:30 2017 Mathias
*/

#include <stdlib.h>

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

int my_revlist_synthesis(t_list **begin)
{
  int i;
  t_list *end;
  t_list *tmp;
  t_list *ptmp;

  i = 0;
  end = *begin;
  while (end->next != NULL && ++i > 0)
    end = end->next;
  while (1)
    {
      i = 0;
      tmp = *begin;
      while (tmp->next != NULL && ++i > 0)
	tmp = tmp->next;
      if (i == 0)
	break;
      ptmp = *begin;
      while (--i > 0)
	ptmp = ptmp->next;
      tmp->next = ptmp;
      ptmp->next = NULL;
    }
  (*begin)->next = NULL;
  *begin = end;
}

t_list *my_findnodeeqinlist_synthesis(t_list *begin, void *data_ref,
				      int (*cmp)(void *, void *))
{
  while (begin->next != NULL)
    {
      if (cmp(begin->data, data_ref) == 0)
	break;
      begin = begin->next;
    }
  return (begin);
}
