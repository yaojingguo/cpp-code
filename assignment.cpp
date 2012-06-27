#include <iostream>
#include <list>

using namespace std;

struct entry {
	int no;
	int value;
	struct entry& operator = (struct entry& other) {
		cout << "assignment" << endl;
		no = other.no;
		value = other.value;
	}
};

class container {
	private:
		list<struct entry> ls;	
	public:
		container() {
			struct entry one = {1, 10};
			ls.push_back(one);
		}
		void takeEntry(struct entry* p) {
			*p = ls.front(); // trigger an assignment
			ls.pop_front();
		}
};

void test1() {
	cout << "=========== test1" << endl;
	struct entry e = {10, 100};
	struct entry& alias = e; // no assignment triggered

	struct entry other;
	other = alias; // trigger an assignment
}

void test2() {
	cout << "=========== test2" << endl;
	container c;
	struct entry instance;
	c.takeEntry(&instance);
	cout << "no: " << instance.no << ", value: " << instance.value << endl;
}

// core dump
void test3() {
	cout << "=========== test3" << endl;
	container c;
	struct entry* p;
	c.takeEntry(p);	
}

int main(int argc, const char *argv[]) {
	test1();
	test2();
	test3();
	return 0;
}
