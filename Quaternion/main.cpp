
#include"VEC3.h"
#include "QuartanionElement.h"
#include "Quartanion.h"
#include"math.h"
#include<iostream>

namespace {
	float pi = 3.141592653589793238462643;
}

int main() {
	VEC3 axis = { 0,0,1 };
	Quartanion q;

	QuartanionElement quartanion= q.CalculateRotateQuartanion(pi / 2, axis);
	QuartanionElement conjQuartanion = q.CalculateConjuRotateQuartanion(pi / 2, axis);
	VEC3 coord = { 1,0,0 };

	VEC3 result= q.AttatchQuartanion(coord, quartanion, conjQuartanion);

	std::cout << result.x << "," << result.y << "," << result.z << std::endl;
}