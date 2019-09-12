#include "peca.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main ()
{
	srand(time(NULL));
	TppecaDomino* pieces = createPieces();
	TppecaDomino* all = pieces;
	int i;

	for (i = 0; i < 28; i++) {
		printf("i: %d, Right: %d, Left: %d\n", i, all->numberRight, all->numberLeft);
		all = all->right;
	}

	printf("\n\n----------------------------------------------------\n\n");

	TppecaDomino* playerOnePieces = getPlayerPieces(pieces, 7);
	all = playerOnePieces;

	for (i = 0; i < 7; i++) {
		printf("i: %d, Right: %d, Left: %d\n", i, all->numberRight, all->numberLeft);
		all = all->right;
	}

	printf("\n\n----------------------------------------------------\n\n");

	TppecaDomino* playerTwoPieces = getPlayerPieces(pieces, 7);
	all = playerTwoPieces;

	for (i = 0; i < 7; i++) {
		printf("i: %d, Right: %d, Left: %d\n", i, all->numberRight, all->numberLeft);
		all = all->right;
	}
	return 0;
}