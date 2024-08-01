#include <iostream>

using namespace std;

int main() {
	// Inicializa um array de caracteres 10x10 com caracteres '#'
	char mapa[10][10] = {
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#'},
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
		{'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
		{'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
		{'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
		{'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
		{'#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#'},
		{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}
	};

	// PosiC'C#o inicial do jogador e desenha jogador
	int x = 1;
	int y = 1;
	mapa[x][y] = '@';

	//posicao inicial do X e desenha o X no mapa
	int pos_Xx1 = 6;
	int pos_Xy1 = 2;
	mapa[pos_Xx1][pos_Xy1] = 'X';

	//posicao inicial da caixa1 e desenha a caixa1 no mapa
	int pos_Dx1 = 5;
	int pos_Dy1 = 3;
	mapa[pos_Dx1][pos_Dy1] = 'D';

	// VariC!vel de controle do jogo
	int jogo_ligado = 1;

	while (jogo_ligado == 1) {
		// Imprime o mapa atualizado
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cout << mapa[i][j] << ' ';
			}
			cout << endl;
		}
		cout << "Mova usando W A S D: \n";
		char comando;
		cin >> comando;


        while(comando != 's' and comando != 'S' and comando!='W' and comando!='w' and comando!='D' and comando!='d' and comando!='A' and comando!= 'a'){
            cout << "Digite um comando valido, W A S D";
            cin >> comando;
        }
            
		if(comando == 's' or comando == 'S') {
			//faz a caixa n subir em cima da parede
			if(mapa[x+2][y] == '#' and mapa[x+1][y] == 'D') {
				x--;
			}
			//faz o jogador n subir em cima da parede, e faz jogador mover com a caixa
			if(mapa[x+1][y] != '#' ) {
				mapa[x][y] = ' ';
				if(mapa[x+1][y] =='D') {
					mapa[x+2][y] = 'D';
				}
				if(mapa[x+1][y]=='X') {
					mapa[x][y] = '@';
					x--;
				}

				x++;
				mapa[x][y]='@';
			}
		}
		if(comando == 'w' or comando == 'W') {
			//faz a caixa n subir em cima da parede
			if(mapa[x-2][y] == '#' and mapa[x-1][y] == 'D') {
				x++;
			}
			//faz o jogador n subir em cima da parede, e faz jogador mover com a caixa
			if(mapa[x-1][y] != '#' ) {
				mapa[x][y] = ' ';
				if(mapa[x-1][y] =='D') {
					mapa[x-2][y] = 'D';
				}
				if(mapa[x-1][y]=='X') {
					mapa[x][y] = '@';
					x++;
				}
				x--;
				mapa[x][y]='@';
			}
		}
		if(comando == 'd' or comando == 'D') {
			//faz a caixa n subir em cima da parede
			if(mapa[x][y+2] == '#' and mapa[x][y+1] == 'D') {
				y--;
			}
			//faz o jogador n subir em cima da parede, e faz jogador mover com a caixa
			if(mapa[x][y+1] != '#' ) {
				mapa[x][y] = ' ';
				if(mapa[x][y+1] =='D') {
					mapa[x][y+2] = 'D';
				}
				if(mapa[x][y+1]=='X') {
					mapa[x][y] = '@';
					y--;
				}
				y++;
				mapa[x][y]='@';
			}
		}
		if(comando == 'a' or comando == 'A') {
			//faz a caixa n subir em cima da parede
			if(mapa[x][y-2] == '#' and mapa[x][y-1] == 'D') {
				y++;
			}
			//faz o jogador n subir em cima da parede, e faz jogador mover com a caixa
			if(mapa[x][y-1] != '#' ) {
				mapa[x][y] = ' ';
				if(mapa[x][y-1] =='D') {
					mapa[x][y-2] = 'D';
				}
				if(mapa[x][y-1]=='X') {
					mapa[x][y] = '@';
					y++;
				}

				y--;
				mapa[x][y]='@';
			}
		}

		//fim do jogo
		if (mapa[pos_Xx1][pos_Xy1] == 'D') {

			cout << " voce ganhou";
			return 0;
		}

	}
	return 0;
}