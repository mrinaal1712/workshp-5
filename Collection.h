#pragma once
#include"Globals.h"
using namespace std;

namespace sdds{
	template <typename T>
	class Collection
	{
		typedef void (*AddCallback)(const Collection<T>&, const T&);

		string m_name;
		size_t m_size;
		T *m_items = nullptr;

		AddCallback m_addCallback = nullptr;

	public:
		Collection(const std::string& name){
			m_name = name;
			m_size = 0;
		}
		~Collection(){
    		delete[] m_items;
		}

		const std::string& name() const{
			return m_name;
		}

		size_t size() const{
			return m_size;
		}

		void setObserver(AddCallback newCallback){
			m_addCallback = newCallback;
		}


		Collection<T>& operator+=(const T& item){
			for(int i = 0; i < m_size; i++){
				if(m_items[i].title() == item.title()){
					return *this;
				}
			}

			T* newItems = new T[m_size + 1];
			newItems[m_size] = item;

			for(int i = 0; i < m_size; i++){
				newItems[i] = m_items[i];
			}

			if(m_items)
				delete[] m_items;
			
			m_items = newItems;
			m_size++;

			if(m_addCallback)
				m_addCallback(*this, item);

			return *this;
		};

		T& operator[](size_t idx) const{
			if (idx >= m_size)
			{
				throw std::out_of_range("Bad Index[" + to_string(idx) + "] collection has [" + to_string(m_size) + "] items");
			}
			else
			{
				return m_items[idx];
			}
		};
		T* operator[](const std::string& title) const{
			for(int i = 0; i < m_size; i++){
				if(m_items[i].title() == title){
					return &m_items[i];
				}
			}

			return nullptr;
		}

	};
}

template<typename T>
ostream & operator << (ostream &out, sdds::Collection<T> &collection){
    for(int i = 0; i < collection.size(); i++){
        out << collection[i];
    }

	return out;
}