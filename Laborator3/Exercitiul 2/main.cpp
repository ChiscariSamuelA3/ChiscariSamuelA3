#include "Canvas.h"

int main()
{
	Canvas m1(50, 50);
	bool ok = true;
	int nr;
	while (ok)
	{
		cout << "Introduceti o cifra (1-7) pentru a desena, iar 8 pentru oprire:\n";
		cin >> nr;
		switch (nr)
		{
		case 1:
			m1.DrawCircle(7, 7, 5, 35);
			m1.Print();
			break;
		case 2:
			m1.FillCircle(20, 7, 5, 35);
			m1.Print();
			break;
		case 3:
			m1.DrawRect(2, 15, 12, 30, 35);
			m1.Print();
			break;
		case 4:
			m1.FillRect(15, 15, 25, 30, 35);
			m1.Print();
			break;
		case 5:
			m1.DrawLine(2, 35, 12, 45, 35);
			m1.Print();
			break;
		case 6:
			m1.DrawLine(15, 45, 25, 35, 35);
			m1.Print();
			break;
		case 7:
			m1.Clear();
			cout << "Tabloul este gol\n";
			break;
		case 8:
			ok = false;
			break;
		}
	}

	return 0;
}