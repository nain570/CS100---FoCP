/********************************************************
 * lifegame.c -- utility functions for Convoy's Game of Life. *
 * *
 * Author. TODO.*
 * *
 * Purpose. function definitions for the game. *
 * *
 * Usage. *
 * Call the functions in main() to evolve the world. *
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include "lifegame.h"

/* hard-coded world size */
#define WORLDHEIGHT 10
#define WORLDWIDTH  10

/* character representations of cell states */
#define CHAR_ALIVE '*'
#define CHAR_DEAD  ' '

/* current cell states of the world */
static int world[WORLDHEIGHT][WORLDWIDTH];

/* next generation cell states */
static int nextstates[WORLDHEIGHT][WORLDWIDTH];

/* 
 * initialize the world to a hard-coded pattern, and 
 * reset all the cells in the next generation to DEAD 
 */
void initialize_world(void) {
	int i, j;

	for (i = 0; i < WORLDHEIGHT; i++)
		for (j = 0; j < WORLDWIDTH; j++)
			world[i][j] = nextstates[i][j] = DEAD;
	/* pattern "glider" */	
	world[5][4] = ALIVE;
	world[3][1] = ALIVE;
	world[6][2] = ALIVE;
	world[4][3] = ALIVE;
	world[2][4] = ALIVE;
}

int get_world_width(void) {
	return WORLDWIDTH;
}

int get_world_height(void) {
	return WORLDHEIGHT;
}

int get_cell_state(int x, int y) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT)
		return DEAD;
	return world[x][y];
}

void set_cell_state(int x, int y, int state) {
	if (x < 0 || x >= WORLDWIDTH || y < 0 || y >= WORLDHEIGHT) {
		fprintf(stderr,"Error: coordinates (%d,%d) are invalid.\n", x, y);
		abort();
	}
	nextstates[x][y] = state;
}

int num_neighbors(int x, int y) {
	
	/* your code comes here!!! */	
	int neighbours = 0; //for counting alive neighbours
	int i, j; //for loops
	
	for (i = x - 1; i <= x + 1; ++i){
		for (j = y-1; j <= y + 1; ++j){
			if (i == x && j == y) //skipping the cell itself
				continue;
			if (get_cell_state(i, j) == 1) //if neighbour is alive, add 1 to neighbour
				++neighbours;
		}
	}
	return neighbours;
}

int get_next_state(int x, int y) {
	
	/* your code comes here!!! */
	int numNeighbours = num_neighbors(x, y); //NO. of neighbours
	//RULES
	if ((world[x][y] == 1) && (numNeighbours != 2 && numNeighbours != 3))
		return 0;
	else if ((world[x][y] == 1) && (numNeighbours == 2 || numNeighbours == 3))
		return 1;
	else if ((world[x][y] == 0) && (numNeighbours == 3))
		return 1;
	else if ((world[x][y] == 0) && (numNeighbours != 3))
		return 0;
}

void next_generation(void) {
	
	/* your code comes here!!! */
	int x, y; //for current cell coordinates
	for (x = 0; x < WORLDHEIGHT; ++x){
		for (y = 0; y < WORLDWIDTH; ++y){
			if (get_next_state(x, y) == 1) //setting next states to be Alive or dead
				set_cell_state(x, y, 1);
			else
				set_cell_state(x, y, 0);
		}
	}
			
	finalize_evolution(); /* called at end to finalize */
}


void finalize_evolution(void) {
	int x, y;
	for (x = 0; x < WORLDHEIGHT; x++) {
		for (y = 0; y < WORLDWIDTH; y++) {
			world[x][y] = nextstates[x][y];
			nextstates[x][y] = DEAD;
		}
	}
}

void output_world(void) {
	char worldstr[2*WORLDWIDTH+2];
	int i, j;

	worldstr[2*WORLDWIDTH+1] = '\0';
	worldstr[0] = '+';
	for (i = 1; i < 2*WORLDWIDTH; i++)
		worldstr[i] = '-';
	worldstr[2*WORLDWIDTH] = '+';
	puts(worldstr);
	for (i = 0; i <= 2*WORLDWIDTH; i+=2)
		worldstr[i] = '|';
	for (i = 0; i < WORLDHEIGHT; i++) {
		for (j = 0; j < WORLDWIDTH; j++)
			worldstr[2*j+1] = world[i][j] == ALIVE ? CHAR_ALIVE : CHAR_DEAD;
		puts(worldstr);
	}
	worldstr[0] = '+';
	for (i = 1; i < 2*WORLDWIDTH; i++)
		worldstr[i] = '-';
	worldstr[2*WORLDWIDTH] = '+';
	puts(worldstr);
}
