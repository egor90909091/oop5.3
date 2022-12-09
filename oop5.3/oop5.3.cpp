// oop5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;
class Base{
public :
Base() {
cout<<" Base ( ) \n";
}
Base(Base* obj) {
	cout << "Base* obj \n";

}

Base(Base& obj) {
	cout << "Base& obj\n";

}
~Base() {
cout<<"~Base ( ) \n";
}
};

class Desc : public Base{

public:
Desc() {

cout<<"Desc ( ) \n";
}
Desc(Desc* obj) {
	cout << "Desc* obj";

}

Desc(Desc& obj) {

	cout << "Desc& obj";
}
~Desc() {
	
cout<<"~Desc ( ) \n";
}
void GoGo() {

}
};
//void func1(unique_ptr<Base> )
//{
//	cout << "func1 unique_ptr<Base>\n";
//}
//void func2(unique_ptr<Base>&)
//{
//	cout << "func2 unique_ptr<Base>&\n";
//}
//
//void func3(shared_ptr<Base>)
//{
//	cout << "func3 shared_ptr<Base>";
//}

void func1(Base a )
{
	cout << "functuion1 base a\n";
}
void func2(Base *a)
{
	cout << "functuion2 base*a\n";
}

void func3(Base &a)
{
	cout << "functuion3 base&a\n";
}

//сделать передачу объекта разными способами 


int main()
//{
//	{
//	unique_ptr<Base> ptr1(new Base());
//	func1(move(ptr1));
//	cout << endl;
//}
//	
//		unique_ptr<Base>unik2(new Base());
//		func2(unik2);
//		cout << endl;
//
//{
//		shared_ptr<Base> shared1 = make_shared<Base>(new Base());
//
//		func3(shared1);
//		cout << endl << endl;
//}


	shared_ptr<Base> shared = make_shared<Base>(new Base());
	{
		shared_ptr<Base> TestPtrWillDIe(new Base());
		TestPtrWillDIe = shared;
	
	}
	cout <<endl <<" *&" << endl<<endl;

	
	Base b;
	Base* ptr_b = new Base;

	cout << endl << "#1" << endl;
	func1(b);
	cout << endl << "#2" << endl;
	func2(&b);
	cout << endl << "#3" << endl;
	func3(b);
	cout << endl;

	cout << "#4" << endl;
	func1(*ptr_b);
	cout << endl << "#5" << endl;
	func2(ptr_b);
	cout << endl << "#6" << endl;
	func3(*ptr_b);

	cout << "---------------------" << endl;

	Desc d;
	Desc* ptr_d = new Desc;

	cout << endl<< "#1" << endl;
	func1(d);
	cout << endl << "#2" << endl;
	func2(&d);
	cout << endl << "#3" << endl;
	func3(d);
	cout << endl;

	cout << "#4" << endl;
	func1(*ptr_d);
	cout << endl << "#5" << endl;
	func2(ptr_d);
	cout << endl << "#6" << endl;
	func3(*ptr_d);

	cout << "---------------------" << endl;

	Base* ptr = new Desc;

	cout << "#1" << endl;
	func1(*ptr);
	cout << endl << "#2" << endl;
	func2(ptr);
	cout << endl << "#3" << endl;
	func3(*ptr);
	cout << endl;


	delete ptr_b;
	delete ptr_d;
	delete ptr;

	cout << endl << "end of main()" << endl<< endl;



}

