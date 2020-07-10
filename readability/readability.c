
#include <cs50.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int countLetters = 0;
    int countWords = 1;
    int countSentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122))
        {
            countLetters++;
        }
        else if (text[i] == 32)
        {
            countWords++;
        }
        else if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            countSentences++;
        }
    }
    float L = 100 * (float) countLetters / (float) countWords;
    float S = 100 * (float) countSentences / (float) countWords;
    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }


}
