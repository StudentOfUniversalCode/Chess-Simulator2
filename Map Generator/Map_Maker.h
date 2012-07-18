
void MapMaker(char map [] [8], int ROWS, int COLLUMNS) {
	//--------------------------------------------------------------------------


	//Sets all memory addresses in map[] [] to 'b', black
	for (int count=0; count < ROWS; count) {
		for (int counter=0; counter < COLLUMNS; counter++) {
			map [count] [counter] = 'b';
		}
		count++;
	}
	//sets alternating squares 'w', white
 for (int count=0; count < ROWS; count++) {
		for (int counter=0; counter < COLLUMNS; counter+=2) {
			map [count] [counter] = 'w';
		}
		count++;
		for (int counter=1; counter < COLLUMNS; counter+=2) {
			map [count] [counter] = 'w';
		}
	}
 //Board is now blank, with no pieces on it, just black and white squares.
 //--------------------------------------------------------------------------------------------
}