#include <stdio.h>
#include <stdlib.h>

typedef struct no{
  int ticket;
  struct no *proximo;
}No;

//ADICIONAR
void inserir_na_fila(No **fila, int n){
  No *aux, *novo = malloc(sizeof(No));
  if(novo){
    novo->ticket = n;
    novo->proximo = NULL;
    if(*fila == NULL)
    *fila = novo;
    else{
      aux = *fila;
      while(aux->proximo)
        aux = aux->proximo;
        aux->proximo = novo;
    }
  }
  else
    printf("\nERRO NA ALOCACAO");
  }

//PRIORIDADE
void inserir_prioridade(No **fila, int n){
  No *aux, *novo = malloc(sizeof(No));
  if(novo){
    novo->ticket = n;
    novo->proximo = NULL;
    if(*fila == NULL)
    *fila = novo;
    else{
			if( n > 99){
				if((*fila)->ticket < 100){
					novo->proximo = *fila;
					*fila = novo;
				}else{
					aux = *fila;
					while(aux->proximo && aux->proximo->ticket > 99)
					aux = aux->proximo;
					novo->proximo = aux->proximo;
					aux->proximo = novo;					
				}

			}else{
				printf("Ticket não é de prioridade");
      	aux = *fila;
      	while(aux->proximo)
        aux = aux->proximo;
        aux->proximo = novo;
				}
    }
  }
  else
    printf("\nERRO NA ALOCACAO");
  }

//REMOVER
No* remover_da_fila(No **fila){
  No *remover = NULL;
	

  if(*fila){
    remover = *fila;
    *fila = remover->proximo;
  }else{
    printf("\nFILA DO BANCO VAZIA");
		
}
  return remover;
}


//IMPRIMIR
void imprimir(No *fila){
	printf("\n#-----FILA DO BANCO - TICKETS/FICHAS------#\n");
	while(fila){
		printf("%d ",fila->ticket);
		fila = fila->proximo;
	}
	printf("\n#-----------------------------------------#\n");
}

int main(void){
	int opt, opc, ticket, tempo = 0, tempoP = 0;
	No *r, *fila = NULL;
	int contAtendido = 0, contador = 0, contPrioridade = 0, contPrior = 0;
	int consultar = 0, sacar = 0, aplicacao = 0, extrato = 0, pagD = 0, pagDc = 0;
	int consultart = 0, sacart = 0, aplicacaot = 0, extratot = 0, pagDt = 0, pagDct = 0;
	do{
		printf("\n\n#-----MENU SISTEMA BANCO-----#\n");
		printf("\n[1] - INSERIR CLIENTE NA FILA\n[2] - REMOVER/ATENDER CLIENTE\n[3] - MOSTRAR FILA DO BANCO\n[7] - INSERIR COM PRIORIDADE\n[0] - FECHAR BANCO/SAIR\nOPCAO: ");
    scanf("%d", &opt);

		switch(opt){
			case 1:
				printf("\nDigite o numero do ticket: ");
				scanf("%d", &ticket);
				inserir_na_fila(&fila, ticket);
				contador++;
			//	printf("%d",contador);
			/*	printf("\nOpcoes Disponiveis");
				printf("\n\t1 - Consultar saldo");
				printf("\n\t2 - Sacar");
				printf("\n\t3 - Aplicação");
				printf("\n\t4 - Extrato");
				printf("\n\t5 - Pagamento em dinheiro");
				printf("\n\t6 - Pagamento com débito em conta");
				printf("\nOPCAO: ");
				scanf("%d", &opc);
				if(opc == 1){
					tempo += 10;
				}else if(opc == 2){
					tempo += 20;
				}else if(opc == 3){
					tempo += 30;
				}else if(opc == 4){
					tempo += 40;
				}else if(opc == 5){
					tempo += 50;
				}else if(opc == 6){
					tempo += 35;
				}
				printf("%d",tempo);*/
				break;
			case 2:
				if(contador == 0){
					printf("BANCO ESTA VAZIO!");
					break;
				}else if(contador - contAtendido == 0){
					printf("BANCO ESTA VAZIO!");
					break;
				}

				if(contPrior > 0){
				r = remover_da_fila(&fila);
				printf("\n----TEMPO DE ESPERA: [%d segundos]----",tempo);
				printf("\n\n--Opcoes Disponiveis - Clientes Prioridade--:");
				printf("\n\t1 - Consultar saldo");
				printf("\n\t2 - Sacar");
				printf("\n\t3 - Aplicação");
				printf("\n\t4 - Extrato");
				printf("\n\t5 - Pagamento em dinheiro");
				printf("\n\t6 - Pagamento com débito em conta");
				printf("\nOPCAO: ");
				scanf("%d", &opc);
				if(opc == 1){
					tempo += 10;
					printf("\nOperacao de 10 segundos");
					consultar++;
					consultart +=10;
					tempoP += 10;
				}else if(opc == 2){
					tempo += 20;
					printf("\nOperacao de 20 segundos");
					sacar++;
					sacart += 20;
					tempoP += 20;
				}else if(opc == 3){
					tempo += 30;
					printf("\nOperacao de 30 segundos");
					aplicacao++;
					aplicacaot+=30;
					tempoP += 30;
				}else if(opc == 4){
					tempo += 40;
					printf("\nOperacao de 40 segundos");
					extrato++;
					extratot += 40;
					tempoP += 40;
				}else if(opc == 5){
					tempo += 50;
					printf("\nOperacao de 50 segundos");
					pagD++;
					pagDt += 50;
					tempoP += 50;
				}else if(opc == 6){
					tempo += 35;
					printf("\nOperacao de 35 segundos");
					pagDc++;
					pagDct += 35;
					tempoP += 35;
				}
				printf("\nTEMPO DO CAIXA [%d segundos]",tempo);
				if(r){
					printf("\nCliente atendido com o ticket - [%d]", r->ticket);
					free(r);
				}
				contAtendido++;
				printf("\nForam atendidos: %d clientes", contAtendido);
					

					contPrior--;
				}else{

				r = remover_da_fila(&fila);
				printf("\n----TEMPO DE ESPERA: [%d segundos]----",tempo);
				printf("\n\n--Opcoes Disponiveis--:");
				printf("\n\t1 - Consultar saldo");
				printf("\n\t2 - Sacar");
				printf("\n\t3 - Aplicação");
				printf("\n\t4 - Extrato");
				printf("\n\t5 - Pagamento em dinheiro");
				printf("\n\t6 - Pagamento com débito em conta");
				printf("\nOPCAO: ");
				scanf("%d", &opc);
				if(opc == 1){
					tempo += 10;
					printf("\nOperacao de 10 segundos");
					consultar++;
					consultart +=10;
				}else if(opc == 2){
					tempo += 20;
					printf("\nOperacao de 20 segundos");
					sacar++;
					sacart += 20;
				}else if(opc == 3){
					tempo += 30;
					printf("\nOperacao de 30 segundos");
					aplicacao++;
					aplicacaot+=30;
				}else if(opc == 4){
					tempo += 40;
					printf("\nOperacao de 40 segundos");
					extrato++;
					extratot += 40;
				}else if(opc == 5){
					tempo += 50;
					printf("\nOperacao de 50 segundos");
					pagD++;
					pagDt += 50;
				}else if(opc == 6){
					tempo += 35;
					printf("\nOperacao de 35 segundos");
					pagDc++;
					pagDct += 35;
				}
				printf("\nTEMPO DO CAIXA [%d segundos]",tempo);
				if(r){
					printf("\nCliente atendido com o ticket - [%d]", r->ticket);
					free(r);
				}
				contAtendido++;
				printf("\nForam atendidos: %d clientes", contAtendido);
				}
				break;
			case 3:
				printf("\n");
				imprimir(fila);
			break;
			case 7:
				printf("\nOs tickets para pessoas com prioridade são maiores que [99]");
				printf("\nSao prioridade: Idosos, Gravidas e Deficientes");
				printf("\nDigite o numero do ticket( > 99): ");
				scanf("%d", &ticket);
				inserir_prioridade(&fila, ticket);
				contador++;
				contPrioridade++;
				contPrior++;
				//printf("%d",contador);
				break;
			case 0:
			printf("\n\n\t#------Termino do Expediente------#\n\n");
			printf("\nTempo Total do atendimento do banco ate fechar foi %d segundos ",tempo);
			printf("\n\tForam cadastrados para o atendimento no total [%d] Clientes",contador);
			printf("\n\tForam cadastados [%d] Clientes com Prioridade",contPrioridade);
			printf("\n\tForam atendidos [%d] Clientes",contAtendido);
			printf("\n\tRestou [%d] Clientes para ser Atendido",contador-contAtendido);
	
			printf("\n\n\n#----------HISTORICO DE TRANSACOES - GERAL----------#");
			printf("\n\tConsulta: [%d] Tempo: [%d segundos]",consultar, consultart);
			printf("\n\tSacar:    [%d] Tempo: [%d segundos]",sacar, sacart);
			printf("\n\tAplicacao:[%d] Tempo: [%d segundos]",aplicacao, aplicacaot);
			printf("\n\tExtrato:  [%d] Tempo: [%d segundos]",extrato, extratot);
			printf("\n\tPag. em dinheiro: [%d] Tempo: [%d segundos]",pagD, pagDt);
			printf("\n\tPag. com debito em conta Consulta: [%d] Tempo: [%d segundos]",pagDc,pagDct);
				
			printf("\n\n\n#----------HISTORICO DE TRANSACOES - Clientes com Prioridades----------#");
			printf("\n\t----Clientes com prioridades [%d]\tTempo total [%d segundos]----", contPrioridade,tempoP);
		

			break;
			default:
			if(opt != 0)
				printf("\nOpcao invalida\n");
			
		}
	}while(opt != 0);


	return 0;
}