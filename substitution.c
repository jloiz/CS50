#include <ctype.h>
#include <stdio.h>
#include <string.h>


int make_cipher_txt(char *str, int k);


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Must supply one input only.");
        return 1;
    } else
    if (strlen(argv[1]) != 26)
    {
        printf("Cipher must be exactly 26 characters long.");
        return 1;
    }
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key input must be alphabetical.");
            return 1;
        }
        for (int j = i + 1; j < strlen(argv[1]); j++)
        {
            if (argv[1][i] == argv[1][j])
            {
                printf("Cipher may not have repeated characters");
                return 1;
            }
        }
    }


    char plain_txt[256];
    char cipher_txt[256];

    printf("plaintext:  ");
    fgets(plain_txt, sizeof(plain_txt), stdin);

    int text_len = strlen(plain_txt);

    printf("ciphertext:  ");
    for (int i = 0; i < text_len; i++)
    {   
        if (islower(plain_txt[i]))
        {
            printf("%c", tolower(argv[1][plain_txt[i] - 97]));
        } else       
        if (isupper(plain_txt[i]))  
        {
            printf("%c", toupper(argv[1][plain_txt[i]- 65]));
        } else
        {
            printf("%c", plain_txt[i]);
        }
    }
    printf("\n");
        
    return 0;
}
