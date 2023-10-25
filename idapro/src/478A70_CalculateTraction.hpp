#include <cmath>
#include <algorithm>
#include "Vector3.hpp"
#include "4783E0_ApplyAcceleration.hpp"
#include "4787F0_ApplyBoost.hpp"
#include "480650_GetDecelerationFactor.hpp"

// SWE1R Static Addresses
// [0x4ADC48] = 0.00
// [0x4ADC50] = 1.00
// [0x4ADC9C] = 2.00
// [0x4ADD68] = 0.996666
// [0x4ADD6C] = 0.80
// [0x4ADD70] = 0.45
// [0x4ADD74] = -2.00

void CalculateTraction(PodEngineData *PodEngine, float SpeedTotal, vec3::Vector3 *pEngineFwdVec);