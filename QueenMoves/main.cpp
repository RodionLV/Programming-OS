#include <iostream>
#include <cmath>

using namespace std;

struct Cord{
private:
	int x = 0;
	int y = 0;
	
 	char horizon[9] = "abcdefhg";
	
	Cord(int x, int y): x{x}, y{y}{}
	
	int getHorizonInt(char c){
		for(int i = 0; i < 8; i++){
			if(horizon[i] == c) return i; 
		}
		
		return -1;
	}
	
	int getVerticalInt(char c){
		int v = (int)c-49;
		
		if( 0 <= v && v < 8) return v;	
		return -1;
	}
	
public:
	Cord(){}
	Cord(char x, char y){
		int nx = getHorizonInt(x);
		int ny = getVerticalInt(y);
		
		if(nx == -1 || ny == -1)
			throw std::invalid_argument("invalid argument");
			
		this->x = nx;
		this->y = ny;
	}
	
	int getX(){ 
		return x;
	}
	int getY(){
		return y;
	}
	
	Cord diff(Cord cord){
		int nx = abs(this->x - cord.x); 
		int ny = abs(this->y - cord.y);
		
		Cord nCord{nx, ny};
		return nCord;
	}
};

int main(){
	setlocale(LC_ALL, "rus");

	char x1, x2;
	char y1, y2;
	
	while(true){
		try{
			wcout<<L"Введите координату 1 (пример: a1, h3):"<<endl;
			cin>>x1>>y1;
			
			Cord c1{ x1, y1 };
			
			wcout<<L"Введите координату 2:"<<endl;
			cin>>x2>>y2;
			
			Cord c2{ x2, y2 };
				
			Cord diff = c1.diff(c2);
			
			if( diff.getX() == diff.getY() || diff.getX() == 0 || diff.getY() == 0){
				cout<<"yes"<<endl;
			}else{
				cout<<"no"<<endl;
			}	
		}catch(const exception& e){
			cout<<e.what()<<endl;
		}
		
		cout<<endl;
	}
}








