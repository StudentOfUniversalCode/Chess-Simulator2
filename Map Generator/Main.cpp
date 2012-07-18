//Created by B.Hassell on 11.23.11
//Generates the playing board, or map
//Last modified: 12.12.11

//Comments  (45/45):
//
// 1) Nice work. I like the game board
// 2) I wonder if an enum for the pieces (instead of 'j', 'm', 'n', 'p') would be more readable?


#include <iostream>
#include <iomanip>
#include <string>
#include "Map_Maker.h"
#include "Definitions.h"
#include "Play.h"
#include "IntroScreen.h"
#include "Display.h"
#include "Psuedo.h"
#include "Interpret.h"
using namespace std;

int main() {


	//initial declarations
	static pawn BPawna, BPawnb, BPawnc, BPawnd, BPawne, BPawnf, BPawng, BPawnh;
	static pawn WPawna, WPawnb, WPawnc, WPawnd, WPawne, WPawnf, WPawng, WPawnh;
	static bishop BBishopa, BBishopb;
	static bishop WBishopa, WBishopb;
	static rook BRooka, BRookb;
	static rook WRooka, WRookb;
	static queen BQueen, WQueen;
	static knight BKnighta, BKnightb;
	static knight WKnighta, WKnightb;
	static king BKing, WKing;
	BPawnh.posx = 7;
	BPawnh.posy = 1;
	BPawnh.color = 1;
	BPawng.posx = 6;
	BPawng.posy = 1;
	BPawng.color = 1;
	BPawnf.posx = 5;
	BPawnf.posy = 1;
	BPawnf.color = 1;
	BPawne.posx = 4;
	BPawne.posy = 1;
	BPawne.color = 1;
	BPawnd.posx = 3;
	BPawnd.posy = 1;
	BPawnd.color = 1;
	BPawnc.posx = 2;
	BPawnc.posy = 1;
	BPawnc.color = 1;
	BPawnb.posx = 1;
	BPawnb.posy = 1;
	BPawnb.color = 1;
	BKnightb.posx = 6;
	BKnightb.posy = 0;
	BKing.posx = 4;
	BKing.posy = 0;
	BBishopb.posx = 5;
	BBishopb.posy = 0;
	BKnighta.posx = 1;
	BKnighta.posy = 0;
	BQueen.posx = 3;
	BQueen.posy = 0;
	BRooka.posx = 0;
	BRooka.posy = 0;
	BRookb.posx = 7;
	BRookb.posy = 0;
	BPawna.posx = 0;
	BPawna.posy = 1;
	BPawna.color = 1;
	BBishopa.posx = 2;
	BBishopa.posy = 0;
	//White definitions
	WPawnh.posx = 7;
	WPawnh.posy = 6;
	WPawnh.color = 0;
	WPawng.posx = 6;
	WPawng.posy = 6;
	WPawng.color = 0;
	WPawnf.posx = 5;
	WPawnf.posy = 6;
	WPawnf.color = 0;
	WPawne.posx = 4;
	WPawne.posy = 6;
	WPawne.color = 0;
	WPawnd.posx = 3;
	WPawnd.posy = 6;
	WPawnd.color = 0;
	WPawnc.posx = 2;
	WPawnc.posy = 6;
	WPawnc.color = 0;
	WPawnb.posx = 1;
	WPawnb.posy = 6;
	WPawnb.color = 0;
	WKnightb.posx = 6;
	WKnightb.posy = 7;
	WKnightb.color = 0;
	WKing.posx = 4;
	WKing.posy = 7;
	WKing.color = 1;
	WBishopb.posx = 5;
	WBishopb.posy = 7;
	WBishopb.color = 1;
	WKnighta.posx = 1;
	WKnighta.posy = 7;
	WKnighta.color = 1;
	WQueen.posx = 3;
	WQueen.posy = 7;
	WQueen.color = 1;
	WRooka.posx = 0;
	WRooka.posy = 7;
	WRooka.color = 1;
	WRookb.posx = 7;
	WRookb.posy = 7;
	WRookb.color = 1;
	WPawna.posx = 0;
	WPawna.posy = 6;
	WPawna.color = 0;
	WBishopa.posx = 2;
	WBishopa.posy = 7;
	WBishopa.color = 1;
	char x;
	int y, X=0;
	char map [ROWS] [COLLUMNS];
	bool turn=1, possible=0;
	bool capture = 0;


	//Cycles Program until x = -1

	string Name;

	do {
		bool move = 1;
		MapMaker(map, ROWS, COLLUMNS);						//Generates plain chess board
		//Gives position of Black Pawn A
		if (BPawna.inPlay != false)
			map [BPawna.posx] [BPawna.posy] = 'j';			//Black pawn a is j
		if (BPawnb.inPlay != false)
			map [BPawnb.posx] [BPawnb.posy] = 'p';			//Black pawn b is p
		if (BPawnc.inPlay != false)
			map [BPawnc.posx] [BPawnc.posy] = 'm';			//Black pawn c is m
		if (BPawnd.inPlay != false)
			map [BPawnd.posx] [BPawnd.posy] = 'n';			//Black pawn d is n
		if (BPawne.inPlay != false)
			map [BPawne.posx] [BPawne.posy] = 'i';			//Black pawn e is i
		if (BPawnf.inPlay != false)
			map [BPawnf.posx] [BPawnf.posy] = 'y';			//Black pawn f is y
		if (BPawng.inPlay != false)
			map [BPawng.posx] [BPawng.posy] = 't';			//Black pawn g is t
		if (BPawnh.inPlay != false)
			map [BPawnh.posx] [BPawnh.posy] = 'r';			//Black pawn h is r
		if (BRooka.inPlay != false)
			map [BRooka.posx] [BRooka.posy] = 'f';			//Black rook a is f
		if (BRookb.inPlay != false)
			map [BRookb.posx] [BRookb.posy] = 'v';			//Black rook b is v
		if (BQueen.inPlay != false)
			map [BQueen.posx] [BQueen.posy] = 'l';			//Black queen is l
		if (BKnighta.inPlay != false)
			map [BKnighta.posx] [BKnighta.posy] = 'k';		//Black knight a is k
		if (BKnightb.inPlay != false)
			map [BKnightb.posx] [BKnightb.posy] = 'c';		//Black knight b is c
		if (BBishopb.inPlay != false)
			map [BBishopb.posx] [BBishopb.posy] = 'h';		//Black bishop b is h
		if (BBishopa.inPlay != false)
			map [BBishopa.posx] [BBishopa.posy] = 'u';		//Black bishop a is u
		if (BKing.inPlay != false)
			map [BKing.posx] [BKing.posy] = 'o';			//Black king is o
		if (WPawna.inPlay != false)
			map [WPawna.posx] [WPawna.posy] = 1;			//Wlack pawn a is 1
		if (WPawnb.inPlay != false)
			map [WPawnb.posx] [WPawnb.posy] = 2;			//Wlack pawn b is 2
		if (WPawnc.inPlay != false)
			map [WPawnc.posx] [WPawnc.posy] = 3;			//Wlack pawn c is 3
		if (WPawnd.inPlay != false)
			map [WPawnd.posx] [WPawnd.posy] = 4;			//Wlack pawn d is 4
		if (WPawne.inPlay != false)
			map [WPawne.posx] [WPawne.posy] =5;				//Wlack pawn e is 5
		if (WPawnf.inPlay != false)
			map [WPawnf.posx] [WPawnf.posy] = 6;			//Wlack pawn f is 6
		if (WPawng.inPlay != false)
			map [WPawng.posx] [WPawng.posy] = 7;			//Wlack pawn g is 7
		if (WPawnh.inPlay != false)
			map [WPawnh.posx] [WPawnh.posy] = 8;			//Wlack pawn h is 8
		if (WRooka.inPlay != false)
			map [WRooka.posx] [WRooka.posy] = 9;			//Wlack rook a is 9
		if (WRookb.inPlay != false)
			map [WRookb.posx] [WRookb.posy] = 10;			//Wlack rook W is 10
		if (WQueen.inPlay != false)
			map [WQueen.posx] [WQueen.posy] = 11;			//Wlack queen is 11
		if (WKnighta.inPlay != false)
			map [WKnighta.posx] [WKnighta.posy] = 12;		//Wlack knight a is 12
		if (WKnightb.inPlay != false)
			map [WKnightb.posx] [WKnightb.posy] = 13;		//Wlack knight b is 13
		if (WBishopb.inPlay != false)
			map [WBishopb.posx] [WBishopb.posy] = 15;		//Wlack Wishop b is 14
		if (WBishopa.inPlay != false)
			map [WBishopa.posx] [WBishopa.posy] = 14;		//Wlack Wishop a is 15
		if (WKing.inPlay != false)
			map [WKing.posx] [WKing.posy] = 16;				//Wlack king is 16

		displayBoard(map);


		if (turn == 0)
			cout << "It is White's turn." << endl;
		else if (turn == 1)
			cout << "It is Black's turn." << endl;
		cout << "Available pieces to play are: " << endl;

		if (turn == 0) {//white's turn
			if (WPawna.inPlay == 1)
				cout << "Pawna (wpa), ";
			if (WPawnb.inPlay == 1)
				cout << "Pawnw (wpb), ";
			if (WPawnc.inPlay == 1)
				cout << "Pawnc (wpc), ";
			if (WPawnd.inPlay == 1)
				cout << "Pawnd (wpd), ";
			if (WPawne.inPlay == 1)
				cout << "Pawne (wpe), ";
			if (WPawnf.inPlay == 1)
				cout << "Pawnf (wpf), ";
			if (WPawng.inPlay == 1)
				cout << "Pawng (wpg), ";
			if (WPawnh.inPlay == 1)
				cout << "Pawnh (wph), ";
			if (WKnighta.inPlay == 1)
				cout << "Knight1 (wk1), ";
			if (WKnightb.inPlay == 1)
				cout << "Knight2 (wk2), ";
			if (WRooka.inPlay == 1)
				cout << "Rook1 (wr1), ";
			if (WRookb.inPlay == 1)
				cout << "Rook2 (wr2), ";
			if (WBishopa.inPlay == 1)
				cout << "Bishop1 (wb1), ";
			if (WBishopb.inPlay == 1)
				cout << "Bishop2 (wb2), ";
			if (WQueen.inPlay == 1)
				cout << "Queen (wqueen), ";
			if (WKing.inPlay == 1)
				cout << "King (wking)";
			cout << endl;
		}
		else if (turn == 1) { //black's turn
			if (BPawna.inPlay == 1)
				cout << "Pawna (bpa), ";
			if (BPawnb.inPlay == 1)
				cout << "Pawnb (bpb), ";
			if (BPawnc.inPlay == 1)
				cout << "Pawnc (bpc), ";
			if (BPawnd.inPlay == 1)
				cout << "Pawnd (bpd), ";
			if (BPawne.inPlay == 1)
				cout << "Pawne (bpe), ";
			if (BPawnf.inPlay == 1)
				cout << "Pawnf (bpf), ";
			if (BPawng.inPlay == 1)
				cout << "Pawng (bpg), ";
			if (BPawnh.inPlay == 1)
				cout << "Pawnh (bph), ";
			if (BKnighta.inPlay == 1)
				cout << "Knight1 (bk1), ";
			if (BKnightb.inPlay == 1)
				cout << "Knight2 (bk2), ";
			if (BRooka.inPlay == 1)
				cout << "Rook1 (br1), ";
			if (BRookb.inPlay == 1)
				cout << "Rook2 (br2), ";
			if (BBishopa.inPlay == 1)
				cout << "Bishop1 (bb1), ";
			if (BBishopb.inPlay == 1)
				cout << "Bishop2 (bb2), ";
			if (BQueen.inPlay == 1)
				cout << "Queen (bqueen), ";
			if (BKing.inPlay == 1)
				cout << "King (bking)";
			cout << endl;
		}

		cout << "Enter the name of the piece, along with the coordinates: ";
		cin >> Name >> x >> y;

		switch (x) {
		case 'a': X = 1; break;
		case 'b': X = 2; break;
		case 'c': X = 3; break;
		case 'd': X = 4; break;
		case 'e': X = 5; break;
		case 'f': X = 6; break;
		case 'g': X = 7; break;
		case 'h': X = 8; break;
		default: X = 8; break;
		}

		switch (y) {
		case 8: y = 1; break;
		case 7: y = 2; break;
		case 6: y = 3; break;
		case 5: y = 4; break;
		case 4: y = 5; break;
		case 3: y = 6; break;
		case 2: y = 7; break;
		case 1: y = 8; break;
		default: y = 8; break;
		}

		X-=1;
		y-=1;

		cout << "X is " << X << " and Y is " << y << endl;
		cout << "Move is " << move;

		if(turn == 1) {
			// Same Color Collision
			if(BPawna.posx == X && BPawna.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BPawnb.posx == X && BPawnb.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BPawnc.posx == X && BPawnc.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BPawnd.posx == X && BPawnd.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BPawne.posx == X && BPawne.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BPawnf.posx == X && BPawnf.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BPawng.posx == X && BPawng.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BPawnh.posx == X && BPawnh.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BBishopa.posx == X && BBishopa.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BBishopb.posx == X && BBishopb.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BKnighta.posx == X && BKnighta.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BKnightb.posx == X && BKnightb.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BKing.posx == X && BKing.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BQueen.posx == X && BQueen.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BRooka.posx == X && BRooka.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(BRookb.posx == X && BRookb.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			cout << endl;

		}

		if(turn == 0) {
			// Same Color Collision
			if(WPawna.posx == X && WPawna.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WPawnb.posx == X && WPawnb.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WPawnc.posx == X && WPawnc.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WPawnd.posx == X && WPawnd.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WPawne.posx == X && WPawne.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WPawnf.posx == X && WPawnf.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WPawng.posx == X && WPawng.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WPawnh.posx == X && WPawnh.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WBishopa.posx == X && WBishopa.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WBishopb.posx == X && WBishopb.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WKnighta.posx == X && WKnighta.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WKnightb.posx == X && WKnightb.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WKing.posx == X && WKing.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WQueen.posx == X && WQueen.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WRooka.posx == X && WRooka.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			else if(WRookb.posx == X && WRookb.posy == y) {
				cout << "Can not move there.";
				move = 0;
			}
			cout << endl;

		}

		if (move == 1 && turn == 1) {
			if (Name == "bpa" || Name == "BPa" || Name == "Bpa" || Name == "bPa" && BPawna.inPlay == 1)
				Pawn(map, BPawna.posx, BPawna.posy, X, y, BPawna.firstPlay, BPawna.color, capture);
			else if (Name == "bpb" || Name == "BPb" || Name == "Bpb" || Name == "bPb" && BPawnb.inPlay == 1)
				Pawn(map, BPawnb.posx, BPawnb.posy, X, y, BPawnb.firstPlay, BPawnb.color, capture);
			else if (Name == "bpc" || Name == "BPc" || Name == "Bpc" || Name == "bPc" && BPawnc.inPlay == 1)
				Pawn(map, BPawnc.posx, BPawnc.posy, X, y, BPawnc.firstPlay, BPawnc.color, capture);
			else if (Name == "bpd" || Name == "BPd" || Name == "Bpd" || Name == "bPd" && BPawnd.inPlay == 1)
				Pawn(map, BPawnd.posx, BPawnd.posy, X, y, BPawnd.firstPlay, BPawnd.color, capture);
			else if (Name == "bpe" || Name == "BPe" || Name == "Bpe" || Name == "bPe" && BPawne.inPlay == 1)
				Pawn(map, BPawne.posx, BPawne.posy, X, y, BPawne.firstPlay, BPawne.color, capture);
			else if (Name == "bpf" || Name == "BPf" || Name == "Bpf" || Name == "bPf" && BPawnf.inPlay == 1)
				Pawn(map, BPawnf.posx, BPawnf.posy, X, y, BPawnf.firstPlay, BPawnf.color, capture);
			else if (Name == "bpg" || Name == "BPg" || Name == "Bpg" || Name == "bPg" && BPawng.inPlay == 1)
				Pawn(map, BPawng.posx, BPawng.posy, X, y, BPawng.firstPlay, BPawng.color, capture);
			else if (Name == "bph" || Name == "BPh" || Name == "Bph" || Name == "bPh" && BPawnh.inPlay == 1)
				Pawn(map, BPawnh.posx, BPawnh.posy, X, y, BPawnh.firstPlay, BPawnh.color, capture);
			else if (Name == "BB1" || Name == "bB1" || Name == "Bb1" || Name == "bb1" && BBishopa.inPlay == 1)
				Bishop(map, BBishopa.posx, BBishopa.posy, X, y);
			else if (Name == "BB2" || Name == "bB2" || Name == "Bb2" || Name == "bb2" && BBishopb.inPlay == 1)
				Bishop(map, BBishopb.posx, BBishopb.posy, X, y);
			else if (Name == "BK1" || Name == "bK1" || Name == "Bk1" || Name == "bk1" && BKnighta.inPlay == 1)
				Knight(map, BKnighta.posx, BKnighta.posy, X, y);
			else if (Name == "BK2" || Name == "bK2" || Name == "Bk2" || Name == "bk2" && BKnightb.inPlay == 1)
				Knight(map, BKnightb.posx, BKnightb.posy, X, y);
			else if (Name == "Bking" || Name == "bKing" || Name == "BKing" || Name == "bking" && BKing.inPlay == 1)
				King(map, BKing.posx, BKing.posy, X, y);
			else if (Name == "BQueen" || Name == "bqueen" || Name == "Bqueen" || Name == "bQueen" && BQueen.inPlay == 1)
				Queen(map, BQueen.posx, BQueen.posy, X, y);
			else if (Name == "BR1" || Name == "br1" || Name == "Br1" || Name == "bR1" && BRooka.inPlay == 1)
				Rook(map, BRooka.posx, BRooka.posy, X, y);
			else if (Name == "BR2" || Name == "br2" || Name == "Br2" || Name == "bR2" && BRookb.inPlay == 1)
				Rook(map, BRookb.posx, BRookb.posy, X, y);
		}
		if (move == 1 && turn == 0) {
			if (Name == "wpa" || Name == "WPa" || Name == "Wpa" || Name == "wPa" && WPawna.inPlay == 1)
				Pawn(map, WPawna.posx, WPawna.posy, X, y, WPawna.firstPlay, WPawna.color, capture);
			else if (Name == "wpb" || Name == "WPb" || Name == "Wpb" || Name == "wPb" && WPawnb.inPlay == 1)
				Pawn(map, WPawnb.posx, WPawnb.posy, X, y, WPawnb.firstPlay, WPawnb.color, capture);
			else if (Name == "wpc" || Name == "WPc" || Name == "Wpc" || Name == "wPc" && WPawnc.inPlay == 1)
				Pawn(map, WPawnc.posx, WPawnc.posy, X, y, WPawnc.firstPlay, WPawnc.color, capture);
			else if (Name == "wpd" || Name == "WPd" || Name == "Wpd" || Name == "wPd" && WPawnd.inPlay == 1)
				Pawn(map, WPawnd.posx, WPawnd.posy, X, y, WPawnd.firstPlay, WPawnd.color, capture);
			else if (Name == "wpe" || Name == "WPe" || Name == "Wpe" || Name == "wPe" && WPawne.inPlay == 1)
				Pawn(map, WPawne.posx, WPawne.posy, X, y, WPawne.firstPlay, WPawne.color, capture);
			else if (Name == "wpf" || Name == "WPf" || Name == "Wpf" || Name == "wPf" && WPawnf.inPlay == 1)
				Pawn(map, WPawnf.posx, WPawnf.posy, X, y, WPawnf.firstPlay, WPawnf.color, capture);
			else if (Name == "wpg" || Name == "WPg" || Name == "Wpg" || Name == "wPg" && WPawng.inPlay == 1)
				Pawn(map, WPawng.posx, WPawng.posy, X, y, WPawng.firstPlay, WPawng.color, capture);
			else if (Name == "wph" || Name == "WPh" || Name == "Wph" || Name == "wPh" && WPawnh.inPlay == 1)
				Pawn(map, WPawnh.posx, WPawnh.posy, X, y, WPawnh.firstPlay, WPawnh.color, capture);
			else if (Name == "WB1" || Name == "wB1" || Name == "Wb1" || Name == "wb1" && WBishopa.inPlay == 1)
				Bishop(map, WBishopa.posx, WBishopa.posy, X, y);
			else if (Name == "WW2" || Name == "wW2" || Name == "Ww2" || Name == "ww2" && WBishopb.inPlay == 1)
				Bishop(map, WBishopb.posx, WBishopb.posy, X, y);
			else if (Name == "WK1" || Name == "wK1" || Name == "Wk1" || Name == "wk1" && WKnighta.inPlay == 1)
				Knight(map, WKnighta.posx, WKnighta.posy, X, y);
			else if (Name == "WK2" || Name == "wK2" || Name == "Wk2" || Name == "wk2" && WKnightb.inPlay == 1)
				Knight(map, WKnightb.posx, WKnightb.posy, X, y);
			else if (Name == "Wking" || Name == "wKing" || Name == "WKing" || Name == "wking" && WKing.inPlay == 1)
				King(map, WKing.posx, WKing.posy, X, y);
			else if (Name == "WQueen" || Name == "wqueen" || Name == "Wqueen" || Name == "wQueen" && WQueen.inPlay == 1)
				Queen(map, WQueen.posx, WQueen.posy, X, y);
			else if (Name == "WR1" || Name == "wr1" || Name == "Wr1" || Name == "wR1" && WRooka.inPlay == 1)
				Rook(map, WRooka.posx, WRooka.posy, X, y);
			else if (Name == "WR2" || Name == "wr2" || Name == "Wr2" || Name == "wR2" && WRookb.inPlay == 1)
				Rook(map, WRookb.posx, WRookb.posy, X, y);
		}

		if (turn==1 && move==1) {
			// Different Color Collision
			if(WPawna.posx == X && WPawna.posy == y) {WPawna.inPlay = 0; capture = 1; cout << "White Pawn a has been captured." << endl;}
			else if(WPawnb.posx == X && WPawnb.posy == y) {WPawnb.inPlay = 0; capture = 1; cout << "White Pawn b has been captured." << endl;}
			else if(WPawnc.posx == X && WPawnc.posy == y) {WPawnc.inPlay = 0; capture = 1; cout << "White Pawn c has been captured." << endl;}
			else if(WPawnd.posx == X && WPawnd.posy == y) {WPawnd.inPlay = 0; capture = 1; cout << "White Pawn d has been captured." << endl;}
			else if(WPawne.posx == X && WPawne.posy == y) {WPawne.inPlay = 0; capture = 1; cout << "White Pawn e has been captured." << endl;}
			else if(WPawnf.posx == X && WPawnf.posy == y) {WPawnf.inPlay = 0; capture = 1; cout << "White Pawn f has been captured." << endl;}
			else if(WPawng.posx == X && WPawng.posy == y) {WPawng.inPlay = 0; capture = 1; cout << "White Pawn g has been captured." << endl;}
			else if(WPawnh.posx == X && WPawnh.posy == y) {WPawnh.inPlay = 0; capture = 1; cout << "White Pawn h has been captured." << endl;}
			else if(WBishopa.posx == X && WBishopa.posy == y) {WBishopa.inPlay = 0; capture = 1; cout << "White Bishop 1 has been captured." << endl;}
			else if(WBishopb.posx == X && WBishopb.posy == y) {WBishopb.inPlay = 0; capture = 1; cout << "White Bishop 2 has been captured." << endl;}
			else if(WKnighta.posx == X && WKnighta.posy == y) {WKnighta.inPlay = 0; capture = 1; cout << "White Knight 1 has been captured." << endl;}
			else if(WKnightb.posx == X && WKnightb.posy == y) {WKnightb.inPlay = 0; capture = 1; cout << "White Knight 2 has been captured." << endl;}
			else if(WRooka.posx == X && WRooka.posy == y) {WRooka.inPlay = 0; capture = 1; cout << "White Rook 1 has been captured." << endl;}
			else if(WRookb.posx == X && WRookb.posy == y) {WRookb.inPlay = 0; capture = 1; cout << "White Rook 2 has been captured." << endl;}
			else if(WKing.posx == X && WKing.posy == y) {WKing.inPlay = 0; capture = 1; cout << "White King has been captured." << endl;}
			else if(WQueen.posx == X && WQueen.posy == y) {WQueen.inPlay = 0; capture = 1; cout << "White Queen has been captured." << endl;}
		}

		if (turn==0 && move==1) {
			// Different Color Collision
			if(BPawna.posx == X && BPawna.posy == y) {BPawna.inPlay = 0; capture = 1; cout << "Black Pawn a has been captured." << endl;}
			else if(BPawnb.posx == X && BPawnb.posy == y) {BPawnb.inPlay = 0; capture = 1; cout << "Black Pawn b has been captured." << endl;}
			else if(BPawnc.posx == X && BPawnc.posy == y) {BPawnc.inPlay = 0; capture = 1; cout << "Black Pawn c has been captured." << endl;}
			else if(BPawnd.posx == X && BPawnd.posy == y) {BPawnd.inPlay = 0; capture = 1; cout << "Black Pawn d has been captured." << endl;}
			else if(BPawne.posx == X && BPawne.posy == y) {BPawne.inPlay = 0; capture = 1; cout << "Black Pawn e has been captured." << endl;}
			else if(BPawnf.posx == X && BPawnf.posy == y) {BPawnf.inPlay = 0; capture = 1; cout << "Black Pawn f has been captured." << endl;}
			else if(BPawng.posx == X && BPawng.posy == y) {BPawng.inPlay = 0; capture = 1; cout << "Black Pawn g has been captured." << endl;}
			else if(BPawnh.posx == X && BPawnh.posy == y) {BPawnh.inPlay = 0; capture = 1; cout << "Black Pawn h has been captured." << endl;}
			else if(BBishopa.posx == X && BBishopa.posy == y) {BBishopa.inPlay = 0; capture = 1; cout << "Black Bishop 1 has been captured." << endl;}
			else if(BBishopb.posx == X && BBishopb.posy == y) {BBishopb.inPlay = 0; capture = 1; cout << "Black Bishop 2 has been captured." << endl;}
			else if(BKnighta.posx == X && BKnighta.posy == y) {BKnighta.inPlay = 0; capture = 1; cout << "Black Knight 1 has been captured." << endl;}
			else if(BKnightb.posx == X && BKnightb.posy == y) {BKnightb.inPlay = 0; capture = 1; cout << "Black Knight 2 has been captured." << endl;}
			else if(BRooka.posx == X && BRooka.posy == y) {BRooka.inPlay = 0; capture = 1; cout << "Black Rook 1 has been captured." << endl;}
			else if(BRookb.posx == X && BRookb.posy == y) {BRookb.inPlay = 0; capture = 1; cout << "Black Rook 2 has been captured." << endl;}
			else if(BKing.posx == X && BKing.posy == y) {BKing.inPlay = 0; capture = 1; cout << "Black King has been captured." << endl;}
			else if(BQueen.posx == X && BQueen.posy == y) {BQueen.inPlay = 0; capture = 1; cout << "Black Queen has been captured." << endl;}
		}

		if (move==1){
			turn=swap(turn);
		}
		else turn = turn;
	}while (x!=-1);

	return 0;
}