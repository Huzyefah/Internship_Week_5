#include<iostream>
using namespace std;

const int ROWS = 3;

class game {
	char board[ROWS][ROWS];

public:
	void emptyBoard() {
		for (int i = 0; i < 3;i++) {
			for (int j = 0; j < 3;j++) {
				board[i][j] = '?';
			}
		}
	}
	bool checkBoardIsFull() {
		for (int i = 0; i < 3;i++) {
			for (int j = 0; j < 3;j++) {
				if (board[i][j] == '?') {
					return false;
				}
			}
		}
		cout << "Board is full!!\n";
		return true;
	}
	bool checkWin() {
		for (int i = 0; i < 3;i++) {
			if (board[i][0] == board[i][1] && board[1][1] == board[i][2] && board[i][0] != '?') {
				cout << "Player " << board[i][1] << " wins!!!\n";
				return true;
			}
		}
		for (int i = 0; i < 3;i++) {
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '?') {
				cout << "Player " << board[i][1] << " wins!!!\n";
				return true;
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '?') {
			cout << "Player " << board[1][1] << " wins!!!\n";
			return true;
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '?') {
			cout << "Player " << board[1][1] << " wins!!!\n";
			return true;
		}
		return false;
	}
	void printBoard() {
		for (int i = 0; i < 3;i++) {
			for (int j = 0; j < 3;j++) {
				cout << " " << board[i][j] << " ";
				if (j != 2) {
					cout << "|";
				}
			}
			cout << endl;
			if (i != 2) {
				cout << "-----------";
				cout << endl;
			}
		}
	}
	void startGame() {
		char player = 'O';
		int row = 0;
		int col = 0;
		restart:
		emptyBoard();
		while (true) {
			system("CLS");
			printBoard();
			if (checkWin() || checkBoardIsFull()) {
				char choice;
				cout << "\nDo you want to restart? (y for yes | anything else for no): ";
				cin >> choice;
				if (choice == 'y') {
					goto restart;
				}
			}
			cout << "\nPlayer " << player << "'s turn\n";
		re:
			cout << "Enter Row (1, 2, 3): ";
			cin >> row;
			cout << "Enter Column (1, 2, 3): ";
			cin >> col;
			if (row > 3 || col > 3 || row < 0 || col < 0 || board[row-1][col-1] != '?') {
				cout << "Invalid!\n";
				goto re;
			}
			board[row - 1][col - 1] = player;
			player == 'O' ? player = 'X' : player = 'O';
		}
	}

};

void main() {
	game g;
	g.startGame();
}