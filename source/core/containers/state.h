#pragma once
#include <vector>

template <class T>
class State
{
protected:
	T m_Value;
	std::vector<State*> m_Children;

public:
	State() :
		m_Value()
	{}

	State(const T& value) :
		m_Value(value)
	{}

	State(const State& state)
	{
		Duplicate(state);
	}

	void Duplicate(const State<T> original)
	{
		m_Value = original.m_Value;
		m_Children = original.m_Children;
	}

	inline std::vector<State*>& GetChildren() { return m_Children; }
	inline T& GetValue() { return m_Value; }
	inline const T& GetValue() const { return m_Value; }
};