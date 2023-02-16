//============================================================================
// Name        : aula00.cpp
// Author      : Hugo Marcondes
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Pessoa {

//private:
	string  nome;
	int     idade;

public:
	Pessoa(string nome = "sem_nome", int idade = 0) {
			cout << "Estou criando um objeto da classe Pessoa (" << nome << "," << idade << ")" << endl;
			this->nome = nome;
			this->idade = idade;
	}

	~Pessoa(){
		cout << "RIP " << nome << endl;
	}

	void setIdade(int id){ idade = id; }

	string getNome() { return nome; }
	int    getIdade() { return idade; }

	void print(){
		cout << "<<" << this << ">> - " << nome << "," << idade << endl;
	}

};

Pessoa gbl_obj;

void func(){
	cout << "Entrando na função func()" << endl;

	Pessoa obj("Antônio Marcondes", 8);
	obj.print();

	cout << "Saindo da função func()" << endl;
}

int main() {
    cout << "Iniciando a função main." << endl;

	Pessoa obj("Hugo Marcondes", 43);

	cout << "Global" << endl;
	gbl_obj.print();

	cout << "MAIN" << endl;
	obj.print();

	func();

	cout << "Saindo da função main()" << endl;

	return 0;
}


