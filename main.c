#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define L 3
#define C 3

float metrosQuadrados(float larg, float comp);
float calTijolo(float m2, int tijolo);
float calTelha(float m2, int telha);
float calPiso(float m2, int piso);
void imprimirMatriz(float M[][C], float m2);
void imprimirInfos();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    int menu, material, tijolo, telha, piso;
    int i, j, inicial = 1, cont = 0;
    float matriz[L][C], larg, comp, qtd, m2;

    //Aqui colocar uma introdução para o programa


    //Inicialização da Matriz
    for(i = 0;i < L;i++){
        for(j = 0; j < C; j++){
            matriz[i][j] = 0;
            if(j == 0){ // inicializa a primeira coluna com 1, 2 e 3.
                matriz[i][j] = inicial;
                inicial++;
            }
        }
    }

     for(i = 0;i < L;i++){
        for(j = 0; j < C; j++){
            printf("%f\t", matriz[i][j]);
        }
        printf("\n");
     }


    //Entrada de dados
    printf("\nInforme a largura, em metros, do cômodo o qual deseja cálcular os materiais necessários para construir: ");
    scanf("%f", &larg);
    printf("\nAgora informe o comprimento, em metros, do cômodo: ");
    scanf("%f", &comp);

    // Calcula o metro quadrado
    m2 = metrosQuadrados(larg, comp);

    //Menu
    printf("\nO que você deseja fazer? ");
    printf("\n1. Inserir material para cálculo,");
    printf("\n2. Remover material do cálculo,");
    printf("\n3. Alterar material,");
    printf("\n4. Consultar matriz dos cálculos,");
    printf("\n5. Ver informações dos desenvolvedores,");
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
                            qtd = calTijolo(m2, tijolo); // Chama a função para cálculo da quantidade de tijolos

                        matriz[0][1] = tijolo;
                        matriz[0][2] = qtd;
                        cont++; // Faz a contagem de itens cadastrados para mostrar mensagem antes do menu
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
                            qtd = calTelha(m2, telha); // Chama a função para cálculo da quantidade de telhas

                        matriz[1][1] = telha;
                        matriz[1][2] = qtd;
                        cont++; // Faz a contagem de itens cadastrados para mostrar mensagem antes do menu
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
                            qtd = calPiso(m2, piso); // Chama a função para cálculo da quantidade de piso

                        matriz[2][1] = piso;
                        matriz[2][2] = qtd;
                        cont++; // Faz a contagem de itens cadastrados para mostrar mensagem antes do menu
                    break;
                    default:
                        printf("\nOpção inválida!\n");
                }
            break;
            case 2:
                //Remover
            break;
            case 3: //Alterar

            break;
            case 4: //Consultar
                imprimirMatriz(matriz, m2);
            break;
            case 5: //Informações
                imprimirInfos();
            break;
            default:
                printf("\nOpção inválida!\n");
        }

        if(cont == 3){ // Confere se o usuário já cadastrou todos os materiais
            printf("\n\n>> Você já cadastrou todos os itens!");
            printf("\nConsulte a matriz para ver a quantidade de todos os materiais!\n");
        } else{
            printf("\n>> Você já cadastrou ");
            if(matriz[1][0] != 0){
                printf("o tipo de tijolo, ");
            }
            if(matriz[1][1] != 0){
                printf("o tipo de telha, ");
            }
            if(matriz[1][2] != 0){
                printf("o tipo de piso, ");
            }
            printf("mas ainda falta cadastrar material!\n");
        }
        for(i = 0;i < L;i++){
        for(j = 0; j < C; j++){
            printf("%f\t", matriz[i][j]);
        }
        printf("\n");
     }

        printf("\nO que você deseja fazer? ");
        printf("\n1. Inserir material para cálculo,");
        printf("\n2. Remover material do cálculo,");
        printf("\n3. Alterar material,");
        printf("\n4. Consultar matriz dos cálculos,");
        printf("\n5. Ver informações dos desenvolvedores,");
        printf("\n6. Sair;");
        printf("\nOpção: ");
        scanf("%d", &menu);
    }

    printf("\nEsperamos que você tenha gostado da experiência!");
    printf("\n\t\tAté a próxima :)\n");
}
float metrosQuadrados(float larg, float comp){
    return larg * comp;
}

float calTijolo(float m2, int tijolo){
    float qtd;

    if(tijolo == 1){ // cálculo vendação
        qtd =  m2 * 40;
    } else if(tijolo == 2){ // cálculo tijolo estrutural
        qtd =  m2 * 16.7 ;
    } else if(tijolo == 3){
        // cálculo bloco de concreto
    }
    return qtd;
}

float calTelha(float m2, int telha){
    float qtd;

    if(telha == 1){ // cálculo telha colonial
        qtd = m2 * 24;
    } else if(telha == 2){ // cálculo telha Portuguesa
        qtd = m2 * 17;
    } else if(telha == 3){ // cálculo Brasilit
        qtd = m2 * 0.4;
    }
    return qtd;
}

float calPiso(float m2, int piso){
    float qtd;

    if(piso == 1){ // cálculo Porcelanato
        qtd = m2 * 2.8;
    } else if(piso == 2){ // cálculo Laminado
        qtd = m2 * 2.4;
    }
    return qtd;
}

void imprimirMatriz(float M[][C], float m2){

    // Aqui irá a a impressão da matriz com as quantidades
}

void imprimirInfos(){

    //Imprimir as informações dos desenvolvedores

}
