/*
	If the start location is equal to the ending location, then we've
		solved the maze, so return true.
	Mark the start location as visted.
	For each of the four directions,
		If the location one step in that direction (from the start
		location) is unvisited,
			then call pathExists starting from that location (and
				ending at the same ending location as in the
				current call).
			 If that returned true,
				 then return true.
	Return false
*/
#include <string>

using namespace std;

const char OPEN = '.';
const char SEEN = 'o';

bool pathExists(string maze[], int nRows, int nCols, int sr, int sc, int er, int ec) {
	if (sr == er && sc == ec) {
		return true;
	}
	maze[sr][sc] = SEEN;
	if (sr - 1 >= 0 && maze[sr - 1][sc] == OPEN) {
		if (pathExists(maze, nRows, nCols, sr - 1, sc, er, ec)) {
			return true;
		}
	}
	if (sr + 1 < nRows && maze[sr + 1][sc] == OPEN) {
		if (pathExists(maze, nRows, nCols, sr + 1, sc, er, ec)) {
			return true;
		}
	}
	if (sc - 1 >= 0 && maze[sr][sc - 1] == OPEN) {
		if (pathExists(maze, nRows, nCols, sr, sc - 1, er, ec)) {
			return true;
		}
	}
	if (sc + 1 < nCols && maze[sr][sc + 1] == OPEN) {
		if (pathExists(maze, nRows, nCols, sr, sc + 1, er, ec)) {
			return true;
		}
	}
	return false;
}