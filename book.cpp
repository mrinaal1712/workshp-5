#include "Book.h"

using namespace sdds;

const string& Book::title() const
{
	return m_title;
}

const string& Book::country() const
{
	return m_publicationCountry;
}

const size_t& Book::year() const
{
    return m_publicationYear;
}

double& Book::price()
{
    return m_bookPrice;
}

Book::Book(const string& strBook){
    string current_token;
    string book_string = strBook;

    int index = book_string.find(",");
    current_token = book_string.substr(0, index);
    remove_space(current_token);
    m_author = current_token;
    book_string.erase(0, index + 1);


    index = book_string.find(",");
    current_token = book_string.substr(0, index);
    remove_space(current_token);
    m_title = current_token;
    book_string.erase(0, index + 1);


    index = book_string.find(",");
    current_token = book_string.substr(0, index);
    remove_space(current_token);
    m_publicationCountry = current_token;
    book_string.erase(0, index + 1);


    index = book_string.find(",");
    current_token = book_string.substr(0, index);
    remove_space(current_token);
    m_bookPrice = stod(current_token);
    book_string.erase(0, index + 1);


    index = book_string.find(",");
    current_token = book_string.substr(0, index);
    remove_space(current_token);
    m_publicationYear = stoi(current_token);
    book_string.erase(0, index + 1);

    current_token = book_string;
    remove_space(current_token);
    m_summary = book_string;

}

namespace sdds{
    ostream & operator << (ostream &out, const Book &book_obj)
    {
        //AUTHOR | TITLE | COUNTRY | YEAR | PRICE | DESCRIPTION

        out << setw(20) << book_obj.m_author << " | ";
        out << setw(22) << book_obj.m_title << " | ";
        out << setw(5) << book_obj.m_publicationCountry << " | " << setw(4) << book_obj.m_publicationYear << " | " << setw(6) << book_obj.m_bookPrice << " | " << book_obj.m_summary << endl;
        return out;
    }
}