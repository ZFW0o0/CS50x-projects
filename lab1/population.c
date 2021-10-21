#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask for the initial size of the population
    int initialSize;

    do
    {
        initialSize = get_int("Start size: ");
    } while (initialSize < 9);

    //Ask for the end size of the population
    int endSize;

    do
    {
        endSize = get_int("End size:");
    } while (endSize < initialSize);

    // Calculate the number of years when we reach the limit

    int years = 0;
    int population = initialSize;
    int increase = 0;
    int decrease = 0;

    while (population < endSize)
    {
        gain = population / 3;
        lose = population / 4;
        population = population + gain - lose;
        years++;
    }
    printf("Years: %d\n", years);
}
