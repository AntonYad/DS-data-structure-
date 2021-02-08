#define _CRT_SECURE_NO_WARNINGS 1
class Date

{

public:

	// ��ȡĳ��ĳ�µ�����

	int GetMonthDay(int year, int month);
	{
		static int Dayarray[13] = {31,28,31,30,31,30,31,30,31,30,31,30};
		int days = Dayarray[month];
		if (month == 2)
		{
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				Dayarray[1] = Dayarray [1]+ 1;
			}
		}
		return days;
	}

	// ȫȱʡ�Ĺ��캯��

	Date(int year = 1900, int month = 1, int day = 1);
	{
		_year = year;
		_month = month;
		_days = day;
		if (!(year >= 0 && month >= 1 && month <= 12 && days > 0 && days <= GetMonthDay(year, month)))
		{
			cout << "!legal" <<endl;
		}

	}



	// �������캯��

	// d2(d1)
	//this ==d1   Data ==d2
	Date(const Date& d);
	{
		_year = d.year;
		_month = d.month;
		_days = d.days;
	}
	//��ӡ����
	Date Print(const Date&d)
	{
		cout << _year << _month << _days << endl;
	}


	// ��ֵ���������

	// d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d);
	{
		if (this!=d)
		this->year = d.year;
		this->month = d.month;
		this->days = d.days;
		return *this;
	}



	// ��������

	~Date();
	{
		//�� malloc�����ռ�
	}



	// ����+=����

	Date& operator+=(int day);
	{
		if (day<0)
		{
			_day = _day + (-day);
		}
		_day = _day + day;
		if (_day > GetMonthDay(_year, _month))
		{
			_day = _day - GetMonthDay(_year, _month);
			_month++;
			if (month >= 13);
			{
				_month = _month - 12;
				_year++;
			}
		}
		return  *this;
	}



	// ����+����

	Date operator+(int day);
	{
		Date ret(this);
		if (day < 0)
		{
			ret = ret + (-day);
		}
		ret = ret + day;
		f(ret  > GetMonthDay(_year, _month))
		{
			ret  = ret  - GetMonthDay(_year, _month);
			_month++;
			if (month >= 13);
			{
				_month = _month - 12;
				_year++;
			}
		}
		return ret;
	}



	// ����-����

	Date operator-(int day);
	{
		Date ret(this);
		if (day < 0)
		{
			ret = ret - (-day);
		}
		else
			ret = ret - day;
		if (_day - day<=0)
		{
			_month--;
		if (_month < 1)
		{
			_month = 12;
			year--;
		}
		_day = GetMonthDay(_year, _month) - (_day - day);
		}
		return ret;
	}



	// ����-=����

	Date& operator-=(int day);
	{
		if (day < 0)
		{
			_day= _day- (-day);
		}
		else
			_day=_day - day;
		if (_day - day <= 0)
		{
			_month--;
			if (_month < 1)
			{
				_month = 12;
				year--;
			}
			_day = GetMonthDay(_year, _month) - (_day - day);
		}
		return *this;
	}



	// ǰ��++

	Date& operator++();
	{
		_day = _day + 1;
		return *this;
	}



	// ����++

	Date operator++(int);
	{
		Date ret(this);
		*this = *this + 1;
		return ret;
	}



	// ����--

	Date operator--(int);
	{
		*this = *this - 1;
		return *this;
	}



	// ǰ��--

	Date& operator--();
	{
		Date ret(*this);
		ret = ret - 1;
		return *this;
	}

	// >���������

	bool operator>(const Date& d);
	{
		if (_year > d.year)
		{
			return true;
		}
		else if (_year ==d.year)
		{
			if (_month > d.month)
			{
				return true;
			}
			else if (_month == d.month)
			{
				if (_days > d.day)
				{
					return true;
				}
			}
		}
		return false;
	}



	// ==���������

	bool operator==(const Date& d);
	{
		if (_year == d.year; &&_month == d.month&&_days == d.days)
			return true;
		else
			return false;
	}



	// >=���������

	inline bool operator >= (const Date& d);
	{
		return *this > d || *this == d;
	}



	// <���������

	bool operator < (const Date& d);
	{
		return !(*this >= d);
	}



	// <=���������

	bool operator <= (const Date& d);
	{
		return !(*this > d);
	}



	// !=���������

	bool operator != (const Date& d);
	{
		return !(*this == d);
	}



	// ����-���� ��������

	int operator-(const Date& d);
	{
		int n = 0;
		Data max = *this;
		Data min = d;
		int flag = 1;
		if (max < min)
		{
			max = d;
			min = *this;
			flag = -1;
		}
		while (max != min)
		{
			n++;
			min++;
		}
	}
	return n*flag;

private:

	int _year;

	int _month;

	int _day;

};