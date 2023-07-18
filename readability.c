#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// Readability Test Formula:
// index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words
// S = average number of sentences per 100 words

// EXAMPLE
/*
    if user inputs a text with 65 letters, 4 sentences, and 14 words
    divide the 65 letters by the 14 words, multiply the quotient by 100, plug this number in for L (464.29)
    divide the 4 sentences by the 14 words, multiply the quotient by 100, plug this number in for S (28.57)
    0.0588 * 464.29 - 0.296 * 28.57 - 15.8 = 3
    the grade level will be Grade 3

*/
int main(void)
{
    // get user input
    char text[1000];
    printf("Text: ");
    scanf("%s", &text);

    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0; i < strlen(text); i++)
    {
        //get letters
        if (isalpha(text[i]))
        {
            letters++;
        }
        //get words
        else if (text[i] == ' ')
        {
            words++;
        }
        //get sentences
        else if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            sentences++;
        }
    }
    //get grade level
    float L = letters / (float) words * 100;
    float S = sentences / (float) words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %d\n", index);
    }
}
