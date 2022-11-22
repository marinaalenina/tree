#include <iostream>
#include <thread>
#include "Tree.h"
using namespace std;

struct AlphabeticOrder {
	bool operator()(const string& s1, const string& s2, const int& i = 0) {
		if ((s1[i] == '\0') || (s1[i] < s2[i]))
			return true;
		else {
			if (s1[i] > s2[i])
				return false;
			else
				return operator()(s1, s2, i + 1);
		}
	}
};

int main() {
	Tree<int> t;
	thread th1([&]() {
		t.add(8);
		t.add(10);
		t.add(2);
		t.add(6);
		cout << "find tree const 15: " << t.find(15) << " " << endl;
		});
	thread th2([&]() {
		t.add(7);
		t.add(12);
		t.add(5);
		t.add(9);
		cout << "\nfind tree const 9: " << t.find(9) << " " << endl;
		});
	th1.join(); th2.join();
	cout << t << endl;
	Tree<float> t2;
	thread th3([&]() {
		t2.add(9.2);
		t2.add(10.8);
		t2.add(46.1);
		t2.add(23.3);
		});
	thread th4([&]() {
		t2.add(1.3);
		t2.add(3.3);
		t2.add(40.6);
		t2.add(96.2);
		t2.add(23.7);
		t2.add(62.0);
		t2.add(2.2);
		cout << endl;
		t2.klp();
		cout << endl;
		t2.lpk();
		cout << endl;
		});
	th3.join(); th4.join();
	cout << t2 << endl;

	cout << (t2 == t2) << endl;

	Tree<float> t3;
	thread th5([&]() {
		t3.add(4.9);
		t3.add(17.2);
		t3.add(91.0);
		t3.add(2.2);
		});
	thread th6([&]() {
		t3.add(1.3);
		t3.add(3.3);
		t3.add(47.6);
		t3.add(56.6);
		t3.add(45.1);
		t3.add(43.7);
		t3.add(12.0);
		t3.add(2.2);
		cout << endl;
		t3.klp();
		cout << endl;
		t3.lkp();
		cout << endl;
		});
	th5.join(); th6.join();
	cout << t3 << endl;
	cout << (t3 != t2);
	return 0;
}