#include <future>
#include <iostream>
#include <sstream>
#include <fstream>
#include <chrono>   
#include <vector>
#include <pthread.h>

#define SET_NAME(name) test##name
using namespace std;
using namespace chrono;

std::vector<std::string> is_prime(int start,int end) {
	
	std::string data;
	std::vector<std::string> que;
	auto count = end - start;
	que.reserve(count);
	for (int i = start; i < end; ++i)
	{
		std::string s;
		std::stringstream ss(s);
		ss << i;

		que.push_back(ss.str());
	}

	return que;
}


int main() 
{

	int numCPU = 3;
	auto Input = 1000000;
	using FutureVector = std::vector< std::future<std::vector<std::string>>>;
	std::cout << "Dectect CPU Count = " << numCPU << std::endl;
	//std::cout << "Please input how many count of data = ";
	//std::cin >> Input;

	auto Count = Input / numCPU;
	FutureVector ASYC_OBJ;
	for (auto idx = 0; idx < numCPU; ++idx)
	{
		//設定餘數=====
		auto start = idx * Count;
		auto end = (idx + 1)*Count;
		if (Input - end < Count)
		{
			end = Input;
		}
		std::future<std::vector<std::string>> SET_NAME(idx) = std::async(std::launch::async,is_prime, start, end );
		ASYC_OBJ.push_back(std::move(testidx));
	}
	std::fstream file;
	file.open("output.txt", std::ios::out);

	for (int idx = 0; idx < ASYC_OBJ.size(); ++idx)
	{
		auto data = ASYC_OBJ.at(idx).get();
		std::cout << "OBJ_" << idx <<"Size = " << data.size() << std::endl;
		for (auto iter = data.begin(); iter != data.end(); ++iter)
		{
			file << *iter << "\n";
		}
	}
	file.close();

	return 0;
}
