#include <iostream>
using namespace std;

class Programator {
	string nume;
	int nrZileActive;
	int* commituriPeZi;

public:
	Programator (){
		cout << "\nConstructed with no params.\n";
		this->nume = "Anonim";
		this->nrZileActive = 0;
		this->commituriPeZi = nullptr;
	}

	Programator(int nrZileActive, int* commituriPeZi) {
		cout << "\nConstructed with missing params.\n";
		if (nrZileActive > 0 && commituriPeZi != nullptr) {
			this->commituriPeZi = new int[this.nrZileActive];
			this->nrZileActive = nrZileActive;
			for (int i = 0; i < this->nrZileActive; i++) {
				this->commituriPeZi[i] = commituriPeZi[i];
			}
		}
		else {
			this->nrZileActive = 0;
			this->commituriPeZi = nullptr;
		}
	}

	void afisare() {
		cout << "\nNume: " << this->nume << ". Nr zile de activitate: " << this->nrZileActive << ".";
		if (this->nrZileActive > 0 && this->commituriPeZi != nullptr) {
			cout << "Numarul de commituri pe zile: ";
			for (int i = 0; i < this->nrZileActive; i++) {
				cout << this->commituriPeZi[i] << " ";
			}
		}
		else cout << " Nu a efectuat niciun commit inca.";
		cout << "\n";
	}

	void setName(string newName) {
		if (newName.length() < 3) {
			this->nume = "Anonim";
		}
		else this->nume = newName;
	}

	~Programator() {
		cout << "\nDestructor called.\n";
		delete[] this->commituriPeZi;
		this->commituriPeZi = nullptr;
		this->nrZileActive = 0;
	}
};

int main() {
	Programator* p1 = new Programator();
	const int commits[] = { 24, 13, 65, 21 };
	Programator* p2 = new Programator(4, commits);
	p1->afisare();
	p2->afisare();
	delete p1;
	delete p2;
	return 0;
}