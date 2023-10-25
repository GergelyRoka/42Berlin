
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
	int dist2;
} cell;

cell	*table;

int	MyBase; // if i have only 1 base
int NumberOfCells;
int g_myAnts;
int g_oppAnts;

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
		g_oppAnts = 0;
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
			g_oppAnts += table[i].opp_ants;
			if(table[i].resources)
				g_progress.maxCamp++;
		}

		// Write an action using printf(). DON'T FORGET THE TRAILING \n
		// To debug: fprintf(stderr, "Debug messages...\n");
		// WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
		//printf("WAIT\n");
		fprintf(stderr, "Debug messages...\n");
		Action();


	} //ENDGAME


	free(table); //because i am nice
	return 0;
}



void BeforeGameLoop()
{
	fprintf(stderr, "NUMBER OF CELLS: %i\n", NumberOfCells);
	for (int i = 0; i < NumberOfCells; ++i)
	{
		table[i].dist = Distance(MyBase, i, 0, 10);
		fprintf(stderr, "table[%i].dist : %i \n", i, table[i].dist);
	}
}

int Distance(int current, int dest, int dist, int max)
{
	if ( current == dest)
		return(dist);
	if (dist > max)
		return (99);
	
	table[current].dist_flag = 1;

	int D = 999;
	for (int i = 0; i < 6; ++i)
	{
		int neigh = table[current].neigh[i];
		if (neigh != -1 && table[neigh].dist_flag == 0)
		{
			int tmp = Distance(neigh, dest, dist+1, max);
			if (tmp < D)
				D = tmp;
		}
	}
	table[current].dist_flag = 0;
	table[MyBase].dist_flag = 1;

	return (D);

}

int ClosestCamp(int new, int maxdist)
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
				int res = Distance(i, new, 0, maxdist);
				if (res < min)
				{
					min = res;
					min_i = i;
				}
			}
		}
		g_progress.dist += min + 1;
		table[new].dist2 = min;
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

typedef struct
{
	int type;
	int pos;
	int dist;
	int resource;
	int val;
	int dist2;
} resCell;

resCell g_Camps[50];

void InitCamps()
{
	for (int i = 0; i < 20; ++i)
	{
		g_Camps[i].resource = 0;
		g_Camps[i].dist = 999;
	}
	int ci = 0;
	for (int i = 0; i < NumberOfCells && ci < 50; ++i)
	{
		if (table[i].resources)
		{
			g_Camps[ci].dist = table[i].dist;
			g_Camps[ci].pos = i;
			g_Camps[ci].resource = table[i].resources;
			g_Camps[ci].type = table[i].type;
			ci++;
		}
	}

	{
		int i, j;
		bool swapped;
		for (i = 0; i < ci - 1; i++)
		{
			swapped = false;
			for (j = 0; j < ci - i - 1; j++)
			{

					//bugg
				//fprintf(stderr, "Debug messages...\n");


				if (g_Camps[j].dist > g_Camps[j+1].dist)
				{
					resCell tmp;
					tmp.pos = g_Camps[j].pos;
					tmp.resource = g_Camps[j].resource;
					tmp.dist = g_Camps[j].dist;
					tmp.val = g_Camps[j].val;
					tmp.type = g_Camps[j].type;

					g_Camps[j].pos = g_Camps[j + 1].pos;
					g_Camps[j].dist = g_Camps[j + 1].dist; 
					g_Camps[j].resource = g_Camps[j + 1].resource; 
					g_Camps[j].val = g_Camps[j + 1].val;
					g_Camps[j].type = g_Camps[j + 1].type; 

					g_Camps[j + 1].pos 	= tmp.pos;
					g_Camps[j + 1].resource 	= tmp.resource;
					g_Camps[j + 1].val 	= tmp.val;
					g_Camps[j + 1].dist 	= tmp.dist;
					g_Camps[j + 1].type 	= tmp.type;

					swapped = true;
				}
			}
	
			// If no two elements were swapped by inner loop,
			// then break
			if (swapped == false)
				break;
		}
	}
}


void Action()
{
	static int flag = -1;
	int d = 3;
	fprintf(stderr, "init_progress...\n");
	init_progress();
	fprintf(stderr, "init_progress DONE\n");
	fprintf(stderr, "initcamps..\n");
	InitCamps();
	fprintf(stderr, "initcamps DONE\n");


	for (int i = 0; g_Camps[i].resource; ++i)
	{
		//fprintf(stderr, "g_Camps[%i] pos(%i) type(%i) dist(%i) res(%i)\n", i, g_Camps[i].pos, g_Camps[i].type, g_Camps[i].dist, g_Camps[i].resource );
	}
	int maxdist = 3;
	while (true)
	{
		int flag = 0;

		for (int i = 0; g_Camps[i].resource; ++i)
		{
			//fprintf(stderr, "pos(%i)\n", g_Camps[i].pos);
			if (g_Camps[i].type == 1 && g_Camps[i].dist == 1)
			{
				printf("LINE %i %i 1;", MyBase, g_Camps[i].pos);
				
				++flag;
			}
		}
		if (flag)
			break;
		/*for (int i = 0; g_Camps[i].resource; ++i)
		{
			//fprintf(stderr, "pos(%i)\n", g_Camps[i].pos);
			if (g_Camps[i].type == 1 && g_Camps[i].dist == 2)
			{
				printf("LINE %i %i 1;", MyBase, g_Camps[i].pos);
				
				++flag;
			}
		}
		if (flag)
			break;*/
		for (int i = 0; g_Camps[i].resource; ++i)
		{
			if (g_Camps[i].type == 2)
			{
				if (g_myAnts >= g_progress.dist)
				{
					fprintf(stderr, "pos(%i)\n", g_Camps[i].pos);
					printf("LINE %i %i 1;", ClosestCamp(g_Camps[i].pos, g_Camps[i].dist), g_Camps[i].pos);
				}
			}
		}
/*
		//plus 1 egg camp
		if (g_oppAnts +5 > g_myAnts)
		{
			int maxd = 999;
			int	pegg;
			for (int i = 0; g_Camps[i].resource; ++i)
			{
				if (g_Camps[i].type == 1)
					ClosestCamp(g_Camps[i].pos, g_Camps[i].dist);
			}
			for (int i = 0; g_Camps[i].resource; ++i)
			{
				if (g_Camps[i].type == 1)
					if (maxd > table[g_Camps[i].pos].dist2)
					{
						maxd = table[g_Camps[i].pos].dist2;
						pegg = g_Camps[i].pos;
					}
			}
			printf("LINE %i %i 1;", ClosestCamp(pegg, table[pegg].dist), pegg);
		}
		*/
		break;

	}
	printf("MESSAGE hello\n");
}
