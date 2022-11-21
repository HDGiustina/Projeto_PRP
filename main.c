#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define L 3
#define C 2

float calTijolo(float larg, float comp, int tijolo);

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int menu, material, tijolo, telha, piso;
    float matriz[L][C], larg, comp, qtd;

    //Aqui colocar uma introdu��o para o programa


    //Entrada de dados
    printf("\nInforme a largura, em metros, do c�modo o qual deseja c�lcular os materiais necess�rios para construir: ");
    scanf("%f", &larg);
    printf("\nAgora informe o comprimento, em metros, do c�modo: ");
    scanf("%f", &comp);

    //Menu
    printf("\nO que voc� deseja fazer? ");
    printf("\n1. Inserir material para c�lculo,");
    printf("\n2. Remover material do c�lculo,");
    printf("\n3. Alterar material,");
    printf("\n4. Consultar matriz dos c�lculos,");
    printf("\n5. Informa��es dos desenvolvedores,");
    printf("\n6. Sair;");
    printf("\nOp��o: ");
    scanf("%d", &menu);

    while(menu != 6){
        switch(menu){
            case 1: //Inserir
                printf("\n\nQual material voc� deseja inserir?");
                printf("\n1- Tijolo");
                printf("\n2- Telha");
                printf("\n3- Piso");
                printf("\nOp��o: ");
                scanf("%d", &material);

                switch(material){
                    case 1: // Tijolo
                        printf("\n\nQual o tipo de tijolo que voc� deseja?");
                        printf("\n1- Veda��o,");
                        printf("\n2- Estrutural,");
                        printf("\n3- Bloco de concreto,");
                        printf("\nOp��o: ");
                        scanf("%d", &tijolo);

                        if(tijolo < 1 || tijolo > 3){
                            printf("\nOp��o inv�lida!\n");
                            break;
                        } else
                            qtd = calTijolo(larg, comp, tijolo);

                        printf("\npassou\n");
                        matriz[0][0] = tijolo;
                        matriz[0][1] = qtd;
                    break;
                    case 2:
                        // Telha
                    break;
                    case 3:
                        // Piso
                    break;
                    default:
                        printf("\nOp��o inv�lida!\n");
                }
            break;
            case 2:
                //Remover
            break;
            case 3:
                //Alterar
            break;
            case 4:
                //Consultar
            break;
            case 5:
                //Informa��es
            break;
            default:
                printf("\nOp��o inv�lida!\n");
        }

        printf("\nO que voc� deseja fazer? ");
        printf("\n1. Inserir material para c�lculo,");
        printf("\n2. Remover material do c�lculo,");
        printf("\n3. Alterar material,");
        printf("\n4. Consultar matriz dos c�lculos,");
        printf("\n5. Informa��es dos desenvolvedores,");
        printf("\n6. Sair;");
        printf("\nOp��o: ");
        scanf("%d", &menu);
    }

    printf("\nEsperamos que voc� tenha gostado da experi�ncia!");
    printf("\n\t\tAt� a pr�xima :)\n");
}

float calTijolo(float larg, float comp, int tijolo){
    float qtd;

    if(tijolo == 1){
        // c�lculo venda��o
    } else if(tijolo == 2){
        // c�lculo estrutural
    } else if(tijolo == 3){
        // c�lculo bloco de concreto
    }
    return qtd;
}
