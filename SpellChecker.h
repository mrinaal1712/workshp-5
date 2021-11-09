#pragma once
#include"Globals.h"

using namespace std;

namespace sdds{
	class SpellChecker
	{
		string m_badWords[6];
		string m_goodWords[6];
		int m_numReplaced[6];
	public:
		void operator()(string& text);
		
		void showStatistics(std::ostream& out) const;

		SpellChecker(const char* filename);
	};
}