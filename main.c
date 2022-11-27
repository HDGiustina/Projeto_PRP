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

    //Aqui colocar uma introdu��o para o programa


    //Inicializa��o da Matriz
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
    printf("\nInforme a largura, em metros, do c�modo o qual deseja c�lcular os materiais necess�rios para construir: ");
    scanf("%f", &larg);
    printf("\nAgora informe o comprimento, em metros, do c�modo: ");
    scanf("%f", &comp);

    // Calcula o metro quadrado
    m2 = metrosQuadrados(larg, comp);

    //Menu
    printf("\nO que voc� deseja fazer? ");
    printf("\n1. Inserir material para c�lculo,");
    printf("\n2. Remover material do c�lculo,");
    printf("\n3. Alterar material,");
    printf("\n4. Consultar matriz dos c�lculos,");
    printf("\n5. Ver informa��es dos desenvolvedores,");
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
                            qtd = calTijolo(m2, tijolo); // Chama a fun��o para c�lculo da quantidade de tijolos

                        matriz[0][1] = tijolo;
                        matriz[0][2] = qtd;
                        cont++; // Faz a contagem de itens cadastrados para mostrar mensagem antes do menu
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
                            qtd = calTelha(m2, telha); // Chama a fun��o para c�lculo da quantidade de telhas

                        matriz[1][1] = telha;
                        matriz[1][2] = qtd;
                        cont++; // Faz a contagem de itens cadastrados para mostrar mensagem antes do menu
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
                            qtd = calPiso(m2, piso); // Chama a fun��o para c�lculo da quantidade de piso

                        matriz[2][1] = piso;
                        matriz[2][2] = qtd;
                        cont++; // Faz a contagem de itens cadastrados para mostrar mensagem antes do menu
                    break;
                    default:
                        printf("\nOp��o inv�lida!\n");
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
            case 5: //Informa��es
                imprimirInfos();
            break;
            default:
                printf("\nOp��o inv�lida!\n");
        }

        if(cont == 3){ // Confere se o usu�rio j� cadastrou todos os materiais
            printf("\n\n>> Voc� j� cadastrou todos os itens!");
            printf("\nConsulte a matriz para ver a quantidade de todos os materiais!\n");
        } else{
            printf("\n>> Voc� j� cadastrou ");
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

        printf("\nO que voc� deseja fazer? ");
        printf("\n1. Inserir material para c�lculo,");
        printf("\n2. Remover material do c�lculo,");
        printf("\n3. Alterar material,");
        printf("\n4. Consultar matriz dos c�lculos,");
        printf("\n5. Ver informa��es dos desenvolvedores,");
        printf("\n6. Sair;");
        printf("\nOp��o: ");
        scanf("%d", &menu);
    }

    printf("\nEsperamos que voc� tenha gostado da experi�ncia!");
    printf("\n\t\tAt� a pr�xima :)\n");
}
float metrosQuadrados(float larg, float comp){
    return larg * comp;
}

float calTijolo(float m2, int tijolo){
    float qtd;

    if(tijolo == 1){ // c�lculo venda��o
        qtd =  m2 * 40;
    } else if(tijolo == 2){ // c�lculo tijolo estrutural
        qtd =  m2 * 16.7 ;
    } else if(tijolo == 3){
        // c�lculo bloco de concreto
    }
    return qtd;
}

float calTelha(float m2, int telha){
    float qtd;

    if(telha == 1){ // c�lculo telha colonial
        qtd = m2 * 24;
    } else if(telha == 2){ // c�lculo telha Portuguesa
        qtd = m2 * 17;
    } else if(telha == 3){ // c�lculo Brasilit
        qtd = m2 * 0.4;
    }
    return qtd;
}

float calPiso(float m2, int piso){
    float qtd;

    if(piso == 1){ // c�lculo Porcelanato
        qtd = m2 * 2.8;
    } else if(piso == 2){ // c�lculo Laminado
        qtd = m2 * 2.4;
    }
    return qtd;
}

void imprimirMatriz(float M[][C], float m2){

    // Aqui ir� a a impress�o da matriz com as quantidades
}

void imprimirInfos(){

    //Imprimir as informa��es dos desenvolvedores

}
