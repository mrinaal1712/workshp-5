#include"Globals.h"
using namespace std;



int get_start_space_index(string temp)
{
	for (int i = 0; i < temp.length(); i++) {
		if (temp[i] != ' ') {
			return i - 1;
		}
	}
}

int get_end_space_index(string temp)
{
	for (int i = temp.length() - 1; i > 0; i--) {
		if (temp[i] != ' ') {
			return i + 1;
		}
	}
}
void remove_space(string &temp)
{
	int temp_index;
	temp_index = get_start_space_index(temp);
	if (temp_index != -1)
	{
		temp.erase(0, temp_index+1);
	}
	temp_index = get_end_space_index(temp);
	if (temp_index != temp.length())
	{
		temp.erase(temp_index-1);
	}
}

