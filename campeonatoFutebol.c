#include <string.h>
#include <stdio.h>

char estadodotime[20][4]; nomedotime[20][50];
int  matrizgeral[20][5]={},num1,num2,gols1,gols2,cont=0,cont2=0;
int codigo[20];

int menu(){
    int opcao=0;
    printf("-------------------MENU-------------------\n");
    printf("  (1) Cadastro dos times \n");
    printf("  (2) Cadastro do resultado dos jogos \n");
    printf("  (3) Lista dos times por estado \n");
    printf("  (4) Nome do time com maior pontuacao\n");
    printf("  (5) Tabela completa do campeonato \n");
    printf("  (6) Consulta o codigo do time\n");
    printf("  (7) Sair \n");

    printf("\nDigite a opcao desejada: ");
    scanf("%d",&opcao);
    system ("cls");
    return opcao;
}

char cadastro(){
    int num1,i;

    printf ("Digite o numero de times que voce deseja cadastrar: ");
    scanf("%d",&num1);
    system ("cls");

    for(i=0;i<num1;i++){
        printf("Digite o nome do time que voce quer cadastrar: ");
        scanf("%s",nomedotime[cont]);

        printf("Digite a sigla do estado do time %s: ",nomedotime[cont]);
        scanf("%s",estadodotime[cont]);

        codigo[cont] = cont+1;

        printf("%d : Time: %s, estado: %s\n",codigo[cont],nomedotime[cont],estadodotime[cont]);

        system("Pause");

        system ("cls");

        cont ++;

    }

    num1=0;
    printf("O CADASTRO DOS TIMES FOI CONCLUIDO COM SUCESSO!!! \n");
    system("Pause");
    system ("cls");
    main();


}

int verificacodigo(int codigo1, int codigo2){
    int cont3=0,i;
    if (codigo1==codigo2){
        printf("Voce digitou o mesmo codigo para os dois times.\n");
        printf("Por favor retorne ao menu e digite 6 para consultar o codigo do times.\n");
        system("pause");
        system("cls");
        menu();

    }
    if((codigo1==0)||(codigo2==0)){
            printf("Nao ha nenhum time com codigo 0, os codigos comecam a partir do 1.\n");
            printf("Por favor retorne ao menu e digite 6 para consultar o codigo do times.\n");
            system("pause");
            system("cls");
            menu();
     }


    for(i=0;i<20;i++){
        if(codigo1==codigo[i]){
            cont3++;
        }
        else if(codigo2==codigo[i]){
            cont3++;

        }

    }
    if(cont3==2){
        cont3=0;
        return 1;
    }

    else {
        printf("Voce digitou um codigo que nao esta cadastrado.\n");
        printf("Por favor retorne ao menu e digite 7 para consultar o codigo do times.\n");
        system("pause");
        cont3=0;
        system("cls");
        return 0;
    }

}

int cadastroresultado(){
    int i;
    int quant=0;
    gols1 =0;
    gols2 = 0;
    num1 = 0;
    num2 = 0;

    printf("Digite quantos jogos voce deseja cadastrar: ");
    scanf("%d",&quant);

    while (quant>0){
        cont2++;
        quant= quant -1;

        printf("digite o codigo do time da casa: ");
        scanf("%d",&num1);

        printf("digite o numero de gols: ");
        scanf("%d",&gols1);

        printf("digite o codigo do outro time: ");
        scanf("%d",&num2);

        printf("digite o numero de gols: ");
        scanf("%d",&gols2);


        if((verificacodigo(num1,num2)==1) && (num1!=num2)){
            for(i=0;i<20;i++){
                if((codigo[i]== num1)&&(gols1>gols2)){
                    matrizgeral[i][0]++;
                    matrizgeral[i][1]++;
                    matrizgeral[i][4]= matrizgeral[i][4]+3;
                }
                else if((codigo[i]== num1)&&(gols1<gols2)){
                    matrizgeral[i][0]++;
                    matrizgeral[i][3]++;

                }
                else if((codigo[i]== num1)&&(gols1==gols2)){
                    matrizgeral[i][0]++;
                    matrizgeral[i][2]++;
                    matrizgeral[i][4]= matrizgeral[i][4]+1;

                }

            }
            for (i=0;i<20;i++){
                if ((codigo[i]==num2)&&(gols2>gols1)){
                    matrizgeral[i][0]++;
                    matrizgeral[i][1]++;
                    matrizgeral[i][4]= matrizgeral[i][4]+3;

                }
                else if((codigo[i]==num2)&&(gols2<gols1)){
                    matrizgeral[i][0]++;
                    matrizgeral[i][3]++;

                }
                else if((codigo[i]==num2)&&(gols2==gols1)){
                    matrizgeral[i][0] ++;
                    matrizgeral[i][1] ++;
                    matrizgeral[i][4]= matrizgeral[i][4]+1;

                }

             }
             gols1 =0;
             gols2 = 0;
             num1 = 0;
             num2 = 0;
             system("\n pause");
             system("cls");
             printf("CADASTRO DOS RESULTADOS REALIZADO COM SUCESSO\n");
             system("pause");
             system ("cls");
             main();



        }
        else{
            gols1 =0;
            gols2 = 0;
            num1 = 0;
            num2 = 0;
            main();
        }

   }


}

char listaestado(){
    char sigla[4];
    int i,cont2;
    printf("Digite a sigla do estado que voce quer ver a lista: ");
    scanf("%s",sigla);

    for (i=0;i<20;i++){
        if(strcmp(estadodotime[i],sigla)==0){
            printf("%d %s  %s \n",codigo[i],nomedotime[i],estadodotime[i]);
            cont2++;
        }
    }

    if(cont2==0){
        printf("Esse estado nao esta cadastrado");
    }
    cont2=0;
    system("Pause");
    system ("cls");
    main();

}

int quantpontos(){
    int i, maior=0,num=0;

    for(i=0;i<20;i++){
        if(matrizgeral[i][4]> maior){
            maior = 0;
            num = 0;
            maior = matrizgeral[i][4];
            num =i;
        }
    }
    printf("O Time com maior pontuacao foi: %s com %d pontos \n",nomedotime[num],matrizgeral[num][4]);
    system("Pause");
    system ("cls");
    main();
}

int tabela(){

    int i,j;

    printf("        TIMES                JOGOS            VITORIA            EMPATES           DERROTA              PONTOS \n");

    for (i=0;i<20;i++) {
        printf("%20s           %d                  %d                  %d                %d                   %d",nomedotime[i],matrizgeral[i][0],matrizgeral[i][1],matrizgeral[i][2],matrizgeral[i][3],matrizgeral[i][4]);
        printf(" \n");
    }

    system("Pause");
    system ("cls");
    main();

}

int tabelacodigo(){

    int i;

    printf("CODIGO   NOME DO TIME\n");

    for(i=0;i<cont;i++){

        printf("%d        %s\n",codigo[i], nomedotime[i]);
    }

    system("pause");
    system("cls");
    main();
}

int main(){
    int escolha;
    escolha = menu();

    if(escolha == 1){
            if(cont>=20){
                printf("Voce atigiu o numero maximo de times possíveis, nao eh possivel realizar o cadatro de mais nenhum time");
                system("\nPause");
                main();
            }
            else {
                cadastro();
            }

    }

    else if (escolha == 2){

        if(cont<2){
            printf("nao ha times suficientes cadastrados\n");
            system ("PAUSE");
            system ("cls");

            main();
        }

        else{
            cadastroresultado();


        }
    }

    else if(escolha==3){
        if(cont<1){
            printf("Voce nao cadastrou times suficientes\n");
            system ("PAUSE");
            system ("cls");
            main();
        }
        else{
            listaestado();

        }

    }

    else if(escolha == 4){
        if(cont2<1){
            printf("Voce nao cadastrou nenhum resultado de jogo ainda, por favor retorne ao menu\n");
            system ("PAUSE");
            system ("cls");
            main();
        }
        else{
            quantpontos();

        }


    }

    else if(escolha==5){
        tabela();
    }

    else if(escolha==6){
        if(cont<1){
            printf("Voce nao cadastrou times suficientes\n");
            system ("PAUSE");
            system ("cls");
            main();
        }
        else{
            tabelacodigo();
        }

    }

    else if(escolha==7){
        printf("Obrigada por participar do campeonato");

    }

    else{
        printf("Opcao invalida, caso queira sair retorne ao menu e digite 7\n");
        system("Pause");
        system ("cls");
        main();
    }

    return 0;
}




