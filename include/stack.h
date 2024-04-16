#ifndef STACK_H

typedef struct _stack *Stack;

/**
 * @brief Inicializa uma pilha
 * 
 * @param cap Capacidade inicial
 * @param size Tamanho dos elementos
 * @return Pilha inicializada
 */
Stack stack_init(int cap, int size);

/**
 * @brief Insere um elemento na pilha
 * 
 * @param s Pilha
 * @param item Elemento
 */
void stack_push(Stack s, void *item);

/**
 * @brief Remove um elemento da pilha
 * 
 * @param s Pilha
 * @param ptr Ponteiro para o elemento removido
 */
void stack_pop(Stack s, void *ptr);

/**
 * @brief Verifica se a pilha está vazia
 * 
 * @param s Pilha
 * @return int 1 se a pilha está vazia, 0 caso contrário
 */
int stack_empty(Stack s);

/**
 * @brief Libera a memória alocada pela pilha
 * 
 * @param s Pilha
 */
void stack_destroy(Stack s);

#endif