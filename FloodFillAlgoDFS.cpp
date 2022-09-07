#include <bits/stdc++.h>
using namespace std;

int R, C;

void printMat(char input[][50]){
	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cout<<input[i][j];
		}
		cout<<endl;
	}
}



void floodFill(char mat[][50], int i, int j, char ch, char color){

	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, 1, 0, -1};

	//base case-matrix bounds
	if(i<0 or j<0 or i>=R or j>=C){
		return;
	}
	//figure boundary condition
	if(mat[i][j]!=ch){
		return;
	}

	mat[i][j] = color;

	// cout<<endl;
	// printMat(mat);

	for(int k=0; k<4; k++){
		floodFill(mat, i+dx[k], j+dy[k], ch, color);
	}
}


int main(){

	cin>>R>>C;
	char input[15][50];

	for(int i=0; i<R; i++){
		for(int j=0; j<C; j++){
			cin>>input[i][j];
		}
	}

	printMat(input);

	floodFill(input, 8, 13, '.', '/');
	// floodFill(input, 1, 1, '.', '*');
	// floodFill(input, 4, 16, '.', '!');
	cout<<endl;
	cout<<endl;
	cout<<endl;

	printMat(input);


	return 0;
}