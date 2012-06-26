#include <iostream>

using namespace std;

class person {
	private:
		int sex;
		int age;
	public:
		person() : sex(0), age() {}
		int getSex() { return sex; }
		int getAge() { return age; }
};

int main(int argc, const char *argv[]) {
	person p;

	cout << "sex: " << p.getSex() << ", age: " << p.getAge() << endl;
	
	return 0;
}
