//ARENA result
//2023.06.01. 19:33
//place: 1359

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INFINITY 9999
#define MAX 100 //max number of cells

typedef struct
{
	int type;				// 0 for empty, 1 for eggs, 2 for crystal
	int initial_resources;	// the initial amount of eggs/crystals on this cell
	int neighbours[6];		// the index of the neighbouring cell for each direction
	int resources;			// the current amount of eggs/crystals on this cell
	int my_ants;			// the amount of your ants on this cell
	int opp_ants;			// the amount of opponent ants on this cell
	int	ways[MAX];			//ways from other cells
	int distances[MAX];		//distances from other cells
	int beacon;				//1: beacon on on the cell - 0: no beacon
} cell;
cell *g_table;
int g_numberOfCells; // amount of hexagonal cells in this map
//int g_myBase;

int **g_matrix; //matrix for dijkstra -  graph representation (adjacency matrix)
void MY_init_matrix()
{
	g_matrix = (int**)malloc(g_numberOfCells * sizeof(int*));
	for (int i = 0; i < g_numberOfCells; ++i)
		g_matrix[i] = (int*)malloc(g_numberOfCells * sizeof(int));
	for (int i = 0; i < g_numberOfCells; ++i)
		for (int j = 0; j < g_numberOfCells; ++j)
			if (i == j)
				g_matrix[i][j] = 0;
			else
				g_matrix[i][j] = INFINITY;
}
/**
 * @brief fills the connectons with number 1
 * 
 */
void MY_fill_matrix()
{
	for (int i = 0; i < g_numberOfCells; ++i)
		for (int j = 0; j < 6; ++j)
			if (g_table[i].neighbours[j] != -1)
				g_matrix[i][g_table[i].neighbours[j]] = 1, g_matrix[g_table[i].neighbours[j]][i] = 1;
}

void print_matrix()
{
	for (int i = 0; i < g_numberOfCells; ++i)
	{
		for (int j = 0; j < g_numberOfCells; ++j)
			if (g_matrix[i][j] != INFINITY)
				fprintf(stderr, "%i ", g_matrix[i][j]);
			else
				fprintf(stderr, "_ ");
		fprintf(stderr, "\n");
	}
}
/**
 * @brief 
 * 
 * 
 */
typedef struct info_s{
	int base[3];
	cell beaconed[MAX];
	int beacons;
	int mine_crystal;
	int mine_egg;
	int all_crystal;
	int all_egg;
	int my_ants;
	int opp_ants;
	int	crystals;
	int	eggs;
} info_t;
info_t g_info;
void MY_reInfo()
{
	g_info.crystals = 0;
	g_info.eggs = 0;
	g_info.my_ants = 0;
	g_info.opp_ants = 0;
	g_info.all_crystal = 0;
	g_info.all_egg = 0;
	g_info.mine_crystal = 0;
	g_info.mine_egg = 0;

	for (int i = 0; i < g_numberOfCells; ++i)
	{
		if(g_table[i].type == 2)
		{
			g_info.crystals += g_table[i].resources;
			if (g_table[i].resources)
				g_info.all_crystal++;
			if (g_table[i].beacon)
				g_info.mine_crystal++;
		}
		else if(g_table[i].type == 1)
		{
			g_info.eggs += g_table[i].resources;
			if (g_table[i].resources)
				g_info.all_egg++;
			if (g_table[i].beacon)
				g_info.mine_egg++;
		}
		g_info.my_ants += g_table[i].my_ants;
		g_info.opp_ants += g_table[i].opp_ants;
	}
	fprintf(stderr, "minec: %i - minee: %i /n", g_info.mine_crystal, g_info.mine_egg);
}
void dijkstra(int **G, int n, int startnode)
{
	int cost[MAX][MAX], distance[MAX], pred[MAX];
	int visited[MAX], count, mindistance, nextnode, i, j;
	//pred[] stores the predecessor of each node
	//count gives the number of nodes seen so far
	//create the cost matrix
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			if(G[i][j] == 0)
				cost[i][j] = INFINITY;
			else
				cost[i][j] = G[i][j];
	//initialize pred[],distance[] and visited[]
	for(i = 0; i < n; i++)
	{
		distance[i] = cost[startnode][i];
		pred[i] = startnode;
		visited[i] = 0;
	}
	distance[startnode] = 0;
	visited[startnode] = 1;
	count = 1;
	while(count < n - 1)
	{
		mindistance = INFINITY;
		//nextnode gives the node at minimum distance
		for(i = 0; i < n; i++)
			if(distance[i] < mindistance && !visited[i])
			{
				mindistance = distance[i];
				nextnode = i;
			}
		//check if a better path exists through nextnode
		visited[nextnode] = 1;
		for(i = 0; i < n; i++)
			if(!visited[i])
				if(mindistance + cost[nextnode][i] < distance[i])
				{
					distance[i] = mindistance + cost[nextnode][i];
					pred[i] = nextnode;
				}
		count++;
	}	
	//copy //i wasn't able to handle this with pointers... so :3
	for (int i = 0; i < n; ++i)
	{
		g_table[startnode].distances[i] = distance[i];
		g_table[startnode].ways[i] = pred[i];
	}
	/*
	//print the path and distance of each node
	for(i = 0; i < n; i++)
		if(i != startnode)
		{
			fprintf(stderr,"\nDistance of node%d=%d",i, g_table[startnode].distances[i]);
			fprintf(stderr,"\nPath=%d",i);
			j=i;
			do
			{
				j=g_table[startnode].ways[j];
				fprintf(stderr, "<-%d",j);
			}while(j!=startnode);
		}
	*/
}

void My_light()
{
	for (int i = 0; i < g_numberOfCells; ++i)
		if (g_table[i].beacon)
			printf("BEACON %i %i;", i, 1);
	printf("\n");
}

/**
 * @brief Beacon OFF every cell.beacon
 */

void MY_zero_beacon()
{
	for (int i = 0; i < g_numberOfCells; ++i)
		g_table[i].beacon = 0;
}

/**
 * @brief DEAFAULT beacons for bases
 * 
 */
void MY_beacons_for_bases()
{
	g_table[g_info.base[0]].beacon = 1;	// beacon on for the bases
	if (g_info.base[1])
		g_table[g_info.base[1]].beacon = 1;
} 
/**
 * @brief	1st step
 * 			Eggs near the bases are prior for collecting.
 */
int MY_1st_step()
{
	int egg = 1;

	for (int i = 0; i < 6; ++i)
	{
		for (int b = 0; g_info.base[b]; ++b)
		{
			fprintf(stderr, "base: %i | cell %i", b, g_table[g_info.base[b]].neighbours[i]);
			if (g_table[g_table[g_info.base[b]].neighbours[i]].type != -1)
				fprintf(stderr,"| type: %i | resources: %i", g_table[g_table[g_info.base[b]].neighbours[i]].type, g_table[g_table[g_info.base[b]].neighbours[i]].resources);
			fprintf(stderr, "\n");
			if (g_table[g_info.base[b]].neighbours[i] != -1 && g_table[g_table[g_info.base[b]].neighbours[i]].type == 1 && g_table[g_table[g_info.base[b]].neighbours[i]].resources)
			{
				g_table[g_table[g_info.base[b]].neighbours[i]].beacon = 1;
				egg *= b + 2;
				if (g_table[g_table[g_info.base[b]].neighbours[i]].my_ants > g_table[g_table[g_info.base[b]].neighbours[i]].resources)
					egg *= 5; 
			}
		}
	}
	if (egg % 5 == 0) //if more ants then resource, time to step 2
		return (1);
	return (egg);
}


/**
 * @brief check fot every resourced is beaconed-e
 * 
 * @return int 
 */
int MY_every_beaconed()
{
	for (int i = 0; i < g_numberOfCells; ++i)
		if (g_table[i].type && g_table[i].resources && !g_table[i].beacon)
			return (0);
	return (1);
}
/**
 * @brief Make the shortest path to the beaconed routes.
 * 
 * @param new the new cell for connecting
 */
void MY_path(int new)
{
	dijkstra(g_matrix, g_numberOfCells, new);

	for (int di = 1; di < g_numberOfCells / 2; ++di)
	{
		for (int i = 0; i < g_numberOfCells; ++i)
		{
			if (g_table[new].distances[i] == di)
			{
				if (g_table[i].beacon == 1)
				{
					int j;
					j = i;
					do
					{
						j = g_table[new].ways[j];
						//fprintf(stderr, "ez: %i\n", j);
						g_table[j].beacon = 1;
						//fprintf(stderr, "<-%d",j);
					}while(j != new);
					g_table[i].beacon = 1;
					return ;
				}
			}
		}
	}
}

void MY_open_neighbours(int new)
{
	for (int j = 0; j < 6; ++j)
			if(g_table[new].neighbours[j] != -1 && g_table[g_table[new].neighbours[j]].resources)
			{
				/*if (g_table[g_table[new].neighbours[j]].beacon == 0)
					MY_open_neighbours(g_table[new].neighbours[j]);*/
				g_table[g_table[new].neighbours[j]].beacon = 1;
			}
}

/**
 * @brief
 * 1) Open new mines in neigbouring
 * 2) refresh g_info
 * 
 * @param new index of new mine(cell)
 * @return int 0 if no need new mine, 1 time to open a new mine
 */
int MY_opening_new_mine(int new)
{
	for (int i = 0; i < g_numberOfCells; ++i)
	{
		if (g_table[i].beacon == 1)
			MY_open_neighbours(i);
	}

	MY_reInfo();
	if (g_table[new].type == 1 && g_info.mine_egg >= 1)
		return (0);
	if (g_table[new].type == 2 && g_info.mine_crystal >= 5)
		return (0);

	return(1);
}

/**
 * @brief prototype
 * 			mark everything
 */
void MY_2nd_step_every()
{


		for (int di = 1; di < g_numberOfCells / 2; ++di) // g_numberOfCells / 2 .. this should be the longest way to the base;
		{
			for (int i = 0; i < g_numberOfCells; ++i)
			{
				if ((g_table[g_info.base[0]].distances[i] == di) ||
					(g_info.base[1] && g_table[g_info.base[0]].distances[i] == di))
					{
						//fprintf(stderr, "dist: %i cell: %i resources: %i\n", g_table[g_info.base[0]].distances[i], i, g_table[i].resources);
						if (g_table[i].resources)
						{	
							//fprintf(stderr, "hejehuj\n" );
							if (MY_opening_new_mine(i))
								MY_path(i);
						}
					}
			}
		}	
}

/**
 * @brief there is a beacon on a nerby
 * 
 * @param cell 
 * @return 1 there is a beacon, . no beacon
 */
int MY_is_beacon_near(int cell)
{
	for (int i = 0; i < g_numberOfCells; ++i)
		if (g_table[cell].neighbours[i] != -1 && g_table[g_table[cell].neighbours[i]].beacon > 0)
			return (1);
	return (0);
}

void MY_base_beacon_off()
{
	for (int i = 0; g_info.base[i]; ++i)
		if (!MY_beacons_for_bases)
			g_table[g_info.base[i]].beacon = 0;
}

void MY_3rd_step()
{
	MY_reInfo();
	if (g_info.all_crystal <= 4)
	{
		for (int i = 0; i < g_numberOfCells; ++i)
		{
			g_table[i].beacon = 0;
		}
		g_table[g_info.base[0]].beacon = 1;
		if (g_info.base[1])
			g_table[g_info.base[0]].beacon = 1;
		for (int di = 1; di < g_numberOfCells / 2; ++di) // g_numberOfCells / 2 .. this should be the longest way to the base;
		{
			for (int i = 0; i < g_numberOfCells; ++i)
			{
				if ((g_table[g_info.base[0]].distances[i] == di) ||
					(g_info.base[1] && g_table[g_info.base[0]].distances[i] == di))
					{
						//fprintf(stderr, "dist: %i cell: %i resources: %i\n", g_table[g_info.base[0]].distances[i], i, g_table[i].resources);
						if (g_table[i].resources && g_table[i].type == 2)
						{	
							MY_path(i);
						}
					}
			}
		}	
	}
}
/**
 * @brief There are here every action in a round.
 */
void MY_action()
{
		// Write an action using printf(). DON'T FORGET THE TRAILING \n
		// To debug: fprintf(stderr, "Debug messages...\n");
		// WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
	MY_zero_beacon();
	MY_reInfo();
	dijkstra(g_matrix,g_numberOfCells,g_info.base[0]);
	if (g_info.base[1])
		dijkstra(g_matrix,g_numberOfCells,g_info.base[1]);
		//print_matrix();
		//fprintf(stderr, "base: %i\n", g_myBase);
	fprintf(stderr, "äfter dijskta\n");

	MY_beacons_for_bases();
	//FIRST STEP - FIRST NEARLY EGGS
	/*int _1st = MY_1st_step();
	fprintf(stderr, "_1st: %i\n", _1st);
	if ((_1st % 2 == 0 && g_info.base[1] == 0) || 
		(_1st % 2 == 0 && _1st % 3 == 0))
	{
		g_table[g_info.base[0]].beacon = 1;	// beacon on for the bases
		if (g_info.base[1])
			g_table[g_info.base[1]].beacon = 1;
		My_light();
		return ;
	}*/
	MY_2nd_step_every();
	MY_3rd_step();
	//MY_light();
	MY_base_beacon_off();
	My_light();
	//printf("WAIT\n");
}

int main()
{
	scanf("%d", &g_numberOfCells);
	g_table = malloc(g_numberOfCells * sizeof(cell));
	for (int i = 0; i < g_numberOfCells; i++)
	{
		scanf("%d%d%d%d%d%d%d%d", &g_table[i].type, &g_table[i].initial_resources,
			&g_table[i].neighbours[0], &g_table[i].neighbours[1], &g_table[i].neighbours[2],
			&g_table[i].neighbours[3], &g_table[i].neighbours[4], &g_table[i].neighbours[5]);
	}
	int number_of_bases;
	scanf("%d", &number_of_bases);
	for (int i = 0; i < number_of_bases; i++)
	{
		int my_base_index;
		scanf("%d", &my_base_index);
		g_info.base[i] = my_base_index;
	}
	for (int i = 0; i < number_of_bases; i++)
	{
		int opp_base_index;
		scanf("%d", &opp_base_index);
	}
	MY_init_matrix();
	MY_fill_matrix();
	print_matrix();

	// game loop
	while (1)
	{
		for (int i = 0; i < g_numberOfCells; i++)
		{
			scanf("%d%d%d", &g_table[i].resources, &g_table[i].my_ants, &g_table[i].opp_ants);
		}

		// Write an action using printf(). DON'T FORGET THE TRAILING \n
		// To debug: fprintf(stderr, "Debug messages...\n");
		// WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>


		MY_action();
	}

	return 0;
}