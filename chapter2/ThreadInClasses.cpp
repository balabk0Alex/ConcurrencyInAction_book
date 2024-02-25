#include <iostream>
#include <thread>


class thread_one
{
public:
	void show2()
	{
		std::cout << "HI!I AM SHOW2" << std::endl;

	}

	void show1()
	{
		std::cout << "HI!I AM SHOW1" << std::endl;
		show2();
	}

	thread_one(std::thread & th):thread_(th)
	{
		thread_ = std::thread(&thread_one::show1, this);
	}

private:
	std::thread & thread_;
};


int main()
{
	std::thread MAINTHREAD;
	thread_one example( MAINTHREAD );
	MAINTHREAD.join();
	std::cout << "end";
}
