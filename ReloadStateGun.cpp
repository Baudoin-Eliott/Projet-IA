#include "ReloadStateGun.h"

#include <windows.h>  
void gotoxy(int x, int y)
{
	COORD coordinate;
	coordinate.X = x;
	coordinate.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}


void ReloadStateGun::Start(Gun* _gun)
{
	system("cls");
	std::cout << "State : Reloading | Ammo : " << _gun->GetBullets() << "/" << _gun->GetCapacity() << " | Progress : " << m_count << "s/" << m_timer << std::endl;
}

void ReloadStateGun::Update(Gun* _gun, float _deltaTime)
{
	m_count += _deltaTime;
	gotoxy(45, 0);
	std::cout << m_count << "s/" << m_timer;
	std::cout << std::endl;

	if (m_count > m_timer)
	{
		_gun->Reload();
		_gun->SetState(State::Idle);
		m_count = 0;
	}
}

bool ReloadStateGun::CanTransitionFrom(Gun* _gun, State _currentState)
{
	return (_gun->CanReload() && _currentState == State::Idle);
}
