#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INFINITY 9999

typedef struct
{
	int type;				// 0 for empty, 1 for eggs, 2 for crystal
	int initial_resources;	// the initial amount of eggs/crystals on this cell
	int neighbours[6];		// the index of the neighbouring cell for each direction
	int resources;			// the current amount of eggs/crystals on this cell
	int my_ants;			// the amount of your ants on this cell
	int opp_ants;			// the amount of opponent ants on this cell

} cell;
cell *g_table;
int g_numberOfCells; // amount of hexagonal cells in this map
int g_myBase;

int **g_matrix; //matrix for dijkstra
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
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

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
		my_base_index = g_myBase;
	}
	for (int i = 0; i < number_of_bases; i++)
	{
		int opp_base_index;
		scanf("%d", &opp_base_index);
	}
	MY_init_matrix();
	MY_fill_matrix();

	// game loop
	while (1) {
		for (int i = 0; i < g_numberOfCells; i++)
		{
			scanf("%d%d%d", &g_table[i].resources, &g_table[i].my_ants, &g_table[i].opp_ants);
		}

		// Write an action using printf(). DON'T FORGET THE TRAILING \n
		// To debug: fprintf(stderr, "Debug messages...\n");

	print_matrix();
		// WAIT | LINE <sourceIdx> <targetIdx> <strength> | BEACON <cellIdx> <strength> | MESSAGE <text>
		printf("WAIT\n");
	}

	return 0;
}