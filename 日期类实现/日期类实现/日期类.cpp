#define _CRT_SECURE_NO_WARNINGS 1
class Date

{

public:

	// 获取某年某月的天数

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

	// 全缺省的构造函数

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



	// 拷贝构造函数

	// d2(d1)
	//this ==d1   Data ==d2
	Date(const Date& d);
	{
		_year = d.year;
		_month = d.month;
		_days = d.days;
	}
	//打印日期
	Date Print(const Date&d)
	{
		cout << _year << _month << _days << endl;
	}


	// 赋值运算符重载

	// d2 = d3 -> d2.operator=(&d2, d3)

	Date& operator=(const Date& d);
	{
		if (this!=d)
		this->year = d.year;
		this->month = d.month;
		this->days = d.days;
		return *this;
	}



	// 析构函数

	~Date();
	{
		//无 malloc开创空间
	}



	// 日期+=天数

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



	// 日期+天数

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



	// 日期-天数

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



	// 日期-=天数

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



	// 前置++

	Date& operator++();
	{
		_day = _day + 1;
		return *this;
	}



	// 后置++

	Date operator++(int);
	{
		Date ret(this);
		*this = *this + 1;
		return ret;
	}



	// 后置--

	Date operator--(int);
	{
		*this = *this - 1;
		return *this;
	}



	// 前置--

	Date& operator--();
	{
		Date ret(*this);
		ret = ret - 1;
		return *this;
	}

	// >运算符重载

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



	// ==运算符重载

	bool operator==(const Date& d);
	{
		if (_year == d.year; &&_month == d.month&&_days == d.days)
			return true;
		else
			return false;
	}



	// >=运算符重载

	inline bool operator >= (const Date& d);
	{
		return *this > d || *this == d;
	}



	// <运算符重载

	bool operator < (const Date& d);
	{
		return !(*this >= d);
	}



	// <=运算符重载

	bool operator <= (const Date& d);
	{
		return !(*this > d);
	}



	// !=运算符重载

	bool operator != (const Date& d);
	{
		return !(*this == d);
	}



	// 日期-日期 返回天数

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