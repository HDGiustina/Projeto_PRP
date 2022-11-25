#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define L 3
#define C 3

float calTijolo(float larg, float comp, int tijolo);
float calTelha(float larg, float comp, int telha);
float calPiso(float larg, float comp, int piso);
void imprimirMatriz(float M[][C], float larg, float comp);
void imprimirInfos();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int menu, material, tijolo, telha, piso;
    float matriz[L][C], larg, comp, qtd;

    //Aqui colocar uma introdução para o programa


    //Inicialização da Matriz

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

                        if(tijolo < 1 || tijolo > 3){ // Confere se o usuário não digitou opção inválida
                            printf("\nOpção inválida!\n");
                            break;
                        } else
                            qtd = calTijolo(larg, comp, tijolo); // Chama a função para cálculo da quantidade de tijolos

                        matriz[0][1] = tijolo;
                        matriz[0][2] = qtd;
                    break;
                    case 2: // Telha
                        printf("\n\nQual o tipo de telha que você deseja?");
                        printf("\n1- Colonial,");
                        printf("\n2- Portuguesa,");
                        printf("\n3- Brasilit,");
                        printf("\nOpção: ");
                        scanf("%d", &telha);

                        if(telha < 1 || telha > 3){ // Confere se o usuário não digitou opção inválida
                            printf("\nOpção inválida!\n");
                            break;
                        } else
                            qtd = calTelha(larg, comp, telha); // Chama a função para cálculo da quantidade de telhas

                    break;
                    case 3: // Piso
                        printf("\n\nQual o tipo de piso que você deseja?");
                        printf("\n1- Pocelanato,");
                        printf("\n2- Laminado,");
                        printf("\nOpção: ");
                        scanf("%d", &piso);

                        if(piso < 1 || piso > 2){ // Confere se o usuário não digitou opção inválida
                            printf("\nOpção inválida!\n");
                            break;
                        } else
                            qtd = calPiso(larg, comp, piso); // Chama a função para cálculo da quantidade de piso

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
            case 4: //Consultar
                imprimirMatriz(matriz, larg, comp);
            break;
            case 5: //Informações
                imprimirInfos();
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

float calTelha(float larg, float comp, int telha){
    float qtd;

    if(telha == 1){
        // cálculo telha colonial
    } else if(telha == 2){
        // cálculo telha Portuguesa
    } else if(telha == 3){
        // cálculo Brasilit
    }
    return qtd;
}

float calPiso(float larg, float comp, int piso){
    float qtd;

    if(piso == 1){
        // cálculo Porcelanato
    } else if(piso == 2){
        // cálculo Laminado
    }
    return qtd;
}

void imprimirMatriz(float M[][C], float larg, float comp){

    // Aqui irá a a impressão da matriz com as quantidades
}

void imprimirInfos(){

    //Imprimir as informações dos desenvolvedores

}
