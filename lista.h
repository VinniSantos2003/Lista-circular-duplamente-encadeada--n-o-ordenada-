#include <iostream>
#include <stdio.h>
using namespace std;

struct lista{

    int dado;
    lista * prox;
    lista * ant;

};

int menu();
bool isEmpty(lista * l);
lista * inicializar();
lista * inserirInicio(lista* l,int dado);
lista * inserirFim(lista* l,int dado);
lista * removeIncio(lista * l);
lista * removeFim(lista * l);
lista * removeValor(lista* l,int dado);
void imprimirFrenteFim(lista * l);
void imprimirReverso(lista *l );




