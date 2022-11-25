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

    //Aqui colocar uma introdu��o para o programa


    //Inicializa��o da Matriz

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

                        if(tijolo < 1 || tijolo > 3){ // Confere se o usu�rio n�o digitou op��o inv�lida
                            printf("\nOp��o inv�lida!\n");
                            break;
                        } else
                            qtd = calTijolo(larg, comp, tijolo); // Chama a fun��o para c�lculo da quantidade de tijolos

                        matriz[0][1] = tijolo;
                        matriz[0][2] = qtd;
                    break;
                    case 2: // Telha
                        printf("\n\nQual o tipo de telha que voc� deseja?");
                        printf("\n1- Colonial,");
                        printf("\n2- Portuguesa,");
                        printf("\n3- Brasilit,");
                        printf("\nOp��o: ");
                        scanf("%d", &telha);

                        if(telha < 1 || telha > 3){ // Confere se o usu�rio n�o digitou op��o inv�lida
                            printf("\nOp��o inv�lida!\n");
                            break;
                        } else
                            qtd = calTelha(larg, comp, telha); // Chama a fun��o para c�lculo da quantidade de telhas

                    break;
                    case 3: // Piso
                        printf("\n\nQual o tipo de piso que voc� deseja?");
                        printf("\n1- Pocelanato,");
                        printf("\n2- Laminado,");
                        printf("\nOp��o: ");
                        scanf("%d", &piso);

                        if(piso < 1 || piso > 2){ // Confere se o usu�rio n�o digitou op��o inv�lida
                            printf("\nOp��o inv�lida!\n");
                            break;
                        } else
                            qtd = calPiso(larg, comp, piso); // Chama a fun��o para c�lculo da quantidade de piso

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
            case 4: //Consultar
                imprimirMatriz(matriz, larg, comp);
            break;
            case 5: //Informa��es
                imprimirInfos();
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

float calTelha(float larg, float comp, int telha){
    float qtd;

    if(telha == 1){
        // c�lculo telha colonial
    } else if(telha == 2){
        // c�lculo telha Portuguesa
    } else if(telha == 3){
        // c�lculo Brasilit
    }
    return qtd;
}

float calPiso(float larg, float comp, int piso){
    float qtd;

    if(piso == 1){
        // c�lculo Porcelanato
    } else if(piso == 2){
        // c�lculo Laminado
    }
    return qtd;
}

void imprimirMatriz(float M[][C], float larg, float comp){

    // Aqui ir� a a impress�o da matriz com as quantidades
}

void imprimirInfos(){

    //Imprimir as informa��es dos desenvolvedores

}
