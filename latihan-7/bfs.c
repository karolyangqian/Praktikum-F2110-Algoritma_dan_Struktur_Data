#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "boolean.h"

const int MXN = 100;
#define UNPASSED -1

void displayPointsQueue(Queue q) {
    printf("Points:\n");
    ElType e;
    while (!isEmpty(q))
    {
        dequeue(&q, &e);
        printf("(%d, %d)\n", e.row, e.col);
    } 
}


int main()
{
    int N;
    char arr[MXN][MXN];
    int dist[MXN][MXN];
    ElType awal, cur, add;

    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %c", &arr[i][j]);
            dist[i][j] = UNPASSED;
            if (arr[i][j] == 'A') {
                awal.row = i;
                awal.col = j;
            }
        }
    }

    // Start code here...
    Queue q;
    CreateQueue(&q);
    enqueue(&q, awal);
    dist[awal.row][awal.col] = 0;

    // arah: bawah, kanan, atas, kiri
    int arah_r[4] = {1, 0, -1, 0};
    int arah_c[4] = {0, 1, 0, -1};
    int ar, ac;
    boolean found = false;

    while (!isEmpty(q)) {
        dequeue(&q, &cur);

        for (int i = 0; i < 4; i++) {
            ar = arah_r[i];
            ac = arah_c[i];
            if (cur.row+ar >= 0 && cur.col+ac >= 0 && cur.row+ar < MXN && cur.col+ac < MXN && dist[cur.row+ar][cur.col+ac] == UNPASSED && arr[cur.row+ar][cur.col+ac] != '#') {
                add.row = cur.row+ar;
                add.col = cur.col+ac;
                enqueue(&q, add);
                dist[add.row][add.col] = dist[cur.row][cur.col] + 1;
            }
            if (arr[add.row][add.col] == 'B') {
                found = true;
                break;
            }
        }
        // displayPointsQueue(q);
        // printf("\n");
        if (found) {
            printf("Ya\n");
            printf("%d\n", dist[add.row][add.col]);
            break;
        }
    }

    if (isEmpty(q)) {
        printf("Tidak\n");
    }

    // displayPointsQueue(q);
    return 0;
}