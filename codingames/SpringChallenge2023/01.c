#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
typedef struct
{
    //int cell;
    int type;
    int base;
    int resource;
    int neigh_0;
    int neigh_1;
    int neigh_2;
    int neigh_3;
    int neigh_4;
    int neigh_5;
    int my_ants;
    int opp_ants;
    int feed;
} cell;

typedef struct {
    int pos;
    int val;
    int feed;
} obj;



cell    *table;
int my_base;
int global_my_ants;

int main()
{
    // amount of hexagonal cells in this map
    int number_of_cells;
    scanf("%d", &number_of_cells);

    table = malloc(sizeof(number_of_cells));

    for (int i = 0; i < number_of_cells; i++) {
        // 0 for empty, 1 for eggs, 2 for crystal
        int type;
        // the initial amount of eggs/crystals on this cell
        int initial_resources;
        // the index of the neighbouring cell for each direction
        int neigh_0;
        int neigh_1;
        int neigh_2;
        int neigh_3;
        int neigh_4;
        int neigh_5;
        scanf("%d%d%d%d%d%d%d%d", &type, &initial_resources, &neigh_0, &neigh_1, &neigh_2, &neigh_3, &neigh_4, &neigh_5);
        table[i].type = type;
        table[i].resource = initial_resources;
        table[i].neigh_0 = neigh_0;
        table[i].neigh_1 = neigh_1;
        table[i].neigh_2 = neigh_2;
        table[i].neigh_3 = neigh_3;
        table[i].neigh_4 = neigh_4;
        table[i].neigh_5 = neigh_5;
        table[i].base = 0;
        table[i].feed = 0;
    }
    int number_of_bases;
    scanf("%d", &number_of_bases);
    for (int i = 0; i < number_of_bases; i++) {
        int my_base_index;
        scanf("%d", &my_base_index);
        table[my_base_index].base = 1;
        my_base = my_base_index;
    }
    for (int i = 0; i < number_of_bases; i++) {
        int opp_base_index;
        scanf("%d", &opp_base_index);
        table[opp_base_index].base = 2;
    }


    obj Cry;
    obj Cry2;
    obj Egg;
    obj Egg2;
    Cry.pos = my_base;
    Cry.val = 0;
    Cry.feed = 0;
    Cry2.pos = my_base;
    Cry2.val = 0;
    Cry2.feed = 0;
    Egg.pos = my_base;
    Egg.val = 0;
    Egg.feed = 0;
    Egg2.pos = my_base;
    Egg2.val = 0;
    Egg2.feed = 0;

    // game loop
    while (1) {
        global_my_ants = 0;
        for (int i = 0; i < number_of_cells; i++) {
            // the current amount of eggs/crystals on this cell
            int resources;
            // the amount of your ants on this cell
            int my_ants;
            // the amount of opponent ants on this cell
            int opp_ants;
            scanf("%d%d%d", &resources, &my_ants, &opp_ants);
            table[i].resource = resources;
            table[i].my_ants = my_ants;
            table[i].opp_ants = opp_ants;
            global_my_ants += my_ants;
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");

        Cry.feed = table[Cry.pos].resource;
        Cry2.feed = table[Cry2.pos].resource;
        Egg.feed = table[Egg.pos].resource;
        Egg2.feed = table[Egg2.pos].resource;


        if(!Egg.feed)
        {
            int i = 0;
            Egg.val = 0;
            while (i < number_of_cells)
            {
                if(table[i].type == 1 && Egg.val < table[i].resource)
                {
                        Egg.pos = i;
                        Egg.val = table[i].resource;
                }
                ++i;
            }
        }
        if(!Egg2.feed)
        {
            int i = 0;
            Egg2.val = 0;
            while (i < number_of_cells)
            {
                if(Egg.pos != i && table[i].type == 1 && Egg2.val < table[i].resource)
                {
                        Egg2.pos = i;
                        Egg2.val = table[i].resource;
                }
                ++i;
            }
        }
        if(!Cry.feed)
        {
            int i = 0;
            Cry.val = 0;
            while (i < number_of_cells)
            {
                if(table[i].type == 2 && Cry.val < table[i].resource)
                {
                        Cry.pos = i;
                        Cry.val = table[i].resource;
                }
                ++i;
            }
        }
        if(!Cry2.feed)
        {
            int i = 0;
            Cry2.val = 0;
            while (i < number_of_cells)
            {
                if(i != Cry.pos && table[i].type == 2 && Cry2.val < table[i].resource)
                {
                        Cry2.pos = i;
                        Cry2.val = table[i].resource;
                }
                ++i;
            }
        }

        // WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
        printf("WAIT\n");
    }

    free(table);
    return 0;
}