#include <stdio.h>//biblioteca de comunicação com o usuario
#include <stdlib.h>//biblioteca de alocação de espaço de memoria 
#include <locale.h>//bibliotecade alocação de texto porregião
#include <string.h>//biblioteca responsavel por cuidar dos strings

int registro()//função reponçavel por cadastrar novos usuarios
{//inicio da criação de variavel/string
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo[40];
	char *token;
//fim da criação de variavel/string
    token = strtok(cpf, ","); 
     
	printf ("digite o cpf a ser cadastrado: ");
	scanf("%s", cpf);//%s para salvar strings
	
	strcpy(arquivo, cpf);// responsavel por copia valor das strings
	
	FILE *file;//cria o aquivo
	file = fopen(arquivo,"w");//cria uma pasta e escrever
	fprintf(file, cpf);//salva o valor da variavel
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file= fopen(arquivo,"a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	printf("digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen( arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);
	
	system("pause");
}

int consulta()
{
	
		setlocale(LC_ALL,"portuguese"); //definido a linguagem

	char cpf[40];
	char conteudo[200];
	char *token;
	
	printf ("digite o cpf a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("não foi possivel abrir o arquivo, não localizado!. \n");
	}
   	
   	while(fgets(conteudo, 200, file) != NULL)
   	{
   		printf("\n essas são as informações do usuario: \n ");
   		
   		token = strtok(conteudo, ",");//variavel ultilizada para dividir a string em linhas 
		printf("cpf: %s\n", token);//informação aaparecer antes
		
		token = strtok(NULL,",");
		printf("nome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("sobrenome: %s\n", token);
		
		token = strtok(NULL, ",");
		printf("cargo: %s\n", token);   
		
	   }
   	
   	printf("\n");    
   	system("pause");
   	
}

int deletar()
{
	char cpf[40];
	
	printf("digitr o cpf do usuário que deseja deletar:  ");
	scanf("%s", cpf);
	
	FILE *file; //abrindo o arquivo para leituraa"r"
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("o usuário não se encontra no sistema \n");
		system("pause");
		return 0;  //comando que faz o usuario retorna a tela inicial.
	}
	    fclose(file);
	    
	    printf("deseja deletar este aluno do sistema? ");
	    printf("%s",cpf);
	    printf("\ndigite (s) para sim ou digite (n) para não! \n\n");
	    
	    getchar(); //função para captura a entrada do usuario
	    
	    char opcao; // criando variavel
	    opcao = getchar(); //definindo que a variavel sera baseada no getchar
	    
	    if(opcao == 's' || opcao == 'S')
	    {
	    
		if (remove(cpf) == 0)
	    	{
	    		remove(cpf);
				printf("aluno deletado com sucesso!\n");
			}
			system("pause");
		}
		
		else if (opcao == 'n' || opcao == 'N')
		{
			printf("retorne ao menu principal \n");
			system("pause");
		}
	    else
	    {
	    	printf("opcao invalida");
	    	system("pause");
		}
}

int main()
{
	int opcao=0; //definindo a variavel
	int laco=1;// repertição 
	 
	 
	for(laco=1;laco=1;)//repetição de programa
	{
	
	system("cls"); //limpeza de tela
	
	setlocale(LC_ALL,"portuguese"); //definido a linguagem

	printf("#####cartório da ebac####\n\n"); //inicio do menu
	printf("escolha a opção desejada do menu:\n\n"); //Inicio do menu
	printf("\t1 - registrar nomes\n");
	printf("\t2 - consultar nomes\n");
	printf("\t3 - deletar nomes\n\n"); 
	printf("\t4 - sair do sistem\n\n");// fim do menu
	printf("opção: ");

    scanf("%d", &opcao);// armazenamento a escolha do usuario

    system("cls");//responçavelpor limpar a tela
    
    switch(opcao){//chamada de funções 
    	
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
    	printf("obrigado por ultilizar o sistema!\n\n");
    	return 0;
    	break;
    	
    	default:
    		printf("essa opção não esta disponivel!\n");
		system("pause");
		break;
    	
	}

  
    }
}