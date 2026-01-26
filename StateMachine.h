#pragma once
#include <vector>


template<typename T, typename Component>
class StateMachine
{
private:

	int m_currentStateIndex = 0;
	std::vector<Component*> m_state;
	

public:
	StateMachine<T>() {}
};

