#pragma once
#include <vector>
#include "StateMachine.h"
class GunStateBase;

enum class State
{
	Idle = 0,
	Shooting = 1,
	Reloading = 2
};

class Gun {

private:

	int m_bullets;
	int m_capacity;


	float m_shoot_timer;
	float m_reload_timer;

	float m_count = 0;

	StateMachine<Gun, GunStateBase> SM = StateMachine<Gun, GunStateBase>(this);
	


	

public:
	
	Gun(int _capacity, float _shoot_timer_s, float _reload_timer_s);


	std::vector<GunStateBase*> GetStates() const { return SM.GetStates(); }

	State GetCurrentState() const { return static_cast<State>(SM.GetCurrentStateIndex()); };

	void UseBullet() { m_bullets--; }
	int GetBullets() const { return m_bullets; }
	int GetCapacity() const { return m_capacity; }
	bool CanShoot() const { return m_bullets > 0; }
	bool CanReload() const { return m_bullets < m_capacity; }
	void SetState(State _newState);
	void Update(float _deltaTime);
	void Reload();
	void Shoot();

};
