#pragma once
#include<vector>
#include"TestStand.h"

class Tester;
class OverheatTest;

class Engine
{
public:
	Engine() {};
	~Engine() {};
	virtual void accept(Tester &t) = 0;
};
class InternalCombustionEngine:public Engine
{
public:
	InternalCombustionEngine(double I, std::vector<double> M, std::vector<double> V, double T, double H_m, double H_v, double C );
	~InternalCombustionEngine() {};
	void accept(Tester &t);
	double I, T, H_m, H_v, C;
	std::vector<double> M;
	std::vector<double> V;

};
