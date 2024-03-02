#include <iostream>
#include <string>
#include "./classes/queue.h"

using namespace std;

int main(int argc, char** argv) {
	Queue queue;
	
	cout<< "print: " << queue.print() << endl;
	
	for(int i = 0; i < 14; i++){
		queue.add(i);
		cout<< "add: " << queue.print() << endl;
	}
	
	for(int i = 0; i < 16; i++){
		cout<<"remove: "<<queue.remove() << endl;
		cout<<"print: "<< queue.print() << endl;
	}
	
	return 0;
}