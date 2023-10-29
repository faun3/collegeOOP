#include <iostream>

using namespace std;

class Student {
private:
	static int currentId;
	static Student* instances[100];
	static int nrInstances;
	const int id;
public:
	static bool allUniq() {
		for (int i = 0; i < nrInstances - 1; i++) {
			for (int j = i + 1; j < nrInstances; j++) {
				if (instances[i]->getId() == instances[j]->getId()) return false;
			}
		}
		return true;
	}
	Student() : id(currentId++) {
		instances[nrInstances++] = this;
	}
	~Student() {
		nrInstances--;
	}
	int getId() {
		return this->id;
	}
};

// without this definition, the program compiles but doesn't link
int Student::currentId = 0;
int Student::nrInstances = 0;
Student* Student::instances[100];

int main() {
	Student* s1 = new Student();
	Student* s2 = new Student();
	cout << s1->getId() << " " << s2->getId();
	Student* s3 = new Student();
	cout << " " << s3->getId();

	cout << endl;
	if (Student::allUniq()) {
		cout << endl << "ok";
	}
	else cout << endl << "whoops";
	delete s1;
	Student* s4 = new Student();

	if (Student::allUniq()) {
		cout << endl << "ok";
	}
	else cout << endl << "whoops";
	delete s2;
	delete s3;
	return 0;
}