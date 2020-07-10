#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

bool isNumber(string s);

int main(int argc, string argv[])
{
    if (argc == 2 && isNumber(argv[1]))

    {
        int k = atoi(argv[1]);
       // printf("%i\n",k);
        string s = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int i = 0, n = strlen(s) ; i < n; i++)
        {
            if (s[i] >= 65 && s[i] <= 90)
            {
                printf("%c", (((s[i] - 65) + k) % 26) + 65);
            }
            else if (s[i] >= 97 && s[i] <= 122)
            {
                printf("%c", (((s[i] - 97) + k) % 26) + 97);
            }
            else
            {
                printf("%c", s[i]);
            }

        }

        printf("\n");
        return 0;
    }

    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}
bool isNumber(string s)
{
    for (int i = 0; i < strlen(s); i++)
        if (isdigit(s[i]) == false)
            return false;

    return true;
}