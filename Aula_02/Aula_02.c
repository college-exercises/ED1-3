#include<stdio.h>

void mostrarOpcoesMenu(){
    printf("Informe a opcao desejada: \n\n");
    printf("1 - Vender pipoca.\n");
    printf("2 - Fechar Faturamento.\n");
    printf("3 - Fechar Programa.\n\n");
    printf("Opcao: ");
}

void mostrarOpcoesPipoca(){
    printf("Informe a opcao desejada: \n\n");
    printf("1 - Salgada R$ 5,00.\n");
    printf("2 - Doce R$ 7,50.\n");
    printf("Opcao: ");
}

int escolherCarrinho(){
    
    int carrinho;
    
    printf("Informe o carrinho: ");
    scanf("%i", &carrinho);

    return carrinho;
}

int instanciarVetor(){
    
    int *inicio, qt, i;

    qt = 15;

    inicio = (int*)malloc(qt * 2 * sizeof(int));

    for (i = 0; i < (qt * 2); i++)
    {
        *(inicio + i) = 0;
    }

    return inicio;
}

int escolherPipoca(){
    
    int pipoca;

    mostrarOpcoesPipoca();
    scanf("%i", &pipoca);

    return pipoca;
}

void registrarVenda(int carrinho, int pipoca, int *ponteiro){
  
    carrinho--;
    pipoca--;

    *(ponteiro + ((2 * carrinho) + pipoca)) += 1;
}

void venderPipoca(int *ponteiro){
    int carrinho, pipoca;

    carrinho = escolherCarrinho();
    pipoca = escolherPipoca();
    registrarVenda(carrinho, pipoca, ponteiro);
}

void exibirFaturamento(int *ponteiro){
    
    double precoSalgada, precoDoce;

    precoDoce = 7.50;
    precoSalgada = 5.00;

    int i, j;

    printf("\n\n");
    printf("Carrinho | Salg |  $  |  Doce  |  $  | Total  |  $ \n");
    printf("---------+------+-----+--------+-----+--------+------\n");
    
    for (i = 0; i < 15; i++)
    {
        int qtDoce, qtSalgada, receitaDoce, receitaSalgada, carroAtual;

        carroAtual = (i + 1);

        qtSalgada = *(ponteiro + 0 + (2 * i));
        qtDoce= *(ponteiro + 1 + (2 * i));

        receitaSalgada = *(ponteiro + 0 + (2 * i)) * precoSalgada;
        receitaDoce = *(ponteiro + 1 + (2 * i)) * precoDoce;

        if (carroAtual < 10)
            printf("   0%i    |   %i   |  %i  |   %i   |  %i  |   %i    |  %i \n", carroAtual, qtSalgada, receitaSalgada, qtDoce, receitaDoce, (qtSalgada + qtDoce), (receitaDoce + receitaSalgada));
        else
            printf("   %i    |   %i   |  %i  |   %i   |  %i  |   %i    |  %i \n", carroAtual, qtSalgada, receitaSalgada, qtDoce, receitaDoce, (qtSalgada + qtDoce), (receitaDoce + receitaSalgada));        
    }

    printf("\n\n");
}

int main(){

    int op;

    int *ponteiro;
    
    ponteiro = instanciarVetor();

    do
    {
        mostrarOpcoesMenu();
        scanf("%i", &op);

        switch (op)
        {
            case 1:
                venderPipoca(ponteiro);
                break;

            case 2:
                exibirFaturamento(ponteiro);
                break;
            
            default:
                return 0;
                break;
        }
    } while (op == 1);

    return 0;
}