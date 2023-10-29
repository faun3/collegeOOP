#include <iostream>

using namespace std;

class Student {
private:
	static int currentId;
	int id;
public:
	Student() {
		id = currentId++;
	}
	~Student() {

	}
	int getId() {
		return this->id;
	}
};

// without this DEFINITION (it's not a declaration), the program compiles but doesn't link
int Student::currentId = 0;

int main() {
	Student* s1 = new Student();
	Student* s2 = new Student();
	cout << s1->getId() << " " << s2->getId();
	delete s1;
	delete s2;
	return 0;
}