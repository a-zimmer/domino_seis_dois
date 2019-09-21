#include "peca.h"
#include <stdio.h>
#include <stdlib.h>

int TOTAL_PIECES = 28;

TppecaDomino* createPieces ()
{
	TppecaDomino *pieces = init();
	int i, j;

	for (i = 0; i < 7; i++) {
		for (j = i; j < 7; j++) {
			pieces = insertIni(pieces, i, j);
		}
	}

	return pieces;
}

TppecaDomino* getPlayerPieces (TppecaDomino* pieces, int totPieces)
{
	TppecaDomino *sorted = (TppecaDomino *) malloc(sizeof(TppecaDomino));
	TppecaDomino *availables = pieces;
	int i, count = 0;

	while (count < totPieces) {
		int pieceNumber = randomInt(TOTAL_PIECES - count);

		printf("pieceNumber: %d\n", pieceNumber);
		printf("Before for\n");
		for (i = 0; i <= pieceNumber; i++) {
			if (i == pieceNumber) {

				printf("Before removeFromAvailables\n");
				availables = removeFromAvailables (pieces, availables);
				printf("After removeFromAvailables\n");
				//printf("Before setPlayerPiece\n");
				//sorted = setPlayerPiece (sorted, availables);
			} else {
				printf("Before numberRight: %d, numberLeft: %d\n", availables->numberRight, availables->numberLeft);
				availables = availables->right == NULL ? pieces : availables->right;
				printf("After numberRight: %d, numberLeft: %d\n\n\n\n", availables->numberRight, availables->numberLeft);
			}

		}
		printf("After for\n");

		printf("Before reset availables\n");
		printf("\n\n\n\nBefore numberRight: %d, numberLeft: %d\n", availables->numberRight, availables->numberLeft);
		availables = pieces;
		printf("After numberRight: %d, numberLeft: %d\n\n\n\n", availables->numberRight, availables->numberLeft);
		printf("After reset availables\n");

		count++;
	}

	TOTAL_PIECES -= count;

	return sorted;
}

TppecaDomino* setPlayerPiece (TppecaDomino *sorted, TppecaDomino *availables)
{
	TppecaDomino *all = sorted;
	all->left->right = availables;
	all->left->left = NULL;

	availables->left = all;
	return sorted;
}

TppecaDomino* removeFromAvailables (TppecaDomino *pieces, TppecaDomino *availables)
{
	TppecaDomino *all = availables;

	if (all == NULL) {
		printf("vazio\n");
		return pieces;
	}

	if (all->right == NULL && all->left == NULL) {
		printf("primeiro\n");
		free(all);
		return NULL;
	}


	// Exclusão no início
	if (all->left == NULL) {
		printf("Exclusão no início\n");
		all->right->left = NULL;
		free(all);
		return pieces;
	}

	// Exclusão no final
	if (all->right == NULL) {
		printf("Exclusão no final\n");
		all->left->right = NULL;
		free(all);
		return pieces;
	}

	printf("Exclusão no meio\n");

	// Exclusão no meio
	all->left->right = all->right;
	all->right->left = all->left;

	free(all);

	return pieces;
}

TppecaDomino* insertIni (TppecaDomino* pieces, int right, int left)
{
	TppecaDomino *new = malloc(sizeof(TppecaDomino));
	new->numberRight = right;
	new->numberLeft = left;
	new->right = pieces;
	new->left = NULL;

	if (pieces) {
		pieces->left = new;
	}

	return new;
}

TppecaDomino* init ()
{
	return NULL;
}

int randomInt (int length)
{
	return rand() % length;
}
