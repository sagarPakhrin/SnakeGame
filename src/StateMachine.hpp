#pragma once
#include <memory>
#include <stack>
#include "State.hpp"


namespace Sagar
{
		typedef std::unique_ptr<State> StateRef;

		class StateMachine
		{
				public:
						StateMachine(){}
						~StateMachine(){}

						void AddState(StateRef newState, bool isReplacing=false);
						void RemoveState();
						void ProcessStateChanges();
						StateRef &GetActiveState();

				private:
						std::stack<StateRef> _states;
						StateRef _newState;
						bool _isRemoving;
						bool _isAdding;
						bool _isReplacing;
		};
}
