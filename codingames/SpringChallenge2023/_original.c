#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    // amount of hexagonal cells in this map
    int number_of_cells;
    scanf("%d", &number_of_cells);
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
    }
    int number_of_bases;
    scanf("%d", &number_of_bases);
    for (int i = 0; i < number_of_bases; i++) {
        int my_base_index;
        scanf("%d", &my_base_index);
    }
    for (int i = 0; i < number_of_bases; i++) {
        int opp_base_index;
        scanf("%d", &opp_base_index);
    }

    // game loop
    while (1) {
        for (int i = 0; i < number_of_cells; i++) {
            // the current amount of eggs/crystals on this cell
            int resources;
            // the amount of your ants on this cell
            int my_ants;
            // the amount of opponent ants on this cell
            int opp_ants;
            scanf("%d%d%d", &resources, &my_ants, &opp_ants);
        }

        // Write an action using printf(). DON'T FORGET THE TRAILING \n
        // To debug: fprintf(stderr, "Debug messages...\n");


        // WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
        printf("WAIT\n");
    }

    return 0;
}