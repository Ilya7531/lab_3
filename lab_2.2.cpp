#include <iostream>
#include <stdlib.h>
using namespace std;

class Fraction{

    int chislitel;
    int znamenatel;

    public:
    Fraction(){}

    Fraction(const Fraction & fr)
    {
        chislitel = fr.chislitel;
        znamenatel = fr.znamenatel;
    }

    ~Fraction(){}

    Fraction(int m, int n)
    {
        if(n==0)
        {
            cout << "Delenie na null\n";
            exit(13);
        }
        chislitel = m;
        znamenatel = n;
        reduce();
    }

    void Vivod()
    {
        cout << chislitel << '/' << znamenatel;
    }

    Fraction operator +(Fraction fr)
    {
        chislitel = chislitel * fr.znamenatel + fr.chislitel * znamenatel;
        znamenatel = znamenatel * fr.znamenatel;
        reduce();
        return *this;
    }

    Fraction operator -(Fraction fr)
    {
        chislitel = chislitel * fr.znamenatel - fr.chislitel * znamenatel;
        znamenatel = znamenatel * fr.znamenatel;
        reduce();
        return *this;
    }

    Fraction operator *(Fraction fr)
    {
        chislitel = chislitel * fr.chislitel;
        znamenatel = znamenatel * fr.znamenatel;
        reduce();
        return *this;
    }

    Fraction operator /(Fraction fr)
    {
        chislitel = chislitel * fr.znamenatel;
        znamenatel = znamenatel * fr.chislitel;
        reduce();
        return *this;
    }

    Fraction &operator =(Fraction fr)
    {
        if(this!=&fr)
        {
            znamenatel = fr.znamenatel;
            chislitel = fr.chislitel;
        }

        return *this;
    }

    bool operator < (Fraction fr)
    {
        double a, b;
        a = chislitel / znamenatel;
        b = fr.chislitel / fr.znamenatel;
        return a < b;
    }
	bool operator > (Fraction fr)
	{
	    double a, b;
        a = chislitel / znamenatel;
        b = fr.chislitel / fr.znamenatel;
        return a > b;
	}

	bool operator == (Fraction fr)
	{
	    double a, b;
        a = chislitel / znamenatel;
        b = fr.chislitel / fr.znamenatel;
        return a == b;
	}
	bool operator != (Fraction fr)
	{
	    double a, b;
        a = chislitel / znamenatel;
        b = fr.chislitel / fr.znamenatel;
        return a != b;
	}
	bool operator <= (Fraction fr)
	{
	    double a, b;
        a = chislitel / znamenatel;
        b = fr.chislitel / fr.znamenatel;
        return a <= b;
	}
	bool operator >= (Fraction fr)
	{
	    double a, b;
        a = chislitel / znamenatel;
        b = fr.chislitel / fr.znamenatel;
        return a >= b;
	}

    void plus(Fraction fr)
    {
        chislitel = chislitel * fr.znamenatel + znamenatel * fr.chislitel;
        znamenatel *= fr.znamenatel;
    }

    void minus(Fraction fr)
    {
        chislitel = chislitel * fr.znamenatel - znamenatel * fr.chislitel;
        znamenatel *= fr.znamenatel;
    }

    void multiplication(Fraction fr)
    {
        chislitel = chislitel * fr.chislitel;
        znamenatel *= fr.znamenatel;
    }

    void division(Fraction fr)
    {
        chislitel = chislitel * fr.znamenatel;
        znamenatel *= fr.chislitel;
    }

    void equals(Fraction fr)
    {
        chislitel = fr.chislitel;
        znamenatel = fr.znamenatel;
    }

    void reduce()
{	int x,y;
	x=abs(chislitel);
	y=abs(znamenatel);
	if (znamenatel!=0){
	if (chislitel==0)
		znamenatel=1;
	else
	{
	while (x!=y)
		if (x>y) x-=y;
		else y-=x;
	chislitel/=x;
	znamenatel/=x;}
	}
}

};

void index(Fraction *array, int s);

int main()
{
    Fraction a(6, 3), b(3, 2), c;
    c = a + b;
    c.Vivod(); cout << endl;
    c = a - b;
    c.Vivod(); cout << endl;
    c = a * b;
    c.Vivod(); cout << endl;
    c = a / b;
    c.Vivod(); cout << endl;
    cout << (a < b) <<endl;

    int m, n;
    int s;

    Fraction *frac;

    cout << "Number of fractions : ";
    cin >> s;
    while (s < 0) cout << "Number of fractions : " ;

    frac = new Fraction[s];

    for (int i = 0; i < s; i++)
    {
        cout << "Write chislitel:" ;
        cin >> m;
        cout << "Write znamenatel:" ;
        cin >> n;
        while (n == 0) cout << "Write znamenatel:" ;
        frac[i] = Fraction(m, n);
        cout << endl;
    }

    for (int i = 0; i < s; i++)
    {
        frac[i].Vivod();
        cout << ";\n";
    }

    cout << endl;

    index(frac, s);

    for (int i = 0; i < s; i++)
    {
        frac[i].Vivod();
        cout << ";\n";
    }

    return 0;
}

void index(Fraction *array, int s)
{
    for (int i = 0; i < s-1; i++)
    {
        if (i % 2 == 0) array[i] = array[i] + array[i+1];
    }
}

