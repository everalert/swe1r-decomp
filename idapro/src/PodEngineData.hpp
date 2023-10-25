#pragma once
#include "Timing.hpp"
#include "Vector3.hpp"
#include "PodRaceData.hpp"


enum PodEngineDataFlags0060 {
	PODENGINE_IN_AUTOPILOT = (1<<7),
	PODENGINE_IS_BRAKING = (1<<9),
	PODENGINE_RESPAWN_INVULN = (1<<13),
	PODENGINE_DEAD = (1<<14),
	PODENGINE_IS_BOOSTING = (1<<23),
	PODENGINE_TERRAIN_ZON = (1<<25),
	PODENGINE_TERRAIN_ZON_EXIT = (1<<26)
};

enum PodEngineDataFlags0064 {
	PODENGINE_TERRAIN_SWAMP = (1<<0),
	PODENGINE_IS_OFFTHROTTLE = (1<<2),
	PODENGINE_IS_SLIDING = (1<<3),
	PODENGINE_IS_MANUALSLIDING = (1<<4), // actually not manualsliding but something to do with sliding for sure
	PODENGINE_TERRAIN_SIDE = (1<<5),
	PODENGINE_TERRAIN_NOROLL = (1<<10),
	PODENGINE_RACE_COMPLETE = (1<<25)
};

struct PodEngineData {
	vec3::Vector3 SpawnPosition;
	vec3::Vector3 Position;
	int Flags0060;
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
	vec3::Vector3 Velocity;
	vec3::Vector3 SlopeSpeed;
	vec3::Vector3 CollisionSpeed;
	vec3::Vector3 OpponentCollisionSpeed;
	float StatMultiplierMAYBE;
	float TerrainSpeedOffset;
	float TerrainSpeedFactor;
	float TractionFactorIce;
	float TractionFactorSlide;
	float PitchInputMAYBE;
	PodRaceData *PodRaceData;
};