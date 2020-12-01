#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //validação
    if (argc != 2)
    {
        printf("KEY\n");
        return 1;
    }
    else
    {
        int length = strlen(argv[1]);
        if (length != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }
        for (int i = 0; i < length; i++)
        {
            int count = 0;
            if (argv[1][i] / 10 < 6) //numero
            {
                printf("Key must only contain alphabetic characters.\n");
                return 1;
            }
            for (int j = 0; j < length; j++)
            {
                if (argv[1][i] == argv[1][j])
                {
                    count++;
                }
                if (count > 1)
                {
                    printf("Key must not contain repeated characters.\n");
                    return 1;
                }
            }
        }
        //cipher

        string s = get_string("plaintext: ");
        printf("ciphertext: ");
        string alphabet = "abcdefghijklmnopqrstuvwxyz";
        string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            if (s[i] >= 'a' && s[i] <= 'z')
            {
                for (int j = 0; j < strlen(alphabet); j++)
                {
                    if (s[i] == alphabet[j])
                    {
                        printf("%c", tolower(argv[1][j]));
                    }
                }
            }
            else if (s[i] >= 'A' && s[i] <= 'Z')
            {
                for (int j = 0; j < strlen(alphabetUpper); j++)
                {
                    if (s[i] == alphabetUpper[j])
                    {
                        printf("%c", toupper(argv[1][j]));
                    }
                }
            }
            else
            {
                printf("%c", s[i]);
            }
        }
        printf("\n");
    }
}
