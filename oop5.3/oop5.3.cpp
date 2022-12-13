// oop5.3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "oop5.3.h"
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

virtual ~Base() {
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
	cout << "GOGOGOGOGO\n";
}
};
void function1(unique_ptr<Base> )
{
	cout << "func1 unique_ptr<Base>\n";
}
void function2(unique_ptr<Base>&)
{
	cout << "func2 unique_ptr<Base>&\n";
}

void function3(shared_ptr<Base>)
{
	cout << "func3 shared_ptr<Base>";
}




void func1(Base a )
{
	cout << "functuion1 base a\n";

	
}
void func2(Base *a)
{
	cout << "functuion2 base*a\n";
	if (dynamic_cast<Desc*>(a))
	 dynamic_cast<Desc*>(a)->GoGo();
	
	
	
}

void func3(Base &a)
{
	cout << "functuion2 base*a\n";
	if (dynamic_cast<Desc*>(&a))
		dynamic_cast<Desc*>(&a)->GoGo();
	cout << "functuion3 base&a\n";
}
Base out1() {
	cout<<"out1\n";
	Base b;
	return b;


}
//создаем на куче и копируем и утечка 
Base out2() {
	cout << "out2\n";

	Base *a = new Base();
	return *a;

}
//получим адрес на мертвый объект
Base* out3() {
	cout << "out2\n";

	Base out3;
	return &out3;

}

//утечка
Base* out4() {
		Base *out4 = new Base();
		return out4;

}
Base& out5() {
	Base out5;
	return out5;
}


Base& out6() {
	Base* out6 = new Base();
	return *out6;


}


int main(){

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

	cout << endl << "end of &*" << endl<< endl;
	//cоздаем три файла 
	
	Base pop;
	pop = out1();

	//Base pop2 = out2();//создаем на куче и копируем и утечка new without delete 


	Base* pop3 = out3();//получим адрес на мертвый объект


	Base* pop4 = out4();

	Base& pop5 = out5();


	Base& pop6 = out6();


	{
		{
			unique_ptr<Base> ptr1(new Base());
			function1(move(ptr1));
			cout << endl;
		}

		

		{
			shared_ptr<Base> shared1 = make_shared<Base>(new Base());

			function3(shared1);
			cout << endl << endl;
		}


		shared_ptr<Base> shared = make_shared<Base>(new Base());
		{
			shared_ptr<Base> TestPtrWillDIe(new Base());
			TestPtrWillDIe = shared;

		}

	}

}

