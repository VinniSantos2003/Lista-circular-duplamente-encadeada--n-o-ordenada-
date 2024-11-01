#include "lista.h"

int main(){
    int op(0),dado(0);
    lista* novaLista;

    do{
        op = menu();
        switch (op)
        {
        case 1:
            novaLista = inicializar();
            break;
        case 2:
            cout << "Insira um dado a ser inserido no Inicio da lista: ";
            cin >> dado;
            novaLista = inserirInicio(novaLista,dado);
            break;
        case 3:
            cout << "Insira um dado a ser inserido no Final da lista: ";
            cin >> dado;
            novaLista = inserirFim(novaLista,dado);
            break;
        case 4:
            novaLista = removeIncio(novaLista);
            break;
        case 5:
            novaLista = removeFim(novaLista);
            break;
        case 6:
            cout << "Insira um dado a ser removido da lista: ";
            cin >> dado;
            novaLista = removeValor(novaLista,dado);
            break;
        case 7:
            imprimirFrenteFim(novaLista);
            break;
        case 8:
            imprimirReverso(novaLista);
            break;
        default:
            cout<<"Insira uma opcao valida ou digite 0 para sair\n";
            break;
        }

    }while(op!=0);



    return 0;
}