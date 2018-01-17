#pragma once
#include <condition_variable>
#include "Decomposition.h"
#include <string>
#include <fstream>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
class ThreadPool
{
public:
	ThreadPool::ThreadPool(std::string &);
	ThreadPool::~ThreadPool();
	void StartWork();
	void Start(std::string &);
	void readFile(std::string &);

	
private:
	
	std::mutex mutx;
	std::mutex mlock;
	std::thread producer;
	std::condition_variable condVariable;
	std::condition_variable paused;
	
	std::vector<std::thread> threads;
	std::string inputFile;
	const std::string outputFile;
	std::queue<uint64_t> taskqueue;
	std::string fileName;
	std::ofstream fout;
	uint64_t number;
	std::ifstream fin;
	bool done = false;
	bool pause, exit;
	void Pause();
	void Exit();
	void  worker();
	void Resume();
	;
};