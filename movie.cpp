#include "Movie.h"

using namespace sdds;

Movie::Movie(const std::string& strMovie){
    string movieString, currentToken;

    movieString = strMovie;
    int index = movieString.find(",");
    currentToken = movieString.substr(0, index);
    remove_space(currentToken);
    m_title = currentToken;
    movieString.erase(0, index + 1);


    index = movieString.find(",");
    currentToken = movieString.substr(0, index);
    remove_space(currentToken);
    m_publicationYear = stoi(currentToken);
    movieString.erase(0, index + 1);


    currentToken = movieString;
    remove_space(currentToken);
    m_description = currentToken;

}

const std::string& Movie::title() const{
    return m_title;
}

namespace sdds{
    ostream & operator << (ostream &out, const Movie &movie_obj)
    {
        //TITLE | YEAR | DESCRIPTION

        out << setw(40) << movie_obj.m_title << " | ";
        out << setw(4) << movie_obj.m_publicationYear << " | " << movie_obj.m_description << endl;
        return out;
    }
}