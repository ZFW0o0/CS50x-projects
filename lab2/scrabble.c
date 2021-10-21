#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    if (score1 == score2)
    {
        printf("Tie!\n");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    int sum_point = 0;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int sequence = 0;
        int k = 0;
        int ASCII = (int) word[i];
        if (ASCII >= 65 && ASCII <= 90)
        {
            sequence = ASCII - 65;
        }
        else if (ASCII >= 97 && ASCII <= 122)
        {
            sequence = ASCII - 97;
        }
        else
        {
            continue;
        }
        
        //printf ("%i\n",sequence);
        int point = POINTS[sequence];
        sum_point += point; 
        k++;
    }
    return sum_point;
}
