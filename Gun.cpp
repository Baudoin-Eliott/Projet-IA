
#include "Gun.h"
#include <iostream>
#include "GunStateBase.h"
#include "IdleStateGun.h"
#include "ReloadStateGun.h"
#include "ShootStateGun.h"

void Gun::SetState(State _newState)
{
	SM.SetState(static_cast<int>(_newState));
}

void Gun::Update(float _deltaTime)
{
	SM.Update(_deltaTime);
}

Gun::Gun(int _capacity, float _shoot_timer_s, float _reload_timer_s) : m_capacity(_capacity), m_bullets(_capacity), m_shoot_timer(_shoot_timer_s * 1000), m_reload_timer(_reload_timer_s * 1000) 
{
	SM.AddState(new IdleStateGun);
	SM.AddState(new ShootStateGun);
	SM.AddState(new ReloadStateGun);


}



void Gun::Reload()
{
	m_bullets = m_capacity;
	std::cout << "Ok, ammo :" << m_bullets << "/" << m_capacity << std::endl;
}

void Gun::Shoot()
{
	std::cout << "Bang ! ammo :" << m_bullets << "/" << m_capacity << std::endl;
}
