#include <iostream>
using namespace std;

class Programator {
	string nume;
	int nrZileActive;
	int* commituriPeZi;

public:
	Programator() {
		cout << "\nConstructed with no params.\n";
		this->nume = "Anonim";
		this->nrZileActive = 0;
		this->commituriPeZi = nullptr;
	}

	Programator(int nrZileActive, int* commituriPeZi) {
		cout << "\nConstructed with missing params.\n";
		if (nrZileActive > 0 && commituriPeZi != nullptr) {
			this->nrZileActive = nrZileActive;
			this->commituriPeZi = new int[this->nrZileActive];
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
			cout << " Numarul de commituri pe zile: ";
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

	double averageCommits() {
		if (this->nrZileActive == 0 || this->commituriPeZi == nullptr) return 0;
		int commitSum = 0;
		for (int i = 0; i < this->nrZileActive; i++) {
			commitSum += this->commituriPeZi[i];
		}
		return ((float)commitSum / this->nrZileActive);
	}

	int mostCommits() {
		if (this->nrZileActive == 0 || this->commituriPeZi == nullptr) return -1;
		int currentBest = this->commituriPeZi[0];
		for (int i = 1; i < this->nrZileActive; i++) {
			if (this->commituriPeZi[i] > currentBest) currentBest = this->commituriPeZi[i];
		}
		return currentBest;
	}

	int getNrOfDays() {
		return this->nrZileActive;
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
	int commits[] = { 24, 13, 65, 21 };
	Programator* p2 = new Programator(4, commits);
	p1->afisare();
	p2->setName("");
	p2->afisare();
	delete p1;
	p2->setName("John Programare");
	p2->afisare();
	if (p2->getNrOfDays() > 0) {
		cout << "Average for p2: " << p2->averageCommits() << ". Most commits in a day by p2: " << p2->mostCommits() << "\n";
	}
	else {
		cout << "p2 has not commited anything yet.";
	}
	delete p2;
	return 0;
}