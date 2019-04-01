#include  <iostream>
using namespace std;

void PrintBoard(char board[8][8]) {
	char a = 97;
	for (int i = 8; i > 0; i--) {
		cout << i << " ";
		for (int j = 1; j < 9; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << "  ";
	for (int i = 1; i < 9; a++, i++) {
		cout << a << " ";
	}
	cout << endl;

}

// Function to check paths vertically upwards
void WcheckPathVerticalUp(char board[8][8], int i1, int i2, int j1, int j2, bool& imp, bool& path) { 
	imp = false;
	if ((j2 > 0 || j2 < 8) || (i2 > 0 || i2 < 8)) {
		imp = true;  // Bool Impossible, so that character can not move out of the board
	}
	else {
		imp = false;
	}
	path = false;
	for (int i = 1; i < i2 - i1; i++) {
		if (board[i1 + i][j1] == '-') {
			path = true;
		}
		else {
			path = false;
			i = i2 + 1;
		}
	}
}
// Function to check paths vertically downwards
void WcheckPathVerticalDown(char board[8][8], int i1, int i2, int j1, int j2, bool& imp, bool& path) {
	imp = false;
	if ((j2 > 0 || j2 < 8) || (i2 > 0 || i2 < 8)) {
		imp = true;  // Bool Impossible, so that character can not move out of the board
	}
	else {
		imp = false;
	}
	path = false;
	for (int i = 1; i < i1 - i2; i++) {
		if (board[i1 - i][j1] == '-') {
			path = true;
		}
		else {
			path = false;
			i = i1 + 1;
		}
	}
}
// Function to check paths horizontally right
void WcheckPathHorizontalRight(char board[8][8], int i1, int i2, int j1, int j2, bool& imp, bool& path) {
	imp = false;
	if ((j2 > 0 || j2 < 8) || (i2 > 0 || i2 < 8)) {
		imp = true;  // Bool Impossible, so that character can not move out of the board
	}
	else {
		imp = false;
	}
	path = false;
	for (int i = 1; i < j2 - j1; i++) {
		if (board[i1][j1 + i] == '-') {
			path = true;
		}
		else {
			path = false;
			i = j2 + 1;
		}
	}
}
// Function to check paths horizontally left
void WcheckPathHorizontalLeft(char board[8][8], int i1, int i2, int j1, int j2, bool& imp, bool& path) {
	imp = false;
	if ((j2 > 0 || j2 < 8) || (i2 > 0 || i2 < 8)) {
		imp = true;  // Bool Impossible, so that character can not move out of the board
	}
	else {
		imp = false;
	}
	path = false;
	for (int i = 1; i < j1 - j2; i++) {
		if (board[i1][j1 - i] == '-') {
			path = true;
		}
		else {
			path = false;
			i = j1 + 1;
		}
	}
}
// Function to check path diagonaly top right
void WcheckPathTR(char board[8][8], int i1, int i2, int j1, int j2, bool& imp, bool& path) {
	imp = false;
	if ((j2 > 0 || j2 < 8) || (i2 > 0 || i2 < 8)) {
		imp = true;  // Bool Impossible, so that character can not move out of the board
	}
	else {
		imp = false;
	}
	path = false;
	for (int i = 1; i < i2 - i1; i++) {
		if (board[i1 + i][j1 + i] == '-') {
			path = true;

		}
		else {
			path = false;
			i = i + 20;
		}
	}
}
// Function to check path diagonaly top left
void WcheckPathTL(char board[8][8], int i1, int i2, int j1, int j2, bool& imp, bool& path) {
	imp = false;
	if ((j2 > 0 || j2 < 8) || (i2 > 0 || i2 < 8)) {
		imp = true;  // Bool Impossible, so that character can not move out of the board
	}
	else {
		imp = false;
	}
	path = false;
	for (int i = 1,j=1; i < i2 - i1,j<j1-j2;j++, i++) {
		if (board[i1 + i][j1 - j] == '-') {
			path = true;

		}
		else {
			path = false;
			i = i + 20;
		}
	}
}
// Function to check path diagonaly bottom right
void WcheckPathBR(char board[8][8], int i1, int i2, int j1, int j2, bool& imp, bool& path) {
	imp = false;
	if ((j2 > 0 || j2 < 8) || (i2 > 0 || i2 < 8)) {
		imp = true;  // Bool Impossible, so that character can not move out of the board
	}
	else {
		imp = false;
	}
	path = false;
	for (int i = 1; i <=j2-j1; i++) {
		if (board[i1 - i][j1 + i] == '-') {
			path = true;

		}
		else {
			path = false;
			i = i1+ 20;
		}
	}
}
// Function to check path diagonaly bottom left
void WcheckPathBL(char board[8][8], int i1, int i2, int j1, int j2, bool& imp, bool& path) {
	imp = false;
	if ((j2 > 0 || j2 < 8) || (i2 > 0 || i2 < 8)) {
		imp = true;  // Bool Impossible, so that character can not move out of the board
	}
	else {
		imp = false;
	}
	path = false;
	for (int i = 1, j = 1; i < i2, j < j1; i++, j++) {
		if (board[i1 - i][j1 + j] == '-') {
			path = true;

		}
		else {
			path = false;
			i = i + 20;
			j = 10;
		}
	}
}


// Validity Check for White Pawn (Capital)
void pwnmoveW(char board[8][8], int i1, int i2, int j1, int j2, bool& valid) {
	bool back = false;
	bool lr = false;
	bool movef = false;
	bool movef2 = false;
	bool imp = false;
	bool path = false;
	bool kill = false;
	WcheckPathVerticalUp(board, i1, i2, j1, j2, imp, path);
	if (board[i1][j1] == 'P') {
		if (j1 != j2) {
			if (board[i2][j2] == 'P' || board[i2][j2] == 'R' || board[i2][j2] == 'N' || board[i2][j2] == 'B' || board[i2][j2] == 'Q' || board[i2][j2] == 'K') {
				kill = false;
			}
			else {
				kill = true;
				cout << endl;
				board[i2][j2] = 'P';
				board[i1][j1] = '-';
				valid = true;
			}
		}
		if (!kill) {
			if (j1 == j2) { // So that the pawn moves left or right, if it can kill
				lr = true;
			}
			else {
				lr = false;
			}
		}
		if (i1 > i2) { // So that the pawn does not move backwards
			back = false;
		}
		else {
			back = true;
		}
		if (i1 <= 2) { //Pawn moves 2 times in the first move, and one step afterwards
			if (i1 == 2) {
				if (i2 == i1 + 2) {
					movef2 = true;
				}
			}
			else {
				movef2 = false;
				if (i2 != i1 + 1) {
					movef = false;
				}
				else {
					movef = true;
				}
			}
		}
		if (j1 != j2) {
			if (!back || !imp ) { // Pawn will only move if all bools are valid
				cout << " Invalid move" << endl;
			}
			else {
				cout << endl;
				board[i2][j2] = 'P';
				board[i1][j1] = '-';
				valid = true;
			}
		}
		else {
			if (j1 == j2 && i2 - i1 == 2 && !kill) {
				if (!back || !imp || !path) {
					cout << "Invalid move" << endl;
				}

				else {
					board[i2][j2] = 'P';
					board[i1][j1] = '-';
					valid = true;
				}
			}

				if (j1 == j2 && i2 - i1 == 1 && !kill) {
					if (!back || !imp) {
						cout << "Invalid move" << endl;
					}
					else {
						board[i2][j2] = 'P';
						board[i1][j1] = '-';
						valid = true;
					}
				}
			}
		
	}
	else {
		cout << "Piece not available to move";
	}
	PrintBoard(board);
}

// Validity Check for White Rook (Capital)
void rookmoveW(char board[8][8], int i1, int i2, int j1, int j2, bool& valid) {
	bool horizontal = false;
	bool vertical = false;
	bool imp = true;
	bool pathup = true;
	bool pathdown = true;
	bool pathright = true;
	bool pathleft = true;
	bool kill = false;
	bool kill2 = false;
	WcheckPathVerticalUp(board, i1, i2, j1, j2, imp, pathup);
	WcheckPathVerticalDown(board, i1, i2, j1, j2, imp, pathdown);
	WcheckPathHorizontalRight(board, i1, i2, j1, j2, imp, pathright);
	WcheckPathHorizontalLeft(board, i1, i2, j1, j2, imp, pathleft);
	if (board[i1][j1] == 'R') {
		if ((i2 - i1 == 1 && j1 == j2) || (j1 == j2 && i1 - i2 == 1) || (i1 == i2 && j1 - j2 == 1) || (i1 == i2 && j2 - j1 == 1)) {
			if (board[i2][j2] == 'P' || board[i2][j2] == 'R' || board[i2][j2] == 'N' || board[i2][j2] == 'B' || board[i2][j2] == 'Q' || board[i2][j2] == 'K') {
			}
			else {
					if (board[i2][j2] != '-') {
						board[i2][j2] = 'R';
						board[i1][j1] = '-';
						valid = true;
					}
					if (board[i2][j2] == '-') {
						board[i2][j2] = 'R';
						board[i1][j1] = '-';
						valid = true;
					}
			}
		}
		else {
			if (i1 == i2 && j1 != j2) {
				horizontal = true;
			}
			else {
				horizontal = false;
			}
			if (j1 == j2 && i1 != i2) {
				vertical = true;
			}
			else {
				vertical = false;
			}
			if ((horizontal && imp && (pathright || pathleft)) || (vertical && imp && (pathup || pathdown))) {
			}
			else {
				cout << "Invalid Move" << endl;
			}
			if (pathright || pathleft || pathup || pathdown) {
				kill = true;
			}
			if (board[i2][j2] != 'P' || board[i2][j2] != 'R' || board[i2][j2] != 'N' || board[i2][j2] != 'B' || board[i2][j2] != 'Q' || board[i2][j2] != 'K' || board[i2][j2] != '-') {
				kill2 = true;
			}
			else {
			}
			if (kill && kill2) {
				board[i2][j2] = 'R';
				board[i1][j1] = '-';
				valid = true;
			}
		}
	}
	else {
		cout << "Piece not availabe to move" << endl;
	}
	PrintBoard(board);
}

//Validity Check for White Horse (Capital)
void horsemoveW (char board[8][8], int i1, int i2, int j1, int j2, bool& valid) {
	bool upwards = false;
	bool downwards = false;
	bool right = false;
	bool left = false;
	if (board[i1][j1] == 'N') {
		if (board[i2][j2] == '-') {
			if( (i2 == i1 + 2 && j2 == j1 - 1 ) || (i2 == i1+2 && j2==j1 + 1)) {
				upwards = true;
			}
			else {
				upwards = false;
			}
			if ((i2 == i1 - 2 && j2 == j1 + 1) ||(i2 == i1 - 2 && j2 == j1 - 1)) {
				downwards = true;
			}
			else {
				downwards = false;
			}
			if ((i2 == i1 - 1 && j2 == j1 + 2 )|| (i2 == i1 + 1 && j2 == j1 + 2)) {
				right = true;
			}
			else {
				right = false;
			}
			if ((i2 == i1 + 1 && j2 == j1 - 2) || (i1 - 1 && j2 == j1 - 2)) {
				left = true;
			}
			else {
				left = false;
			}
			if (!upwards && !downwards && !left && !right) {
				cout << "Invalid move" << endl; 
			}
			else {
				if (upwards || downwards || left || right) {
					if (board[i2][j2] == 'P' || board[i2][j2] == 'R' || board[i2][j2] == 'N' || board[i2][j2] == 'B' || board[i2][j2] == 'Q' || board[i2][j2] == 'K') {
					}
					else {

						if (board[i2][j2] != '-') {
							board[i2][j2] = 'N';
							board[i1][j1] = '-';
							valid = true;
						}
						if (board[i2][j2] == '-') {
							board[i2][j2] = 'N';
							board[i1][j1] = '-';
							valid = true;
						}
					}
				}
			}
		}
	}
	else {
			cout << "Piece not available to move";
	}
	PrintBoard(board);
}

//Validity Check for White Bishop (Capital)
void bishopmoveW(char board[8][8], int i1, int i2, int j1, int j2, bool& valid) {
	bool tr = false;
	bool tl = false;
	bool br = false;
	bool bl = false;
	bool imp = false;
	bool pathtr = false;
	bool pathtl = false;
	bool pathbr = false;
	bool pathbl = false;
	bool kill = false;
	if (board[i1][j1] == 'B') {
		if ((i2 - i1 == 1 && j2 - j1 == 1) || ( i2 - i1 == 1 && j1 - j2 == 1) || ( i1 - i2 == 1 && j2 - j1 == 1) || (i1 - i2 == 1 && j1 - j2 == 1)) {
			if (board[i2][j2] == 'P' || board[i2][j2] == 'R' || board[i2][j2] == 'N' || board[i2][j2] == 'B' || board[i2][j2] == 'Q' || board[i2][j2] == 'K') {
			}
			else {
					if (board[i2][j2] != '-') {
						board[i2][j2] = 'B';
						board[i1][j1] = '-';
						valid = true;
					}
					if (board[i2][j2] == '-') {
						board[i2][j2] = 'B';
						board[i1][j1] = '-';
						valid = true;
					}
			}
		}
		else {
			if (i2 - i1 == j2 - j1 && i2 - i1 > 0 && j2 - j1 > 0) {
				tr = true;
				WcheckPathTR(board, i1, i2, j1, j2, imp, pathtr);
				if (pathtr) {
				}
				else {
					cout << "Invalid Move" << endl;

				}
			}
			if (i2 - i1 == j1 - j2 && i2 - i1 > 0 && j1 - j2 > 0) {
				tl = true;
				WcheckPathTL(board, i1, i2, j1, j2, imp, pathtl);
				if (pathtl) {
				}
				else {
					cout << "Invalid Move" << endl;
				}
			}
			if (i1 - i2 == j2 - j1 && i1 - i2 > 0 && j2 - j1 > 0) {
				br = true;
				WcheckPathBR(board, i1, i2, j1, j2, imp, pathbr);
				if (pathbr) {
				}
				else {
					cout << "Invalid Move" << endl;
				}
			}
			if (i1 - i2 == j1 - j2 && i1 - i2 > 0 && j1 - j2 > 0) {
				bl = true;
				WcheckPathBL(board, i1, i2, j1, j2, imp, pathbl);
				if (pathbl) {
				}
				else {
					cout << "Invalid Move" << endl;
				}
			}
			if (pathtr || pathtl || pathbr || pathbl) {
				if (board[i2][j2] == 'P' || board[i2][j2] == 'R' || board[i2][j2] == 'N' || board[i2][j2] == 'B' || board[i2][j2] == 'Q' || board[i2][j2] == 'K') {
					kill = true;
					board [i2][j2] = 'B';
					board [i1][j1] = '-';
					valid = true;
				}
				else {
					if (pathtr || pathtl || pathbr || pathbl) {
						if (board[i2][j2] != '-') {
							board[i2][j2] = 'B';
							board[i1][j1] = '-';
							valid = true;
						}
						if (board[i2][j2] == '-') {
							board[i2][j2] = 'B';
							board[i1][j1] = '-';
							valid = true;
						}
					}
				}
			}
		}
	}
	else {
		cout << "Bishop not available to move";
	}
	PrintBoard(board);
}

//Validity Check for White Queen (Capital)
void queenmoveW(char board[8][8], int i1, int i2, int j1, int j2, bool& valid) {
	bool horizontal = false;
	bool vertical = false;
	bool imp = true;
	bool pathup = false;
	bool pathdown = false;
	bool pathright = false;
	bool pathleft = false;
	bool kill = false;
	bool tr = false;
	bool tl = false;
	bool br = false;
	bool bl = false;
	bool pathtr = false;
	bool pathtl = false;
	bool pathbr = false;
	bool pathbl = false;
	
	WcheckPathVerticalUp(board, i1, i2, j1, j2, imp, pathup);
	WcheckPathVerticalDown(board, i1, i2, j1, j2, imp, pathdown);
	WcheckPathHorizontalRight(board, i1, i2, j1, j2, imp, pathright);
	WcheckPathHorizontalLeft(board, i1, i2, j1, j2, imp, pathleft);
	WcheckPathTR(board, i1, i2, j1, j2, imp, pathtr);
	WcheckPathTL(board, i1, i2, j1, j2, imp, pathtl);
	WcheckPathBR(board, i1, i2, j1, j2, imp, pathbr);
	WcheckPathBL(board, i1, i2, j1, j2, imp, pathbl);

	if (board[i1][j1] == 'Q') {
		if ((i2 - i1 == 1 && j2 - j1 == 1) || (i2 - i1 == 1 && j1 - j2 == 1) || (i1 - i2 == 1 && j2 - j1 == 1) || (i1 - i2 == 1 && j1 - j2 == 1) || (i2 - i1 == 1 || i1 - i2 == 1) || (i1 == i2 && j1 != j2) || (j1 == j2 && i1 != i2)) {
			if (board[i2][j2] != 'P' || board[i2][j2] != 'R' || board[i2][j2] != 'N' || board[i2][j2] != 'B' || board[i2][j2] != 'Q' || board[i2][j2] != 'K') {
				if (board[i2][j2] != '-') {
					board[i2][j2] = 'Q';
					board[i1][j1] = '-';
					valid = true;
				}
				if (board[i2][j2] == '-') {
					board[i2][j2] = 'Q';
					board[i1][j1] = '-';
					valid = true;
				}
			}
		}
		else {
			if (i1 == i2 && j1 != j2) {
				horizontal = true;
			}
			else {
				horizontal = false;
			}
			if (j1 == j2 && i1 != i2) {
				vertical = true;
			}
			else {
				vertical = false;
			}
			if (i2 - i1 == j2 - j1 && i2 - i1 > 0 && j2 - j1 > 0) {
				tr = true;
			}
			else {
				tr = false;
			}
			if (i2 - i1 == j1 - j2 && i2 - i1 > 0 && j1 - j2 > 0) {
				tl = true;
			}
			else {
				tl = false;
			}
			if (i1 - i2 == j2 - j1 && i1 - i2 > 0 && j2 - j1 > 0) {
				br = true;
			}
			else {
				br = false;
			}
			if (i1 - i2 == j1 - j2 && i1 - i2 > 0 && j1 - j2) {
				bl = true;
			}
			else {
				bl = false;
			}
			if ((horizontal && imp && (pathright || pathleft)) || (vertical && imp && (pathup || pathdown)) || (tr && imp && pathtr) || (tl && imp && pathtl) || (br && imp && pathbr) || (bl && imp && pathbl)) {
			}
			else {
				cout << "Invalid move" << endl;
			}
			if ((horizontal && imp && (pathright || pathleft)) || (vertical && imp && (pathup || pathdown)) || (tr && imp && pathtr) || (tl && imp && pathtl) || (br && imp && pathbr) || (bl && imp && pathbl)){
				if (board[i2][j2] == 'P' || board[i2][j2] == 'R' || board[i2][j2] == 'N' || board[i2][j2] == 'B' || board[i2][j2] == 'Q' || board[i2][j2] == 'K') {
					kill = true;
					board[i2][j2] = 'Q';
					board[i1][j1] = '-';
					valid = true;
				}
				else {
					if (board[i2][j2] != '-') {
						board[i2][j2] = 'Q';
						board[i1][j1] = '-';
						valid = true;
					}
					if (board[i2][j2] == '-') {
						board[i2][j2] = 'Q';
						board[i1][j1] = '-';
						valid = true;
					}
				}
			}
		}
	}
	else {
		cout << "Piece not available to move" << endl;
	}
	PrintBoard(board);
}

//Validity Check for White King (Capital)
void kingmoveW(char board[8][8], int i1, int i2, int j1, int j2, bool& valid) {
	bool updown = false;
	bool leftright = false;
	bool diagbltr = false;
	bool diagbrtl = false;
	valid = false;
	if (board[i1][j1] == 'K') {
		if (i2 == i1 + 1 || i2 == i1 - 1) {
			updown = true;
		}
		else {
			updown = false;
		}
		if (j2 == j1 + 1 || j2 == j1 - 1) {
			leftright = true;
		}
		else {
			leftright = false;
		}
		if ((i2 == i1 + 1 && i2 == i1 - 1) || (j2 == j1 + 1 && j2 == j1 - 1)) {
			diagbltr = true;
		}
		else {
			diagbltr = false;
		}
		if ((i2 == i1 + 1 && i2 == i1 - 1) || (j2 == j1 + 1 && j2 == j1 - 1)) {
			diagbrtl = true;
		}
		else {
			diagbrtl = false;
		}
		if (board[i2][j2] == 'P' || board[i2][j2] == 'R' || board[i2][j2] == 'N' || board[i2][j2] == 'B' || board[i2][j2] == 'Q' || board[i2][j2] == 'K') {
		}
		else {
			if (updown || leftright || diagbltr || diagbrtl) {
				if (board[i2][j2] != '-') {
					board[i2][j2] = 'K';
					board[i1][j1] = '-';
					valid = true;
				}
				if (board[i2][j2] == '-') {
					board[i2][j2] = 'K';
					board[i1][j1] = '-';
					valid = true;
				}
			}
		}
		if (updown || leftright || diagbltr || diagbrtl) {
			cout << "Valid move" << endl;
		}
		else {
			cout << "Invalid move" << endl;
		}
	}
	else {
		cout << "Piece not available to move" << endl;
	}
	PrintBoard(board);
}




// Validity Check for Black Pawn (lower)
void pwnmoveB(char board[8][8], int i1, int i2, int j1, int j2, bool& valid2) {
	bool back = false;
	bool lr = false;
	bool movef = false;
	bool movef2 = false;
	bool imp = false;
	bool path = false;
	bool kill = false;
	WcheckPathVerticalDown(board, i1, i2, j1, j2, imp, path);
	if (board[i1][j1] == 'p') {
		if (j1 != j2) {
			if (board[i2][j2] == 'p' || board[i2][j2] == 'r' || board[i2][j2] == 'n' || board[i2][j2] == 'b' || board[i2][j2] == 'q' || board[i2][j2] == 'k') {
				kill = false;
			}
			else {
				kill = true;
				board[i2][j2] = 'p';
				board[i1][j1] = '-';
				valid2 = true;
			}
		}
		if (!kill) {
			if (j1 == j2) { // So that the pawn moves left or right, if it can kill
				lr = true;
			}
			else {
				lr = false;
			}
		}
		if (i2 > i1) { // So that the pawn does not move backwards
			back = false;
		}
		else {
			back = true;
		}
		if (i1-i2 <= 2) { //Pawn moves 2 times in the first move, and one step afterwards
			if (i1 == 7) {
				if (i1 == i2 + 2) {
					movef2 = true;
				}
			}
			else {
				movef2 = false;
				if (i1 != i2 + 1) {
					movef = false;
				}
				else {
					movef = true;
				}
			}
		}
		if (j1 != j2) {
			if (!back || !imp) { // Pawn will only move if all bools are valid
				cout << " Invalid move" << endl;
			}
			else {
				board[i2][j2] = 'p';
				board[i1][j1] = '-';
				valid2 = true;
			}
		}
		else {
			if (j1 == j2 && i1 - i2 == 2 && !kill) {
				if (!back || !imp || !path) {
					cout << "Invalid move" << endl;
				}

				else {
					board[i2][j2] = 'p';
					board[i1][j1] = '-';
					valid2 = true;
				}
			}

			if (j1 == j2 && i1 - i2 == 1 && !kill) {
				if (!back || !imp) {
					cout << "Invalid move" << endl;
				}
				else {
					board[i2][j2] = 'p';
					board[i1][j1] = '-';
					valid2 = true;
				}
			}
		}

	}
	else {
		cout << "Piece not available to move" << endl;
	}
	PrintBoard(board);
}

//Validity Check for Black Rook (Lower)
void rookmoveB(char board[8][8], int i1, int i2, int j1, int j2, bool& valid2) {
	bool horizontal = false;
	bool vertical = false;
	bool imp = true;
	bool pathup = true;
	bool pathdown = true;
	bool pathright = true;
	bool pathleft = true;
	bool kill = false;
	bool kill2 = false;
	WcheckPathVerticalUp(board, i1, i2, j1, j2, imp, pathup);
	WcheckPathVerticalDown(board, i1, i2, j1, j2, imp, pathdown);
	WcheckPathHorizontalRight(board, i1, i2, j1, j2, imp, pathright);
	WcheckPathHorizontalLeft(board, i1, i2, j1, j2, imp, pathleft);
	if (board[i1][j1] == 'r') {
		if ((i2 - i1 == 1 && j1 == j2) || (j1 == j2 && i1 - i2 == 1) || (i1 == i2 && j1 - j2 == 1) || (i1 == i2 && j2 - j1 == 1)) {
			if (board[i2][j2] == 'p' || board[i2][j2] == 'r' || board[i2][j2] == 'n' || board[i2][j2] == 'b' || board[i2][j2] == 'q' || board[i2][j2] == 'k') {
			}
			else {
				if (board[i2][j2] != '-') {
					board[i2][j2] = 'r';
					board[i1][j1] = '-';
					valid2 = true;
				}
				if (board[i2][j2] == '-') {
					board[i2][j2] = 'r';
					board[i1][j1] = '-';
					valid2 = true;
				}
			}
		}
		else {
			if (i1 == i2 && j1 != j2) {
				horizontal = true;
			}
			else {
				horizontal = false;
			}
			if (j1 == j2 && i1 != i2) {
				vertical = true;
			}
			else {
				vertical = false;
			}
			if ((horizontal && imp && (pathright || pathleft)) || (vertical && imp && (pathup || pathdown))) {
			}
			else {
				cout << "Invalid Move" << endl;
			}
			if (pathright || pathleft || pathup || pathdown) {
				kill = true;
			}
			if (board[i2][j2] != 'p' || board[i2][j2] != 'r' || board[i2][j2] != 'n' || board[i2][j2] != 'b' || board[i2][j2] != 'q' || board[i2][j2] != 'k' || board[i2][j2] != '-') {
				kill2 = true;
			}
			else {
			}
			if (kill && kill2) {
				board[i2][j2] = 'r';
				board[i1][j1] = '-';
				valid2 = true;
			}
		}
	}
	else {
		cout << "Piece not availabe to move" << endl;
	}
	PrintBoard(board);
}

//Validity Check for Black Horse (Lower)
void horsemoveB(char board[8][8], int i1, int i2, int j1, int j2, bool& valid2) {
	bool upwards = false;
	bool downwards = false;
	bool right = false;
	bool left = false;
	if (board[i1][j1] == 'n') {
		if (board[i2][j2] == '-') {
			if ((i2 == i1 + 2 && j2 == j1 - 1) || (i2 == i1 + 2 && j2 == j1 + 1)) {
				upwards = true;
			}
			else {
				upwards = false;
			}
			if ((i2 == i1 - 2 && j2 == j1 + 1) || (i2 == i1 - 2 && j2 == j1 - 1)) {
				downwards = true;
			}
			else {
				downwards = false;
			}
			if ((i2 == i1 - 1 && j2 == j1 + 2) || (i2 == i1 + 1 && j2 == j1 + 2)) {
				right = true;
			}
			else {
				right = false;
			}
			if ((i2 == i1 + 1 && j2 == j1 - 2) || (i1 - 1 && j2 == j1 - 2)) {
				left = true;
			}
			else {
				left = false;
			}
			if (!upwards && !downwards && !left && !right) {
				cout << "Invalid move" << endl;
			}
			else {
				if (upwards || downwards || left || right) {
					if (board[i2][j2] == 'p' || board[i2][j2] == 'r' || board[i2][j2] == 'n' || board[i2][j2] == 'b' || board[i2][j2] == 'q' || board[i2][j2] == 'k') {
						cout << "Not Killed";
					}
					else {

						if (board[i2][j2] != '-') {
							board[i2][j2] = 'n';
							board[i1][j1] = '-';
							valid2 = true;
						}
						if (board[i2][j2] == '-') {
							board[i2][j2] = 'n';
							board[i1][j1] = '-';
							valid2 = true;
						}
					}
				}
			}
		}
	}
	else {
		cout << "Piece not available to move";
	}
	PrintBoard(board);
}

//Validity Check for Black Bishop (Lower)
void bishopmoveB(char board[8][8], int i1, int i2, int j1, int j2, bool& valid2) {
	bool tr = false;
	bool tl = false;
	bool br = false;
	bool bl = false;
	bool imp = false;
	bool pathtr = false;
	bool pathtl = false;
	bool pathbr = false;
	bool pathbl = false;
	bool kill = false;
	if (board[i1][j1] == 'b') {
		if ((i2 - i1 == 1 && j2 - j1 == 1) || (i2 - i1 == 1 && j1 - j2 == 1) || (i1 - i2 == 1 && j2 - j1 == 1) || (i1 - i2 == 1 && j1 - j2 == 1)) {
			if (board[i2][j2] == 'p' || board[i2][j2] == 'r' || board[i2][j2] == 'n' || board[i2][j2] == 'b' || board[i2][j2] == 'q' || board[i2][j2] == 'k') {
				cout << "Not Killed" << endl;
			}
			else {
				if (board[i2][j2] != '-') {
					board[i2][j2] = 'b';
					board[i1][j1] = '-';
					valid2 = true;
				}
				if (board[i2][j2] == '-') {
					board[i2][j2] = 'b';
					board[i1][j1] = '-';
					valid2 = true;
				}
			}
		}
		else {
			if (i1 - i2 == j1 - j2 && i1 - i2 > 0 && j1 - j2 > 0) {
				bl = true;
				WcheckPathBL(board, i1, i2, j1, j2, imp, pathbl);
				if (pathbl) {
					cout << "Valid Move" << endl;
				}
				else {
					cout << "Invalid Move" << endl;

				}
			}
			if (i1 - i2 == j2 - j1 && i1 - i2 > 0 && j2 - j1 > 0) {
				br = true;
				WcheckPathBR(board, i1, i2, j1, j2, imp, pathbr);
				if (pathbr) {
					cout << "Valid Move" << endl;
				}
				else {
					cout << "Invalid Move" << endl;
				}
			}
			if (i2 - i1 == j1 - j2 && i2 - i1 > 0 && j1 - j2 > 0) {
				tl = true;
				WcheckPathTL(board, i1, i2, j1, j2, imp, pathtl);
				if (pathtl) {
					cout << "Valid Move" << endl;
				}
				else {
					cout << "Invalid Move" << endl;
				}
			}
			if (i2 - i1 == j2 - j1 && i2 - i1 > 0 && j2 - j1 > 0) {
				tr = true;
				WcheckPathTR(board, i1, i2, j1, j2, imp, pathtr);
				if (pathtr) {
					cout << "Valid Move" << endl;
				}
				else {
					cout << "Invalid Move" << endl;
				}
			}
			if (pathtr || pathtl || pathbr || pathbl) {
				if (board[i2][j2] == 'p' || board[i2][j2] == 'r' || board[i2][j2] == 'n' || board[i2][j2] == 'b' || board[i2][j2] == 'q' || board[i2][j2] == 'k' || board[i2][j2] == '-') {
					kill = true;
					board[i2][j2] = 'b';
					board[i1][j1] = '-';
					valid2 = true;
				}
				else {
					if (pathtr || pathtl || pathbr || pathbl) {
						if (board[i2][j2] != '-') {
							board[i2][j2] = 'b';
							board[i1][j1] = '-';
							valid2 = true;
						}
						if (board[i2][j2] == '-') {
							board[i2][j2] = 'b';
							board[i1][j1] = '-';
							valid2 = true;
						}
					}
				}
			}
		}
	}
	else {
		cout << "Piece not available to move";
	}
	PrintBoard(board);
}

//Validity Check for Black Queen (Lower)
void queenmoveB(char board[8][8], int i1, int i2, int j1, int j2, bool& valid2) {
	bool horizontal = false;
	bool vertical = false;
	bool imp = true;
	bool pathup = false;
	bool pathdown = false;
	bool pathright = false;
	bool pathleft = false;
	bool kill = false;
	bool tr = false;
	bool tl = false;
	bool br = false;
	bool bl = false;
	bool pathtr = false;
	bool pathtl = false;
	bool pathbr = false;
	bool pathbl = false;
	WcheckPathVerticalUp(board, i1, i2, j1, j2, imp, pathup);
	WcheckPathVerticalDown(board, i1, i2, j1, j2, imp, pathdown);
	WcheckPathHorizontalRight(board, i1, i2, j1, j2, imp, pathright);
	WcheckPathHorizontalLeft(board, i1, i2, j1, j2, imp, pathleft);
	WcheckPathTR(board, i1, i2, j1, j2, imp, pathtr);
	WcheckPathTL(board, i1, i2, j1, j2, imp, pathtl);
	WcheckPathBR(board, i1, i2, j1, j2, imp, pathbr);
	WcheckPathBL(board, i1, i2, j1, j2, imp, pathbl);

	if (board[i1][j1] == 'q') {
		if ((i2 - i1 == 1 && j2 - j1 == 1) || (i2 - i1 == 1 && j1 - j2 == 1) || (i1 - i2 == 1 && j2 - j1 == 1) || (i1 - i2 == 1 && j1 - j2 == 1) || (i2 - i1 == 1 || i1 - i2 == 1) || (i1 == i2 && j1 != j2) || (j1 == j2 && i1 != i2)) {
			if (board[i2][j2] != 'p' || board[i2][j2] != 'r' || board[i2][j2] != 'n' || board[i2][j2] != 'b' || board[i2][j2] != 'q' || board[i2][j2] != 'k') {
				if (board[i2][j2] != '-') {
					board[i2][j2] = 'q';
					board[i1][j1] = '-';
					valid2 = true;
				}
				if (board[i2][j2] == '-') {
					board[i2][j2] = 'q';
					board[i1][j1] = '-';
					valid2 = true;
				}
			}
		}
		else {
			if (i1 == i2 && j1 != j2) {
				horizontal = true;
			}
			else {
				horizontal = false;
			}
			if (j1 == j2 && i1 != i2) {
				vertical = true;
			}
			else {
				vertical = false;
			}
			if (i2 - i1 == j2 - j1 && i2 - i1 > 0 && j2 - j1 > 0) {
				bl = true;
			}
			else {
				tr = false;
			}
			if (i2 - i1 == j1 - j2 && i2 - i1 > 0 && j1 - j2 > 0) {
				tl = true;
			}
			else {
				tl = false;
			}
			if (i1 - i2 == j2 - j1 && i1 - i2 > 0 && j2 - j1 > 0) {
				br = true;
			}
			else {
				br = false;
			}
			if (i1 - i2 == j1 - j2 && i1 - i2 > 0 && j1 - j2) {
				bl = true;
			}
			else {
				bl = false;
			}
			if ((horizontal && imp && (pathright || pathleft)) || (vertical && imp && (pathup || pathdown)) || (tr && imp && pathtr) || (tl && imp && pathtl) || (br && imp && pathbr) || (bl && imp && pathbl)) {
				cout << "Valid move" << endl;
			}
			else {
				cout << "Invalid move" << endl;
			}
			if ((horizontal && imp && (pathright || pathleft)) || (vertical && imp && (pathup || pathdown)) || (tr && imp && pathtr) || (tl && imp && pathtl) || (br && imp && pathbr) || (bl && imp && pathbl)) {
				if (board[i2][j2] == 'p' || board[i2][j2] == 'r' || board[i2][j2] == 'n' || board[i2][j2] == 'b' || board[i2][j2] == 'q' || board[i2][j2] == 'k') {
					kill = true;
					board[i2][j2] = 'q';
					board[i1][j1] = '-';
					valid2 = true;
				}
				else {
					if (board[i2][j2] != '-') {
						board[i2][j2] = 'q';
						board[i1][j1] = '-';
						valid2 = true;
					}
					if (board[i2][j2] == '-') {
						board[i2][j2] = 'q';
						board[i1][j1] = '-';
						valid2 = true;
					}
				}
			}
		}
	}
	else {
		cout << "Piece not available to move" << endl;
	}
	PrintBoard(board);
}

//Validity Check for Black King (Lower)
void kingmoveB(char board[8][8], int i1, int i2, int j1, int j2, bool& valid2) {
	bool updown = false;
	bool leftright = false;
	bool diagbltr = false;
	bool diagbrtl = false;
	if (board[i1][j1] == 'k') {
		if (i2 == i1 + 1 || i2 == i1 - 1) {
			updown = true;
		}
		else {
			updown = false;
		}
		if (j2 == j1 + 1 || j2 == j1 - 1) {
			leftright = true;
		}
		else {
			leftright = false;
		}
		if ((i1 == i2 + 1 && i1 == i2 - 1) || (j1 == j2 + 1 && j1 == j2 - 1)) {
			diagbrtl = true;
		}
		else {
			diagbrtl = false;
		}
		if ((i1 == i2 + 1 && i1 == i2 - 1) || (j1 == j2 + 1 && j1 == j2 - 1)) {
			diagbltr = true;
		}
		else {
			diagbltr = false;
		}
		if (board[i2][j2] == 'p' || board[i2][j2] == 'r' || board[i2][j2] == 'n' || board[i2][j2] == 'b' || board[i2][j2] == 'q' || board[i2][j2] == 'k') {
			cout << "Not Killed" << endl;
		}
		else {
			if (updown || leftright || diagbltr || diagbrtl) {
				if (board[i2][j2] != '-') {
					board[i2][j2] = 'k';
					board[i1][j1] = '-';
					valid2 = true;
				}
				if (board[i2][j2] == '-') {
					board[i2][j2] = 'k';
					board[i1][j1] = '-';
					valid2 = true;
				}
			}
		}
		if (updown || leftright || diagbltr || diagbrtl) {
			cout << "Valid move" << endl;
		}
		else {
			cout << "Invalid move" << endl;
		}
	}
	else {
		cout << "Piece not available to move" << endl;
	}
	PrintBoard(board);
}


//check and check mate for white king
void checkWK(char board[8][8], int &i1, int &j1) {
	bool pawn = false;
	bool rook = false;
	bool horse = false;
	bool bishop = false;
	int i = 0;
	int z = 0;
	for (int a = 0; a < 8; a++) {
		for (int j = 0; j < 8; j++) {
			if (board[a][j] == 'K') {
				i1 = a;
				j1 = j;

			}
		}
	}
	if (board[i1 + 1][j1 + 1] == 'p' || board[i1 + 1][j1 - 1] == 'p') {
		pawn = true;
	}
	else {
		pawn = false;
	}

	if (board[i1 + 2][j1 + 1] == 'n' || board[i1 + 2][j1 - 1] == 'n' || board[i1 - 2][j1 + 1] == 'n' || board[i1 - 2][j1 - 1] == 'n' || board[i1 + 1][j1 + 2] == 'n' || board[i1 - 1][j1 + 2] == 'n' || board[i1 + 1][j1 - 2] == 'n' || board[i1 - 1][j1 - 2] == 'n') {
		horse = true;
	}
	else {
		horse = false;
	}
	while (i < 8) {
		if ((board[i1 + i][j1] == 'r' || board[i1 + i][j1] == 'q') || (board[i1 - i][j1] == 'r' || board[i1 - i][j1] == 'q') || (board[i1][j1 + i] == 'r' || board[i1][j1 + i] == 'q') || (board[i1][j1 - i] == 'r' || board[i1][j1 - i] == 'q')) {
			rook = true;
		}
		else {
			rook = false;
		}
		i++;
	}
	while (z < 8) {
		if ((board[i1 + z][j1 + z] == 'b' || board[i1 + z][j1 + z] == 'q') || (board[i1 + z][j1 - z] == 'b' || board[i1 + z][j1 - z] == 'q') || (board[i1 - z][j1 - z] == 'b' || board[i1 - z][j1 - z] == 'q') || (board[i1 - z][j1 + z] == 'b' || board[i1 - z][j1 + z] == 'q')) {
			bishop = true;
		}
		else {
			//bishop = false;
		}
		z++;
	}

	if (pawn || rook || bishop || horse) {
		cout << "White Player, Check King" << endl;
	}
	else {
	}
}
void checkm8WK(char board[8][8], int &i1, int &j1) {
	bool pawn = false;
	bool rook = false;
	bool horse = false;
	bool bishop = false;
	int i = 0;
	int z = 0;
	for (int a = 0; a < 9; a++) {
		for (int j = 0; j < 9; j++) {
			if (board[i][j] == 'K') {
				i1 = a;
				j1 = j;

			}
		}
	}
	if (board[i1 + 1][j1 + 1] == 'p' || board[i1 + 1][j1 - 1] == 'p') {
		pawn = true;
	}
	else {
		pawn = false;
	}

	if (board[i1 + 2][j1 + 1] == 'n' || board[i1 + 2][j1 - 1] == 'n' || board[i1 - 2][j1 + 1] == 'n' || board[i1 - 2][j1 - 1] == 'n' || board[i1 + 1][j1 + 2] == 'n' || board[i1 - 1][j1 + 2] == 'n' || board[i1 + 1][j1 - 2] == 'n' || board[i1 - 1][j1 - 2] == 'n') {
		horse = true;
	}
	else {
		horse = false;
	}
	while (i < 8) {
		if ((board[i1 + i][j1] == 'r' || board[i1 + i][j1] == 'q') || (board[i1 - i][j1] == 'r' || board[i1 - i][j1] == 'q') || (board[i1][j1 + i] == 'r' || board[i1][j1 + i] == 'q') || (board[i1][j1 - i] == 'r' || board[i1][j1 - i] == 'q')) {
			rook = true;
		}
		else {
			rook = false;
		}
		i++;
	}
	while (z < 8) {
		if ((board[i1 + z][j1 + z] == 'b' || board[i1 + z][j1 + z] == 'q') || (board[i1 + z][j1 - z] == 'b' || board[i1 + z][j1 - z] == 'q') || (board[i1 - z][j1 - z] == 'b' || board[i1 - z][j1 - z] == 'q') || (board[i1 - z][j1 + z] == 'b' || board[i1 - z][j1 + z] == 'q')) {
			bishop = true;
		}
		else {
			bishop = false;
		}
		z++;
	}

	if (pawn && rook && bishop && horse) {
		cout << "White Player, Check Mate" << endl;
	}
	else {
	}
}


//check and check mate for black king
void checkBK(char board[8][8], int& i1,int& j1) {
	bool pawn = false;
	bool rook = false;
	bool horse = false;
	bool bishop = false;
	int i = 0;
	for (int a = 0; a < 9; a++) {
		for (int j = 0; j < 9; j++) {
			if (board[a][j] == 'k') {
				i1 = a;
				j1 = j;
				a = a + 9; 
				j = j + 9;
			}

		}
	}
	if (board[i1 + 1][j1 + 1] == 'P' || board[i1 + 1][j1 - 1] == 'P') {
		pawn = true;
	}
	else {
		//pawn = false;
	}

	if (board[i1 + 2][j1 + 1] == 'N' || board[i1 + 2][j1 - 1] == 'N' || board[i1 - 2][j1 + 1] == 'N' || board[i1 - 2][j1 - 1] == 'N' || board[i1 + 1][j1 + 2] == 'N' || board[i1 - 1][j1 + 2] == 'N' || board[i1 + 1][j1 - 2] == 'N' || board[i1 - 1][j1 - 2] == 'N') {
		horse = true;
	}
	else {
		//horse = false;
	}

	i = 0;
		while (i < 8) {
			if ((board[i1 + i][j1] == 'R' || board[i1 + i][j1] == 'Q') || (board[i1 - i][j1] == 'R' || board[i1 - i][j1] == 'Q') || (board[i1][j1 + i] == 'R' || board[i1][j1 + i] == 'Q') || (board[i1][j1 - i] == 'R' || board[i1][j1 - i] == 'Q')) {
				rook = true;
			}
			else {
			//	rook = false;
			}
			if ((board[i1 + i][j1 + i] == 'B' || board[i1 + i][j1 + i] == 'Q') || (board[i1 + i][j1 - i] == 'B' || board[i1 + i][j1 - i] == 'Q') || (board[i1 - i][j1 - i] == 'B' || board[i1 - i][j1 - i] == 'Q') || (board[i1 - i][j1 + i] == 'B' || board[i1 - i][j1 + i] == 'Q')) {
				bishop = true;
			}
			else {
			//	bishop = false;
			}
			i++;
		}
	
	if (pawn || rook || bishop || horse) {
		cout << "Black Player, Check King" << endl;
	}
	else {
	}
}
void checkm8BK(char board[8][8], int& i1, int& j1) {
	bool pawn = false;
	bool rook = false;
	bool horse = false;
	bool bishop = false;
	int i = 0;
	for (int a = 0; a < 9; a++) {
		for (int j = 0; j < 9; j++) {
			if (board[a][j] == 'k') {
				i1 = a;
				j1 = j;
				a = a + 9;
				j = j + 9;
			}

		}
	}
	if (board[i1 + 1][j1 + 1] == 'P' || board[i1 + 1][j1 - 1] == 'P') {
		pawn = true;
	}
	else {
		pawn = false;
	}

	if (board[i1 + 2][j1 + 1] == 'N' || board[i1 + 2][j1 - 1] == 'N' || board[i1 - 2][j1 + 1] == 'N' || board[i1 - 2][j1 - 1] == 'N' || board[i1 + 1][j1 + 2] == 'N' || board[i1 - 1][j1 + 2] == 'N' || board[i1 + 1][j1 - 2] == 'N' || board[i1 - 1][j1 - 2] == 'N') {
		horse = true;
	}
	else {
		horse = false;
	}

	i = 0;
	while (i < 8) {
		if ((board[i1 + i][j1] == 'R' || board[i1 + i][j1] == 'Q') || (board[i1 - i][j1] == 'R' || board[i1 - i][j1] == 'Q') || (board[i1][j1 + i] == 'R' || board[i1][j1 + i] == 'Q') || (board[i1][j1 - i] == 'R' || board[i1][j1 - i] == 'Q')) {
			rook = true;
		}
		else {
			rook = false;
		}
		if ((board[i1 + i][j1 + i] == 'B' || board[i1 + i][j1 + i] == 'Q') || (board[i1 + i][j1 - i] == 'B' || board[i1 + i][j1 - i] == 'Q') || (board[i1 - i][j1 - i] == 'B' || board[i1 - i][j1 - i] == 'Q') || (board[i1 - i][j1 + i] == 'B' || board[i1 - i][j1 + i] == 'Q')) {
			bishop = true;
		}
		else {
			bishop = false;
		}
		i++;
	}

	if (pawn && rook && bishop && horse) {
		cout << "Black Player, Check Mate" << endl;
	}
	else {
	}
}


//Promotion for White & Black Pawn
void PromoW(char board[8][8], int& i2, int& j2) {
	int promo;
	for (int i = 8, j = 1; j < 9; j++) {
		if (board[i][j] == 'P') {
			i2 = i;
			j2 = j;
		}
	}
	cout << "Your white pawn can be promoted. If you'd like to, press enter 1 for Queen, 2 for Bishop, 3 for Rook, 4 for Knight, or 5 to not promote.";
	cin >> promo;
	if (promo = 1) {
		board[i2][j2] = 'Q';
	}
	else {
		if (promo = 2) {
			board[i2][j2] = 'B';
		}
		if (promo = 3) {
			board[i2][j2] = 'R';
		}
		if (promo = 4) {
			board[i2][j2] = 'N';
		}
		if (promo = 5) {
			board[i2][j2] = 'P';
		}
	}
}
void PromoB(char board[8][8], int& i2, int& j2) {
	int promo;
	for (int i = 1, j = 1; j < 8; j++) {
		if (board[i][j] == 'p') {
			i2 = i;
			j2 = j;
		}
	}
	cout << "Your black pawn can be promoted. If you'd like to, press enter 1 for Queen, 2 for Bishop, 3 for Rook, 4 for Knight, or 5 to not promote.";
	cin >> promo;
	if (promo = 1) {
		board[i2][j2] = 'q';
	}
	else {
		if (promo = 2) {
			board[i2][j2] = 'b';
		}
		if (promo = 3) {
			board[i2][j2] = 'r';
		}
		if (promo = 4) {
			board[i2][j2] = 'n';
		}
		if (promo = 5) {
			board[i2][j2] = 'p';
		}
	}
}


int main() {

	char board[8][8];
	bool kill = true;
	bool valid = false;
	bool valid2 = false;
	int i = 0;
	int j = 0;

	int i1 = 0, j1 = 0, i2 = 0, j2 = 0;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			board[i][j] = '-';
		}
	}


	board[1][1] = 'R';  board[8][1] = 'r';
	board[1][2] = 'N';  board[8][2] = 'n';
	board[1][3] = 'B'; 	board[8][3] = 'b';
	board[1][4] = 'Q';	board[8][4] = 'q';
	board[1][5] = 'K';	board[8][5] = 'k';
	board[1][6] = 'B';	board[8][6] = 'b';
	board[1][7] = 'N';	board[8][7] = 'n';
	board[1][8] = 'R';	board[8][8] = 'r';
	board[2][1] = 'P';	board[7][1] = 'p';
	board[2][2] = 'P';	board[7][2] = 'p';
	board[2][3] = 'P';	board[7][3] = 'p';
	board[2][4] = 'P';	board[7][4] = 'p';
    board[2][5] = 'P';	board[7][5] = 'p';
	board[2][6] = 'P';	board[7][6] = 'p';
	board[2][7] = 'P';	board[7][7] = 'p';
	board[2][8] = 'P';	board[7][8] = 'p';
	
	PrintBoard(board);

	bool win = false ;
	while (!win) {
		valid = false;
		valid2 = false;
		while (!valid) {
			cout << "Whites turn" << endl;
			cout << "Enter Pick Up Coordinates: ";
			cin >> j1 >> i1;
			cout << "Enter Drop Off Coordinates: ";
			cin >> j2 >> i2;
			cout << endl;

			if (board[i1][j1] == 'P') {
				pwnmoveW(board, i1, i2, j1, j2, valid);
			//	PromoW(board, i2, j2);
			}
			else {
				if (board[i1][j1] == 'R') {
					rookmoveW(board, i1, i2, j1, j2, valid);
				}
				if (board[i1][j1] == 'N') {
					horsemoveW(board, i1, i2, j1, j2, valid);
				}
				if (board[i1][j1] == 'B') {
					bishopmoveW(board, i1, i2, j1, j2, valid);
				}
				if (board[i1][j1] == 'Q') {
					queenmoveW(board, i1, i2, j1, j2, valid);
				}
				if (board[i1][j1] == 'K') {
					kingmoveW(board, i1, i2, j1, j2, valid);
				}
			}
		}
		//checkBK(board, i, j);
		//checkm8BK(board, i, j);
		while (!valid2) {
			cout << "Blacks turn" << endl;
			cout << "Enter Pick Up Coordinates: ";
			cin >> j1 >> i1;
			cout << "Enter Drop Off Coordinates: ";
			cin >> j2 >> i2;
			cout << endl;
			if (board[i1][j1] == 'p') {
				pwnmoveB(board, i1, i2, j1, j2, valid2);
				//PromoB(board, i2, j2);
			}
			else {
				if (board[i1][j1] == 'r') {
					rookmoveB(board, i1, i2, j1, j2, valid2);
				}
				if (board[i1][j1] == 'n') {
					horsemoveB(board, i1, i2, j1, j2, valid2);
				}
				if (board[i1][j1] == 'b') {
					bishopmoveB(board, i1, i2, j1, j2, valid2);
				}
				if (board[i1][j1] == 'q') {
					queenmoveB(board, i1, i2, j1, j2, valid2);
				}
				if (board[i1][j1] == 'k') {
					kingmoveB(board, i1, i2, j1, j2, valid2);
				}
			}	
		}
		//checkWK(board,i,j);
		//checkm8WK(board, i, j);
	}
	system("pause");
}

               