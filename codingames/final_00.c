#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INFINITY 9999
#define MAX 99 //max number of cells

typedef struct
{
	int index;
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
	int	game_type; 		// 1 -> 1 base/player | 2 -> 2 bases/player
	cell_t *my_base[2];	// cell indexes for bases
	cell_t *opp_base[2];// cell indexes of opp bases
	int	my_score;		// my score
	int opp_score;		// opp score
	int beacons;		// every beacons of mine
	int mines;			// every opened mine
	int crystal_mines;	// crystal mine
	int egg_mines;		// egg mine
	int crystal_cells;	// number of cells of crystal resources
	int egg_cells;		// number of cells of egg resources
	int my_ants;		// number of my ants
	int opp_ants;		// number of opp ants
	int	crystals;		// all crystals resources on the board
	int	eggs;			// amount of eggs on the board
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
 * @brief turn on the beacons for my bases
 */
void MY_beacons_for_bases()
{
	info.my_base[0]->beacon = 1;
	info.my_base[1] ? info.my_base[1]->beacon = 1 : 0;
}

/**
 * @brief Checkfor beacons in the neighborhood of a cell
 * 
 * @param cell index of the cell
 * @return int 1 if there is a beaconed neighbour, 0 if none beacon
 */
int MY_is_any_beacon_nearby(int cell)
{
	for (int i = 0; i < 6; ++i)
		if (g_table[cell].neighbours[i] != -1
			&& g_table[g_table[cell].neighbours[i]].beacon)
			return (1);
	return (0);
}

/**
 * @brief beacon off on a base if there is no connection with it
 */
void MY_beacons_off_for_bases()
{
	if (MY_is_any_beacon_nearby(info.my_base[0]->index) == 0)
		info.my_base[0]->beacon = 0;
	if (info.my_base[1] && MY_is_any_beacon_nearby(info.my_base[1]->index) == 0)
		info.my_base[1]->beacon = 0;
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
/**
 * @brief refresh the info, gamestatus
 */
MY_info_refresh()
{
	info.beacons = 0;
	info.mines = 0;
	info.my_ants = 0;
	info.opp_ants = 0;
	info.mines = 0;
	info.crystal_mines = 0;
	info.egg_mines = 0;
	info.crystal_cells = 0;
	info.egg_cells = 0;
	info.crystals = 0;
	info.eggs = 0;

	for (int i = 0; i < g_size; ++i)
	{
		// if no more resource on the cell, change the type to zero
		if (g_table[i].resources == 0)
			g_table[i].type = 0;

		info.beacons += g_table[i].beacon;
		info.my_ants += g_table[i].my_ants;
		info.opp_ants += g_table[i].opp_ants;
		
		if (g_table[i].type == 1)
		{
			info.egg_cells++;
			info.eggs += g_table[i].resources;
			if (g_table[i].beacon)
			{
				info.mines++;
				info.egg_mines++;
			}
		}
		else if (g_table[i].type == 2)
		{
			info.crystal_cells++;
			info.crystals += g_table[i].resources;
			if (g_table[i].beacon)
			{
				info.mines++;
				info.crystal_mines++;
			}
		}
	}
}

/**
 * @brief my actions fot a turn
 * 
 */
void MY_action()
{
	MY_beacons_off();
	MY_beacons_for_bases();

	MY_beacons_off_for_bases();
	MY_light();
}

int main()
{
	scanf("%d", &g_size); 
	for (int i = 0; i < g_size; i++)
	{
		g_table[i].index = i;
		scanf("%d%d%d%d%d%d%d%d", &g_table[i].type, &g_table[i].initial_resources,
			&g_table[i].neighbours[0], &g_table[i].neighbours[1], &g_table[i].neighbours[2],
			&g_table[i].neighbours[3], &g_table[i].neighbours[4], &g_table[i].neighbours[5]);
	}
	scanf("%d", &info.game_type);
	for (int i = 0; i < info.game_type; i++)
	{
		int index;
		scanf("%d", &index);
		info.my_base[i] = &g_table[index];
	}
	for (int i = 0; i < info.game_type; i++)
	{
		int index;
		scanf("%d", &index);
		info.opp_base[i] = &g_table[index];
	}

	MY_init_matrix();
	MY_print_matrix();
	dijkstra(info.my_base[0]->index);
	dijkstra(info.opp_base[0]->index);
	info.game_type == 2 ? dijkstra(info.my_base[1]->index), dijkstra(info.opp_base[1]->index) : 0;
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
	}

	return 0;
}