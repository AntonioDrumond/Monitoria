#include <iostream>

class cell{
	public:
	int data;
	cell* next;

	cell(int x){		//Constructor with starting data
		data = x;
		next = nullptr;
	}

	cell(){ 			//Constructor without starting data
		data = 0;
		next = nullptr;
	}

	~cell(){			//Destructor
		if(next!=nullptr) delete next;
	}

};

class pill{
	public:
	cell* top;

	pill(){
		top = nullptr;
	}

	pill(int value){
		top = new cell(value);
	}

	~pill(){
		delete top;
	}

	bool printReverse(){
		if(this->top != nullptr){
			printReverse(top);
			return true;
		}
		else return false;
	}

	bool print(){
		if(top==nullptr) return false;
		cell* tmp = top;
		do{
			std::cout << tmp->data << "\n";
			tmp = tmp->next;
		}while(tmp != nullptr);
		return true;
	}

	void push(int value){
		cell* tmp = new cell(value);
		tmp->next = top;
		top = tmp;
	}
		

	int pop(){
		if(top==nullptr) return 0;
		else{
			int el = top->data;
			cell* tmp = top;
			top = top->next;
			tmp->next = nullptr;
			delete tmp;
			return el;
		}
	}

	void dupTop(){
		if(top!=nullptr){
			push(top->data);
		}
	}

	void swapTop(){
		if(top!=nullptr){
			int el = top->next->data;
			top->next->data = top->data;
			top->data = el;
		}
	}

	void invert(){
		if(top!=nullptr){
			pill* result = new pill();
			invert(result, top);
			delete top;
			top = result->top;
			result->top = nullptr;
			delete result;
		}
	}

	private:
	void printReverse(cell* current){
		if(current->next != nullptr) printReverse(current->next);
		std::cout << current->data << "\n";
	}

	void invert(pill* result, cell* current){
		result->push(current->data);
		if(current->next != nullptr) invert(result, current->next);
	}

};

class line{
	public:
	int size;
	cell* pri;
	cell* ult;

	line(){
		pri = new cell();
		ult = pri;
		size = 0;
	}

	~line(){
		delete pri;
	}
	
	void push(int value){
		ult->next = new cell(value);
		ult = ult->next;
		size++;
	}

	int pop(){
		if(pri!=ult){
			int val = pri->data;
			cell* tmp = pri;
			pri = pri->next;
			tmp->next = nullptr;
			delete tmp;
			size--;
			return val;
		}
		else return 0;
	}

	void print(){
		if(pri->next!=nullptr) print(pri->next);
	}

	void concat(line* other){
		if(other->pri->next != nullptr) concat(other->pri->next);
	}

	int compare(line* other){
		cell* tCrr = pri;
		cell* oCrr = other->pri;
		while(tCrr->next!=nullptr && oCrr->next!=nullptr){
			int diff = tCrr->data - oCrr->data;
			if(diff<0) return -1;
			else if(diff>0) return 1;
			tCrr = tCrr->next;
			oCrr = oCrr->next;
		}
		if(tCrr != nullptr){
			return -1;
		} 
		else if(oCrr != nullptr){
			return 1;
		}
		return 0;
	}

	bool searchBool(int target){
		bool found = false;
		cell* current = pri;
		while(!found && current->next!=nullptr){
			current = current->next;
			if(current->data == target) found = true;
		}
		return found;
	}

	void sort(){
		cell* current = pri->next;
		int buffer = 0;
		while(current!=nullptr){
			cell* menor = current;
			cell* anlz = current->next;
			while(anlz!=nullptr){
				if(anlz!=nullptr && anlz->data < menor->data) {
					menor = anlz;
				}
				anlz = anlz->next;
			}
			//swap current - menor
			buffer = current->data;
			current->data = menor->data;
			menor->data = buffer;

			current = current->next;
		}
	}


	line* merge(line* other){
		line* result = new line();
		cell* tCrr = pri->next;
		cell* oCrr = other->pri->next;
		while(tCrr!=nullptr || oCrr!=nullptr){
			if(tCrr!=nullptr){
				result->push(tCrr->data);
				tCrr = tCrr->next;
			}
			if(oCrr!=nullptr){
				result->push(oCrr->data);
				oCrr = oCrr->next;
			}
		}
		return result;
	}

	line* mergeUp(line* other){
		line* result = merge(other);
		result->sort();
		return result;
	}

	private:
	void print(cell* current){
		std::cout << current->data << "\n";
		if(current->next!=nullptr) print(current->next);
	}

	void concat(cell* current){
		push(current->data);
		if(current->next) concat(current->next);
	}

};
