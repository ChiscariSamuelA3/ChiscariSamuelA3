#include "Canvas.h"

Canvas::Canvas(int w, int h)
{
	mat[h][w];
	width = w;
	height = h;

	for (int i = 0; i <= h; i++)
		for (int j = 0; j <= w; j++)
			mat[i][j] = 32;
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	if ((x - ray<0 || x + ray>width) || (y - ray<0 || y + ray>height))
		cout << "Coordonate incorecte pentru desenarea cercului." << '\n';
	else
	{
		for (int i = x - ray; i <= x + ray; i++)
			for (int j = y - ray; j <= y + ray; j++)
				if ((i - x) * (i - x) + (j - y) * (j - y) == ray * ray)
					mat[j][i] = ch;
	}
}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	if ((x - ray<0 || x + ray>width) || (y - ray<0 || y + ray>height))
		cout << "Coordonate incorecte pentru desenarea cercului." << '\n';
	else
	{
		for (int i = x - ray; i <= x + ray; i++)
			for (int j = y - ray; j <= y + ray; j++)
				if ((i - x) * (i - x) + (j - y) * (j - y) <= ray * ray)
					mat[j][i] = ch;
	}
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || left > width || top < 0 || top > height || right < 0 || right > width || bottom < 0 || bottom > height)
		cout << "Coordonate incorecte pentru desenarea paralelogramului." << '\n';
	else
	{
		if (left > right)
		{
			swap(left, right);
		}
		if (top > bottom)
		{
			swap(top, bottom);
		}

		for (int i = left; i <= right; i++)
			mat[top][i] = ch;
		for (int i = top; i <= bottom; i++)
			mat[i][right] = ch;
		for (int i = right; i >= left; i--)
			mat[bottom][i] = ch;
		for (int i = bottom; i >= top; i--)
			mat[i][left] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	if (left < 0 || left > width || top < 0 || top > height || right < 0 || right > width || bottom < 0 || bottom > height)
		cout << "Coordonate incorecte pentru desenarea paralelogramului." << '\n';
	else
	{
		if (left > right)
		{
			swap(left, right);
		}
		if (top > bottom)
		{
			swap(top, bottom);
		}

		for (int i = top; i <= bottom; i++)
			for (int j = left; j <= right; j++)
				mat[i][j] = ch;
	}
}

void Canvas::SetPoint(int x, int y, char ch)
{
	mat[y][x] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int xDr, yDr, xSt, ySt, err, dErr;
	xDr = abs(x2 - x1);
	if (x1 < x2)
		xSt = 1;
	else
		xSt = -1;
	yDr = -abs(y2 - y1);
	if (y1 < y2)
		ySt = 1;
	else
		ySt = -1;
	err = xDr + yDr;
	while (1)
	{
		SetPoint(x1, y1, ch);
		if (x1 == x2 && y1 == y2)
			break;
		dErr = err * 2;
		if (dErr >= yDr)
		{
			err += yDr;
			x1 += xSt;
		}
		if (dErr <= xDr)
		{
			err += xDr;
			y1 += ySt;
		}
	}
}

void Canvas::Print()
{
	for (int i = 0; i <= width; i++)
	{
		for (int j = 0; j <= height; j++)
			cout << mat[i][j] << ' ';
		cout << endl;
	}
}

void Canvas::Clear()
{
	for (int i = 0; i <= width; i++)
		for (int j = 0; j <= height; j++)
			mat[i][j] = 32;
}