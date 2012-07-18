//Holds functions for displaying each piece in ASCII

void displayBoard(char map [] [8]) {
	char rtop = 187, rbot = 188;
	
 //Displays chess board with positions of pieces
	cout << "     a  b  c  d  e  f  g  h " << endl;
	cout << "   �������������������������" << rtop << endl;
	for (int count=0; count < ROWS; count++) {
		cout << " " << ROWS-count << " �";
		for (int counter=0; counter < COLLUMNS; counter++) {
			switch (map [counter] [count]) {
			case 'w': cout << "���"; break;		//White tile
			case 'b': cout << "���"; break;		//Black tile
			case 'j': cout << "B�a"; break;		//Black pawn a
			case 'p': cout << "B�b"; break;		//Black pawn b
			case 'm': cout << "B�c"; break;		//Black pawn c
			case 'n': cout << "B�d"; break;		//Black pawn d
			case 'i': cout << "B�e"; break;		//Black pawn e
			case 'y': cout << "B�f"; break;		//Black pawn f
			case 't': cout << "B�g"; break;		//Black pawn g
			case 'r': cout << "B�h"; break;		//Black pawn h
			case 'k': cout << "Bk1"; break;		//Black knight a
			case 'c': cout << "Bk2"; break;		//Black knight b
			case 'f': cout << "B�1"; break;		//Black rook a
			case 'v': cout << "B�2"; break;		//Black rook b
			case 'u': cout << "B�1"; break;		//Black Bishop a
			case 'h': cout << "B�2"; break;		//Black Bishop b
			case 'o': cout << "BK^"; break;		//Black King
			case 'l': cout << "BQ^"; break;		//Black Queen
			case 1: cout << "W�a"; break;		//White pawn a
			case 2: cout << "W�b"; break;		//White pawn b
			case 3: cout << "W�c"; break;		//White pawn c
			case 4: cout << "W�d"; break;		//White pawn d
			case 5: cout << "W�e"; break;		//White pawn e
			case 6: cout << "W�f"; break;		//White pawn f
			case 7: cout << "W�g"; break;		//White pawn g
			case 8: cout << "W�h"; break;		//White pawn h
			case 9: cout << "W�1"; break;		//White rook a
			case 10: cout << "W�2"; break;		//White rook b
			case 11: cout << "BQ^"; break;		//White Queen
			case 12: cout << "Wk1"; break;		//White knight a
			case 13: cout << "Wk2"; break;		//White knight b
			case 14: cout << "W�1"; break;		//White Bishop a
			case 15: cout << "W�2"; break;		//White Bishop b
			case 16: cout << "WK^"; break;		//White King
			default: cout << "{-}"; break;		//Displays when an invaliv character is in the array
			}
		}
		cout << "�" << endl;
	}
	cout << "   �������������������������" << rbot << endl;
	//cout << endl << &#200�;
}
