#include "dfs.h"

#include "stack.h"

#define INITIAL_STACK_CAP 4000
#define INITIAL_GROUP_CAP 10000

void dfs(Vector graph, Node n, FILE *output) {
    Vector group = vector_init(INITIAL_GROUP_CAP, sizeof(Vertex));
    Stack s = stack_init(INITIAL_STACK_CAP, sizeof(Node));
    stack_push(s, &n);

    while (!stack_empty(s)) {
        Node cur = NULL;
        stack_pop(s, &cur);

        if (node_get_visited(cur)) {
            continue;
        }
        
        node_set_visited(cur);
        Vector adjs = node_get_adjacent(cur);

        Vertex v = node_get_vertex(cur);
        vector_push(group, &v);

        for (int i = 0; i < vector_size(adjs); i++) {
            int index = *(int *)vector_at(adjs, i);
            Node adj = *(Node *)vector_at(graph, index);
            stack_push(s, &adj);
        }
    }

    vector_sort(group, vertex_compare_name);

    for (int i = 0; i < vector_size(group); i++) {
        Vertex v = *(Vertex *)vector_at(group, i);
        fprintf(output, "%s", vertex_get_name(v));
        if (i < vector_size(group) -1) fprintf(output, ",");
    }

    fprintf(output, "\n");

    vector_destroy(group);
    stack_destroy(s);
}