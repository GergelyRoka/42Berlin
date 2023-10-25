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
    int dist;
} cell;

typedef struct {
    int pos;
    int val;
    int feed;
} obj;

 int dist(cell *array, int start, int dest, int current, int path, int way[100]);

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
/// my code

int way[100];
for(int i = 0; i < 100; ++i)
{
    way[i] = -1;
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
    int first = 0;
    for (int i = 0; i < number_of_cells; i++)
    {
        table[i].dist = dist(table, my_base, i, my_base, 0, way);
    }

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

    int flag = 0;
    int d = 4;

    int db = 0;
    struct
    {
        int pos;
        int value;
        int dist;
    } k[100];
    while (!flag){
        for (int i = 0; i < number_of_cells; i++)
        {
            if (table[i].dist < d && table[i].resource)
            {
                k[db].pos = i;
                k[db].value = table[i].resource / table[i].dist + 1;
                if (table[i].type == 1)
                    k[db].value *=2;

                k[db].dist = table[i].dist;
                ++db;
                /*
                printf("LINE %i %i %i;", my_base, i, table[i].resource / 10 +1);
                ++flag;
                if(table[i].my_ants > table[i].resource)
                {
                    d+= 2;
                }*/
                ++flag;
            }
       
        }
        if (db < 4)
            d+=4; 
        if (flag == 0)
            d += 3;
    }
    printf("MESSAGE db: %i:::;", db);
    int bi, bj;
    bool swapped;
    for (bi = 0; bi < db - 1; bi++) {
        swapped = false;
        for (bj = 0; bj < db - bi - 1; bj++) {
            if (k[bj].value > k[bj + 1].value) {
                int pos = k[bj].pos;
                int value = k[bj].value;
                k[bj].pos = k[bj+1].pos;
                k[bj].value = k[bj+1].value;
                k[bj+1].pos = pos;
                k[bj+1].value = value;
                //swap(&k[bj], &k[bj + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
    for (int i = 0 ; i < db; ++i)
    {
        printf("LINE %i %i %i;", my_base, k[i].pos, k[i].value );
    }
    printf("\n");
    /*
    if (flag)
    {
        printf("\n");
    }
    else
    {

        Cry.feed = table[Cry.pos].resource;
        Cry2.feed = table[Cry2.pos].resource;
        Egg.feed = table[Egg.pos].resource;
        Egg2.feed = table[Egg2.pos].resource;

        if (global_my_ants > 20)
            ++first;

        if(!Egg.feed)
        {
            first++;
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
        printf("MESSAGE base -> %i = %i;", Cry.pos, dist(table, my_base, Cry.pos, my_base, 0));
        //printf("LINE %i %i 1;LINE %i %i 1;LINE %i %i 1;LINE %i %i 1\n", my_base, Cry.pos, my_base, Cry2.pos, my_base, Egg.pos, my_base, Egg2.pos);
        if (first == 1)
             printf("LINE %i %i 1;\n", my_base, Egg.pos);
        else
        printf("LINE %i %i 1;LINE %i %i 1;LINE %i %i 1;\n", my_base, Cry.pos, my_base, Cry2.pos, my_base, Egg.pos);
        // WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
        //printf("WAIT\n");
        */
    }


    free(table);
    return 0;
}

int is_on_way(int current, int target, int way[100])
{
    for(int i = 0; i < 100 && way[i] != current; ++i)
    {
        if (way[i] == target)
            return (1);
    }
    return (0);
}

int dist(cell *array, int start, int dest, int current, int path, int way[100])
{
    int _path[6];
    int j = 0;

    while (j < 6)
    {
        _path[j] = 10000;
        j++;
    }

    if (path > 10)
        return 11;
    if (dest == current)
        return path;
    way[path+1] = current;
    if (array[current].neigh_0 != -1 && !is_on_way(current, array[current].neigh_0, way ))
    {   
        _path[0] =   dist(array, current, dest, array[current].neigh_0, path +1, way);
    }
    if (array[current].neigh_1 != -1 && !is_on_way(current, array[current].neigh_1, way ))
       _path[1] =   dist(array, current, dest, array[current].neigh_1, path +1, way);
    if (array[current].neigh_2 != -1 && !is_on_way(current, array[current].neigh_2, way ))
        _path[2] =  dist(array, current, dest, array[current].neigh_2, path +1, way);
    if (array[current].neigh_3 != -1 && !is_on_way(current, array[current].neigh_3, way ))
       _path[3] =  dist(array, current, dest, array[current].neigh_3, path +1, way);
    if (array[current].neigh_4 != -1 && !is_on_way(current, array[current].neigh_4, way ))
        _path[4] =  dist(array, current, dest, array[current].neigh_4, path +1, way);
    if (array[current].neigh_5 != -1 && !is_on_way(current, array[current].neigh_5, way ))
        _path[5] =  dist(array, current, dest, array[current].neigh_5, path +1, way);
    
    int min = 1000;
    int i = 0;
    while(i < 6)
    {
        if (_path[i] < min)
        {
            //printf("MESSAGE path[%i]: %i ;", i, _path[i]);
            min = _path[i];
        }
        ++i;
    }
    return min;
}
