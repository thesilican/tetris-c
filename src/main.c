#include <stdio.h>
#include "game.h"

int main()
{
    Bag bag = bag_new(10);
    for (int i = 0; i < 100; i++)
    {
        bag_shuffle(&bag);
        for (int i = 0; i < 7; i++)
        {
            if (i != 0)
            {
                printf(" ");
            }
            char c = piece_type_to_char(bag.pieces[i]);
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}