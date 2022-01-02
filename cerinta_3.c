#include "utils.h"

/**
 * TODO:   Implementati o functie ce ce genereaza matricea drumurilor unui graf reprezentat cu 
 * ajutorul matricei de adiacenta
 * @note   
 * @param  graph: Graful in reprezentarea matrice de adiacenta
 * @retval - o matrice reprezentand matricea drumurilor
 */
int **findPaths(graph_matrix *graph)
{
    int **dist;
    dist = (int **)malloc(sizeof(int *) * graph->V);

    for (int i = 0; i < graph->V; i++)
        dist[i] = (int *)malloc(graph->V * sizeof(int));

    for (int i = 0; i < graph->V; i++)
        for (int j = 0; j < graph->V; j++)
            dist[i][j] = graph->matrix[i][j];

    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            for (int k = 0; k < graph->V; k++)
            {
                if (dist[i][k] == 1 && dist[j][i] == 1)
                    dist[j][k] = 1;
            }
        }
    }

    for (int i = 0; i < graph->V; i++)
        for (int j = 0; j < graph->V; j++)
            if (i == j)
                dist[i][j] = 0;

    return dist;
}