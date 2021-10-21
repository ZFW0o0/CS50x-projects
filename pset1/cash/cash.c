#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //prompt the user for an amount of change 
    float change_dollar;
    do
    {
        change_dollar = get_float("Change owed:");
    }
    while (change_dollar < 0 );
    
    //convert change from dollar to cent 
    int change_cent = round(change_dollar*100);
    int coin = 0;
    
    //record how many quarters are required 
    while (change_cent >= 25)
    {
        change_cent = change_cent - 25;
            coin = coin + 1;
    }
    //record how many dimes are required
    while (change_cent >= 10)
    {
        change_cent = change_cent - 10;
        coin = coin + 1;
    }
    //record how many nickels are required
    while (change_cent >= 5)
    {
        change_cent = change_cent - 5;
        coin = coin + 1;
    }
    //record how many pennies are required
    while (change_cent > 0)
    {
        change_cent = change_cent - 1;
        coin = coin + 1;
    }
    
    printf("%i\n",coin);
    
}