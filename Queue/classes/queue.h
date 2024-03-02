#include <string>
#include <iostream>
class Queue{
	private:
		int max_size; 
		int size;
		int* queue;
		
		int _size_buf = 5;
		
		void resize_queue(){
			int* new_queue = new int[max_size];
			
			for(int i = 0; i < size; i++){
				new_queue[i] = queue[i];
			}
			
			delete[] queue;
			queue = new_queue;
		}
		
	public:
		Queue(){		
			size = 0;
			max_size = _size_buf;
			
			queue = new int[max_size];
		}
	
		void add(int item){
			if(size == max_size){
				max_size += _size_buf;
				resize_queue();
			}
			
			queue[size] = item;
			size++;        
    	}
    	
    	int remove(){
    		if(size == 0){
    			return 0;
			}
    		if(size < max_size - _size_buf && max_size > _size_buf){
    			max_size -= _size_buf;
    			resize_queue();
			}
    		
    		int removed = queue[0];
    		
    		for(int i = 1; i < size; i++){
    			queue[i-1] = queue[i];
			}
			
			size--;
			return removed;
		}
    	
    	int get_size(){
    		return size;
		}
    	
    	std::string print(){
    		if(size == 0){
    			return "[]";
			}
    		
    		std::string res = "[";
    		for(int i = 0; i < size-1; i++){
    			res += std::to_string(queue[i]) + ", ";
			}
			
			res += std::to_string(queue[size-1]) + "]";
    		return res;
		}
};