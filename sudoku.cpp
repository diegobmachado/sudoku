#include <stdio.h>
#include <stdlib.h>

int s[9][9];

int game_over(){
	int x, y;
	for(x=0; x<9; x++){
		for(y=0; y<9; y++){
			if(s[x][y] == 0){
				return 0;
			}
		}
	}
	return 1;
}

void mostrar(){
	int x, y;
	
	for(x=0; x<9; x++){
		for(y=0; y<9; y++){
			printf("%d ", s[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

int validar(int i, int j, int n){
	int x, y, tx, ty;
	for(y=0; y<9; y++){
		if(s[i][y] == n && y != j){
			printf("Linha inválida.\n");
			return 0;
		}
	}
	
	for(x=0; x<9; x++){
		if(s[x][j] == n && x != i){
			printf("Coluna inválida.\n");
			return 0;
		}
	}
	
	// 2 5 8
	tx = i / 3 * 3 + 2;
	ty = j / 3 * 3 + 2;
	
	for(x = (i / 3 * 3); x <= tx; x++){
		for(y = (j / 3 * 3); y <= ty; y++){
			if(s[x][y] == n){
				printf("Número inválido.\n");
				return 0;
			}
		}
	}
	
	return 1;
}

void popular(){
	int x, y;
	
	for(x=0; x<9; x++){
		for(y=0; y<9; y++){
			s[x][y] = 0;
		}
	}
}

int main(){
	int x, y, n;
	int go = 0;
	
	popular();
	go = game_over();
	
	while(go == 0){
		do{
			printf("Informe a linha: \n");
			scanf("%d", &x);
		}while(x < 1 || x > 9);
			
		do{
			printf("Informe a coluna: \n");
			scanf("%d", &y);
		}while(y < 1 || y > 9);
		
		do{
			printf("Informe N: \n");
			scanf("%d", &n);
		}while(n < 0 || n > 9);
		
		system("cls");
		
		if(n == 0 || validar(x-1, y-1, n) == 1){
			s[x-1][y-1] = n;
		}else{
			printf("inválido\n");
		}
		
		mostrar();
		go = game_over();
	}
}
