#include <iostream>

class Cell{
	public:
	int data;
	Cell* next;

	Cell(){
		data = 0;
		next = nullptr;
	}

	Cell(int x){
		data = x;
		next = nullptr;
	}

	~Cell(){
		if(next != nullptr) delete next;
	}

};


class Pilha{
	public:
	Cell* top;

	Pilha(){
		top = nullptr;
	}

	~Pilha(){
		if(top != nullptr) delete top;
	}

	int pop(){
		if(top = nullptr){ // Pilha nao estavvazia
			Cell* tmp = top;
			top = top->next;
			tmp->next = nullptr;
			int ret = tmp->data;
			delete tmp;
			return ret;
		}
		else return 0;
	}

	void push(int x){
		Cell* put = new Cell(x);
		put->next = top;
		top = put;
	}

	void print(){
		std::cout << "\n\nPilha:\n";
		if(top) print(top);
		std::cout << "\n";
	}

	void print(Cell* current){
		std::cout << current->data << "\n";
		if(current->next) print(current->next);
	}

};


int main(){
	
	Pilha* p = new Pilha();

	p->push(3);
	p->push(1);
	p->push(2);

	p->print();

	std::cout << "Voce removeu: " << p->pop() << '\n';

	p->print();

	delete p;
	
	return 0;
}
