#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompt the user to type in an integer to indicate the desired height 
    int height;
    do
    {
        height = get_int("Height:");
        //printf("%i\n",height);
    }
    while(height > 8 || height < 1 );
    
    //j indicates which row of the pyramid we are working on
    int j = 1; 
    
    for(int i = 0; i < height; i += 1)
    {
        //print one less space every row we move down
        for (int space = height-j; space > 0; space -= 1)
        {
            printf(" ");
        }
        
        //print one more hash every row we move down 
        for (int hashes = 0; hashes < j; hashes += 1)
        {
            printf("#");
        }
        printf("\n");
        j += 1;
    }
}    



