#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


float count_words(char string[]);
float count_letters(char word[]);
float count_sentences(char sentence[]);


int main(void)
{
    float letter_scr = 0.0;
    float sent_scr = 0.0;
    float index = 0.0;

    char inp_str[256];
    printf("Enter a phrase to grade:  ");
    fgets(inp_str, sizeof(inp_str), stdin);

    for (int i = 0, len = strlen(inp_str); i < len; i++)
    {
        inp_str[i] = toupper(inp_str[i]);
    }

    letter_scr = (count_letters(inp_str)/count_words(inp_str))*100;
    sent_scr = (count_sentences(inp_str)/count_words(inp_str))*100;

    index = (0.0588 * letter_scr) - (0.296 * sent_scr) - 15.8;
    index = round(index);

    printf("Grade: %i", (int) index);

    
    return 0;
}



float count_words(char string[])
{
    float word_tot = 1;             // initialise to one as sentence has one more word than spaces 

    for (int i = 0, len = strlen(string); i < len; i++)
    {
        if (string[i] == ' ')
        {
            word_tot += 1;
        }
    }

    return word_tot;
}



float count_letters(char words[])
{
    float letter_tot = 0;

    for (int i = 0, len = strlen(words); i < len; i++)
    {
        if (words[i] <= 'Z' && words[i] >= 'A')
        {
            letter_tot += 1;
        }
    }

    return letter_tot;
}



float count_sentences(char string[])
{
    float sents_tot = 0;             

    for (int i = 0, len = strlen(string); i < len; i++)
    {
        if (string[i] == '.' || string[i] == '!' || string[i] == '?')
        {
            sents_tot += 1;
        }
    }

    return sents_tot;
}



