#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


bool test(int argc, string argv[]);
int cipher(string plain, int key);

int main(int argc, string argv[])
{
    bool test_result = test(argc, argv);
    if ( test_result == false)
    {
        printf("Usage: ./caesar key\n");
    }
    else
    {
        string plaintext = get_string("plaintext: ");
        int key = atoi(argv[1]);
        cipher(plaintext, key);
    }
    return 1;
}

bool test(int argc, string argv[])
{
    bool a,b;
    string key = argv[1];
    if (argc == 2)
    {
        a = true;
    }
    else
    {
        a = false;
    }

    int keylen = strlen(argv[1]);
    b = true;
    for(int i = 0; i < keylen; i++ )
    {
        char key_character = key[i];
        if (key_character >= 48 && key_character <= 57 )
        {
            continue;
        }
        else
        {
            b = false;
            break;
        }
    }

    if (a == true && b == true)
    {
        return true;
    }
    else
    {
        return false;
    }

}

int cipher(string plain, int key)
{
    int textlen = strlen(plain);
    char ciphertext[textlen];
    for(int i = 0; i < textlen; i++ )
    {
        char plain_character = plain[i];
        char cipher_character = 'a';
        bool letter = isalpha(plain_character);
        bool uppercase = isupper(plain_character);
        if(letter == false)
        {
            cipher_character = plain_character;
        }
        else if(uppercase)
        {
            int uppercase_order = plain_character - 65;
            cipher_character = 65 + (uppercase_order + key) % 26;
        }
        else
        {
            int lowercase_order = plain_character - 97;
            cipher_character = 97 + (lowercase_order + key) % 26;
        }
    ciphertext[i] = cipher_character;
    }
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}