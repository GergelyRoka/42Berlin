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
		printf("WAIT\n");
	}

	return 0;
}