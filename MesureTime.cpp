#include<iostream>
#include<chrono>

int main()
{

	std::chrono::system_clock::time_point start, end;
	start = std::chrono::system_clock::now();

	/*
	ˆ—
	*/
	end = std::chrono::system_clock::now();

	auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	std::cout << elapsed << "ms" << std::endl;
	return 0;
}