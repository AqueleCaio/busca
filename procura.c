#include <stdio.h>
#include <stdlib.h>

//devolve a posicao do vetor V em que o 
//valor_buscado estah, devolve -1 se naum encontrar
int busca_valor(int * V, int inicio, int fim, int valor_buscado){
  
  //função que roda ate encontrar o numero buscado
  //ou ate que todas as posiçes forem percorridas
  do{
    //calcula a mediana
    int mediana = (inicio + fim) / 2;
    
    //caso o valor seja encontrado o programa retorna a mediana
    if(V[mediana] == valor_buscado) return mediana;
    else{
      if(V[mediana] < valor_buscado){
        inicio = mediana + 1;
      }
      else if(V[mediana] > valor_buscado){
        fim = mediana - 1;
      }
    }
  }while(inicio <= fim);

  return -1;
}

int main(){
  int n, aux, troca;
  int quantidade_buscas;
  
  scanf("%d %d", &n, &quantidade_buscas);
  
  //definindo uma semente para a geracao de numero aleatorio
  srand(n);
  
  int * V = (int *) malloc(n*sizeof(int));
  
  for(int i = 0; i < n; i++){
     V[i] = rand() % (2*n);
  }
  
  //organiza os numeros do vetor de forma crescente
  do{
      troca = 0;
      for(int i = 0; i < n-1; i++){
          if(V[i] > V[i+1]){
              aux = V[i];
              V[i] = V[i+1];
              V[i+1] = aux;
              troca = 1;
            }
        }

  }while (troca);

  
  int hit = 0;
  int miss = 0;
  int inicio = 0;
  int fim = n--;

  for(int b = 0; b < quantidade_buscas; b++){
    int valor_buscado = rand() % (2*n);
    int res = busca_valor(V, inicio, fim, valor_buscado);
    if(res != -1) {
      hit++;
    }else{
      miss++;
    }
  }
  printf("Acertos: %d Erros: %d\n", hit, miss);

  return 0;
}