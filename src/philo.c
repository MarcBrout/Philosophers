/*
** philo.c for philo in /home/brout_m/rendu/system/PSU_2016_philo
**
** Made by brout_m
** Login   <marc.brout@epitech.eu>
**
** Started on  Thu Mar  9 16:47:46 2017 brout_m
** Last update Thu Mar  9 18:27:47 2017 brout_m
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "arguments.h"
#include "extern.h"
#include "philo.h"

static bool getMaxEat(const char *maxEat, t_loop *phil)
{
  phil->maxEat = atoi(maxEat);
  return (phil->maxEat > 0);
}

static bool getNbPhilosopher(const char *nbPhil, t_loop *phil)
{
  phil->nbPhil = atoi(nbPhil);
  return (phil->nbPhil > 1);
}

static int	setPhilosophers(int ac, char **av, t_loop *phil, t_arg args[2])
{
  int		i;
  int		j;

  i = 1;
  while (i < ac)
    {
      j = 0;
      while (j < 2)
        {
	  if (!strcmp(args[j].cmd, av[i]))
            {
	      if (!args[j].func(av[i + 1], phil))
		return (1);
	      break;
            }
	  ++j;
        }
      if (j == 2)
	return (1);
      i += 2;
    }
  return (0);
}

int		main(int ac, char **av)
{
  t_loop	philosophers;
  t_philo	*table;

  if (ac != 5 ||
      setPhilosophers(ac, av, &philosophers ,
		      (t_arg[2]){{"-p", &getNbPhilosopher},
			  {"-e", &getMaxEat}}))
    {
      fprintf(stderr,
	      "Usage: %s: -p [NBPHILOSOPHE > 1] -e [MAXEAT > 0]\n",
	      av[0]);
      return (1);
    }
  if (!(table = createTable(&philosophers)))
    return (1);
  RCFStartup(ac, av);
  if (launchPhilosophy(&philosophers, table))
    {
      free(table);
      return (1);
    }
  free(table);
  RCFCleanup();
  return (0);
}
