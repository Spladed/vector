#include<iostream>

using namespace std;

class Vec4
{
	float s[4];	
public:
	class Error {};
	Vec4(float a = 0.0, float b = 0.0, float c = 0.0, float d = 0.0)
	{
		s[0] = a;
		s[1] = b;
		s[2] = c;
		s[3] = d;
	}
	void check(int i)
	{
		if (i < 0 || i >= 4)
			throw Error();
	}
	float operator[](int i)
	{
		check(i);
		return s[i];
	}
	friend Vec4 operator+(const Vec4& a, const Vec4& b)
	{
		Vec4 sa;
		sa.s[0] = a.s[0] + b.s[0];
		sa.s[1] = a.s[1] + b.s[1];
		sa.s[2] = a.s[2] + b.s[2];
		sa.s[3] = a.s[3] + b.s[3];
		return sa;
	}
	friend Vec4 operator-(const Vec4& a, const Vec4& b)
	{
		Vec4 sa;
		sa.s[0] = a.s[0] - b.s[0];
		sa.s[1] = a.s[1] - b.s[1];
		sa.s[2] = a.s[2] - b.s[2];
		sa.s[3] = a.s[3] - b.s[3];
		return sa;
	}
	friend Vec4 operator*(const Vec4& a, const Vec4& b)
	{
		Vec4 sa;
		sa.s[0] = a.s[0] * b.s[0];
		sa.s[1] = a.s[1] * b.s[1];
		sa.s[2] = a.s[2] * b.s[2];
		sa.s[3] = a.s[3] * b.s[3];
		return sa;
	}
	friend Vec4 operator/(const Vec4& a, const Vec4& b)
	{
		for (int i = 0; i < 4; i++)
		{
			if (b.s[i] == 0)
				throw Error();
		}
		Vec4 sa;
		sa.s[0] = a.s[0] / b.s[0];
		sa.s[1] = a.s[1] / b.s[1];
		sa.s[2] = a.s[2] / b.s[2];
		sa.s[3] = a.s[3] / b.s[3];
		return sa;
	}
	Vec4& operator=(Vec4 a)
	{
		s[0] = a.s[0];
		s[1] = a.s[1];
		s[2] = a.s[2];
		s[3] = a.s[3];
		return *this;
	}
	Vec4& operator+=(Vec4& a)
	{
		s[0] += a.s[0];
		s[1] += a.s[1];
		s[2] += a.s[2];
		s[3] += a.s[3];
		return *this;
	}
	Vec4& operator-=(Vec4& a)
	{
		s[0] -= a.s[0];
		s[1] -= a.s[1];
		s[2] -= a.s[2];
		s[3] -= a.s[3];
		return *this;
	}
	Vec4& operator*=(Vec4& a)
	{
		s[0] *= a.s[0];
		s[1] *= a.s[1];
		s[2] *= a.s[2];
		s[3] *= a.s[3];
		return *this;
	}
	Vec4& operator/=(Vec4& a)
	{
		for (int i = 0; i < 4; i++)
		{
			if (a.s[i] == 0)
				throw Error();
		}
		s[0] /= a.s[0];
		s[1] /= a.s[1];
		s[2] /= a.s[2];
		s[3] /= a.s[3];
		return *this;
	}
};

int main()
{
	Vec4 a(23, 45, 34), b(0, 8, 9, 4), c;
	c = a + b;
	cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << endl;
	c = a - b;
	cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << endl;
	c = a * b;
	cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << endl;
	try {
		c = a/b;
	}
	catch (Vec4::Error) {
		cerr << "divided by zero!\n";
	}
	cout << c[0] << " " << c[1] << " " << c[2] << " " << c[3] << endl;
	return 0;
}