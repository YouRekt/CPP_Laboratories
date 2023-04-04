#include "pattern.h"
#include "card.h"

pattern::pattern(int sx, element el) : sx(sx),el(el)
{
}

void pattern::paint(card& c) const
{
	for (int i = 0; i < c.size(); i++)
	{
		c(sx, i) = el;
	}
}