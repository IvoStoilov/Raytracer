#include "ProfileManager.h"

ProfileManager* ProfileManager::s_Instance = nullptr;

void ProfileInfo::UpdateInfo(uint64_t time)
{
	if (time < m_MinTime || m_CallCount == 0)
		m_MinTime = time;

	if (time > m_MaxTime)
		m_MaxTime = time;

	m_AvgTime = (m_AvgTime * m_CallCount + time) / (m_CallCount + 1);
	m_CallCount++;
}

void ProfileManager::Initialize()
{
	if (s_Instance == nullptr)
		s_Instance = new ProfileManager();
}

bool ProfileManager::UpdateOrRegister(std::string name, long long time /*= 0ull*/)
{
	auto it = m_Repo.find(name);
	if (it == m_Repo.end())
	{
		ProfileInfo info;
		info.UpdateInfo(time);
		m_Repo[name] = info;
		return false;
	}
	it->second.UpdateInfo(time);
	return true;
}

void ProfileManager::GetInfo(const char* name) const
{
	GetInfo(std::string(name));
}

void ProfileManager::GetInfo(std::string& name) const
{
	auto it = m_Repo.find(name);
	if (it == m_Repo.end())
		printf("No data in Repository.\n");
	else
	{
		printf("%s\n", it->first.c_str());
		it->second.Print();
	}
}
