
#include <stdio.h>
#include <stdlib.h>
char jv[3][3] = {
	{'_','_','_'},
	{'_','_','_'},
	{'_','_','_'}
};
void mostra(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
		   printf("%c ",jv[i][j]);
		}
		printf("\n");
	}
}
int jogar(char proximo){
	int linha, coluna;
	int retorno = 0;
	do{
		do{
			printf("Para sair digite 9.\nDigite a linha 1 a 3 para %c: \n",proximo);
			scanf("%d",&linha);	
			if (linha == 9) return 9;
		}while ((linha < 0 || linha > 4));
		linha--;
		system("clear");
		do{
			printf("Para sair digite 9.\n Digite a coluna 1 a 3 para %c \n",proximo);
			scanf("%d",&coluna);
			if (coluna == 9) return 9;
		}while (coluna < 0 || coluna > 4);
		coluna--;
		system("clear");		
		retorno = !(jv[linha][coluna] != '_');
	}while(!retorno);
	jv[linha][coluna] = proximo;
	mostra();
	return retorno;
}
int vlinha(int linha, int coluna){
	for(int j=coluna; j<2; j++){
		printf("Devolve (linha %d) (coluna %d) %d\n",linha,j,(jv[linha][j] != jv[linha][j+1]));
		if(jv[linha][j] != jv[linha][j+1]) return 0;
	}
	printf("Retornando Linha 1\n");
	return 1;
}
int vcoluna(int linha, int coluna){
	for(int i=linha; i<2; i++){
		printf("Devolve Coluna (linha %d) (coluna %d) %d\n",i,coluna,(jv[i][coluna] != jv[i+1][coluna]));
		if(jv[i][coluna] != jv[i+1][coluna]) return 0;
	}
	printf("Retornando Coluna 1\n");
	return 1;
}
int vdiagonalP(int indice){
	for(int i=indice; i<2; i++){
		printf("Diagonal P (linha %d) (coluna %d) %d\n",i,i,(jv[i][i] != jv[i+1][i+1]));
		if(jv[i][i] != jv[i+1][i+1]) return 0;
	}
	printf("Retornando Diagonal P 1\n");
	return 1;
}

int vdiagonalS(int indice){
	for(int i=indice; i>1; i--){
		printf("Diagonal S (linha %d) (coluna %d) %d\n",i,i,(jv[i][i] != jv[i+1][i+1]));
		if(jv[i][i] != jv[i-1][i-1]) return 0;
	}
	printf("Retornando Diagonal S 1\n");
	return 1;
}
int verifica(){
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++){
			if(i==0 && j == 0){
			   if(jv[0][0] != '_'){
					if(vlinha(i,j)) return 1;
					if(vcoluna(i,j)) return 1;
					if(vdiagonalP(i)) return 1;
			   }
			}
			if(i==0 && j == 1){
			    if(jv[0][1] != '_'){
			   		if(vcoluna(i,j)) return 1;
				}
			}
			if(i==0 && j == 2){
				if(jv[0][2] != '_'){
			   		if(vcoluna(i,j)) return 1;
			   		if(vdiagonalS(j)) return 1;
				}
			}
			if(i==1 && j == 0){
				if(jv[1][0] != '_'){
			   		if(vlinha(i,j)) return 1;
				}
			}
			if(i==2 && j == 0){
				if(jv[2][0] != '_'){
			   		if(vlinha(i,j)) return 1;
				}
			}
		}
	}
	return 0;
}
int main(){
    char proximo = 'x';
    int jogadas = 0;
    int vencedor = 0;
    do{
    	printf("Escolha quem comeca 'x' ou 'o'\n");
        scanf("%c",&proximo);
        mostra();
		system("clear");
	}while(proximo != 'x' && proximo != 'o');
    do{
    	jogadas += jogar(proximo);
    	if(jogadas > 4) vencedor = verifica();
    	if(!vencedor){
    		if(proximo == 'x') proximo = 'o';
    		else proximo = 'x';
		}
	}while(jogadas != 9 && !vencedor);
	system("clear");
		if(vencedor) printf("'%c' venceu!\n",proximo);
		else if(jogadas == 9) printf("Sem vencedor!\n");
		else printf("Obrigado por tentar!\n");
	return 0;
}

