#ifndef PECA_H
#define PECA_H

int TOTAL_PIECES;

typedef struct _pecaDomino {
	int numberRight;
	int numberLeft;
	struct _pecaDomino *right;
	struct _pecaDomino *left;
} TppecaDomino;

int randomInt (int length);

TppecaDomino* init ();
TppecaDomino* createPieces ();
TppecaDomino* getPlayerPieces (TppecaDomino* pieces, int totPieces);
TppecaDomino* insertIni (TppecaDomino* pieces, int right, int left);
TppecaDomino* removeFromAvailables (TppecaDomino *pieces, TppecaDomino *last, TppecaDomino *availables);

#endif