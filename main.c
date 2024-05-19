#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <conio.h>

void titulo();
int menu();
void criaRelatorio();
void exibeRelatorio();
void preencheRelatorio();
void finalizaRelatorio();
void ExibeSubtotal();

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int opcao, c;
    do{
    opcao = menu();
    switch(opcao)
    {
    case 1:
        criaRelatorio();
        break;

    case 2:
        exibeRelatorio();
        break;

    case 3:
        preencheRelatorio();
        break;

    case 4:
        ExibeSubtotal();
        break;

    case 5:
        finalizaRelatorio();//Função que coletará os dados do arquivo de texto e somará os totais.
        break;
    case 6:
        for(c = 3; c > 0; c--)
        {
          titulo();
          c == 1 ? printf("\n\n\t\tO Programa fechará em %d segundo...", c):printf("\n\n\t\tO Programa fechará em %d segundos...", c);
          Sleep(1000);
        }
    }
    }while(opcao!=6);
    return 0;
}
void titulo()
{
    system("cls");
    printf("\t\t===============================================================\n");
    printf("\t\t R E L A T O R I O   D E   S E R V I Ç O   D E   C A M P O\n");
    printf("\t\t===============================================================\n\n");
}

int menu()
{
    int opcao;
    do{
    system("cls");
    titulo();
    printf("\n\t\tEscolha uma opcao:\n\n");
    printf("\t\t[1] Novo Relatorio\n\t\t[2] Exibir Relatório\n\t\t[3] Inserir Dados no Relatório\n\t\t[4] Mostrar Subtotais\n\t\t[5] Finalizar Relatório\n\t\t[6] Sair do programa\n");
    printf("\t\t: ");
    scanf("%d", &opcao);
    }while((opcao > 6)||(opcao < 1));
    return opcao;
}

void criaRelatorio()
{
    int mes;
    char nome[31], ano[5], mestring[20];
    titulo();
    printf("\t\tDigite seu nome: ");
    fflush(stdin);
    gets(nome);
    printf("\t\tDigite o ano: ");
    fflush(stdin);
    gets(ano);
    do{
    system("cls");
    titulo();
    printf("\t\tEscolha a opção correspondente ao mês correto:\n\n");
    printf("\t\t[1]Janeiro\t[2]Fevereiro\n");
    printf("\t\t[3]Março\t[4]Abril\n");
    printf("\t\t[5]Maio   \t[6]Junho\n");
    printf("\t\t[7]Julho\t[8]Agosto\n");
    printf("\t\t[9]Setembro\t[10]Outubro\n");
    printf("\t\t[11]Novembro\t[12]Dezembro\n\t\t: ");
    fflush(stdin);
    gets(mestring);
    mes = atoi(mestring); // Converte string para inteiro.
    }while((mes<1)||(mes>12));
    char nomeArquivo[51];
    strcat((strcpy(nomeArquivo, mestring)),nome);
    strcat(nomeArquivo, ano);
    strcat(nomeArquivo, ".txt");
    printf("\n\t\tNome do arquivo: %s", nomeArquivo);

    FILE *relatorio;
    relatorio = fopen(nomeArquivo, "r");
    if(relatorio!=NULL)
    {
        printf("\n\t\tEsse relatório já existe. Você pode abrí-lo ou editá-lo.\7");
        fclose(relatorio);
        Sleep(4000);
        return 7;
    }

    relatorio = fopen(nomeArquivo, "w");
    if(relatorio==NULL)
    {
        printf("\n\t\tERRO AO GERAR RELATÓRIO!");
        Sleep(3000);
    }

    else
    {
        printf("\n\t\tArquivo para Relatório GERADO com sucesso!");
        fclose(nomeArquivo);
        Sleep(3000);
    }
}

void exibeRelatorio()
{
    int dados[6], cont, mes;
    char nomeArquivo[51], nome[41], mestring[3], ano[5];
    FILE *relatorio;
    do{
    titulo();
    printf("\t\tEscolha a opção correspondente ao mês correto:\n\n");
    printf("\t\t[1]Janeiro\t[2]Fevereiro\n");
    printf("\t\t[3]Março\t[4]Abril\n");
    printf("\t\t[5]Maio   \t[6]Junho\n");
    printf("\t\t[7]Julho\t[8]Agosto\n");
    printf("\t\t[9]Setembro\t[10]Outubro\n");
    printf("\t\t[11]Novembro\t[12]Dezembro\n\t\t: ");
    fflush(stdin);
    gets(mestring);
    mes = atoi(mestring); // Converte string para inteiro.
    }while((mes<1)||(mes>12));
    printf("\t\tDigite seu nome: ");
    fflush(stdin);
    gets(nome);
    printf("\t\tDigite o ano: ");
    fflush(stdin);
    gets(ano);
    system("cls");
    strcat((strcpy(nomeArquivo, mestring)),nome);
    strcat(strcat(nomeArquivo, ano),".txt");
    relatorio = fopen(nomeArquivo, "r");
    printf("\t\tNOME COMPLETO DO ARQUIVO: %s", nomeArquivo);
    Sleep(3000);


    if(relatorio==NULL)
    {
        printf("\n\t\tERRO AO ABRIR RELATÓRIO!");
        Sleep(3000);
    }

    else
    {
        for(cont = 0;(fscanf(relatorio, "%d\n", &dados[cont]))!=EOF; cont++)
        {
            switch(cont)
            {
                case 0:
                    printf("\n\t\t---------------------------------\n\t\tDia: %d\n\n", dados[0]);
                break;
                case 1:
                    printf("\t\tPublicações: %d\n", dados[1]);
                break;
                case 2:
                    printf("\t\tVídeos: %d\n", dados[2]);
                break;
                case 3:
                    printf("\t\tHoras: %d\n", dados[3]);
                break;
                case 4:
                    printf("\t\tMinutos: %d\n", dados[4]);
                break;
                case 5:
                    printf("\t\tRevisitas: %d\n", dados[5]);
                break;

            }
            if(cont==5)
                cont = -1;
        }
        printf("\n\n\n\t\tRelatório ABERTO com sucesso!");
        printf("\n\t\tPressione qualquer tecla para prosseguir...");
        fclose(relatorio);
        getch();
    }
}

void preencheRelatorio()
{
    int dia, pub, videos, horas, minutos, revisitas, mes, continua, confirma, teste = 0, num;
    char nome[41], mestring[3], ano[5];
    char nomeArquivo[51];
    FILE *relatorio;
     do{
    titulo();
    printf("\t\tEscolha a opção correspondente ao mês correto:\n\n");
    printf("\t\t[1]Janeiro\t[2]Fevereiro\n");
    printf("\t\t[3]Março\t[4]Abril\n");
    printf("\t\t[5]Maio   \t[6]Junho\n");
    printf("\t\t[7]Julho\t[8]Agosto\n");
    printf("\t\t[9]Setembro\t[10]Outubro\n");
    printf("\t\t[11]Novembro\t[12]Dezembro\n\t\t: ");
    fflush(stdin);
    gets(mestring);
    mes = atoi(mestring); // Converte string para inteiro.
    }while((mes<1)||(mes>12));
    printf("\t\tDigite seu nome: ");
    fflush(stdin);
    gets(nome);
    printf("\t\tDigite o ano: ");
    fflush(stdin);
    gets(ano);
    titulo();
    strcat((strcpy(nomeArquivo, mestring)),nome);
    strcat(strcat(nomeArquivo, ano),".txt");
    relatorio = fopen(nomeArquivo, "r");
    printf("\t\tNOME COMPLETO DO ARQUIVO: %s", nomeArquivo);
    Sleep(3000);

     if(relatorio==NULL)
    {
        printf("\n\t\tERRO AO ABRIR RELATÓRIO! Talvez ele não exista...");
        Sleep(4000);
    }

    else
    {
        printf("\n\t\tRelatório existe!");
        while(fscanf(relatorio, "%d\n", &num)!=EOF)
        {
            teste++;
        }
        fclose(relatorio);
        relatorio = fopen(nomeArquivo, "a");
        do{
            do{

            if(teste==0)
                {
                    printf("\n\t\tDigite os minutos que sobraram do relatório do mês anterior: ");
                    scanf("%d", &num);
                }
            printf("\n\t\tInforme o dia do mês: ");
            scanf("%d", &dia);
            printf("\t\tPublicações: ");
            scanf("%d", &pub);
            printf("\t\tVídeos: ");
            scanf("%d", &videos);
            printf("\t\tHoras: ");
            scanf("%d", &horas);
            printf("\t\tMinutos: ");
            scanf("%d", &minutos);
                if(teste == 0)
                    minutos += num;
            teste++;
            printf("\t\tRevisitas: ");
            scanf("%d", &revisitas);
            printf("\t\tConfirma as informações acima?\n\t\t[1]Sim\t[0]Não\n\t\t: ");
            scanf("%d", &confirma);
            titulo();
            }while(!confirma);
            fprintf(relatorio,"%d\n%d\n%d\n%d\n%d\n%d\n", dia, pub, videos, horas, minutos, revisitas);
            printf("\n\t\tInserir o trabalho de mais um dia?");
            printf("\n\t\t[1]Sim\n\t\t[0]Não\n\t\t: ");
            scanf("%d", &continua);
        }while(continua);
     fclose(relatorio);
     printf("\n\t\tRelatório ATUALIZADO com sucesso!");
     Sleep(3000);
    }
}

void finalizaRelatorio()
{
    int horas = 0, minutos = 0, mes;
    int vetor[6], cont, mestring[3], ano[5], nome[41];
    char nomeArquivo[51];
    char nomeTotal[51];
    int vetoraux[7];
    for(cont = 0; cont < 7; cont++)
    {
        vetoraux[cont] = 0;
    }
    FILE *relatorio;
    do{
    system("cls");
    printf("\t\tEscolha a opção correspondente ao mês correto:\n\n");
    printf("\t\t[1]Janeiro\t[2]Fevereiro\n");
    printf("\t\t[3]Março\t[4]Abril\n");
    printf("\t\t[5]Maio   \t[6]Junho\n");
    printf("\t\t[7]Julho\t[8]Agosto\n");
    printf("\t\t[9]Setembro\t[10]Outubro\n");
    printf("\t\t[11]Novembro\t[12]Dezembro\n\t\t: ");
    fflush(stdin);
    gets(mestring);
    mes = atoi(mestring); // Converte string para inteiro.
    }while((mes<1)||(mes>12));
    printf("\t\tDigite seu nome: ");
    fflush(stdin);
    gets(nome);
    printf("\t\tDigite o ano: ");
    fflush(stdin);
    gets(ano);
    system("cls");
    strcat((strcpy(nomeArquivo, mestring)),nome);
    strcat(strcat(nomeArquivo, ano),".txt");
    relatorio = fopen(nomeArquivo, "r");
    system("cls");
    printf("\t\tNOME COMPLETO DO ARQUIVO: %s", nomeArquivo);
    Sleep(3000);
    if(relatorio==NULL)
    {
        printf("\n\t\tERRO AO ABRIR RELATÓRIO! Talvez ele não exista...");
        Sleep(3000);
    }
      else
    {
     printf("\n\t\tRelatório ABERTO com sucesso!");
     printf("\n\t\tInforme quantos estudos bíblicos você dirigiu no mês: ");
     scanf("%d", &vetoraux[6]);
     printf("\n\t\tAguarde... Já estamos calculando!");
     Sleep(3000);

     for(cont = 0;(fscanf(relatorio, "%d\n", &vetor[cont]))!=EOF; cont++)
        {
            vetoraux[cont] += vetor[cont];
            if(cont==5)
                cont = -1;
        }
      titulo();
      if(vetoraux[4] >= 60)
        {
            horas += vetoraux[4] / 60;
            minutos += vetoraux[4]%60;
            vetoraux[4] = minutos;
            vetoraux[3] += horas;
        }
    fclose(relatorio);
    FILE *total;
    strcpy(nomeTotal,"TOTAL");
    strcat(nomeTotal, nomeArquivo);
    total = fopen(nomeTotal, "w");
    for (cont = 0; cont < 7; cont++)
        {
        switch(cont)
            {
                case 0:
                    fprintf(total, "===========================\nTOTAIS:\n===========================\n");
                break;
                case 1:
                    printf("\t\tTotal Publicações: %d\n", vetoraux[1]);
                    fprintf(total, "Total Publicações: %d\n", vetoraux[1]);
                break;
                case 2:
                    printf("\t\tTotal Vídeos: %d\n", vetoraux[2]);
                    fprintf(total, "Total Vídeos: %d\n", vetoraux[2]);
                break;
                case 3:
                    printf("\t\tTotal Horas: %d\n", vetoraux[3]);
                    fprintf(total, "Total Horas: %d\n", vetoraux[3]);
                break;
                case 4:
                    printf("\t\tTotal Minutos: %d\n", vetoraux[4]);
                    fprintf(total, "Total Minutos: %d\n", vetoraux[4]);
                break;
                case 5:
                    printf("\t\tTotal Revisitas: %d\n", vetoraux[5]);
                    fprintf(total, "Total Revisitas: %d\n", vetoraux[5]);
                break;
                case 6:
                    printf("\t\tTotal Estudos: %d\n\t\t===========================\n", vetoraux[6]);
                    fprintf(total, "Total Estudos: %d\n----------------------------\n", vetoraux[6]);
                break;
            }
        }
     printf("\n\n\n\t\tTotais Calculados com sucesso!");
     printf("\n\t\tPressione qualquer tecla para prosseguir...");
     fclose(total);
     getch();
    }
}

void ExibeSubtotal()
{
 int horas = 0, minutos = 0, mes;
    int vetor[6], cont, mestring[3], nome[41], ano[5];
    char nomeArquivo[51];
    int vetoraux[6];
    for(cont = 0; cont < 7; cont++)
    {
        vetoraux[cont] = 0;
    }
    FILE *relatorio;
        do{
            titulo();
            printf("\t\tEscolha a opção correspondente ao mês correto:\n\n");
            printf("\t\t[1]Janeiro\t[2]Fevereiro\n");
            printf("\t\t[3]Março\t[4]Abril\n");
            printf("\t\t[5]Maio   \t[6]Junho\n");
            printf("\t\t[7]Julho\t[8]Agosto\n");
            printf("\t\t[9]Setembro\t[10]Outubro\n");
            printf("\t\t[11]Novembro\t[12]Dezembro\n\t\t: ");
            fflush(stdin);
            gets(mestring);
            mes = atoi(mestring); // Converte string para inteiro.
        }while((mes<1)||(mes>12));
    printf("\t\tDigite seu nome: ");
    fflush(stdin);
    gets(nome);
    printf("\t\tDigite o ano: ");
    fflush(stdin);
    gets(ano);
    titulo();
    strcat((strcpy(nomeArquivo, mestring)),nome);
    strcat(strcat(nomeArquivo, ano),".txt");
    relatorio = fopen(nomeArquivo, "r");
    titulo();
    printf("\t\tNOME COMPLETO DO ARQUIVO: %s", nomeArquivo);
    Sleep(3000);
    if(relatorio==NULL)
    {
        printf("\n\t\tERRO AO ABRIR RELATÓRIO! Talvez ele não exista...");
        Sleep(3000);
    }
      else
    {
     printf("\n\t\tRelatório ABERTO com sucesso!");
     printf("\n\t\tAguarde... Já estamos calculando!");
     Sleep(3000);

     for(cont = 0;(fscanf(relatorio, "%d\n", &vetor[cont]))!=EOF; cont++)
        {
            vetoraux[cont] += vetor[cont];
            if(cont==5)
                cont = -1;
        }
      titulo();
      if(vetoraux[4] >= 60)
        {
            horas += vetoraux[4] / 60;
            minutos += vetoraux[4]%60;
            vetoraux[4] = minutos;
            vetoraux[3] += horas;
        }
    for (cont = 0; cont < 7; cont++)
        {
        switch(cont)
            {
                case 0:
                    printf("\n\n\t\t===========================\n\t\tTOTAIS:\n\t\t===========================\n");
                break;
                case 1:
                    printf("\t\tTotal Publicações: %d\n", vetoraux[1]);

                break;
                case 2:
                    printf("\t\tTotal Vídeos: %d\n", vetoraux[2]);

                break;
                case 3:
                    printf("\t\tTotal Horas: %d\n", vetoraux[3]);

                break;
                case 4:
                    printf("\t\tTotal Minutos: %d\n", vetoraux[4]);

                break;
                case 5:
                    printf("\t\tTotal Revisitas: %d\n", vetoraux[5]);

                break;
            }
        }
     printf("\n\n\n\t\tTotais Calculados com sucesso!");
     printf("\n\t\tPressione qualquer tecla para prosseguir...");
     fclose(relatorio);
     getch();
    }
}
