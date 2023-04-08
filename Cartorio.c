#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h>//biblioteca de aloca��o de espa�o em mm�ria
#include <locale.h>//biblioteca de aloca��es de texto por regi�o
#include <string.h>//biblioteca respons�vel por cuidar das string

int registro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio cria��o de vari�veis/string
	char arquivo[40];//string semelhante as carteiras de uma fileira
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final cria��o de vari�veis
	printf("Digite o CPF a ser cadastrado: ");//coletando informa��o do usu�rio
	scanf("%s", cpf);//%s refere-se a string
	
	strcpy(arquivo,cpf);//responsavel por copiar os valors das string
	
	FILE *file;//cria arquivo
	file = fopen(arquivo, "w");//cria o arquivo
	fprintf(file,cpf);//salvo valor da variavel
	fclose(file);//fecha o arquivo
	
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo,"a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file= fopen (arquivo, "a");
	fprintf (file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo,"a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE*file;
	file = fopen(cpf, "r");
	
	if(file == NULL){
		printf("N�o foi possivel abrir o arquivo, n�o foi localizado!. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o cpf a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf, "r");
	
	
	
	if(file != NULL)
	{
		printf("Usu�rio deletado com sucesso!.\n");
		system("pause");
	}else{
		
		printf("O usu�rio n�o se encontra no sistema!\n");
		system("pause");
		
		
	}
	
}
int main() //fun��o principal
{
   int opcao=0;	
   int laco=1;
   
   for (laco=1;laco=1;)
   {
   
    system("cls");//limpar a tela
   
      setlocale(LC_ALL, "Portuguese");//define o portgu�s como idioma


      printf("###Cart�rio da EBAC###\n\n");//### s�o para espa�o
      printf("Escolha op��o desejada do menu:\n\n");
      printf("\t1 - Registrar nomes\n");// t/ faz o espa�o
      printf("\t2 - Consultar nomes\n");
      printf("\t3 - Deletar nomes\n");
      printf("\t4 - Sair do sistema\n\n");
      printf ("Op��o: ");//fim do menu

       scanf ("%d", &opcao);

    system("cls");
    
    
    switch(opcao)
    {
    	case 1:
    	registro();//chamda de fun��es
	    break;
	    
	    case 2:
	    consulta();
	    break;
	    
	    case 3:
	   deletar();
	    break;
	    
	    case 4:
	    printf("Obrigado por utilizar o sistema!\n");
	    return 0;
	    
	    default:
    	printf("Essa op��o n�o est� disponivel!\n");
    	system ("pause");
    	break;
	}

	
     //fim da sele��o

}
}   
