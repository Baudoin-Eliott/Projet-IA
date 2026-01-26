#pragma once
#include "GunStateBase.h"
class IdleStateGun : public GunStateBase
{



public:
	// Hérité via GunStateBase
	void Start(Gun* _gun) override;
	void Update(Gun* _gun, float _deltaTime) override;
	bool CanTransitionFrom(Gun* _gun, State _currentState) override;
};

