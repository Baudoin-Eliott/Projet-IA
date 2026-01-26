
#include "Gun.h"
#include <iostream>
#include "GunStateBase.h"
#include "IdleStateGun.h"
#include "ReloadStateGun.h"
#include "ShootStateGun.h"

void Gun::Update(float _deltaTime)
{
	m_Gunstates[(int)m_currentState]->Update(this, _deltaTime);
	return;
	
	
	
	switch (m_currentState) {
	case(State::Idle):
		break;
	case(State::Reloading):
		m_count += _deltaTime;
		std::cout << "State : Reloading | Ammo : " << m_bullets << "/" << m_capacity << " | Progress : " << m_count << "s/" << m_reload_timer << std::endl;
		if (m_count >= m_reload_timer) {
			m_count = 0;
			Reload();
		}

		break;
	case(State::Shooting):
		m_count += _deltaTime;
		std::cout << "State : Shooting | Ammo : " << m_bullets << "/" << m_capacity << " | Progress : " << m_count << "s/" << m_shoot_timer << std::endl;

		if (m_count >= m_shoot_timer) {
			m_count = 0;
			Shoot();
		}
		
		break;
	default:
		break;
	}

}

Gun::Gun(int _capacity, float _shoot_timer_s, float _reload_timer_s) : m_capacity(_capacity), m_bullets(_capacity), m_shoot_timer(_shoot_timer_s * 1000), m_reload_timer(_reload_timer_s * 1000) 
{
	m_Gunstates.push_back(new IdleStateGun());
	m_Gunstates.push_back(new ShootStateGun());
	m_Gunstates.push_back(new ReloadStateGun());

}

void Gun::SetState(State _newState)
{
	
		m_currentState = _newState;
		m_Gunstates[(int)m_currentState]->Start(this);
}


void Gun::Reload()
{
	m_bullets = m_capacity;
	m_currentState = State::Idle;
	std::cout << "Ok, ammo :" << m_bullets << "/" << m_capacity << std::endl;
}

void Gun::Shoot()
{
	m_currentState = State::Idle;
	std::cout << "Bang ! ammo :" << m_bullets << "/" << m_capacity << std::endl;
}
