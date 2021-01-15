#ifndef _sandpile_h__
#define _sandpile_h__

#include <stdio.h>
#include <stdlib.h>

void myprint_grid(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);
void topple(int grid1[3][3]);
void add_grids(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid1[3][3]);
void alt_myprint_grid(int grid[3][3]);

#endif
