#include "ThreadPool.h"
#include "Decomposition.h"
#include <fstream>
#include <thread>
#include <string>
#include <queue>
#include <iostream>
using namespace std;
ThreadPool::ThreadPool(std::string &filename)
{
	std::ifstream fin(filename);
	fin.open(filename);
	if (!fin.is_open())
	{
		std::cerr << "Input file can't be opened.\n";
		this->Exit();
	}

	//readFile(filename);
	Start(filename);
}
ThreadPool::~ThreadPool()
{
	done = true;
	condVariable.notify_all();
	unsigned const threadCount = threads.size();
	for (unsigned i = 0; i < threadCount; ++i) {
		threads[i].join();
	}
}
void ThreadPool::StartWork() {
	std::string command;
	while (!taskqueue.empty() && !done) {
		std::cin >> command;
		if (command == "exit") {
			Exit();
			break;
		}
		else if (command == "pause") {
			Pause();
		}
		else if (command == "resume") {
			Resume();
		}
	}
}





void ThreadPool::readFile(std::string &filename)
{
	
		while (fin >> number)
			{
				std::unique_lock < std::mutex> lockFile(mlock);
				unique_lock<mutex> prodLock(mlock);
				
				taskqueue.push(number);
				std::cout << number;
				
			}
			done = true;
}

void ThreadPool::Start(std::string &inputfilename)
{

	static std::ofstream fout("output.txt");
	
	if (!fout.good()) {
		std::cerr << "Output file can't be opened.\n";
		this->Exit();
	};
	producer = thread(&ThreadPool::readFile, this);
	unsigned const threadCount = std::thread::hardware_concurrency();

	for (unsigned i = 0; i < threadCount; ++i) {

		threads.emplace_back(&ThreadPool::worker, this);
	}

};

void ThreadPool::worker()
{
	std::unique_lock < std::mutex> lock(mutx);
	condVariable.wait(lock, [this]
	{
		return ((!taskqueue.empty() || done) && !pause);
	});
	if (taskqueue.empty() && !done)
		std::this_thread::sleep_for(std::chrono::seconds(1));
	if ((taskqueue.empty() && done) || exit)
		return;
	number=taskqueue.front();

	taskqueue.pop();
	decomposition factors;
	lock.unlock();
	factors.Factorize(number);
	std::string answ = factors.GetDecomposition();
	lock.lock();
	paused.wait(lock, [this] {
		return (!pause);
	});
	fout << answ;
};
void ThreadPool::Resume()
{
	pause = false;
	fout.open(outputFile);
	if (!fout.good()) {
		std::cerr << "File can't be opened.\n";
		this->Exit();
	}
	paused.notify_all();
	condVariable.notify_all();

}
void ThreadPool::Pause()
{
	pause = true;
	fout.close();
	std::this_thread::sleep_for(std::chrono::seconds(10));
};
void ThreadPool::Exit()
{
	done = true;
	exit = true;
	condVariable.notify_all();
};
