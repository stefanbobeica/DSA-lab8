#include "utils.h"


graph_list* matrixToList(graph_matrix* graph) 
{   
    graph_list* ret;
    
    ret = (graph_list*)malloc(sizeof(graph_list));
    

    ret->E = graph->E;
    ret->V = graph->V;

    ret->listHeads = (node**)calloc(graph->V, sizeof(node*));
   

    for(int i = 0; i < graph->V; i++)
    {
        for(int j = 0; j < graph->V; j++)
        {
            if(graph->matrix[i][j] == 1)
            {
                ret->listHeads[i] = push_values(ret->listHeads[i], j);
            }
        }
    }

    return ret;
}

void free_graph_matrix(graph_matrix** graph) 
{
    for(int i = 0; i < (*graph)->V; i++)
        free((*graph)->matrix[i]);
    free((*graph)->matrix);
    free((*graph));
    *graph = NULL;
}


node* push_values(node* root, int val) 
{   node *p;
    if(root==NULL)
    {
        p = (node*)malloc(sizeof(node));
        
        p->next = NULL;
        p->vertexNr = val;
        return p;
    }
    root->next = push_values(root->next, val);
    return root;
}


void print_graph_list(graph_list* graph) {
}