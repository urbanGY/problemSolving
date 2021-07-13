#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
using namespace std;

int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
int cnt = 0;
bool cmp (int a, int b) {
								return a < b;
}

int find(int x, int y, vector<vector<bool> >& check, int **matrix, int n) {
								if(x < 0 || y < 0 || x >= n || y >= n || matrix[x][y] == 0 || check[x][y]) return 0;
								check[x][y] = true;

								for(int i = 0; i < 4; i++) {
																int nx = x + dx[i], ny = y + dy[i];
																cnt += find(nx,ny,check,matrix,n);
								}
								return cnt + 1;
}

void solution(int sizeOfMatrix, int **matrix) {
								vector<vector<bool> > check(sizeOfMatrix, vector<bool>(sizeOfMatrix,false));
								vector<int> answer;
								for(int i = 0; i < sizeOfMatrix; i++) {
																for(int j = 0; j < sizeOfMatrix; j++) {
																								if(matrix[i][j] == 1 && !check[i][j]) {
																																int tmp = find(i,j,check,matrix,sizeOfMatrix);
																																answer.push_back(tmp);
																								}
																}
								}
								sort(answer.begin(), answer.end(), cmp);
								int length = answer.size();
								printf("%d\n",length);
								for(auto& elem : answer)
																printf("%d ",elem);

}

struct input_data {
								int sizeOfMatrix;
								int **matrix;

};

void process_stdin(struct input_data& inputData) {
								string line;
								istringstream iss;

								getline(cin, line);
								iss.str(line);
								iss >> inputData.sizeOfMatrix;

								inputData.matrix = new int*[inputData.sizeOfMatrix];
								for (int i = 0; i < inputData.sizeOfMatrix; i++) {
																getline(cin, line);
																iss.clear();
																iss.str(line);
																inputData.matrix[i] = new int[inputData.sizeOfMatrix];
																for (int j = 0; j < inputData.sizeOfMatrix; j++) {
																								iss >> inputData.matrix[i][j];
																}
								}
}

int main() {
								struct input_data inputData;
								process_stdin(inputData);

								solution(inputData.sizeOfMatrix, inputData.matrix);
								return 0;
}
