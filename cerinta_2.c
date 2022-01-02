#include "utils.h"

/**
 * TODO:   O functie ce transforma un graf reprezentat prin liste de adiacenta 
 * intr-unul reprezentat cu ajutorul unei matrice de adiacenta
 * @note   Nodurile trebuie indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta
 * @retval - Graful in reprezentarea matrice de adiacenta
 */
graph_matrix *listToMatrix(graph_list *graph)
{   int i=0;
    graph_matrix *ret;
    node *current;
    ret = (graph_matrix *)malloc(sizeof(graph_matrix));
    ret->E = graph->E;
    ret->V = graph->V;
    ret->matrix = (int **)malloc(graph->V * sizeof(int *));
    while(i!=graph->V)
    {
        ret->matrix[i] = (int *)calloc(graph->V, sizeof(int));

        current = graph->listHeads[i];
        while (current != NULL)
        {
            ret->matrix[i][current->vertexNr] = 1;
            current = current->next;
        }
    i++;
    }

    return ret;
}

/**
 * TODO:   Eliberati memoria grafului primit ca parametru
 * @note   Nodurile sunt indexate intre 0 si V-1
 * @param  graph: Graful in reprezentarea liste de adiacenta, a carui memorie trebuie eliberata
 * @retval 
*/
void free_graph_list(graph_list **graph)
{
    node *prev, *current;
    int i;
    while (i != (*graph)->V)
    {
        prev = (*graph)->listHeads[i];
        if (prev != NULL)
            break;
        current = prev->next;
        if (current == NULL)
        {
            free(prev);
            ;
        }
        while (current != NULL)
        {
            current = current->next;
            prev = current;
            free(prev);
        }
        i++;
    }
    free((*graph)->listHeads);
    free(*graph);
    *graph = NULL;
}

void print_graph_matrix(graph_matrix *graph)
{
    // nice to have; functie de afiseaza continutul unui graf reprezentat prin matrice de adiacenta
}