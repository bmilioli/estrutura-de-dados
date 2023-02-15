#include <stdio.h>
#include <stdlib.h>
#include "locale.h"

typedef struct NO
{
    int dado;
    struct NO *prox;
} NO;

typedef struct FILA
{
    NO *inicio;
    NO *fim;
    int qtd;
} FILA;

void inicializaFila(FILA *f)
{
    f->inicio = NULL;
    f->fim = NULL;
}

void enfileira(int dado, FILA *f)
{
    NO *ptr = (NO *)malloc(sizeof(NO));
    if (ptr == NULL)
    {
        printf("Erro de alocacao de memoria!");
        return;
    }
    else
    {
        ptr->dado = dado;
        ptr->prox = NULL;
        if (f->inicio == NULL)
        {
            f->inicio = ptr;
        }
        else
        {
            f->fim->prox = ptr;
        }
        f->fim = ptr;
        f->qtd++;
        return;
    }
}

int desenfileira(FILA *f)
{
    NO *ptr = f->inicio;
    int dado;
    if (ptr != NULL)
    {
        f->inicio = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if (f->inicio == NULL)
            f->fim = NULL;
        return dado;
    }
    else
    {
        printf("ERRO: Fila vazia");
    }
}

void imprimeFila(FILA *f)
{
    NO *ptr = f->inicio;
    if (ptr != NULL)
    {
        while (ptr != NULL)
        {
            printf("%d ", ptr->dado);
            ptr = ptr->prox;
        }
    }
    else
    {
        printf("ERRO: Fila vazia");
        return;
    }
}

int main()
{
    int numero;
    FILA *f1 = (FILA *)malloc(sizeof(FILA));
    if (f1 == NULL)
    {
        printf("Erro de alocacao de memoria!");
        exit(-1);
    }
    else
    {
        scanf("%d", &numero);
        enfileira(numero, f1);
        scanf("%d", &numero);
        enfileira(numero, f1);
        scanf("%d", &numero);
        enfileira(numero, f1);
        scanf("%d", &numero);
        enfileira(numero, f1);

        imprimeFila(f1);

        numero = desenfileira(f1);
        printf("\nDesenfileiramos o %d", numero);
        imprimeFila(f1);
    }

    return 0;
}