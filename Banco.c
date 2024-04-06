/*Crie um Sistema Bancário.

    No Sistema temos um Lista de Contas Bancárias.
    Deve ser possível Abrir Conta.
    Num Conta é possível Depositar valores, assim como Sacar valores. Desde que tenha saldo suficiente.
    Deverá ser possível também realizar PIX para o chave CPF do Titular, mostrar dados para confirmação do usuário.
    O Extrato Bancário também deve ser uma funcionalidades. Mostrar data, tipo da operação(C, D) e valor. Assim como Saldo atual.
    Deve ser possível consultar Saldo
    Deve ser possível consultar Chave PIX (CPF)
    Tem que validação nas operações
    O Titular tem além dos dados básicos, tem renda, CPF, e endereço
    Banco tem além das Contas, um Nome, e um Endereço.
    Conta tem número, saldo, titular, transações(opcional)

- Identifique os Tipos de Dados bem como eventuais Composições. (TAD: .h e .c)
- Identifique possíveis operações no Tipo Identificados.
- Funções Construtoras
- Faça um Sistema de MENU*/

#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
  char tipo[20];
  int agencia;
  long int numero;
  float saldo;
}ContaBancaria;


typedef struct{
  char chave[20];
  char nome[50];
  char cpf[11];
}pix;

ContaBancaria* criarConta();
void abrirNovaConta(ContaBancaria *conta);
int depositar(ContaBancaria *conta, float valor);
int retirada(ContaBancaria *conta, float valor);
float getSaldo(ContaBancaria *conta);
void setSaldo(ContaBancaria *conta, float novoSaldo);
void imprimirChavePIX(pix* p);
void printConta(ContaBancaria *conta);

int main(){
  char opcao;
  srand(time(NULL));

  ContaBancaria* c1 = criarConta();
  pix* p1 = (pix*)malloc(sizeof(pix));

  do{
    printf("\n-------- Bem Vindo ao Banco ---------");
    printf("\n\nMenu:\n");
    printf("1 - Abrir Nova Conta\n");
    printf("2 - Deposito\n");
    printf("3 - Saque\n");
    printf("4 - Consultar Saldo\n");
    printf("5 - Consultar Chave PPIX\n");
    printf("0 - Sair\n");
    scanf("%c", &opcao);

    switch(opcao){
      case '1':
        abrirNovaConta(c1);
        break;

      case '2':
        if(depositar(c1,getSaldo(c1)) ==  1)
          printf("\nDepositado com Sucesso!\n");
        else
          printf("\nErro no Depósito.\n");
        system("pause");
        break;

      case '3':
        if(retirada(c1,getSaldo(c1))==1)
          printf("\nSaque realizado com sucesso!");
        else
          printf("\nErro na Retirada.");
        system("pause");
        break;

      case '4':
        printf("\nSaldo: %.2f", getSaldo(c1));
        system("pause");
        break;
      
      case '5':
        imprimirChavePIX(p1);
        system("pause");
        break;
        
      default :  
        printf("\nOpção Inválida! Tente Novamente.\n");
        system("pause"); 
    }
  }while (opcao != '0');

  free(c1);
  free(p1);
  return 0;
}

ContaBancaria* criarConta(){
  ContaBancaria* conta = (ContaBancaria*)malloc(sizeof(ContaBancaria));
  conta -> saldo = 0.0;
  return conta;
}

void abrirNovaConta(ContaBancaria *conta){
  char tipo[3];
  float valorInicial;

  printf("\nDigite o Tipo da Conta:\n"
         "1 - Corrente\n"
         "2 - Poupança\n");
  scanf("%2s", tipo);

  if(strcmp(tipo, "1") != 0 &&  strcmp(tipo, "2") != 0) {
    printf("\nTipo de Conta Inválido!\n");
    return;

  printf("Digite o valor incial da conta: ");
  scanf("%f", &valorInicial);

  strcpy(conta -> tipo, tipo);
  conta -> agencia =  rand() % 999 + 1;
  conta -> numero = rand() % 999999 + 1;
  setSaldo(conta, valorInicial);
  }

  }

  int retirada(ContaBancaria *conta, float valor){
    if (getSaldo(conta) >= valor){
      setSaldo(conta, getSaldo(conta) - valor);
      return 1;
    }else{
      printf("Voce nao possui saldo suficiente!\n");
      return 0;
    }
  }

  int depositar(ContaBancaria *conta, float valor){
    setSaldo(conta, getSaldo(conta) + valor);
    return 1;
  }

  float getSaldo(ContaBancaria *conta){
    return conta -> saldo;
  }

  void setSaldo(ContaBancaria *conta, float novoSaldo){
    conta -> saldo = novoSaldo;
  }

  void imprimirChavePIX(pix* p){
    printf("Chave PIX: %s\n", p -> chave);
  }

  void printConta(ContaBancaria *conta){
    printf("\nTipo de Conta: %s\n", conta -> tipo);
    printf("Agencia: %d\n", conta -> agencia);
    printf("Numero da Conta: %d\n", conta -> numero);
    printf("Saldo: %.2f\n", getSaldo(conta));
  }



  


               
            