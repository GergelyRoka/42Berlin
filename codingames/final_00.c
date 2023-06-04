#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INFINITY 9999
#define MAX 99 //max number of cells

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
	int	was_beacon;			//0: if no beacon prev round, 1: was beacon in prev round
}	cell_t;

typedef struct info_s
{
	int	game_type; // 1 -> 1 base/player | 2 -> 2 bases/player
	int my_base[3];	// cell indexes for bases
	int opp_base[3];
	int	my_score;
	int opp_score;
	cell_t beaconed[MAX];
	int beacons;
	int mines;
	int my_ants;
	int opp_ants;
	int	crystals;
	int	eggs;
} info_t;

int		g_size; // amount of hexagonal cells in this map
cell_t	g_table[MAX]; // basicly the gameboard, array of cells
int		g_matrix[MAX][MAX]; //matrix for Dijkstra algorithm - graph representation
info_t	info;	// gamestatus, infos about the gameboard

/**
 * @brief Initializing the matrix, doing the graph representation for dijkstra
 */
void MY_init_matrix()
{
	for (int i = 0; i < g_size; ++i)
		for (int j = 0; j < g_size; ++j)
			if (i == j)
				g_matrix[i][j] = 0;
			else
				g_matrix[i][j] = INFINITY;

	for (int i = 0; i < g_size; ++i)
		for (int j = 0; j < 6; ++j)
			if (g_table[i].neighbours[j] != -1)
				g_matrix[i][g_table[i].neighbours[j]] = 1;
}

/**
 * @brief Printing the matrix
 */
void MY_print_matrix()
{
	for (int i = 0; i < g_size; ++i)
	{
		for (int j = 0; j < g_size; ++j)
			if (g_matrix[i][j] != INFINITY)
				fprintf(stderr, "%i ", g_matrix[i][j]);
			else
				fprintf(stderr, "_ ");
		fprintf(stderr, "\n");
	}
}

/**
 * @brief Dijksta algorithm
 * 
 * @param startnode index of the cell
 */
void dijkstra(int startnode)
{
	int (*G)[MAX] = g_matrix;
	int n = g_size;
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

/**
 * @brief	fprintf the distances from a cell to others
 * 			using the int distances[MAX] of type cell_t
 * 
 * @param cell index of the cell
 */
void MY_print_distance(int cell)
{
	for (int i = 0; i < g_size; ++i)
	{
		fprintf(stderr, "%i-%i,",i, g_table[cell].distances[i]);
	}
	fprintf(stderr,"\n");
}

/**
 * @brief	turn off the beacons on the cells
 * 			save the prev status of the beacon in was_beacon
 */
void MY_beacons_off()
{
	for (int i = 0; i < g_size; ++i)
	{
		g_table[i].was_beacon = g_table[i].beacon;
		g_table[i].beacon = 0;
	}
}

/**
 * @brief turn on the beacons of every cells with beacon
 * 
 * @note: power is 1 in this version, but should be modified later, i guess.
 * 
 */
void MY_light() //My_beacons_on() but with fancier name
{
	for (int i = 0; i < g_size; ++i)
		if (g_table[i].beacon)
			printf("BEACON %i %i;", i, g_table[i].beacon);
	printf("\n");
}


void MY_action()
{
	MY_beacons_off();

	//MY_light();
}

int main()
{
	scanf("%d", &g_size); 
	for (int i = 0; i < g_size; i++)
	{
		scanf("%d%d%d%d%d%d%d%d", &g_table[i].type, &g_table[i].initial_resources,
			&g_table[i].neighbours[0], &g_table[i].neighbours[1], &g_table[i].neighbours[2],
			&g_table[i].neighbours[3], &g_table[i].neighbours[4], &g_table[i].neighbours[5]);
	}
	scanf("%d", &info.game_type);
	for (int i = 0; i < info.game_type; i++)
	{
		scanf("%d", &info.my_base[i]);
	}
	for (int i = 0; i < info.game_type; i++)
	{
		scanf("%d", &info.opp_base[i]);
	}

	MY_init_matrix();
	MY_print_matrix();
	dijkstra(info.my_base[0]);
	dijkstra(info.opp_base[0]);
	info.game_type == 2 ? dijkstra(info.my_base[1]), dijkstra(info.opp_base[1]) : 0;
	// game loop
	while (1)
	{
		scanf("%d%d", &info.my_score, &info.opp_score);
		for (int i = 0; i < g_size; i++)
		{
			scanf("%d%d%d", &g_table[i].resources, &g_table[i].my_ants, &g_table[i].opp_ants);
		}
		// Write an action using printf(). DON'T FORGET THE TRAILING \n
		// To debug: fprintf(stderr, "Debug messages...\n");
		// WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>


		MY_action();
		//MY_light();
		printf("WAIT\n");
	}

	return 0;
}