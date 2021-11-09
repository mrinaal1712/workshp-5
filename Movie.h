#pragma once
#include"Globals.h"
#include <ostream>

namespace sdds{
	class Movie
	{
		std::string m_title;
		size_t m_publicationYear;
		std::string m_description;
	public:
		
		const std::string& title() const;

		template<typename T>
		void fixSpelling(T& spellChecker){
 		   spellChecker(this->m_description);
		}

		Movie(const std::string& strMovie);
		Movie(){};

		friend ostream & operator << (ostream &out, const Movie &movie_obj);
	};
}

