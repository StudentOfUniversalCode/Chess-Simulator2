#include <iostream>
using namespace std;

void Bishop(char map [] [8], int& oldX, int& oldY, int& newX, int& newY) {
	//	bool basicParameter = newX > 0 && newX <= 8 && newY > 0 && newY <= 8;
	//	if(basicParameter) {
	for(int count = 0; count <= 8; count++) {
		if((oldX + count) == newX && (oldY + count) == newY) {
			oldX = newX;
			oldY = newY;
			break;
		}
		else if((oldX - count) == newX && (oldY + count) == newY) {
			oldX = newX;
			oldY = newY;
			break;
		}
		else if((oldX + count) == newX && (oldY - count) == newY) {
			oldX = newX;
			oldY = newY;
			break;
		}
		else if((oldX - count) == newX && (oldY - count) == newY) {
			oldX = newX;
			oldY = newY;
			break;
		}
	}
	//	}
}

bool Rook(char map [] [8], int& oldX, int& oldY, int& newX, int& newY) { // Function for moving Rook

	if(newY == oldY) {
		oldX = newX;                                     //
		return 1;				                                 // Tests vertical
	}                                                    // conditions
	else if(newX == oldX) {   
		// Rook
		oldY = newY;                                     //
		return 1;
	}
	else {cout << "You be crazy.\n"; return 0;}
}

bool Queen(char map [] [8], int& oldX, int& oldY, int& newX, int& newY) { // Function for moving Queen
	bool check=1, check2=1;

	for(int i = 0; i <= 8; i++) {							// Tests diagonal conditions of Queen
		if((newX == oldX + i) && (newY == oldY + i)) {
			oldX = newX;
			oldY = newY;
			return 1;
		}
		else if((newX == oldX - i) && (newY == oldY + i)) {
			oldX = newX;
			oldY = newY;
			return 1;
		}
		else if((newX == oldX + i) && (newY == oldY - i)) {
			oldX = newX;
			oldY = newY;
			return 1;
		}
		else if((newX == oldX - i) && (newY == oldY - i)) {
			oldX = newX;
			oldY = newY;
			return 1;
		}
		else check2 = 0;
	}
	if (check2 == 0) {
		if(newY == oldY) {
			oldX = newX;                                          // Tests vertical
			return 1;
		}                                                        // conditions
		else if(newX == oldX) {							        // of Queen
			oldY = newY;                                       //
			return 1;
		}
		else check = 0;
	}

	if (check == 0 && check2 == 0) {cout << "Whatchu talkin' bout, Willis.\n"; return 0;}
}

bool King(char map [] [8], int& oldX, int& oldY, int& newX, int& newY) {
	if(((newX == oldX + 1) || (newX == oldX - 1)) && newY == oldY) {
		oldX = newX;                                                              //
		return 1;		                                                                  // Tests vertical
	}                                                                             // conditions
	else if(((newY == oldY + 1) || (newY == oldY - 1)) && newX == oldX) {           // of King
		oldY = newY;                                                              //
		return 1;
	}
	else if((newX == oldX + 1) && (newY == oldY + 1)) {
		oldX = newX;
		oldY = newY;
		return 1;
	}
	else if((newX == oldX - 1) && (newY == oldY + 1)) {                            //
		oldX = newX;                                                              // Tests diagonal
		oldY = newY;                                                              // conditions
		return 1;
	}                                                                             //
	else if((newX == oldX + 1) && (newY == oldY - 1)) {
		oldX = newX;
		oldY = newY;
		return 1;
	}
	else if((newX == oldX - 1) && (newY == oldY - 1)) {
		oldX = newX;
		oldY = newY;
		return 1;
	}
	else {cout << "What kind of crack are you smoking?\n"; return 0;};
}

bool Knight(char map [] [8], int& oldX, int& oldY, int& newX, int& newY) {
	bool plusMinusX = (newX == oldX - 1) || (newX == oldX + 1);
	bool plusMinusY = (newY == oldY - 1) || (newY == oldY + 1);
	if((newX == oldX - 2) && plusMinusY) {
		oldX = newX;                                     //  *
		oldY = newY;                                     //  *****
		return 1;												 //  *
	}
	else if((newX == oldX + 2) && plusMinusY) {
		oldX = newX;                                     //      *
		oldY = newY;                                     //  *****
		return 1;	                                             //      *
	}
	else if((newY == oldY - 2) && plusMinusX) {
		oldX = newX;                                     //   *
		oldY = newY;                                     //   *
		return 1;	                                             // *****
	}
	else if((newY == oldY + 2) && plusMinusX) {
		oldX = newX;                                     // *****
		oldY = newY;                                     //   *
		return 1;	                                             //   *
	}
	else {cout << "You make the chess monster sad, but he is also hungry... so watch out.\n"; return 0;}
}

// Pawn Movement Function
bool Pawn(char map[] [8], int& oldX, int& oldY, int& newX, int& newY, bool& firstPlay, bool color, bool isCapture) {
	if(color==1) { // Black
		cout << "Black" << endl;
		if(firstPlay) { // Checks if pawn has moved before, if not, executes nested statements, if so, skips to else statement
			if(((newY == oldY + 2) || (newY == oldY + 1)) && (newX == oldX)) {oldY = newY; return 1;}
			else if(isCapture = 1 && ((newY == oldY + 1 && newX == oldX + 1) || (newY == oldY + 1 && newX == oldX - 1))) {oldX = newX; oldY = newY; isCapture = 0; return 1;}
			else {cout << "INVALID COORDINATES." << endl; return 0;}
			firstPlay = false;
		}
		else {
			if((newY == oldY + 1) && (newX == oldX)) {oldY = newY; return 1;}
			else if(isCapture = 1 && ((newY == oldY + 1 && newX == oldX + 1) || (newY == oldY + 1 && newX == oldX - 1))) {oldX = newX; oldY = newY; isCapture = 0; return 1;}
			else {cout << "COORDINATES INVALID." << endl; return 0;}
		}
	}
	else { // White
		cout << "White" << endl;
		if(firstPlay) {
			if(((newY == oldY - 2) || (newY == oldY - 1)) && (newX == oldX)) {oldY = newY; return 1;}
			else if(isCapture = 1 && ((newY == oldY + 1 && newX == oldX + 1) || (newY == oldY + 1 && newX == oldX - 1))) {oldX = newX; oldY = newY; isCapture = 0; return 1;}
			else {cout << "INVALID COORDINATES." << endl; return 0;}
			firstPlay = false;
		}
		else {
			if(newY == oldY - 1 && newX == oldX) {oldY = newY; return 1;}
			else if(isCapture = 1 && ((newY == oldY + 1 && newX == oldX + 1) || (newY == oldY + 1 && newX == oldX - 1))) {oldX = newX; oldY = newY; isCapture = 0; return 1;}
			else {cout << "COORDINATES INVALID." << endl; return 0;}
		}
	}
}

bool swap(bool turn) {
	if (turn==1)
		return 0;
	if (turn==0)
		return 1;
}