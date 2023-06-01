
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
	int type;
	int neigh[6];
	int initial_resources;
	int my_ants;
	int opp_ants;
	int resources;
	int dist;
	int	dist_flag;
} cell;

cell	*table;

int	MyBase; // if i have only 1 base
int NumberOfCells;
int g_myAnts;

struct progress
{
	int n;
	int camps[100];
	int dist;
	int maxCamp;
} g_progress;


void BeforeGameLoop();
int Distance(int current, int dest, int path, int max);
void Action();

int main()
{
	// amount of hexagonal cells in this map
	int number_of_cells;
	scanf("%d", &number_of_cells);
	////
	NumberOfCells = number_of_cells; 
	////
	table = malloc(number_of_cells * sizeof(cell));

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
		//scanf("%d%d%d%d%d%d%d%d", &type, &initial_resources, &neigh_0, &neigh_1, &neigh_2, &neigh_3, &neigh_4, &neigh_5);

		scanf("%d%d%d%d%d%d%d%d", &table[i].type, &table[i].initial_resources, &table[i].neigh[0], &table[i].neigh[1], &table[i].neigh[2], &table[i].neigh[3], &table[i].neigh[4], &table[i].neigh[5]);
		table[i].dist_flag = 0;
	}
	int number_of_bases;
	scanf("%d", &number_of_bases);
	for (int i = 0; i < number_of_bases; i++) {
		int my_base_index;
		scanf("%d", &my_base_index);
		MyBase = my_base_index;
		table[MyBase].dist_flag = 1;
	}
	for (int i = 0; i < number_of_bases; i++) {
		int opp_base_index;
		scanf("%d", &opp_base_index);
	}

	BeforeGameLoop();

	// game loop
	while (1) {
		g_myAnts = 0;
		g_progress.maxCamp = 0;
		for (int i = 0; i < number_of_cells; i++) {
			// the current amount of eggs/crystals on this cell
			int resources;
			// the amount of your ants on this cell
			int my_ants;
			// the amount of opponent ants on this cell
			int opp_ants;
			//scanf("%d%d%d", &resources, &my_ants, &opp_ants);
			scanf("%d%d%d", &table[i].resources, &table[i].my_ants, &table[i].opp_ants);
			g_myAnts += table[i].my_ants;
			if(table[i].resources)
				g_progress.maxCamp++;
		}

		// Write an action using printf(). DON'T FORGET THE TRAILING \n
		// To debug: fprintf(stderr, "Debug messages...\n");
		// WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
		//printf("WAIT\n");

		Action();


	} //ENDGAME


	free(table); //because i am nice
	return 0;
}



void BeforeGameLoop()
{
	for (int i = 0; i < NumberOfCells; ++i)
	{
		table[i].dist = Distance(MyBase, i, 0, 15);
	}
}

int Distance(int current, int dest, int dist, int max)
{
	int min = dist;
	table[current].dist_flag = 1;
	if (dist > max)
		return 99;

	if (current == dest)
	{
		table[current].dist_flag = 0;
		table[MyBase].dist_flag = 1;
		return (dist);
	}
	min = -1;
	for (int i = 0; i < 6; ++i)
	{
		if (table[current].neigh[i] != -1 && table[table[current].neigh[i]].dist_flag == 0)
		{
			int dist2 = Distance(table[current].neigh[i], dest, dist + 1, max);
			if (min == -1)
				min = dist2;
			if(min > dist2)
				min = dist2;
		}
	}
	table[current].dist_flag = 0;
	table[MyBase].dist_flag = 1;
	if (min == -1)
		return (999);
	return (min);
}

int ClosestCamp(int new, int d)
{
	if (g_progress.n == 0)
	{
		//g_progress.n++;
		g_progress.camps[new] = 1;
		g_progress.dist += table[new].dist + 1;
		return (MyBase);
	}
	else
	{
		int min = table[new].dist;
		int min_i = MyBase;

		for(int i = 0; i < 100; ++i)
		{
			if(g_progress.camps[i] && new != i)
			{
				int res = Distance(i, new, 0, 3);
				if (res < min)
				{
					min = res;
					min_i = i;
				}
			}
		}
		g_progress.dist += min + 1;
		//++g_progress.n;
		return (min_i);
	}
}

void init_progress()
{
	g_progress.dist =0;
	g_progress.n = 0;
	for(int i =0; i < 100; ++i)
		g_progress.camps[i] = 0;
}

void Action()
{
	int d = 5;
	init_progress();

	while((g_progress.n < 5 || g_progress.n == g_progress.maxCamp || g_progress.dist >= g_myAnts) && d < 20)
	{
		for(int i = 0; i < NumberOfCells && g_progress.n < 5; ++i)
		{
			if(table[i].resources && table[i].dist <= d && g_progress.camps[i] == 0)
			{
				g_progress.camps[i] = 1;
				g_progress.n++;
				if(g_progress.n < 5)
					printf("LINE %i %i 1;", ClosestCamp(i, 5), i);
				else
				{
					printf("LINE %i %i 1\n", ClosestCamp(i, 5), i);
					return ;
				}
				fprintf(stderr, "Debug g_progress.n = %i \n", g_progress.n);
			}
		}
		d += 2;
		fprintf(stderr, "Debug d = %i \n", d);
	}
	fprintf(stderr, "table[12].dist : %i \n", table[12].dist);
	printf("MESSAGE good\n");
}