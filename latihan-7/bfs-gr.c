#include <stdio.h>
#include "queue.h"
#include "boolean.h"

#define MAX_N 100
#define UNVISITED -1

char grid[MAX_N][MAX_N];
boolean visited[MAX_N][MAX_N];
int distance[MAX_N][MAX_N];
int n;

int x[] = {0, 0, -1, 1};
int y[] = {-1, 1, 0, 0};

boolean isValid(int row, int col)
{
    return row >= 0 && row < n && col >= 0 && col < n &&
           grid[row][col] != '#' && !visited[row][col];
}

int bfs(int startRow, int startCol, int endRow, int endCol)
{
    Queue q;
    CreateQueue(&q);

    enqueue(&q, (ElType){startRow, startCol});
    visited[startRow][startCol] = true;
    distance[startRow][startCol] = 0;

    while (!isEmpty(q))
    {
        ElType current;
        dequeue(&q, &current);
        int curRow = current.row;
        int curCol = current.col;

        for (int i = 0; i < 4; i++)
        {
            int newRow = curRow + x[i];
            int newCol = curCol + y[i];

            if (isValid(newRow, newCol))
            {
                enqueue(&q, (ElType){newRow, newCol});
                visited[newRow][newCol] = true;
                distance[newRow][newCol] = distance[curRow][curCol] + 1;
            }
        }

        if (curRow == endRow && curCol == endCol)
        {
            return distance[curRow][curCol];
        }
    }
    return -1;
}

int main()
{
    scanf("%d", &n);
    int startRow = -1, startCol = -1, endRow = -1, endCol = -1;

    for (int i = 0; i < n; i++)
    {
        scanf("%s", grid[i]);
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = false;
            distance[i][j] = UNVISITED;
            if (grid[i][j] == 'A')
            {
                startRow = i;
                startCol = j;
            }
            else if (grid[i][j] == 'B')
            {
                endRow = i;
                endCol = j;
            }
        }
    }

    if (startRow == -1 || startCol == -1 || endRow == -1 || endCol == -1)
    {
        printf("Tidak\n");
        return 0;
    }

    int result = bfs(startRow, startCol, endRow, endCol);

    if (result != -1)
    {
        printf("Ya\n%d\n", result);
    }
    else
    {
        printf("Tidak\n");
    }
    return 0;
}