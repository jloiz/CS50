#include <stdio.h> 
#include <math.h>
#include <string.h>

#define MAX 16


int main(void)
{
    unsigned long long card_number;                 
    char card_type[32];
    int card_digits[MAX];
    int check_sum_part1 = 0;
    // int check_sum_part1b = 0;
    int check_sum_part2 = 0;

    while(1)
    {
        scanf("%llu", &card_number);

        unsigned long long N = card_number;     // To overcome the issue of having N be a refence to card_number, rather than an assigment, the scope had to be changed
                                                // i.e., declare the non-permannent variable in a block subordinate to the permanent one.
        int i = 0;
        int dig;

        while (N != 0)                          // Split card number into digits to operate upon
        {
            dig = N % 10;
            card_digits[i] = dig;
            i++;
            N = N /10;
        }


        if (card_digits[15] == 4)               // Determine type of card
        {
            strncpy(card_type, "VISA", sizeof(card_type));
            break;
        } else
        if (card_digits[15] == 5)
        {
            strncpy(card_type, "Mastercard", sizeof(card_type));
            break;
        } else 
        if (card_digits[15] == 3)
        {
            strncpy(card_type, "AMEX", sizeof(card_type));
            break;
        } else
        {
            printf("INVALID\n");
            scanf("%llu", &card_number);
            
        }
    } 

    printf("Card number is %llu \n", card_number);          //Display currently known information
    printf("Card type is: %s \n", card_type);

    int mult_results[MAX/2];
    int other_digits[MAX/2];

    for (int i=0; i<(MAX/2) ; i++)                          // Luhn's Algorithm
    {
        mult_results[i] = 2*card_digits[(2*i)+1];

        if (mult_results[i] < 10)
        {
            check_sum_part1 += mult_results[i];
        } else 
        if (mult_results[i] >= 10)
        {
            check_sum_part1 = check_sum_part1 + 1 + (mult_results[i] % 10);
        }
    }

    for (int i=0; i<MAX/2; i++)
    {
        other_digits[i] = card_digits[2*i];
        check_sum_part2 += other_digits[i];
    }

    if ((check_sum_part1 + check_sum_part2)%10 == 0)        // Do the final check to see if the card number is valid.
    {
        printf("This card number is valid.");
    } else 
    {
        printf("This card number is invalid.");
    }

    return 0;
}

