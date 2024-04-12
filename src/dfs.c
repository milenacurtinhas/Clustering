#include "stack.h"
#include "dfs.h"

void dfs(Vector graph, Node n, FILE *output)
{
    Vector components = vector_init(50, sizeof(Vertex));
    Stack s = stack_init(sizeof(Node));
    stack_push(s, &n);

    while (!stack_empty(s))
    {
        Node cur = NULL;
        stack_pop(s, &cur);
        if (node_get_visited(cur))
        {
            continue;
        }
        node_set_visited(cur);
        Vector adjs = node_get_adjacent(cur);

        Vertex v = node_get_vertex(cur);
        vector_push(components, &v);
        fprintf(output, "%s ", vertex_get_name(v));

        for (int i = 0; i < vector_size(adjs); i++)
        {
            int index = *(int *)vector_at(adjs, i);
            Node adj = *(Node *)vector_at(graph, index);
            stack_push(s, &adj);
        }
    }
    fprintf(output, "\n");
    vector_sort(components, vertex_compare_idx);

    vector_destroy(components);
    stack_destroy(s);
}