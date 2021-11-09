#include "SpellChecker.h"

using namespace sdds;

SpellChecker::SpellChecker(const char* filename){

    for (int i = 0; i < 6; i++)
    {
        m_numReplaced[i] = 0;
    }

    string line;
    ifstream fs;
    fs.open(filename);

    if (!fs.is_open())
    {
        throw("Bad file name!");
    }

    //file opened successfully
    int i = 0;
    while (getline(fs, line))
    {
        if (line == "") 
            continue;
            
        stringstream stream_obj(line);

        string badWord, goodWord;

        getline(stream_obj, badWord, ' ');
        remove_space(badWord);
        m_badWords[i] = badWord;

        getline(stream_obj, goodWord, '\n');
        remove_space(goodWord);
        m_goodWords[i] = goodWord;

        i++;
    }

}

void SpellChecker::operator()(string& text){
    for (int i = 0; i < text.length(); i++)
    {
        for(int j = 0; j < 6; j++){
            int found = text.find(m_badWords[j]);
            while(found != string::npos){
                text = text.replace(found, m_badWords[j].length(), m_goodWords[j]);
                m_numReplaced[j]++;

                found = text.find(m_badWords[j]);
            }
        }
    }
}

void SpellChecker::showStatistics(std::ostream& out) const
{
    cout << "Spellchecker Statistics" << endl
        << setw(15) << m_badWords[0] << ": " << m_numReplaced[0] << " replacements" << endl
        << setw(15) << m_badWords[1] << ": " << m_numReplaced[1] << " replacements" << endl
        << setw(15) << m_badWords[2] << ": " << m_numReplaced[2] << " replacements" << endl
        << setw(15) << m_badWords[3] << ": " << m_numReplaced[3] << " replacements" << endl
        << setw(15) << m_badWords[4] << ": " << m_numReplaced[4] << " replacements" << endl
        << setw(15) << m_badWords[5] << ": " << m_numReplaced[5] << " replacements" << endl;
}