#include <iostream>
#include <cmath>


using namespace std;

double calc_area(double** verts, const int size_rows);

int main(){
	setlocale(LC_ALL, "rus");
	
	int n = 0;
	
	wcout<<L"Введите колличество вершин:"<<endl;
	cout<<"-> ";
	cin>>n;
	
	double **verts = new double*[n+1];
	
	int s = 0;
	while(s < n){
		wcout<<L"\nКоординаты для вершины "<<s+1<<endl;
		
		verts[s] = new double[2];
		
		wcout<<L"Введите x"<<s+1<<":"<<endl;
		cout<<"-> ";
		cin>>verts[s][0];
		wcout<<L"Введите y"<<s+1<<":"<<endl;
		cout<<"-> ";
		cin>>verts[s][1];
		
		s++;
	}
	
	verts[n] = new double[2];
	verts[n][0] = verts[0][0];
	verts[n][1] = verts[0][1];
	
	
	wcout<<L"Площадь равна: "<< calc_area(verts, n) << endl;
	system("pause");
	
	for(int i = 0; i < n; i++){
		delete [] verts[i];
	}

	delete [] verts;
}


double calc_area(double** verts, const int size_rows){
	double s = 0;
	
	for(int i = 0; i < size_rows; i++){
		s += verts[i+1][0] * verts[i][1] - verts[i][0] * verts[i+1][1];
	}
	
	return abs(s/2);
}
