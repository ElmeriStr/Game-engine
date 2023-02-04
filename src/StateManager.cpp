#include "StateManager.h"

//State manager helpottaa huomattavasti state managerointia Stackin avulla 

Engine::StateManager::StateManager() :m_add(false), m_replace(false),m_remove(false)
{
}

Engine::StateManager::~StateManager()
{
}

void Engine::StateManager::Add(std::unique_ptr<State> toADD, bool replace)
{
	m_add = true;
	m_newState = std::move(toADD);

	m_replace = replace;
}

void Engine::StateManager::PopCurrent()
{
	m_remove = true;
}
//State manager helpottaa funktioiden kutsua ja vaihtoa käyttämällä stackkiä 
//See also here for reference https://www.youtube.com/watch?v=QhIqhen6cmw&list=PLiZZKL9HLmWMF8PlzvZu2WOC9kjs1zzhm&index=4
void Engine::StateManager::ProcessStateChange()
{
	if (m_remove&&(!m_stateStack.empty()))
	{
		m_stateStack.pop();
		if (m_stateStack.empty())
		{
			m_stateStack.top()->Start();
		}
		m_remove = false;
	}
	if (m_add)
	{
		if (m_replace && (!m_stateStack.empty()))
		{
			m_stateStack.pop();
			m_replace = false;
		}
		if (!m_stateStack.empty())
		{
			m_stateStack.top()->Pause();
		}
		m_stateStack.push(std::move(m_newState));
		m_stateStack.top()->Init();
		m_stateStack.top()->Start();
		m_add = false;
	}
}

std::unique_ptr<Engine::State> &Engine::StateManager::GetCurrent()
{
	return m_stateStack.top();
}
