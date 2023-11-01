#include <iostream>

using namespace std;

class Entity {
private:
	int value = 0;
public:
	Entity() {}

	Entity(int val) {
		this->value = val;
	}
	Entity(const Entity& e) {
		this->value = e.value;
	}

	Entity& operator++() {
		value++;
		return *this;
	}

	Entity operator++(int) {
		Entity old = *this;
		operator++();
		return old;
	}

	bool operator==(const Entity& e) {
		return (this->value == e.value);
	}

	bool operator==(int x) const {
		return (this->value == x);
	}

	int getValue() const {
		return this->value;
	}

	friend ostream& operator<<(ostream& ost, const Entity& e) {
		ost << "\nValue is: " << e.value;
		return ost;
	}

	Entity& operator+=(const Entity& e) {
		this->value += e.value;
		return *this;
	}

	Entity& operator+(int add) {
		this->value += add;
		return *this;
	}

	friend istream& operator>>(istream& ist, Entity& e) {
		ist >> e.value;
		return ist;
	}
};

bool operator == (int compValue, const Entity& e) {
	return (e == compValue);
}

int main() {
	Entity e(10);
	cout << e.getValue() << endl;
	e++;
	cout << e.getValue() << endl;

	if (11 == e) cout << "\nCool";
	else cout << "\nLame";

	cout << e;

	e += 3;

	cout << e;

	e += e;
	
	cout << e;

	cout << "\nNew value is: ";
	cin >> e;
	cout << e;

	cout << "\n";
	return 0;
}