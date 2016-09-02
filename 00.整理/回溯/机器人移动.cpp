//看我的解法

#include <stdio.h>

int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;
		number /= 10;
	}

	return sum;
}

bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols
		&& getDigitSum(row) + getDigitSum(col) <= threshold
		&& !visited[row* cols + col])
		return true;

	return false;
}

int movingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int count = 0;
	if (check(threshold, rows, cols, row, col, visited))
	{
		visited[row * cols + col] = true;

		count = 1 + movingCountCore(threshold, rows, cols,  //+1 ,,wenti。。
			row - 1, col, visited)
			+ movingCountCore(threshold, rows, cols,
			row, col - 1, visited)
			+ movingCountCore(threshold, rows, cols,
			row + 1, col, visited)
			+ movingCountCore(threshold, rows, cols,
			row, col + 1, visited);
	}

	return count;
}

int movingCount(int threshold, int rows, int cols)
{
	bool *visited = new bool[rows * cols];
	for (int i = 0; i < rows * cols; ++i)
		visited[i] = false;

	int count = movingCountCore(threshold, rows, cols,
		0, 0, visited);

	delete[] visited;

	return count;
}

// ================================ test code ================================
void test(char* testName, int threshold, int rows, int cols, int expected)
{
	if (testName != NULL)
		printf("%s begins: ", testName);

	if (movingCount(threshold, rows, cols) == expected)
		printf("Passed.\n");
	else
		printf("FAILED.\n");
}

void test1()
{
	test("Test1", 5, 10, 10, 21);
}


int main(int agrc, char* argv[])
{
	test1();
}