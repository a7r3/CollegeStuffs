/// Program to Implement Prim's algorithm

// This algorithm is used to calculate a Minimum Spanning tree
// Given: A connected graph
// To derive: A Minimum Spanning Tree
// Characteristics :
// 1) Occupies the least total weight
// 2) Does not have any cyclic dependency

#include<stdio.h>
#define MAX 30

// Adjacency matrix, in which every vertex's
// corresponding adjacent vertex is defined
// If value[x][y] = 9999 -> NO EDGE between x and y
//
// If value >= 0 and not 9999
//  there's an edge between x and y
//   with edge-weight 'value'
int g[MAX][MAX]; // store the graph

// The table which contains the following information
// NODE - The node, represented by its index
// WEIGHT - rmat[X][0] - Weight of the edge which joins ROOT and NODE
// ROOT - rmat[X][1] - Root of the NODE
int rmat[MAX][2];

// Array which shows the visit status of nodes
// 0 -> Node is NOT visited
// 1 -> Node is visited
int v[MAX];

// Method to initialize ...
// > The weight to 9999 (Assumed Infinity)
// > The Root Node to NIL (0)
// > The Visited Status of node to 0 (NOT visited)
void init (int n)
{
        int i;

        for (i = 0; i < n; i++)
        {
                rmat[i][0] = 9999;
                rmat[i][1] = 0;
                v[i] = 0;
        }
}

void prims (int n)
{
        // f -> No. of nodes visited
        int f = 0, u = 0, i, min, minI;
        // While we haven't finished visiting all nodes
        while (f < n)
        {
                // Set default weight to Infinity
                min = 9999;

                // I need a root node to start with
                for (i = 0; i < n; i++)
                {
                        // If its weight is not Infinity
                        // i.e. If the vertices are connected
                        if (g[u][i] != 9999)
                        {
                                // If it's not visited
                                if (!v[i])
                                {
                                        // If weight of the edge is greater than
                                        // the previously calculated weight
                                        if (g[u][i] < rmat[i][0])
                                        {
                                                // Set the new weight, which is lesser
                                                rmat[i][0] = g[u][i];
                                                // Set the new root node
                                                rmat[i][1] = u;
                                        }
                                }
                        }
                }

                // I've visited the current root node, mark it somewhere
                v[u] = 1;

                // Got to search for a new root node
                // `min' holds the minimum weight,
                // `minI' holds the index at which edge with minimum weight is present
                for (i = 0; i < n; i++)
                {
                        // If the weight is lesser than the previously calculated minimum
                        // AND the node is not visited yet
                        if (rmat[i][0] < min && !v[i])
                        {
                                // Update the new minimum and its index
                                min = rmat[i][0];
                                minI = i;
                        }
                }

                // I iz da new root
                // New root is the one with minimum edge-weight
                u = minI;
                // Yeah, we've completed visiting a node
                f++;
        }
}

void main ()
{
        int i, j, n;

        // Just TC stuffs
        // clrscr();

        printf("Enter the number of Vertices > ");
        scanf("%d", &n);

        printf("Enter the weighted adjacency matrix\nIf there's no adjacency, Enter 9999\n");
        for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                        scanf("%d", &g[i][j]);

        // debugging
        /* for (i = 0; i < n; i++)
        {
                for (j = 0; j < n; j++)
                        printf("%d | ", g[i][j]);

                printf("\n");
        }*/

        init(n);

        prims(n);

        printf("\n\n");
        for (i = 0; i < n; i++)
                printf(" %d |", i+1);
        printf("\n");
        for (i = 0; i < n; i++)
                printf(" %d |", rmat[i][0]);
        printf("\n");
        for (i = 0; i < n; i++)
                printf(" %d |", rmat[i][1] + 1);

        // Just TC stuffs
        // getch();
}
