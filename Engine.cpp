#include "pch.h"
#include "Engine.h"
InternalCombustionEngine::InternalCombustionEngine(double _I, std::vector<double> _M, std::vector<double> _V, double _T, double _H_m, double _H_v, double _C)
{
	I = _I;
	M = _M;
	V = _V;
	T = _T;
	H_m = _H_m;
	H_v = _H_v;
	C = _C;
}
void InternalCombustionEngine::accept(Tester &t)
{
	t.test(*this);
}
