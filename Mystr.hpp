//#include <iostream>
class Mystr
{
	char *str;
	int len_size;
	int Mystrlen(const char *str)
	{
		int cou = 0;
		while (str[cou] != '\0')
			++cou;
		return cou;
	}
	public:
		Mystr()
		{
			this->str = nullptr;
			len_size = 0;
		}
		Mystr(const char *str)
		{
			len_size = Mystrlen(str);
			this->str = new char[len_size + 1];
			for(int i = 0; i < len_size; ++i)
			{
				this->str[i] = str[i];
			}
			this->str[len_size] = '\0';
		}
		~Mystr()
		{
			delete [] this->str;
			str = nullptr;
		}
		Mystr(const Mystr &other) //constructor of copy
		{
			len_size = Mystrlen(other.str);
			this->str = new char[len_size + 1];
			for(int i = 0; i < len_size; ++i)
			{
				this->str[i] = other.str[i];
			}
			this->str[len_size] = '\0';
		}
		Mystr & operator = (const Mystr &other) //operation =
		{
			if (this->str != nullptr)
				delete [] this->str;
			len_size = Mystrlen(other.str);
			this->str = new char[len_size + 1];
			for(int i = 0; i < len_size; ++i)
			{
				this->str[i] = other.str[i];
			}
			this->str[len_size] = '\0';
			return *this;
		}
		Mystr operator + (const Mystr &other)
		{
			Mystr temp;
			int len_size1 = Mystrlen(other.str);
			int len_size2 = Mystrlen(this->str);
			temp.len_size = len_size1 + len_size2;
			temp.str = new char[temp.len_size + 1];
			for(int i = 0; i < len_size2; ++i)
			{
				temp.str[i] = this->str[i];
			}
			for(int i = len_size2;i < temp.len_size;++i)
			{
				temp.str[i] = other.str[i-len_size2];
			}
			temp.str[temp.len_size] = '\0';
			
			return temp;
		}
		Mystr operator * (unsigned x) { // string multiply
                Mystr temp;

                temp.len_size = len_size * x;
                temp.str = new char[temp.len_size + 1];

                for (int i = 0; i < x; i++) {
                        for (int j = 0; j < len_size; ++j)
                                temp.str[j] = str[j];
                }

                temp.str[temp.len_size] = '\0';

                return temp;
        	}
		void operator *= (unsigned x) { // string multiply
                	char* temp = str;
	                unsigned temp_len = len_size * x;
                	str = new char[len_size + 1];
        	        for (unsigned i = 0; i < x; i++) {
                	        for (unsigned j = 0; j < temp_len; ++j)
                        	        str[j] = temp[j];
	                }
        	        str[len_size] = '\0';
			//change!
        	}
		bool operator == (const Mystr &other)
		{
			if (this->len_size != other.len_size)
				return false;
			else
			{
				for (int i = 0;i < this->len_size;++i)
					if (this->str[i]!=other.str[i])
						return false;
				return true;
			}
		}
		bool operator != (const Mystr &other)
		{
			return !(this->operator == (other));
		}
		int Mystrlen(const Mystr &str) //вывод длины строки
		{
			return len_size;
		}

		char & operator[](int index)
		{
			return this->str[index];
		}
		Mystr(Mystr &&other) //конструктор перемещения
		{
			this->len_size = other.len_size;
			this->str = other.str;
			other.str = nullptr;
			this->str = new char[len_size + 1];

			for(unsigned i = 0; i < len_size; ++i)
			{
				this->str[i] = other.str[i];
			}
			this->str[len_size] = '\0';
		}
	//	friend void Print();
	
        friend std::ostream& operator << (std::ostream& o, const Mystr& right); // overload <<
        friend std::istream& operator >> (std::istream& i, Mystr& right); // overload >>


};
	std::ostream & operator << (std::ostream& o, const Mystr& right)
	{
		o << right.str;
		return o;
	}
	std::istream& operator >> (std::istream& i, Mystr& right) { // overload >>
	        char* temp = new char[10000];
		i >> temp;
	        right = temp;
        	return i;
	}


