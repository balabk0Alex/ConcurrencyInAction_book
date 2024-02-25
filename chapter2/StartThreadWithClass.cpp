#include <iostream>
#include <thread>
#include <chrono>



class ClassExample
{
public:
	ClassExample()
	{

	}

	void operator()()
	{
		showMessage();
	}

	void showMessage()
	{
		std::cout << "Hi! I am thread!\n"
				"My id: " << std::this_thread::get_id() << std::endl;
	}

private:
};



int main()
{
	std::cout << "Main thread id: " << std::this_thread::get_id() << std::endl;
	ClassExample a; //create object

	std::thread thread1(a);   //create thread

	std::cout << "Secont last thread id: " << std::this_thread::get_id() << std::endl;

	thread1.join(); //main thread will be wait thread1

	std::cout << "End thread id: " << std::this_thread::get_id() << std::endl;

}
