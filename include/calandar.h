/*
** calandar.h for  in /home/mathias/Bureau/projet_epitech/synthese/ADM_calandar_2016
** 
** Made by Mathias
** Login   <mathias@epitech.net>
** 
** Started on  Sat Jul  1 13:12:17 2017 Mathias
** Last update Sat Jul  1 14:26:46 2017 Mathias
*/

#ifndef CALANDAR_H_
# define CALANDAR_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

typedef struct s_employee
{
  long int id;
  char *last_name;
  char *first_name;
  char *post;
  char *zipcode;
}		t_employee;

typedef struct s_meeting
{
  long int id;
  char *date;
  char *place;
  long int *members;
}		t_meeting;

typedef struct s_all
{
  t_employee **emp;
  t_meeting **meet;
  char **com;
  void (**tab)(char **tab, char *str, struct s_all *all);
  void (**sorte)(long int *tab, struct s_all *all);
  void (**sortm)(long int *tab, struct s_all *all);
  char **etab;
  char **mtab;
}		t_all;

char **free_tab(char **tab, char *str, int ex);
void free_all_sequel(t_all * all);
void free_all(t_all *all);
char *append_char(char *str, char c);
char *my_gnl(int fd);
char **append_chartab(char **tab, char *str);
char **split(char *str, char del);
int is_num(char *str);
void append_emp(t_all *all, char **tab);
void new_employee(char **tab, char *str, t_all *all);
void end(char **tab, char *str, t_all *all);
int it_exist(char *str, t_all *all, int ch);
int how_num(char **tab, int i, t_all *all);
void append_int(t_meeting *all, long int nb);
void append_meet(t_all *all, char **tab);
void new_meeting(char **tab, char *str, t_all *all);
int not_in_it(t_all *all, int i, long int sv);
void invite(char **tab, char *str, t_all *all);
void free_meeting(t_all *all, int rank);
int check_meeting(t_all *all, long int rank);
void exclude(char **tab, char *str, t_all *all);
void cancel(char **tab, char *str, t_all *all);
void free_emp(t_all *all, int i);
void sub_emp(t_all *all, long int s);
void fire(char **tab, char *str, t_all *all);
long int *append_intl(long int *tab, long int nb);
long int *get_all_emp(t_all * all);
long int *get_them_emp(t_all *all, char **emp);
void sort_it(long int *tab, t_all *all);
long int *get_emp_meet(t_all *all, long int id);
int my_cmp_mod(char *st, char *tr);
int my_cmp_date(char *date, char *cmp);
void sort_emp_meet(long int *tab, t_all *all);
void switch_emp(long int *tab, int *i);
void sorte_id(long int *tab, t_all *all);
void sorte_zipcode(long int *tab, t_all *all);
void sorte_post(long int *tab, t_all *all);
void sorte_last_name(long int *tab, t_all *all);
void sorte_first_name(long int *tab, t_all *all);
long int *copy_mate(long int *tab, long int no);
void print_emp_meet(t_all *all, long int *meet, long int no);
void print_emp(t_all *all, long int *tab);
void info_employee(char **tab, char *str, t_all *all);
long int *get_all_meet(t_all *all);
long int *get_them_meet(t_all *all, char **meet);
void sort_it_meet(long int *tab, t_all *all);
void sortm_id(long int *tab, t_all *all);
void sortm_zipcode(long int *tab, t_all *all);
void sortm_date(long int *tab, t_all *all);
void print_meet(t_all *all, long int *meet);
void info_meeting(char **tab, char *str, t_all *all);
int is_alphanum(char *str);
void init_all_end(t_all *all);
void init_all_sequel(t_all *all);
t_all *init_all(void);

#endif /* !CALANDAR_H_ */
