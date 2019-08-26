#include <iostream>
#include <queue>

using namespace std;

int f;
int c;
char mapa[500][500];
struct coord{
	int x;
	int y;
	int contador;
};
queue <coord> cola;
coord inicio;
coord hijo;
int visitados[500][500];
int aux=0;

int main(){
	cin >> f >> c;
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cin >> mapa[i][j];
			if(mapa[i][j] == 'G'){
				visitados[i][j] = 1;
				inicio.x = i;
				inicio.y = j;
				inicio.contador=0;
				cola.push(inicio);
			}else{
				visitados[i][j] = 0;
			}
		}
	}
	
/*	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout << mapa[i][j];
		}
		cout << endl;
	}
	cout << endl;
	for(int i=0; i<f; i++){
		for(int j=0; j<c; j++){
			cout << visitados[i][j];
		}
		cout << endl;
	}*/
	
	while(!cola.empty() && mapa[cola.front().x][cola.front().y] != '*'){
		//encolar arriba:
		hijo.x = cola.front().x-1;
		hijo.y = cola.front().y;
		aux++;
		if(hijo.x>=0 && visitados[hijo.x][hijo.y]==0 && mapa[hijo.x][hijo.y] != '#'){
			hijo.contador = cola.front().contador + 1;
			cola.push(hijo);
			visitados[hijo.x][hijo.y] = 1;
		}
		//encolar derecha
		hijo.x = cola.front().x;
		hijo.y = cola.front().y+1;
		if(hijo.y<=c && visitados[hijo.x][hijo.y]==0 && mapa[hijo.x][hijo.y] != '#'){
			hijo.contador = cola.front().contador + 1;
			cola.push(hijo);
			visitados[hijo.x][hijo.y] = 1;
		}
		//encolar abajo
		hijo.x = cola.front().x+1;
		hijo.y = cola.front().y;
		if(hijo.x<=f && visitados[hijo.x][hijo.y]==0 && mapa[hijo.x][hijo.y] != '#'){
			hijo.contador = cola.front().contador + 1;
			cola.push(hijo);
			visitados[hijo.x][hijo.y] = 1;
		}
		//encolar izquierda
		hijo.x = cola.front().x;
		hijo.y = cola.front().y-1;
		if(hijo.y>=0 && visitados[hijo.x][hijo.y]==0 && mapa[hijo.x][hijo.y] != '#'){
			hijo.contador = cola.front().contador + 1;
			cola.push(hijo);
			visitados[hijo.x][hijo.y] = 1;
		}
		cola.pop();
	}
	//imprimir contador
	cout << cola.front().contador << endl;	
	return 0;
}






