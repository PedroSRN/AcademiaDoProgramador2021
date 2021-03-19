#include <stdio.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
#define MAX_PRODUTOS 15
int opcao;

//estrutura de declaracao das variaveis usadas na struct produtos
struct s_produtos{
char nome [20]=("");
char preco[15];
char numseri[8];
char datafab[10];
char fabricante[20];
};


//vetor;
struct s_produtos PRODUTOS[MAX_PRODUTOS];

int n_PRODUTOS = 0;

void editarProduto(struct s_produtos produto,int i){
 PRODUTOS[i] = produto;
}

//Cadastrar produtos
void cadastraProduto(struct s_produtos produto){
     PRODUTOS[n_PRODUTOS] = produto;
     n_PRODUTOS++;
}

 //lendo as informaçoes do produto
 struct s_produtos leDados(){
           struct s_produtos auxiliar;
           system("cls");//limpa tela


           printf("\n Cadastrando Novo Produto\n");

           printf("\nNome do produto: ");
           fflush(stdin);
           fgets(auxiliar.nome, 50, stdin);

           printf("\nPreco da aquisicao: ");
           fflush(stdin);
           fgets(auxiliar.preco,10, stdin);

           printf("\nNumero de serie: ");
           fflush(stdin);
           fgets(auxiliar.numseri,8,stdin);

           printf("\nData de fabricacao: ");
           fflush(stdin);
           fgets(auxiliar.datafab,10,stdin);

           printf("\nNome do fabricante: ");
           fflush(stdin);
           fgets(auxiliar.fabricante,20,stdin);

           return auxiliar;
 }

    //visualiza os produtos cadastrados
     void imprimePRODUTOS(){
         int i;

        for (i=0; i<n_PRODUTOS; i++) {
         printf("\n\n__________________________________\n");
         printf("\nCodigo: %d\n", i+1);
         printf("\nNome do produto: %s", PRODUTOS[i].nome);
         printf("\nNumero de serie: %s", PRODUTOS[i].numseri);
         printf("\nNome do fabricante: %s", PRODUTOS[i].fabricante);
        }
        }


    int menu(){
        int opcao;
        //menu de opçoes
        printf("\n__________________________________\n");
        printf("|_____________MENU_______________|\n");
        printf("| Cadastrar Novo Produto     = 1 |\n");
        printf("| Mostrar Itens Cadastrados  = 2 |\n");
        printf("| Editar Produto Cadastrado  = 3 |\n");
        printf("| Deletar Produto Cadastrado = 4 |\n");
        printf("|             Sair           = 0 |\n");
        printf("__________________________________\n");
        scanf("\n %d" ,&opcao);

        return opcao;
    }

    void editar() {
        int i=0;
         struct s_produtos produtos;
          printf("\n__________________________________\n");
          printf("Digite qual produto quer editar:");
          printf("\n__________________________________\n");
          scanf("%i", &i);
          printf("Novo nome do produto: ");
          fflush(stdin);
          fgets(produtos.nome, 50, stdin);

          printf("Numero de serie: ");
          fflush(stdin);
          fgets(produtos.numseri, 8, stdin);

          printf("Nome do fabricante: ");
          fflush(stdin);
          fgets(produtos.fabricante, 20, stdin);

          editarProduto(produtos, --i);
 }

    //funçao para remover um produto do vetor
    void remover(int posicao) {
    int indice = posicao - 1;
    int i = 0;

   if ((posicao < 1) || (posicao > n_PRODUTOS)) {
        printf("\nPosicao invalida!\n");
        return;
    }

    // 1. caso - remover no final do vetor
    if (posicao == n_PRODUTOS) {
        n_PRODUTOS--;
        return;
    }

    // 2. remove qualquer outra posicao
    for (i=indice; i<n_PRODUTOS; i++) {
        PRODUTOS[i] = PRODUTOS[i+1];
    }
    n_PRODUTOS--;
}

int main() {

    int opcao_selecionada;
    int rem = 0;
    struct s_produtos novo_PRODUTOS;
    int r;


do {
    opcao_selecionada = menu();
    switch(opcao_selecionada){
       case 0: break;

       case 1:
         if (n_PRODUTOS == MAX_PRODUTOS){
            printf("\nESTOQUE ESTA CHEIO");
            break;
         }
        novo_PRODUTOS = leDados();
        cadastraProduto(novo_PRODUTOS);
        break;

       case 2://codigo para exibir
           imprimePRODUTOS();
           break;

       case 3://codigo para editar
         editar();

        break;

       case 4://codigo para excluir produto
         printf("Digite o numero do codigo que deseja excluir: ");
         scanf("%d", &r);
            remover(r);

       break;
      }
   }
   while (opcao_selecionada !=0);


   return 0;
}
