#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 100

typedef struct
{
    int Item[MAXTAM];
    int Topo;
} TPilha;

void TPilha_Inicia(TPilha *p)
{
    p->Topo = -1;
}

int TPilha_Vazia(TPilha *p)
{
    if (p->Topo == -1)
        return 1;
    else
        return 0;
}

int TPilha_Cheia(TPilha *p)
{
    if (p->Topo == MAXTAM - 1)
        return 1;
    else
        return 0;
}

void TPilha_Insere(TPilha *p, int x)
{
    if (TPilha_Cheia(p) == 1)
        printf("ERRO: Pilha Cheia");
    else
    {
        p->Topo++;
        p->Item[p->Topo] = x;
    }
}

int TPilha_Retira(TPilha *p)
{
    int aux;
    if (TPilha_Vazia(p) == 1)
        printf("Erro: Pilha Vazia");
    else
    {
        aux = p->Item[p->Topo];
        p->Topo--;
        return aux;
    }
}

int main()
{
    TPilha *p = (TPilha *)malloc(sizeof(TPilha));
    TPilha_Inicia(p);

    TPilha_Insere(p, 10);
    TPilha_Insere(p, 20);
    TPilha_Insere(p, 30);

    int x = TPilha_Retira(p);
    printf("\n SAIU: %d", x);
    x = TPilha_Retira(p);
    printf("\n SAIU: %d", x);
    x = TPilha_Retira(p);
    printf("\n SAIU: %d", x);
    x = TPilha_Retira(p);
    printf("\n SAIU: %d", x);

    return 0;
}