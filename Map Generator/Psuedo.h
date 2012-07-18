void psuedo(char map [] [8]) {
		//Defines where psuedo pieces will be.
	map [0] [0] = 'f'; //f is black castle
	map [7] [0] = 'f'; //f is black castle
	map [1] [0] = 'k'; //k is black knight
	map [6] [0] = 'k'; //k is black knight
	//map [2] [0] = 'u'; //u is black bishop
	map [5] [0] = 'u'; //u is black bishop
	map [3] [0] = 'o'; //o is black king
	map [4] [0] = 'l'; //l is black queen
	map [0] [1] = 'j'; //l is black pawn
	map [2] [1] = 'j'; //l is black pawn
	map [3] [1] = 'j'; //l is black pawn
	map [4] [1] = 'j'; //l is black pawn
	map [5] [1] = 'j'; //l is black pawn
	map [6] [1] = 'j'; //l is black pawn
	map [7] [1] = 'j'; //l is black pawn
	map [8] [1] = 'j'; //l is black pawn
	}