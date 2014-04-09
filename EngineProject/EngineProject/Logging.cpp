////////////////////////////////////////////////////////////////////////////////
// Filename: Logging.cpp
////////////////////////////////////////////////////////////////////////////////
#include "Logging.h"


Logging::Logging()
{
}

Logging::Logging(const Logging& other)
{
}

Logging::~Logging()
{
}

void Logging::Log(char input[])
{
	string Text;
	ifstream m_input ("Engine_Log.txt");
	if (m_input.is_open())
	{
		string line;
		while (getline(m_input,line))
		{
			Text += line + '\n';
		}
		m_input.close();
	}

	ofstream m_output ("Engine_Log.txt");
	if (m_output.is_open())
	{
		m_output << Text << input << '\n';
		m_output.close();
	}
}
