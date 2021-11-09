#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>
#include<sstream>
#include"Globals.h"

using namespace std;

namespace sdds{
	class Book
	{
		string m_author;
		string m_title;
		string m_publicationCountry;
		size_t m_publicationYear;
		double m_bookPrice;
		string m_summary;

	public:

		template<typename T>
		void fixSpelling(T& spellChecker){
			spellChecker(m_summary);
		}

		const string& title() const;
		const string& country() const;
		const size_t& year() const;
		double& price();

		Book(const string& strBook);
		Book(){};
		
		friend ostream & operator << (ostream &out, const Book &book_obj);
	};
}