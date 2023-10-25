#pragma once
#include "Timing.hpp"
#include "PodEngineData.hpp"

enum PodRaceDataFlags {
	PODRACE_HAS_CONTROL = (1<<0),
	PODRACE_FINISHED = (1<<1)
};

struct PodRaceData {
	char ControlString;
	int Flags;
	int Flags0064;
	float StatAntiSkid;
	float StatTurnResponse;
	float StatMaxTurnRate;
	float StatAcceleration;
	float StatMaxSpeed;
	float StatAirBrakeInv;
	float StatDecelInv;
	float StatBoostThrust;
	float StatHeatRate;
	float StatCoolRate;
	float StatHoverHeight;
	float StatRepairRate;
	float StatBumpMass;
	float StatDamageImmunity;
	float StatBaseHoverHeight;
	float StatISectRadius;
	float Pitch;
	float Speed;
	float AccelerationFactor;
	float BoostFactor;
	PodEngineData *PodEngineData;
};