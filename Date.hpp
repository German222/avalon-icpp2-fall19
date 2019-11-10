#pragma once

namespace ext
{
	enum class Month
	{
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		Novemver,
		December
	};

	int Month_To_Int(Month month) {



		switch (month)
		{
		case ext::Month::January:

			return 1;
			break;

		case ext::Month::February:

			return 2;
			break;

		case ext::Month::March:

			return 3;
			break;

		case ext::Month::April:

			return 4;
			break;

		case ext::Month::May:

			return 5;
			break;

		case ext::Month::June:

			return 6;
			break;

		case ext::Month::July:

			return 7;
			break;

		case ext::Month::August:

			return 8;
			break;

		case ext::Month::September:

			return 9;
		    break;

		case ext::Month::October:

			return 10;
			break;

		case ext::Month::Novemver:

			return 11;

			break;

		case ext::Month::December:

			return 12;
			break;

		default:

			return (int)"fuck, go back";
			break;
		}
	}

	enum DateFormat
	{
		MonthAsInt,
		MonthAsString
	};

	enum Season
	{
		Winter,
		Spring,
		Summer,
	    Autumn
	};

	struct Date
	{
		int year;
		Month month;
		int day;
    };

	struct TimeDelta
	{
		int delta;
	};

	/*
		Возвращает Юлианскую дату
		https://ru.wikipedia.org/wiki/%D0%AE%D0%BB%D0%B8%D0%B0%D0%BD%D1%81%D0%BA%D0%B0%D1%8F_%D0%B4%D0%B0%D1%82%D0%B0
		раздел "Вычисление номера юлианского дня (JDN) по дате григорианского календаря"
		Тестовые данные					Ожидаемый результат
		1.12.2018					2458454
		1.1.2018					2458120
		1.6.2000					2451697
		21.12.2012					2456283
	*/
	TimeDelta countJND(Date date);

	/*
		Рассчитывает количество дней между двумя датами.
		При реализвации используйте CountJND
	*/
	TimeDelta countDistance(Date from, Date to);

	/*

		Выводит в консоль
	*/
	void print(Date data, DateFormat format = DateFormat::MonthAsInt);
	void print(Month month, DateFormat format = DateFormat::MonthAsInt);
	void print(TimeDelta delta);

	/*
		Возвращает сезон (зима, весна, лето, осень) передаваемой даты
	*/
	Season getSeason(Date date);
	Season getSeason(Month month);

	/*
		Написать перегрузку для следующих логических операторов
	*/
	bool operator == (const Date lhs, const Date rhs);
	bool operator != (const Date lhs, const Date rhs);
	bool operator < (const Date lhs, const Date rhs);
	bool operator <= (const Date lhs, const Date rhs);
	bool operator > (const Date lhs, const Date rhs);
	bool operator >= (const Date lhs, const Date rhs);

	/*
		Написать перегрузку для следующих арифметических операторомв
	*/
	Date operator + (const Date date, const TimeDelta delta);
	Date operator + (const TimeDelta delta, const Date date);
	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs);
	Date operator - (const Date date, const TimeDelta delta);
	Date operator - (const TimeDelta delta, const Date date);
	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs);

	TimeDelta operator * (const TimeDelta delta, int multiplier);
	TimeDelta operator * (int multiplier, const TimeDelta delta);
	TimeDelta operator / (const TimeDelta delta, int multiplier);
	TimeDelta operator / (int multiplier, const TimeDelta delta);




	TimeDelta countJND(Date date)
	{
		int a = (14 - Month_To_Int(date.month)) / 12;
		int y = date.year + 4800 - a;
     	int m = Month_To_Int(date.month) + 12 * a - 3;
		int ans = (date.day + ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32045);
		return TimeDelta{ ans };
	}

	TimeDelta countDistance(Date from, Date to)
	{
		TimeDelta ans = countJND(to) - countJND(from);
		return ans;
	}

	void print(Date data, DateFormat format = DateFormat::MonthAsInt)
	{
		cout << data.day << "." << Month_To_Int(data.month) << "." << data.year << endl;
	}

	void print(Month month, DateFormat format = DateFormat::MonthAsInt)
	{
		print(month, DateFormat::MonthAsInt);
		cout << endl;
	}

	void print(TimeDelta delta)
	{
		cout << delta.delta<<endl;
	}

	Season getSeason(Date date)
	{
		switch (date.month)
		{
		case ext::Month::January:
		case ext::Month::February:
		case ext::Month::December:

			return Season::Winter;

			break;

		case ext::Month::March:
		case ext::Month::April:
		case ext::Month::May:

			return Season::Spring;

		    break;

		case ext::Month::June:
		case ext::Month::July:
		case ext::Month::August:

			return Season::Summer;

			break;

		case ext::Month::October:
		case ext::Month::Novemver:
		case ext::Month::September:

			return Season::Autumn;

			break;

		default:

			break;
		}
	}

	Season getSeason(Month month)
	{
		switch (static_cast<int>(month)) {

		case 1:
		case 2:
		case 12:

			return Season::Winter;

			break;

		case 3:
		case 4:
		case 5:

			return Season::Spring;

			break;

		case 6:
		case 7:
		case 8:

			return Season::Summer;

			break;

		case 9:
		case 10:
		case 11:

			return Season::Autumn;

			break;
		}
	}



	bool operator == (const Date lhs, const Date rhs)
	{
		if (lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator != (const Date lhs, const Date rhs)
	{
		if (lhs.day != rhs.day || lhs.month != rhs.month || lhs.year != rhs.year)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator < (const Date lhs, const Date rhs)
	{
		if (lhs.year < rhs.year)
			return true;


		else return false;
	}

	bool operator > (const Date lhs, const Date rhs)
	{
		if (lhs.year > rhs.year)
			return true;

		else return false;
	}

	bool operator <= (const Date lhs, const Date rhs)
	{
		if (lhs.year <= rhs.year)
			return true;

		else return false;
	}

	bool operator >= (const Date lhs, const Date rhs)
	{
		if (lhs.year >= rhs.year)
			return true;


		else return false;
	}



	Date operator + (const Date date, const TimeDelta delta)
	{
		Date temp;
		temp.day = date.day + delta.delta;
		return temp;

	}

	Date operator + (const TimeDelta delta, const Date date)
	{
		Date temp;
		temp.day = date.day + delta.delta;
		return temp;
	}

	TimeDelta operator + (const TimeDelta lhs, const TimeDelta rhs)
	{
		TimeDelta temp;
		temp.delta = lhs.delta + rhs.delta;
		return  temp;
	}

	Date operator - (const Date date, const TimeDelta delta)
	{
		Date temp;
		temp.day = date.day - delta.delta;
		return temp;
	}

	Date operator - (const TimeDelta delta, const Date date)
	{
		Date temp;
		temp.day = date.day - delta.delta;
		return temp;
	}

	TimeDelta operator - (const TimeDelta lhs, const TimeDelta rhs)
	{
		TimeDelta temp;
		temp.delta = lhs.delta - rhs.delta;
		return  temp;
	}



	TimeDelta operator * (const TimeDelta delta, int multiplier)
	{
		TimeDelta temp;
		temp.delta = delta.delta * multiplier;
		return temp;
	}

	TimeDelta operator * (int multiplier, const TimeDelta delta)
	{
		TimeDelta temp;
		temp.delta = multiplier * delta.delta;
		return temp;
	}

	TimeDelta operator / (const TimeDelta delta, int multiplier)
	{
		TimeDelta temp;
		temp.delta = delta.delta / multiplier;
		return temp;
	}

	TimeDelta operator / (int multiplier, const TimeDelta delta)
	{
		TimeDelta temp;
		temp.delta = delta.delta / multiplier;
		return temp;
	}
}
