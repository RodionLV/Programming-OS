#include <iostream>
#include <string>

using namespace std;

int availableSeats(int bus_size, int num_passengers){
	return bus_size - num_passengers % bus_size;
}

void countdown(int count, int multiple, string word){
	for(int i = count; i > 0; i--){
		if((i % multiple) == 0){
			cout<<word<<endl;
		}else{
			cout<<i<<endl;
		}	
	}
}

double discountPromotion(int group[], int size_group = 5, double ticket_price = 10){
	int min = group[0];
	
	for(int i = 1; i < size_group; i++){
		if( group[i] < min ){
			min = group[i];
		}
	}
	
	double sum = ticket_price*size_group;
	return sum - sum/100*min;
}

int main(){
	cout<<"available seats: "<<availableSeats(50, 126)<<endl;
	
	cout<<endl;
	
	countdown(12, 5, "Beer");
	
	cout<<endl;
	
	int group[]{18, 56, 65, 21, 15};
	
	cout<<"discount: "<<discountPromotion(group)<<endl;
}