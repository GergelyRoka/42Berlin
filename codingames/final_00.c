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
	int	ways[MAX];			// ways from other cells
	int distances[MAX];		// distances from other cells
	int real_ways[MAX];		// real
	int real_distances[MAX];	// real
	int beacon;				//1: beacon on on the cell - 0: no beacon - or more for prior
	int	was_beacon;			//0: if no beacon prev round, 1: was beacon in prev round
}	cell_t;

typedef struct info_s
{
	int	game_type; 		// 1 -> 1 base/player | 2 -> 2 bases/player
	cell_t *my_base[2];	// cell indexes for bases
	cell_t *opp_base[2];// cell indexes of opp bases
	cell_t	*res_cells[MAX];
	cell_t	*mine_cells[MAX];
	cell_t	*crystal_cells[MAX];
	cell_t	*egg_cells[MAX];
	int	win_score;		// score for win
	int	my_score;		// my score
	int opp_score;		// opp score
	int beacons;		// every beacons of mine
	int mines;			// every opened mine
	int crystal_mines;	// crystal mine
	int egg_mines;		// egg mine
	int n_crystal_cells;	// number of cells of crystal resources
	int n_egg_cells;		// number of cells of egg resources
	int my_ants;		// number of my ants
	int opp_ants;		// number of opp ants
	int	crystals;		// all crystals resources on the board
	int	eggs;			// amount of eggs on the board
} info_t;

int		g_size; // amount of hexagonal cells in this map
cell_t	g_table[MAX]; // basicly the gameboard, array of cells
int		g_matrix[MAX][MAX]; //matrix for Dijkstra algorithm - graph representation
int		g_real_matrix[MAX][MAX];
info_t	info;	// gamestatus, infos about the gameboard

/**
 * @brief Initializing the matrix, doing the graph representation for dijkstra
 * 		the distance is 1 if the edge goes to resource, otherwise 2
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
			{
				g_matrix[i][g_table[i].neighbours[j]] = 2;
				if (g_table[g_table[i].neighbours[j]].type)
					g_matrix[i][g_table[i].neighbours[j]] = 1;
			}
}

/**
 * @brief Initializing the real matrix, doing the graph representation for dijkstra
 * 		the distance is 1 
 */
void MY_init_real_matrix()
{
	for (int i = 0; i < g_size; ++i)
		for (int j = 0; j < g_size; ++j)
			if (i == j)
				g_real_matrix[i][j] = 0;
			else
				g_real_matrix[i][j] = INFINITY;

	for (int i = 0; i < g_size; ++i)
		for (int j = 0; j < 6; ++j)
			if (g_table[i].neighbours[j] != -1)
			{
				g_real_matrix[i][g_table[i].neighbours[j]] = 1;
			}
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
 * @brief Dijksta algorithm
 * 
 * @param startnode index of the cell
 */
void real_dijkstra(int startnode)
{
	int (*G)[MAX] = g_real_matrix;
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
		g_table[startnode].real_distances[i] = distance[i];
		g_table[startnode].real_ways[i] = pred[i];
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
 * @brief dijkstras for bases 
 * 
 */
void MY_first_dijkstras()
{
	MY_init_matrix();
	MY_init_real_matrix();
	MY_print_matrix();
	dijkstra(info.my_base[0]->index);
	real_dijkstra(info.my_base[0]->index);
	dijkstra(info.opp_base[0]->index);
	real_dijkstra(info.opp_base[0]->index);
	if (info.game_type == 2)
	{
		dijkstra(info.my_base[1]->index);
		real_dijkstra(info.my_base[1]->index);
		dijkstra(info.opp_base[1]->index);
		real_dijkstra(info.opp_base[1]->index);
	}
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
void MY_info_refresh()
{
	info.beacons = 0;
	info.mines = 0;
	info.my_ants = 0;
	info.opp_ants = 0;
	info.mines = 0;
	info.crystal_mines = 0;
	info.egg_mines = 0;
	info.n_crystal_cells = 0;
	info.n_egg_cells = 0;
	info.crystals = 0;
	info.eggs = 0;

	int	ri = 0;
	int mi = 0;
	int ci = 0;
	int ei = 0;

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
			info.n_egg_cells++;
			info.eggs += g_table[i].resources;
			info.res_cells[ri++] = &g_table[i];
			info.egg_cells[ei++] = &g_table[i];
			if (g_table[i].beacon)
			{
				info.mines++;
				info.egg_mines++;
				info.mine_cells[mi++] = &g_table[i];
			}
		}
		else if (g_table[i].type == 2)
		{
			info.n_crystal_cells++;
			info.crystals += g_table[i].resources;
			info.res_cells[ri++] = &g_table[i];
			info.crystal_cells[ci++] = &g_table[i];
			if (g_table[i].beacon)
			{
				info.mines++;
				info.crystal_mines++;
				info.mine_cells[mi++] = &g_table[i];
			}
		}
	}
	info.mine_cells[mi] = NULL;
	info.res_cells[ri] = NULL;
	info.egg_cells[ei] = NULL;
	info.crystal_cells[ci] = NULL;

	MY_init_matrix(); //refresh the matrix too
}

/**
 * @brief open mines near a path
 */
void MY_open_mines_near_beacons()
{
	for (int i = 0; i < g_size; ++i)
		for (int j = 0; j < 6; ++j)
			if (g_table[i].resources && g_table[g_table[i].neighbours[j]].beacon)
				if (g_table[i].beacon == 0)
					g_table[i].beacon++;
}

/**
 * @brief if there is only one crystal res, go for it!
 * 
 */
void MY_last_mine_test()
{
	if (info.n_crystal_cells == 1)
	{
		MY_beacons_off();
		MY_beacons_for_bases();
		dijkstra(info.crystal_cells[0]->index);
		info.crystal_cells[0]->beacon++;
		fprintf(stderr,"charge!!\n");
		for (int distance = 1; distance < g_size / 2; ++distance)
			for (int i = 0; i < g_size; ++i)
				if (info.crystal_cells[0]->distances[i] == distance)
					if (g_table[i].beacon == 1)
					{
						int j;
						j = i;
						do
						{
							j = info.crystal_cells[0]->ways[j];
							//fprintf(stderr, "ez: %i\n", j);
							g_table[j].beacon = 1;
							//fprintf(stderr, "<-%d",j);
						}while(j != info.crystal_cells[0]->index);
						info.crystal_cells[0]->beacon++; //prior beacon for the mine
						MY_open_mines_near_beacons();
						
						return ;
					}
	}
}

/**
 * @brief do the path from a cell to the beaconed one
 * 
 * @param cell index
 */
void MY_path(int cell)
{
	dijkstra(cell);
	for (int distance = 1; distance < g_size / 2; ++distance)
		for (int i = 0; i < g_size; ++i)
			if (g_table[cell].distances[i] == distance && g_table[i].beacon)
			{
				int j;
				j = i;
				do
				{
					j = g_table[cell].ways[j];
					if (g_table[j].beacon == 0)
					g_table[j].beacon = 1;
				}while(j != cell);
				g_table[i].beacon = 1;
				return ;
			}
}

void MY_border_farm()
{
	// calculate the half distance between bases
	int dis_1 = 0;
	int dis_2 = 0;

	if (info.my_base[1])
	{
		dis_1 = info.my_base[0]->distances[info.opp_base[0]->index]
			< info.my_base[0]->distances[info.opp_base[1]->index]
			? info.my_base[0]->distances[info.opp_base[0]->index] / 2 + 1
			: info.my_base[0]->distances[info.opp_base[1]->index] / 2 + 1;
		dis_2 = info.my_base[1]->distances[info.opp_base[0]->index]
			< info.my_base[1]->distances[info.opp_base[1]->index]
			? info.my_base[1]->distances[info.opp_base[0]->index] / 2 + 1
			: info.my_base[1]->distances[info.opp_base[1]->index] / 2 + 1;
	}
	else
		dis_1 = info.my_base[0]->distances[info.opp_base[0]->index];

	fprintf(stderr,"distance: %i\n", dis_1);
	MY_print_distance(info.my_base[0]->index);
}

/**
 * @brief my actions fot a turn
 * 
 */
void MY_action()
{
	//fprintf(stderr,"win_score: %i\n", info.win_score);
	printf("MESSAGE Hello there!;");
	MY_beacons_off();
	MY_beacons_for_bases();
	MY_info_refresh();
	MY_open_mines_near_beacons();
	//1
	MY_border_farm();

	MY_last_mine_test();
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
		if (g_table[i].type == 2)
			info.win_score+=g_table[i].initial_resources;
	}
	info.win_score = info.win_score / 2 + 1;
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

	MY_first_dijkstras();
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