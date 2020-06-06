#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>


bool keycheck (string key);
string encrypt (string plaintext, string key);

int main (int argc, string argv[])
{

    if(argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    if (keycheck(argv[1]) == false)
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = encrypt(plaintext, argv[1]);
    printf("ciphertext: %s\n", ciphertext);
    
    return 0;
}

bool keycheck (string key)
{
    int length = strlen(key);

    for (int i=0; i<length; i++)
    {
        // check for non-alphabetic characters
        if ((bool) isalpha(key[i]) == false)
        {
            printf("Usage: ./substitution key\n");
            return false;
        }

        // check for duplicates, case insensitive
        for(int j=i; j<length; j++)
        {
            if(toupper(key[i]) == toupper(key[j+1]))
            {
                printf("Usage: ./substitution key\n");
                return false;
            }
        }
    }

    // check key length
    if(length != 26)
    {
        printf("Key must contain 26 characters.\n");
        return false;
    }

    return true;
}


// working properly, no debugging needed
string encrypt (string plaintext, string key)
{

    int length = strlen(plaintext);
    bool is_upper = false;
    bool is_alpha = false;
    int encrypt_index;

    for (int i=0; i<length; i++)
    {
        is_upper = isupper(plaintext[i]);
        is_alpha = isalpha(plaintext[i]);

        if (is_alpha == true)
        {
            if(is_upper == true)
            {
                encrypt_index = plaintext[i] - 'A';
                // printf("%c", toupper(key[encrypt_index]));
                plaintext[i] = toupper(key[encrypt_index]);
            } else if(is_upper == false) {
                encrypt_index = plaintext[i] - 'a';
                // printf("%c", tolower(key[encrypt_index]));
                plaintext[i] = tolower(key[encrypt_index]);
            }
        } else {
            plaintext[i] = plaintext[i];
        }
    }

    return plaintext;
    // return "\0";
}