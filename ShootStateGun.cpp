#include "ShootStateGun.h"

#include <windows.h>  
void gotoxy1(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}


void ShootStateGun::Start(Gun* _gun)
{
	_gun->UseBullet();
	system("cls");
	std::cout << "State : Shoot | Ammo : " << _gun->GetBullets() << "/" << _gun->GetCapacity() << " | Progress : " << m_count << "s/" << m_timer << std::endl;

}

void ShootStateGun::Update(Gun* _gun, float _deltaTime)
{
	m_count += _deltaTime;
	gotoxy1(41, 0);
	std::cout << m_count << "s/" << m_timer;
	std::cout << std::endl;
	
	if (m_count > m_timer)
	{
		
		_gun->Shoot();
		_gun->SetState(State::Idle);
		m_count = 0;
	}
}

bool ShootStateGun::CanTransitionFrom(Gun* _gun, State _currentState)
{
	return (_gun->CanShoot() && _currentState == State::Idle);
}
