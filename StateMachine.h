#pragma once
#include <vector>
#include <string>

template<typename T, typename Component>
class StateMachine
{
private:

	int m_currentStateIndex = 0;
	std::vector<Component*> m_states;
	T* m_owner = nullptr;


	std::string m_lastError;


public:
	StateMachine(T* _owner) : m_owner(_owner) {}
	~StateMachine() {

		for (Component* comp : m_states) {
			delete comp;
		}

	}



	std::string GetError() const { return m_lastError; }
	void SetError(const std::string& _error) { m_lastError = _error; }
	void ClearError() { m_lastError.clear(); }




	std::vector<Component*> GetStates() const { return m_states; }


	void AddState(Component* _state) {
		m_states.push_back(_state);
	}


	int GetCurrentStateIndex() const { return m_currentStateIndex; }

	void SetState(int _newStateIndex) {
		if (CanTransitionTo(_newStateIndex)) {
			if (m_states[_newStateIndex]) {
				m_states[_newStateIndex]->Start(m_owner);
				m_currentStateIndex = _newStateIndex;
			}
		}

	}

	void Update(float _deltaTime) {
		if (m_currentStateIndex < m_states.size() && m_states[m_currentStateIndex])
			m_states[m_currentStateIndex]->Update(m_owner, _deltaTime);
	}

	bool CanTransitionTo(int _newStateIndex) {
		ClearError();
		if (_newStateIndex >= 0 && _newStateIndex < m_states.size()) {
			if (!m_states[_newStateIndex]->CanTransitionFrom(m_owner, m_currentStateIndex)) {
				SetError("Transition not allowed from current state");
				return false;
			}
			return true;
		}
		SetError("Invalid state index");
		return false;
	}

	bool TrySetState(int _newStateIndex) {
		if (CanTransitionTo(_newStateIndex)) {
			SetState(_newStateIndex);
			return true;
		}
		return false;
	}


};

