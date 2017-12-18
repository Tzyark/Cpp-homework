#include <iostream>
#include <vector>

using namespace std;

const int N = 101;

const char O = 'O';
const char X = 'X';
const char NONE = '#';

class Chessboard {
private:
    int size, line;
    vector<vector<char>> board;
public:
	Chessboard(int n, int m) {
        size = n;
        line = m;
        board.resize(size, vector<char>(size, NONE));
    }
    char move(int row, int col, char player) {
        board[row][col] = player;
		int rowLeft = row;
		int rowRight = row;
        while (rowLeft - 1 >= 0 && board[rowLeft - 1][col] == player) {
            rowLeft--;
        }
        while (rowRight + 1 < size && board[rowRight + 1][col] == player) {
            rowRight++;
        }
        if (rowRight - rowLeft + 1 >= line) {
            return player;
        }
        
		int colUp = col;
		int colDown = col;
        while (colUp - 1 >= 0 && board[row][colUp - 1] == player) {
            colUp--;
        }
        while (colDown + 1 < size && board[row][colDown + 1] == player) {
            colDown++;
        }
        if (colDown - colUp + 1 >= line) {
            return player;
        }

		int diagUp = 0;
		int diagDown = 0;
        while (row - (diagUp + 1) >= 0 && col - (diagUp + 1) >= 0 && board[row - (diagUp + 1)][col - (diagUp + 1)] == player) {
            diagUp++;
        }
        while (row + (diagDown + 1) < size && col + (diagDown + 1) < size && board[row + (diagDown + 1)][col + (diagDown + 1)] == player) {
            diagDown++;
        }
        if (diagUp + diagDown + 1 >= line) {
            return player;
        }

		int diagLeft = 0;
		int diagRight = 0;
        while (row + (diagLeft + 1) < size && col - (diagLeft + 1) >= 0 && board[row + (diagLeft + 1)][col - (diagLeft + 1)] == player) {
            diagLeft++;
        }
        while (row - (diagRight + 1) >= 0 && col + (diagRight + 1) < size && board[row - (diagRight + 1)][col + (diagRight + 1)] == player) {
            diagRight++;
        }
        if (diagLeft + diagRight + 1 >= line) {
            return player;
        }

        return NONE;
    }
};

int main(int argc, char *argv[]) {
	int n, m;
	cin >> n >> m;
    Chessboard chessboard(n, m);
	int x, y;
	int t = 1;
	while (cin >> x >> y) {
		char player = (t) ? O : X;
        char winner = chessboard.move(x, y, player);
        if (winner != NONE)	{	
			cout << winner << " Success" << endl;
            return 0;
		}
		t ^= 1;
	}
    cout << "Dogfall" << endl;
    return 0;
}