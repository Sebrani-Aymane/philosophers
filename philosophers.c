#include "philosophers.h"

int main (int ac, char **av)
{
    if (ac == 5 || ac == 6)
    {
        parse_arg(ac ,av);
        if(parse_arg(ac,av))
            printf("false input\n");
    }
    else
        printf("wrong input\n");

}