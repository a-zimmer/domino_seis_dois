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
	TppecaDomino *last;
	int i, count = 0;

	while (count < totPieces) {
		int pieceNumber = randomInt(TOTAL_PIECES - count);

		for (i = 0; i <= pieceNumber; i++) {
		printf("i: %d, pieceNumber: %d, i == pieceNumber: %d\n", i, pieceNumber, i == pieceNumber);
			if (i == pieceNumber) {
				sorted = availables;
				printf("sorted->numberRight: %d, sorted->numberLeft: %d\n", sorted->numberRight, sorted->numberLeft);
				availables = removeFromAvailables (pieces, last, availables);
			} else {
				last = availables;
				availables = availables->right;
			}

		}

		count++;
	}

	TOTAL_PIECES -= count;

	return sorted;
}

TppecaDomino* removeFromAvailables (TppecaDomino *pieces, TppecaDomino *last, TppecaDomino *availables)
{
	TppecaDomino *all = pieces;

	if (all == NULL) {
		return pieces;
	}

	if (all->right == NULL && all->left == NULL) {
		free(all);
		return NULL;
	}

	TppecaDomino *ret;

	// Exclusão no início
	if (all->left == NULL) {
		ret = all->right;
		ret->left = NULL;
		free(all);
		return ret;
	}

	// Exclusão no final
	if (all->right == NULL) {
		all->left->right = NULL;
		free(all);
		return pieces;
	}

	// Exclusão no meio
	all->left->right = all->right;
	all->right->left = all->left;
	free(all);

	return pieces;
}

TppecaDomino* insertIni (TppecaDomino* pieces, int right, int left)
{
	TppecaDomino *new = (TppecaDomino *) malloc(sizeof(TppecaDomino));
	new->numberRight = right;
	new->numberLeft = left;
	new->right = pieces;
	new->left = NULL;

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
