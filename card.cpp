#include <iostream>
using namespace std;
#include "card.h"
#include "pattern.h"

void card::init(int _m, element el, element* tab)
{
	m = _m;
	t = new element[m * m];
	if (tab)
	{
		for (int i = 0; i < m * m; i++)
		{
			t[i] = tab[i];
		}
		return;
	}
	for (int i = 0; i < m * m; i++)
	{
		t[i] = el;
	}
}

card::card(int m, element el)
{
	init(m, el);
}

card::card(const card& k) : t(nullptr), m(0)
{
	m = k.size();
	t = new element[m * m];
	for (int i = 0; i < m * m; i++)
	{
		t[i] = k.t[i];
	}
}

card& card::operator=(const card& c)
{
	if (this == &c)
	{
		return *this;
	}
	delete[] t;
	init(c.m, element(), c.t);
	/*m = 0;
	if (c.t)
	{
		m = c.m;
		t = new element[m * m];
		for (int i = 0; i < m * m; i++)
		{
			t[i] = c.t[i];
		}
	}*/
	return *this;
}

int card::size() const
{
	return m;
}

element card::operator()(int i, int j) const
{
	return t[i * m + j];
}

element& card::operator()(int i, int j)
{
	return t[i * m + j];
}

card& card::operator+=(const pattern& g)
{
	g.paint(*this);
	return *this;
}

void card::egg(element el)
{
	int sx, sy, r;
	sx = sy = m / 2;
	r = min(sx, sy) - 1;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if ((i - sx) * (i - sx) + (j - sy) * (j - sy) > r * r)
				(*this)(i, j) = el;
		}
	}

}

ostream& operator<<(ostream& out, const card& k)
{
	for (int i = 0; i < k.m; i++)
	{
		for (int j = 0; j < k.m; j++)
		{
			out << k(i, j);
		}
		out << endl;
	}
	return out;
}