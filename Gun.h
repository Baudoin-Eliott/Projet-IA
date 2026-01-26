#pragma once
#include <vector>

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

	State m_currentState = State::Idle;
	std::vector<GunStateBase*> m_Gunstates;



	

public:
	
	Gun(int _capacity, float _shoot_timer_s, float _reload_timer_s);

	State GetCurrentState() const { return m_currentState; }


	std::vector<GunStateBase*> GetStates() { return m_Gunstates; }
	void UseBullet() { m_bullets--; }
	int GetBullets() { return m_bullets; }
	int GetCapacity() { return m_capacity; }
	bool CanShoot() const { return m_bullets > 0; }
	bool CanReload() const { return m_bullets < m_capacity; }
	void SetState(State _newState);
	void Update(float _deltaTime);
	void Reload();
	void Shoot();

};
