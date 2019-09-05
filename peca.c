#include "peca.h"
#include <stdio.h>
#include <stdlib.h>

TppecaDomino* create ()
{
	TppecaDomino *pieces = init();
	int i, j;

	for (i = 0; i < 7; i++) {
		for (j = i; j < 7; j++) {
			pieces = insertIni(pieces, i, j)
		}
	}

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
