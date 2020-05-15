#include "pch.h"
#include<iostream>
#include "TestStand.h"
#include<iomanip>
#include<thread>
#include <vector>
#include <algorithm>
#include"string.h"
TestStand::TestStand()
{
	
}
TestStand::~TestStand()
{

}
void OverheatTest::test(InternalCombustionEngine &_engine){
	double globalTemperature = this->AreaTemp;
	this->Time = 0;
	const double Time_eps = 0.001;
	const double maxTemperature = _engine.T;
	double currentSpeed = _engine.V[0];
	double currentRotationMoment = _engine.M[0];
	double previousSpeed = currentSpeed;
	double currentTemperature = AreaTemp;
	while(true){
		if (maxTemperature - currentTemperature <= 0.1) {
			return;
		}
		for (unsigned int i = 1; i < _engine.V.size(); i++) {
			if (_engine.V[i - 1] <= currentSpeed && currentSpeed <= _engine.V[i])
			{
				double delta1 = _engine.V[i] - _engine.V[i - 1];
				double delta2 = _engine. M[i] - _engine.M[i - 1];
				double k =(currentSpeed-_engine.V[i - 1]) / delta1;
				currentRotationMoment = _engine.M[i - 1]+ k * delta2;
			}
		}
		currentSpeed = previousSpeed + currentRotationMoment * Time_eps / _engine.I;
		previousSpeed = currentSpeed;
		double Vh = currentRotationMoment * _engine.H_m + currentSpeed * currentSpeed*_engine.H_v;
		double Vc = _engine.C * (globalTemperature - currentTemperature);
		double V_eps = Vh + Vc;
		this->Time += Time_eps;
		double prevTemperature = currentTemperature;
		double Temp_eps= Time_eps * V_eps;
		currentTemperature += Temp_eps;
		auto min_eps = std::min(_engine.H_v, _engine.H_m);
		if (V_eps <= min_eps) {
			this->Time = -1;
			return;
		}
	}
	
}
double TestStand::Overheat_Test(double AreaTemp, Engine* _engine){
	OverheatTest t(AreaTemp);
	_engine->accept(t);
	return t.Time;
}
void TestStand::AddEngine(Engine* en){
	this->engines.push_back(en);
}
std::vector<double> TestStand::Overheat_Test(double AreaTemp) {
	std::vector<double> res;
	for (auto engine : this->engines)
	{
		OverheatTest t(AreaTemp);
		engine->accept(t);
		res.push_back(t.Time);
	}
	return res;
}
