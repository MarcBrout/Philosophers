/*
** philo.h for philo in /home/brout_m/rendu/system/PSU_2016_philo
**
** Made by brout_m
** Login   <marc.brout@epitech.eu>
**
** Started on  Thu Mar  9 16:42:39 2017 brout_m
** Last update Fri Mar 10 17:01:14 2017 brout_m
*/

#ifndef PHILO_H
# define PHILO_H

# define RGHT_C(i, size) ((i) == (size) - 1) ? 0 : (i) + 1
# define TBL(phi) ((phi)->table)
# define RGHT(phi, i, size) (&(TBL(phi)[RGHT_C((i), (size))].stick))
# define RGHT_STCK(p) (RGHT(p, (p)->me, (p)->size))

#include <stdbool.h>

typedef struct		s_philo
{
  int			bowl;
  int			me;
  pthread_t		thread;
  pthread_mutex_t	stick;
  int			size;
  struct s_philo	*table;
}			t_philo;

typedef struct		s_loop
{
  int			nbPhil;
  int			maxEat;
}			t_loop;

extern int g_bowl;

int launchPhilosophy(t_loop const * const philosophers,
		     t_philo *table);
int philoAction(t_philo *phil);
t_philo *createTable(t_loop const * const philosophers);

#endif /* !PHILO_H */
