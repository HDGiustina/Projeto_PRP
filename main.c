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

    //Aqui colocar uma introdução para o programa


    //Entrada de dados
    printf("\nInforme a largura, em metros, do cômodo o qual deseja cálcular os materiais necessários para construir: ");
    scanf("%f", &larg);
    printf("\nAgora informe o comprimento, em metros, do cômodo: ");
    scanf("%f", &comp);

    //Menu
    printf("\nO que você deseja fazer? ");
    printf("\n1. Inserir material para cálculo,");
    printf("\n2. Remover material do cálculo,");
    printf("\n3. Alterar material,");
    printf("\n4. Consultar matriz dos cálculos,");
    printf("\n5. Informações dos desenvolvedores,");
    printf("\n6. Sair;");
    printf("\nOpção: ");
    scanf("%d", &menu);

    while(menu != 6){
        switch(menu){
            case 1: //Inserir
                printf("\n\nQual material você deseja inserir?");
                printf("\n1- Tijolo");
                printf("\n2- Telha");
                printf("\n3- Piso");
                printf("\nOpção: ");
                scanf("%d", &material);

                switch(material){
                    case 1: // Tijolo
                        printf("\n\nQual o tipo de tijolo que você deseja?");
                        printf("\n1- Vedação,");
                        printf("\n2- Estrutural,");
                        printf("\n3- Bloco de concreto,");
                        printf("\nOpção: ");
                        scanf("%d", &tijolo);

                        if(tijolo < 1 || tijolo > 3){
                            printf("\nOpção inválida!\n");
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
                        printf("\nOpção inválida!\n");
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
                //Informações
            break;
            default:
                printf("\nOpção inválida!\n");
        }

        printf("\nO que você deseja fazer? ");
        printf("\n1. Inserir material para cálculo,");
        printf("\n2. Remover material do cálculo,");
        printf("\n3. Alterar material,");
        printf("\n4. Consultar matriz dos cálculos,");
        printf("\n5. Informações dos desenvolvedores,");
        printf("\n6. Sair;");
        printf("\nOpção: ");
        scanf("%d", &menu);
    }

    printf("\nEsperamos que você tenha gostado da experiência!");
    printf("\n\t\tAté a próxima :)\n");
}

float calTijolo(float larg, float comp, int tijolo){
    float qtd;

    if(tijolo == 1){
        // cálculo vendação
    } else if(tijolo == 2){
        // cálculo estrutural
    } else if(tijolo == 3){
        // cálculo bloco de concreto
    }
    return qtd;
}
