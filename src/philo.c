#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "extern.h"
#include "philo.h"
#include "arguments.h"

bool getMaxEat(const char *maxEat, t_loop *phil)
{
    phil->maxEat = atoi(maxEat);
    return (phil->maxEat > 0);
}

bool getNbPhilosopher(const char *nbPhil, t_loop *phil)
{
    phil->nbPhil = atoi(nbPhil);
    return (phil->nbPhil > 0);
}

int setPhilosophers(int ac, char **av, t_loop *phil, t_arg args[2])
{
    int i;
    int j;

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

int main(int ac, char **av)
{
    t_loop philosophers;

    if (ac != 5)
    {
        fprintf(stderr, "Usage: %s: -p [NBPHILOSOPHE] -e [MAXEAT]\n", av[0]);
        return (1);
    }
    RCFStartup(ac, av);
    if (setPhilosophers(ac, av, &philosophers ,
                    (t_arg[2]){{"-p", &getNbPhilosopher}, {"-e", &getMaxEat}}))
    {
        RCFCleanup();
        return (1);
    }
    if (launchPhilosophy(&philosophers))
        return (1);
    RCFCleanup();
    return (0);
}
