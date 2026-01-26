#pragma once
#include "GunStateBase.h"


class ReloadStateGun : public GunStateBase
{
private:
	float m_timer = 1500.f;
	float m_count = 0;


public:

	// Hérité via GunStateBase
	void Start(Gun* _gun) override;
	void Update(Gun* _gun, float _deltaTime) override;
	bool CanTransitionFrom(Gun* _gun, State _currentState) override;
};

