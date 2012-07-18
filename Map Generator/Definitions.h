const int ROWS=8, COLLUMNS=8;


//Note: color is a bool. Black is 1, white is 0.

class pawn
{
public:
  int posx;
  int posy;
  bool inPlay;
  bool color; //1 is black, 0 is white
  bool firstPlay;
  pawn(bool play=1, bool first = 1) {
	  inPlay = 1;
	  firstPlay = 1;
  }
};

class knight
{
public:
  int posx;
  int posy;
  bool inPlay;
  bool color;
  knight(bool play=1) {
	  inPlay = 1;
  }
};

class bishop
{
public:
  int posx;
  int posy;
  int oldx;
  int oldy;
  bool inPlay;
  bool color;
  bishop(bool play=1) {
	  inPlay = 1;
  }
};

class rook
{
public:
  int posx;
  int posy;
  int oldx;
  int oldy;
  bool inPlay;
  bool color;
  rook(bool play=1) {
	  inPlay = 1;
  }
};

class king
{
public:
  int posx;
  int posy;
  int oldx;
  int oldy;
  bool inPlay;
  bool color;
  king(bool play=1) {
	  inPlay = 1;
  }
};

class queen
{
public:
  int posx;
  int posy;
  int oldx;
  int oldy;
  bool inPlay;
  bool color;
  queen(bool play=1) {
	  inPlay = 1;
  }
};

