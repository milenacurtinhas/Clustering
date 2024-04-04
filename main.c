#include <stdio.h>
#include <stdlib.h>
#include "vector.h"
#include "vertex.h"
#include "kruskal.h"

double A_coord[] = {3.0, 7.0};
double B_coord[] = {1.0, 2.0};
double C_coord[] = {7.0, 3.0};
double D_coord[] = {4.0, 7.0};
double E_coord[] = {1.0, 1.0};
double F_coord[] = {6.0, 4.0};
double G_coord[] = {4.0, 6.0};
double H_coord[] = {2.0, 1.0};
double J_coord[] = {7.0, 4.0};
double I_coord[] = {6.0, 3.0};

int k = 3;

int main()
{
    //inicializa vértices
    Vertex A = vertex_init("A", 0, A_coord);
    Vertex B = vertex_init("B", 1, B_coord);
    Vertex C = vertex_init("C", 2, C_coord);
    Vertex D = vertex_init("D", 3, D_coord);
    Vertex E = vertex_init("E", 4, E_coord);
    Vertex F = vertex_init("F", 5, F_coord);
    Vertex G = vertex_init("G", 6, G_coord);
    Vertex H = vertex_init("H", 7, H_coord);
    Vertex I = vertex_init("I", 8, I_coord);
    Vertex J = vertex_init("J", 9, J_coord);

    //inicializa vertores de vértices e arestas
    Vector vertexes = vector_init(30, sizeof(Vertex));
    Vector edges = vector_init(30, sizeof(Edge));

    vector_push(vertexes, &A);
    vector_push(vertexes, &B);
    vector_push(vertexes, &C);
    vector_push(vertexes, &D);
    vector_push(vertexes, &E);
    vector_push(vertexes, &F);
    vector_push(vertexes, &G);
    vector_push(vertexes, &H);
    vector_push(vertexes, &I);
    vector_push(vertexes, &J);

    for (int i = 0; i < vector_size(vertexes); i++)
    {
        Vertex x = *(Vertex *)vector_at(vertexes, i);
        for (int j = i + 1; j < vector_size(vertexes); j++)
        {
            Vertex y = *(Vertex *)vector_at(vertexes, j);
            //inicializa arestas
            Edge e = edge_init(x, y, 2);
            vector_push(edges, &e);
        }
    }

    // for (int i = 0; i < vector_size(edges); i++)
    // {
    //     Edge e = *(Edge *)vector_at(edges, i);
    //     Vertex v1 = edge_vertex1(e);
    //     Vertex v2 = edge_vertex2(e);
    //     printf("%s - %s dist=%lf\n", vertex_get_name(v1), vertex_get_name(v2), edge_distance(e));
    // }

    //inicializa vetor da MST
    Vector MST = kruskal(vertexes, edges);

    vector_pop(MST, k);

    for (int i = 0; i < vector_size(MST); i++)
    {
        Edge e = *(Edge *)vector_at(MST, i);
        Vertex v1 = edge_vertex1(e);
        Vertex v2 = edge_vertex2(e);
        printf("%s - %s\n", vertex_get_name(v1), vertex_get_name(v2));
    }

    //destroi vértices
    vertex_destroy(A);
    vertex_destroy(B);
    vertex_destroy(C);
    vertex_destroy(D);
    vertex_destroy(E);
    vertex_destroy(F);
    vertex_destroy(G);
    vertex_destroy(H);
    vertex_destroy(I);
    vertex_destroy(J);

    //destroi arestas
    for (int i = 0; i < vector_size(edges); i++)
    {
        Edge e = *(Edge *)vector_at(edges, i);
        edge_destroy(e);
    }

    //destroi vertores de vértices e arestas
    vector_destroy(vertexes);
    vector_destroy(edges);

    //destroi vetor da MST
    vector_destroy(MST);

    // TODO: Quebrar agora as k-1 maiores arestas para formar k grupos -> dar pop nos k-1 ultimos elementos da MST ?(observar se MST sempre fica ordenada)
    // Não faço ideia ainda como funciona...
    // E imprimir os grupos -> dijakstra com prioridade

    return 0;
}