#include "lista.h"

int menu(){//OK
    int op(0);
    cout << "1- Inicializar\n";
    cout << "2- Inserir no inicio\n";
    cout << "3- Inserir no fim\n";
    cout << "4- Remover do inicio\n";
    cout << "5- Remover do fim\n";
    cout << "6- Remover valor especifico\n";
    cout << "7- Imprimir do inicio\n";
    cout << "8- Imprimir do final\n";
    cout << "0- Sair\n";
    cout << "Escolha: ";
    cin >> op;
    return op;
}
lista * inicializar(){//OK
    return NULL;
}

bool isEmpty(lista * l){//OK
    if(l == NULL){
        return 1;
    }else{
        return 0;
    }
}
lista * inserirInicio(lista* l,int dado){//OK
    //Retorna o primeiro dado alocado, sempre;
    //As extremidades são conectadas
    lista * novaL = (lista*)malloc(sizeof(lista));
    novaL->dado = dado;
    if(isEmpty(l)){
        novaL->prox = novaL;
        novaL->ant = novaL;
        //Na primeira alocação aponta pra ele mesmo
        return novaL;
    }else{
        if(l->prox == l){
            //Realização da segunda alocação
            novaL->prox = l;
            novaL->ant = l;
            l->prox = novaL;
            l->ant = novaL;
        }else{
           //A ideia de inserir no inicio é colocar o novo nodo após o/na frente do L
            novaL->prox = l->prox;//Digo que o proximo nó do nó atual é o proximo nó de l
            novaL->ant = l;//Digo que o nó anterior ao atual será o l
            //Dessa forma, eu deixo o meu novo nó entre o L e o antigo L-Prox
            l->prox->ant = novaL;
            l->prox = novaL;//Digo que o nó após L será o novo nó, assim colocando ele em sua "frente"
            
        }
        
    }
    return l;
}

lista * inserirFim(lista* l,int dado){//OK
    lista * novaL = (lista*)malloc(sizeof(lista));
    novaL->dado = dado;
    if(isEmpty(l)){
        return inserirInicio(l,dado);//Já tem algo pronto nessa função para caso seja a primeira alocação
    }else{
        //Na segunda alocação também vai ser a mesma coisa , eu acho
        if(l->prox == l){
            return inserirInicio(l,dado);//Já tem pronto também
        }else{
            //Demais alocações, inserir atrás do L(l->ant) primeiro da fila, desconsiderando o L
            novaL->prox = l;
            novaL->ant = l->ant;
            l->ant->prox = novaL;
            l->ant = novaL;
        }
    }

return l;
    /*
    if(!isEmpty(l)){
        lista * aux = l->prox;
        while(aux->prox!=l){
            aux = aux->prox;
        }
        lista * novaL = (lista*)malloc(sizeof(lista));
        novaL->dado = dado;
        aux->prox = novaL;
        novaL->prox = l;
        novaL->ant = aux;
        l->ant = novaL;
    }else{
        cout << "Lista vazia\n";
        return l;
    }
    return l;
    */
}

lista * removeIncio(lista * l){
    if(!isEmpty(l)){
        if(l->prox==l){
            free(l);
            cout << "Lista esvaziada, retornando NULL\n";
            return NULL;
        }
        lista * aux = l->prox;//Salvar ele para dar free depois
        aux->prox->ant = l;
        l->prox = aux->prox;
        free(aux);
    }else{
        cout << "Lista vazia\n";
    }

}

lista * removeFim(lista * l){

    if(!isEmpty(l)){
        if(l->prox == l){
            free(l);
            cout << "Lista esvaziada, retornando NULL\n";
            return NULL;
        }else{
            lista * aux = l->ant;
            aux->ant->prox = l;
            l->ant = aux->ant;
            free(aux);
            return l;
        }

    }else{
        cout << "Lista vazia\n";
        return l;
    }

}

lista * removeValor(lista* l,int dado){    
    //Precisa de loop para rodar a lista procurando o termo
    if(l->dado == dado){
        lista * aux = l->prox;
        l->prox->ant = l->ant;
        l->ant->prox = l->prox;

        if(l->prox == l){
            free(l);
            return NULL;
        }else{
            free(l);
            return aux;
        } 
    }else{
        lista * aux = l->prox;
        while(aux->dado != dado && aux != l){
              aux=aux->prox;
        }
        if(aux == l){
            cout << "Dado nao encontrado \n";
            return l;
        }else{
            aux->prox->ant = aux->ant;
            aux->ant->prox = aux->prox;
            free(aux);
            return l;
        }
    }
}

void imprimirFrenteFim(lista * l){

    if(!isEmpty(l)){
        lista * aux = l;
        do{
            if(aux==l){
                cout << "Nodo controle\n";
            }else if(aux == l->prox){
                cout << "Inicio da lista(nodo apos o L)\n";
            }else if(aux == l->ant){
                cout << "Fim da lista(nodo antes do L)\n";
            }
            cout << "Endereco: " <<aux << endl;
            cout << "Dado: " << aux->dado << endl;
            aux = aux->prox;
        }while(aux != l);
    }else{
        cout << "Lista vazia\n";
    }


}

void imprimirReverso(lista *l){
        if(!isEmpty(l)){
        lista * aux = l;
        do{
            if(aux==l){
                cout << "Nodo controle\n";
            }else if(aux == l->prox){
                cout << "Fim da lista(nodo antes do L)\n";
            }else if(aux == l->ant){
                cout << "Inicio da lista(nodo apos o L)\n";
            }
            cout << "Endereco: " <<aux << endl;
            cout << "Dado: " << aux->dado << endl;
            aux = aux->ant;
        }while(aux != l);
    }else{
        cout << "Lista vazia\n";
    }

}
