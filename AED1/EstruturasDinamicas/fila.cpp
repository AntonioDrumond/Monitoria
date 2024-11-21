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
		if(next) delete next;
	}

};

class Fila{
	public:
	Cell* ini;
	Cell* fim;

	Fila(){
		ini = new Cell(); // Nó cabeça
		fim = ini;
	}

	~Fila(){
		if(ini) delete ini;
	}

	void push(int x){
		Cell* put = new Cell(x);
		fim->next = put;
		fim = put;
	}

	int pop(){
		if(fim == ini){ // Fila vazia
			return 0;
		}
		else{
			int ret = ini->next->data;
			Cell* tmp = ini->next;
			ini->next = ini->next->next;
			tmp->next = nullptr;
			delete tmp;
			return ret;
		}
	}

	void print(){
		std::cout << "Fila:\n";
		if(fim != ini) print(ini->next);
		std::cout << "\n\n";
	}

	void print(Cell* current){
		std::cout << current->data << "->";
		if(current->next) print(current->next);
	}

};

int main(){
	
	Fila* f = new Fila();
	f->push(4);
	f->push(6);
	f->push(1);
	f->push(9);

	f->print();

	std::cout << "Removido: "  << f->pop() << "\n";

	f->print();

	delete f;

	return 0;
}
