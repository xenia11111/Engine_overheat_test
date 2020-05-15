#include "pch.h"
#include <iostream>
#include"TestStand.h"
#include"Engine.h"
#include<vector>
int main(int argc, char* argv[])
{
	double I = 10;
	double T = 110;
	double H_m = 0.01;
	double H_v = 0.0001;
	double C = 0.1;
	std::vector<double> M = { 20, 75, 100, 105, 75, 0 };
	std::vector<double> V = { 0, 75, 150, 200, 250, 300 };
	double areaTemp;
	std::cout << "Enter the area temperature(C):\n";
	std::cin >> areaTemp;
	InternalCombustionEngine e(I, M, V, T, H_m, H_v, C);
	TestStand _testStand;
	_testStand.AddEngine(&e);
	std::vector<double> results = _testStand.Overheat_Test(areaTemp);
	unsigned int id = 0;
	for(auto time : results) {
		id++;
		std::cout << "Engine " << id << ": ";
		if(time==-1)
			std::cout<<"No overheat." << std::endl;
		else
			std::cout<<"Overheat in " << time<<" seconds."<<std::endl;
	}
	return 0;
}


