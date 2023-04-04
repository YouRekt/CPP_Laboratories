#include "history.h"

history::history(const card& c) : num(1)
{
	h[0] = c;
}

void history::write(const card& c)
{
	if (num == n)
	{
		for (int i = 0; i < n - 1; i++)
		{
			h[i] = h[i + 1];
		}
		h[n - 1] = c;
		return;
	}
	h[num] = c;
	num++;
}

card history::undo()
{
	if (num == 1)
		return h[0];
	num--;
	return h[num-1];
}
