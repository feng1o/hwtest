
#include <stdio.h>
#include <string>
#include <stack>

using namespace std;

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited);

bool hasPath(char* matrix, int rows, int cols, char* str)
{
	if (matrix == NULL || rows < 1 || cols < 1 || str == NULL)
		return false;

	bool *visited = new bool[rows * cols];
	memset(visited, 0, rows * cols);

	int pathLength = 0;
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			if (hasPathCore(matrix, rows, cols, row, col, str,
				pathLength, visited))
			{
				return true;
			}
		}
	}

	delete[] visited;

	return false;
}

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, char* str, int& pathLength, bool* visited)
{
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& matrix[row * cols + col] == str[pathLength]
		&& !visited[row * cols + col])
	{
		++pathLength;
		visited[row * cols + col] = true;

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1,
			str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row - 1, col,
			str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row, col + 1,
			str, pathLength, visited)
			|| hasPathCore(matrix, rows, cols, row + 1, col,
			str, pathLength, visited);

		if (!hasPath)
		{
			--pathLength;
			visited[row * cols + col] = false;
		}
	}

	return hasPath;
}

void Test(char* testName, char* matrix, int rows, int cols, char* str, bool expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (hasPath(matrix, rows, cols, str) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

//ABCE
//SFCS
//ADEE

//ABCCED
void Test1()
{
	char matrix[] = "ABCESFCSADEE";
	char* str = "ABCCED";

	Test("Test1", (char*)matrix, 3, 4, str, true);
}



int main(int argc, char* argv[])
{
	Test1();

	return 0;
}