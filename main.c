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

    printf("\n\t\t\t\t\t\t>>> BUILDPLANNER <<<");

    printf("\n\nBem-vindo(a) ao programa que calcula uma estimativa da quantidade dos principais materiais que ser�o utilizados na constru��o de um c�modo!");
    printf("\nInforme a largura e o comprimento do c�modo, insira os tipos de materiais e ao final consulte a matriz que informar� as quantidades estimadas!");

    printf("\n\n************************************************************************************************************************");

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

    //Entrada de dados
    printf("\n\n>> Informe a largura, em metros, do c�modo o qual deseja c�lcular os materiais necess�rios para construir: ");
    scanf("%f", &larg);
    printf("\n>> Agora informe o comprimento, em metros, do c�modo: ");
    scanf("%f", &comp);

    printf("\n----------------------------------------------------------------------------------------------------------------");

    // Calcula o metro quadrado
    m2 = metrosQuadrados(larg, comp);

    //Menu
    printf("\n\n>> O que voc� deseja fazer? ");
    printf("\n1. Inserir material para c�lculo,");
    printf("\n2. Remover material do c�lculo,");
    printf("\n3. Alterar material,");
    printf("\n4. Alterar metragem do c�modo,");
    printf("\n5. Consultar matriz dos c�lculos,");
    printf("\n6. Ver informa��es dos desenvolvedores,");
    printf("\n7. Sair;");
    printf("\nOp��o: ");
    scanf("%d", &menu);

    while(menu != 7){
        printf("\n----------------------------------------------------------------------------------------------------------------");

        switch(menu){
            case 1: //Inserir
                printf("\n\n>> Qual material voc� deseja inserir?");
                printf("\n1- Tijolo");
                printf("\n2- Telha");
                printf("\n3- Piso");
                printf("\nOp��o: ");
                scanf("%d", &material);

                switch(material){
                    case 1: // Tijolo
                        if(matriz[0][1] != 0){ // Verifica se o usu�rio n�o cadastrou o material
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
                            printf("\n\n\t\t\t\tERRO!!");
                            printf("\nVoc� n�o pode atualizar um material que ainda n�o foi cadastrado!\n");
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                        } else{
                            printf("\n\n>> Qual o tipo de tijolo que voc� deseja?");
                            printf("\n1- Veda��o,");
                            printf("\n2- Estrutural,");
                            printf("\n3- Bloco de concreto,");
                            printf("\nOp��o: ");
                            scanf("%d", &tijolo);

                            if(tijolo < 1 || tijolo > 3){ // Confere se o usu�rio n�o digitou op��o inv�lida
                                printf("\n\nXXX Op��o inv�lida! XXX\n");
                                break;
                            } else{
                                qtd = calTijolo(m2, tijolo); // Chama a fun��o para c�lculo da quantidade de tijolos
                                matriz[0][1] = tijolo;
                                matriz[0][2] = qtd;
                                cont++; // Faz a contagem de itens cadastrados para mostrar mensagem antes do menu
                            }
                        }
                    break;
                    case 2: // Telha
                        if(matriz[1][1] != 0){ // Verifica se o usu�rio n�o cadastrou o material
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
                            printf("\n\n\t\t\t\tERRO!!");
                            printf("\nVoc� n�o pode atualizar um material que ainda n�o foi cadastrado!\n");
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                        } else{
                            printf("\n\n>> Qual o tipo de telha que voc� deseja?");
                            printf("\n1- Colonial,");
                            printf("\n2- Portuguesa,");
                            printf("\n3- Brasilit,");
                            printf("\nOp��o: ");
                            scanf("%d", &telha);

                            if(telha < 1 || telha > 3){ // Confere se o usu�rio n�o digitou op��o inv�lida
                                printf("\nXXX Op��o inv�lida! XXX\n");
                                break;
                            } else{
                                qtd = calTelha(m2, telha); // Chama a fun��o para c�lculo da quantidade de telhas
                                matriz[1][1] = telha;
                                matriz[1][2] = qtd;
                                cont++; // Faz a contagem de itens cadastrados para mostrar mensagem antes do menu
                            }
                        }
                    break;
                    case 3: // Piso
                        if(matriz[2][1] != 0){ // Verifica se o usu�rio n�o cadastrou o material
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
                            printf("\n\n\t\t\t\tERRO!!");
                            printf("\nVoc� n�o pode atualizar um material que ainda n�o foi cadastrado!\n");
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                        } else{
                            printf("\n\n>> Qual o tipo de piso que voc� deseja?");
                            printf("\n1- Pocelanato,");
                            printf("\n2- Laminado,");
                            printf("\nOp��o: ");
                            scanf("%d", &piso);

                            if(piso < 1 || piso > 2){ // Confere se o usu�rio n�o digitou op��o inv�lida
                                printf("\nXXX Op��o inv�lida! XXX\n");
                                break;
                            } else{
                                qtd = calPiso(m2, piso); // Chama a fun��o para c�lculo da quantidade de piso
                                matriz[2][1] = piso;
                                matriz[2][2] = qtd;
                                cont++; // Faz a contagem de itens cadastrados para mostrar mensagem antes do menu
                            }
                        }
                    break;
                    default:
                        printf("\nXXX Op��o inv�lida! XXX\n");
                }
            break;
            case 2: //Remover
                printf("\n\n>> Selecione o material que deseja remover:");
                printf("\n1- Tijolo");
                printf("\n2- Telha");
                printf("\n3- Piso");
                printf("\nOp��o: ");
                scanf("%d", &material);

                switch (material){
                    case 1: // zera os valores da primeira linha, a qual corresponde ao tijolo
                        if (matriz[0][1] != 0){ // Verifica se o usu�rio j� cadastrou o material que deseja remover
                            for (i = 0; i < 1; i++){
                                for (j = 1; j < 3; j++){
                                    matriz[i][j] = 0;
                                }
                            }
                            cont--; // Tira da um item contagem de itens cadastrados para mostrar mensagem antes do menu
                            printf("\n\nTijolo removido com sucesso!\n\n");
                        } else{
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
                            printf("\n\n\t\t\t\tERRO!!");
                            printf("\nVoc� n�o pode remover um material que ainda n�o foi cadastrado!\n");
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                        }
                    break;
                    case 2: //zera os valores da segunda linha, a qual corresponde a telha
                        if (matriz[1][1] != 0) { // Verifica se o usu�rio j� cadastrou o material que deseja remover
                            for (i = 1; i < 2; i++){
                                for (j = 1; j < 3; j++){
                                    matriz[i][j] = 0;
                                }
                            }
                            cont--; // Tira da um item contagem de itens cadastrados para mostrar mensagem antes do menu
                            printf("\n\nTelha removida com sucesso!\n\n");
                        } else {
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
                            printf("\n\n\t\t\t\tERRO!!");
                            printf("\nVoc� n�o pode remover um material que ainda n�o foi cadastrado!\n");
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                        }
                    break;
                    case 3: //zera os valores da terceira linha, a qual corresponde ao piso
                        if (matriz[1][2] != 0){ // Verifica se o usu�rio j� cadastrou o material que deseja remover
                            for (i = 2; i < 3; i++) {
                                for (j = 1; j < 3; j++){
                                        matriz[i][j] =0;
                                }
                            }
                            cont--; // Tira da um item contagem de itens cadastrados para mostrar mensagem antes do menu
                            printf("\n\nPiso removido com sucesso!\n\n");
                        } else {
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
                            printf("\n\n\t\t\t\tERRO!!");
                            printf("\nVoc� n�o pode remover um material que ainda n�o foi cadastrado!\n");
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                        }
                    break;
                }
            break;
            case 3: //Alterar material
                printf("\n\n>> Qual material voc� deseja alterar?");
                printf("\n1- Tijolo");
                printf("\n2- Telha");
                printf("\n3- Piso");
                printf("\nOp��o: ");
                scanf("%d", &material);

                switch(material){
                    case 1: // Tijolo
                        if(matriz[0][1] == 0){ // Verifica se o usu�rio j� cadastrou o material
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
                            printf("\n\n\t\t\t\tERRO!!");
                            printf("\nVoc� n�o pode atualizar um material que ainda n�o foi cadastrado!\n");
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                        } else{
                            printf("\n\n>> Qual o tipo de tijolo que voc� deseja?");
                            printf("\n1- Veda��o,");
                            printf("\n2- Estrutural,");
                            printf("\n3- Bloco de concreto,");
                            printf("\nOp��o: ");
                            scanf("%d", &tijolo);

                            if(tijolo < 1 || tijolo > 3){ // Confere se o usu�rio n�o digitou op��o inv�lida
                                printf("\nXXX Op��o inv�lida! XXX\n");
                                break;
                            } else{
                                qtd = calTijolo(m2, tijolo); // Chama a fun��o para c�lculo da quantidade de tijolos
                                matriz[0][1] = tijolo;
                                matriz[0][2] = qtd;
                                printf("\n\nTipo de tijolo atualizado!");
                            }
                        }
                    break;
                    case 2: // Telha
                         if(matriz[1][1] == 0){ // Verifica se o usu�rio j� cadastrou o material
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
                            printf("\n\n\t\t\t\tERRO!!");
                            printf("\nVoc� n�o pode atualizar um material que ainda n�o foi cadastrado!\n");
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                        } else{
                            printf("\n\n>> Qual o tipo de telha que voc� deseja?");
                            printf("\n1- Colonial,");
                            printf("\n2- Portuguesa,");
                            printf("\n3- Brasilit,");
                            printf("\nOp��o: ");
                            scanf("%d", &telha);

                            if(telha < 1 || telha > 3){ // Confere se o usu�rio n�o digitou op��o inv�lida
                                printf("\nXXX Op��o inv�lida! XXX\n");
                                break;
                            } else{
                                qtd = calTelha(m2, telha); // Chama a fun��o para c�lculo da quantidade de telhas
                                matriz[1][1] = telha;
                                matriz[1][2] = qtd;
                                printf("\n\nTipo de telha atualizado!");
                            }
                        }
                    break;
                    case 3: // Piso
                        if(matriz[2][1] == 0){ // Verifica se o usu�rio j� cadastrou o material
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx");
                            printf("\n\n\t\t\t\tERRO!!");
                            printf("\nVoc� n�o pode atualizar um material que ainda n�o foi cadastrado!\n");
                            printf("\nxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n");
                        } else{
                            printf("\n\n>> Qual o tipo de piso que voc� deseja?");
                            printf("\n1- Pocelanato,");
                            printf("\n2- Laminado,");
                            printf("\nOp��o: ");
                            scanf("%d", &piso);

                            if(piso < 1 || piso > 2){ // Confere se o usu�rio n�o digitou op��o inv�lida
                                printf("\nXXX Op��o inv�lida! XXX\n");
                                break;
                            } else{
                                qtd = calPiso(m2, piso); // Chama a fun��o para c�lculo da quantidade de piso
                                matriz[2][1] = piso;
                                matriz[2][2] = qtd;
                                printf("\n\nTipo de piso atualizado!");
                            }
                        }
                    break;
                    default:
                        printf("\nXXX Op��o inv�lida! XXX\n");
                }
            break;
            case 4: //Alterar metragem
                printf("\n\n++ Informe a nova largura, em metros, do c�modo o qual deseja c�lcular os materiais necess�rios para construir: ");
                scanf("%f", &larg);
                printf("\n++ Agora informe o novo comprimento, em metros, do c�modo: ");
                scanf("%f", &comp);

                m2 = metrosQuadrados(larg, comp); // C�lcula o novo metro quadrado

                if(matriz[0][1] != 0){ // Verifica se o usu�rio j� cadastrou o tijolo
                    qtd = calTijolo(m2, tijolo); // Atualiza a quantidade de material ap�s a mudan�a de metragem do c�modo
                    matriz[0][2] = qtd;
                }
                if(matriz[1][1] != 0){ // Verifica se o usu�rio j� cadastrou a telha
                    qtd = calTelha(m2, telha); // Atualiza a quantidade de material ap�s a mudan�a de metragem do c�modo
                    matriz[1][2] = qtd;
                }
                if(matriz[2][1] != 0){ // Verifica se o usu�rio j� cadastrou o piso
                    qtd = calPiso(m2, piso); // Atualiza a quantidade de material ap�s a mudan�a de metragem do c�modo
                    matriz[2][2] = qtd;
                }

                printf("\n\n>> A matriz foi atualizada conforme a mudan�a de metragem do c�modo!\n");
            break;
            case 5: //Consultar
                imprimirMatriz(matriz, m2);
            break;
            case 6: //Informa��es
                imprimirInfos();
            break;
            default:
                printf("\nXXX Op��o inv�lida! XXX\n");
        }

        if(cont == 3){ // Confere se o usu�rio j� cadastrou todos os materiais
            printf("\n\n>> Voc� j� cadastrou todos os itens!");
            printf("\nConsulte a matriz para ver a quantidade de todos os materiais!\n");
        } else if(cont == 0){
            printf("\n\n>> Voc� ainda n�o cadastrou nenhum item!");
            printf("\nDigite 1 para inserir algum tipo de material!\n");
        } else{
            printf("\n>> Voc� j� cadastrou ");
            if(matriz[1][0] != 0){
                printf("o tipo de tijolo, ");
            }
            if(matriz[1][1] != 0){
                printf("o tipo de telha, ");
            }
            if(matriz[2][2] != 0){
                printf("o tipo de piso, ");
            }
            printf("mas ainda falta cadastrar material!\n");
        }

        printf("\n----------------------------------------------------------------------------------------------------------------");

        printf("\n\n>> O que voc� deseja fazer? ");
        printf("\n1. Inserir material para c�lculo,");
        printf("\n2. Remover material do c�lculo,");
        printf("\n3. Alterar material,");
        printf("\n4. Alterar metragem do c�modo,");
        printf("\n5. Consultar matriz dos c�lculos,");
        printf("\n6. Ver informa��es dos desenvolvedores,");
        printf("\n7. Sair;");
        printf("\nOp��o: ");
        scanf("%d", &menu);
    }
    printf("\n**************************************************************************************************************");

    printf("\n\n\t\t\t\tEsperamos que voc� tenha gostado da experi�ncia!");
    printf("\n\t\t\t\t\t\tAt� a pr�xima :)\n");
}
float metrosQuadrados(float larg, float comp){
    return larg * comp;
}

float calTijolo(float m2, int tijolo){
    float qtd;

    if(tijolo == 1){ // c�lculo venda��o
        qtd =  m2 * 40;
    } else if(tijolo == 2){ // c�lculo tijolo estrutural
        qtd =  m2 * 16.7;
    } else if(tijolo == 3){ // c�lculo bloco de concreto
        qtd =  m2 * 12.5;
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

void imprimirMatriz(float M[][C], float m2)
{
    printf("\n\n\n\t\t\t   >> MATRIZ RESULTANTE <<");

    printf("\n\n\n\t\t  Material  |  Tipo do Material | Quantidade ");
    printf("\n\t\t ------------------------------------------- ");
    for(int i=0; i<3; i++) // Percorre as linha
    {
        if (M[i][0] == 1) // Mostra as informa��es da primeira linha da matriz
        {
            printf("\n\t\t   Tijolos  |");
            // Mostra qual tipo de tijolo foi selecionado
            if (M[i][1] == 1)
                printf("      Veda��o      ");
            else if (M[i][1] == 2)
                printf("     Estrutural    ");
            else if (M[i][1] == 3)
                printf(" Bloco de concreto ");

            // Mostra a quantidade c�lculada no programa
            printf("|     %.0f    ", M[i][2]);
        }
        else if (M[i][0] == 2) // Mostra as informa��es da segunda linha da matriz
        {
            printf("\n\t\t            |                   |            ");
            printf("\n\t\t   Telhas   |");
            //mostra qual tipo de telha foi selecionada
            if (M[i][1] == 1)
                printf("     Colonial      ");
            else if (M[i][1] == 2)
                printf("    Portuguesa     ");
            else if (M[i][1] == 3)
                printf("     Brasilit      ");

            // Mostra a quantidade c�lculada no programa
            printf("|     %.0f    ", M[i][2]);
        }
        else if (M[i][0] == 3) // Mostra as informa��es da terceira linha da matriz
        {   printf("\n\t\t            |                   |            ");
            printf("\n\t\t    Pisos   |");
            //mostra qual tipo de piso foi selecionado
            if (M[i][1] == 1)
                printf("    Porcelanato    ");
            else if (M[i][1] == 2)
                printf("     Laminado      ");

            // Mostra a quantidade c�lculada no programa
            printf("|     %.0f     ", M[i][2]);
        }
    }

    printf("\n\n\n\n>> Os c�lculos foram baseados em um c�modo com %.2f metros quadrados!", m2);


    printf("\n\n\n----------------------------------------------------------------------------------------------------------------");
}

void imprimirInfos(){ //Imprime as informa��es dos desenvolvedores

    printf("\n\n >> OBJETIVO DO PROGRAMA:\n");
    printf("\nFacilitar a vida de quem deseja construir um c�modo, o programa faz uma estimativa da quantidade dos principais materiais que ser�o utilizados na constru��o.");

    printf("\n\n >> DESCRI��O DO FUNCIONAMENTO:\n");
    printf("\nO usu�rio dever� informar apenas a metragem do c�modoe selecionar o tipo de material desejado para o programa calcular a estimativa das quantidades necess�rias de cada item.");

    printf("\n\n >> DESENVOLVIDO POR: ");
    printf("\n\nCaroline Ines Tews ");
    printf("\nGuilherme Douglas de Mello Rodrigues ");
    printf("\nHelena Della Giustina Aguiar ");
    printf("\nLucas Munhoz");

    printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++");

    printf("\n\n\t\t\t\t\t\tNOVEMBRO/2022");
    printf("\n\t\t\t\tUniversidade de Santa Cruz do Sul (UNISC)\n");
}
