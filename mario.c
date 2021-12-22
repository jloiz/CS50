#include <stdio.h>

int get_height(void);


int main(void)
{
    int height; 

    height = get_height() + 1;
    printf("height is %i", (height - 1));

    for (int row = 0; row < height; row++)
    {
        for(int left_space = 0; left_space < height - row; left_space++)
        {
            printf(" ");
        }

        for(int left_hash = 0; left_hash < row; left_hash++)
        {
            printf("#");
        }

        printf("  ");

        for(int right_hash = 0; right_hash < row; right_hash++)
        {
            printf("#");
        }

        printf("\n");
    }


    return 0;
}


int get_height(void)
{
    int ret;

    while (1)
    {
        printf("Please input the height of the pyramid to build: \t");
        scanf("%i", &ret);
        if ((ret <= 8) && (ret >=1))
        {
            break;
        }
    }

    return ret;
    
}