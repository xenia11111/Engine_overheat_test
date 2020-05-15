#pragma once
#include"Engine.h"
#include<queue>
class Engine;
class InternalCombustionEngine;

class Tester 
{
public:
	Tester() {};
	~Tester() {};
	virtual void test(InternalCombustionEngine &engine) = 0;
	double Time=0;
};

class OverheatTest:public Tester
{
	double AreaTemp;
public:
	OverheatTest(double T) { AreaTemp = T; };
	~OverheatTest() {};
	void test(InternalCombustionEngine &engine);
};

class TestStand 
{
public:
	TestStand();
	~TestStand();
	std::vector<double> Overheat_Test(double AreaTemp);
	double Overheat_Test(double AreaTemp, Engine* _engine);
	void AddEngine(Engine* en);
	std::vector<Engine*> engines;
};

