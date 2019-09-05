#ifndef PECA_H
#define PECA_H

typedef struct _pecaDomino {
	int numberRight;
	int numberLeft;
	struct _pecaDomino *right;
	struct _pecaDomino *left;
} TppecaDomino;

TppecaDomino* init ();
TppecaDomino* create ();
TppecaDomino* insertIni (TppecaDomino* pieces, int right, int left);

#endif