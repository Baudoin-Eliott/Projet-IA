#pragma once
#include "Gun.h"
#include <iostream>

class GunStateBase
{

public:

	virtual void Start(Gun* _gun) = 0;
	virtual void Update(Gun* _gun, float _deltaTime) = 0;
	virtual bool CanTransitionFrom(Gun* _gun, int _currentStateIndex) = 0;
};

