#include <stdio.h> //biblioteca de comunic��o com usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string

int registro() //Fun��o Respons�vel por Cadastrar os Usu�rios no Sistema
{
    //In�cio da Cria��o de Variaveis/Strings
	char arquivo[40];
	char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //Final da Cri��o de Variaveis/String
    
    printf("Digite o CPF a ser cadastrado: "); //Coletando Informa��es do Usu�rio
    scanf("%s", cpf); //Refere-se a String
    
    strcpy(arquivo, cpf); //Respons�vel por Copiar os Valores da String
    
    FILE *file; //Cria o Arquivo
    file = fopen(arquivo, "w"); //Cria o Arquivo
    fprintf(file,cpf); //Salva o Valor da Vari�vel
    fclose(file); //Fecha o Arquivo
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser cadastrado: ");
    scanf("%s",nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o sobrenome a ser cadastrado: ");
    scanf("%s",sobrenome);
    
    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser cadastrado");
    scanf("%s", cargo);
    
    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);
    
    
    
}

int consulta()  //Fun��o Respons�vel por Consultar Usuarios do Sistema
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi posssivel abrir o arquivo, n�o localizado!.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("Essas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar() //Fun��o Respons�vel por Deletar Usuarios do Sistema
{
	char cpf[40];
	
	printf("Digite o CPF a ser deletado: ");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!. \n");
		system("pause");
	}
	
}

int main()
{
	int opcao=0; //Definindo Vari�veis
	int laco=1;
	char senhadigitada[10]="a";
	int comparacao;
	
  	printf("### Cart�rio da EBAC ###\n\n");
	printf("Login de administrador\n\n Digite sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
        system ("cls");
    	for(laco=1;laco=1;)
    	{
	
        	system("cls");
	
        	setlocale(LC_ALL, "Portuguese");  //Definindo a linguagem
	
            printf("### Cart�rio da EBAC ###\n\n"); //Inicio do menu
            printf("Escolha a op��o desejada do menu:\n\n");
            printf("\t1 - Registrar nomes\n");
            printf("\t2 - Consultar nomes\n");
            printf("\t3 - Deletar nomes\n\n");
            printf("\t4 - Sair do Sistema\n\n");
            printf("Esse Softare � de livre uso dos alunos\n"); //Fim do Menu
            printf("Op��o:");
            scanf("%d", &opcao); //Armazenando a Escolha do Usu�rio
    
            system("cls");
        
            switch(opcao)
            {
             	case 1: 
            	registro();
            	break;
        	
            	case 2:
                consulta();
    	        break;
    	    
    	        case 3:
    	        deletar();
		    	break;
			
    			case 4:
		    	printf("Obrigado por utilizar o sitema!\n");
    			return 0;
    			break; 
			
    			default:
    			printf("Essa op��o n�o est� dispon�vel!\n");
            	system("pause");
     			break;	
	        }
	    	
                if(opcao==1) //In�cio da Sele��o
                {
            	printf("Voc� escolheu o resgistro de nomes!\n");
             	system("pause");
            	}
               if(opcao==2) 
                {
            	printf("voc� escolheu consultar os nomes!\n");
    	        system("pause");
            	}
            	if(opcao==3) 
                {
            	printf("Voc� escolheu deletar os nomes!\n");
            	system("pause");
            	}
            	if(opcao>=4 || opcao<=0) 
                {
            	printf("Essa op��o n�o est� dispon�vel!\n");
            	system("pause");
             	} // Fim da Sele��o
        }
    
	}
     
     else
     printf("Senha incorreta!");
     
}
	
	
