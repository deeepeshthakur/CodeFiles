#include <bits/stdc++.h>

using namespace std;

class My_BigInteger
{
private:
	std::string biginteger;
public:
	//Constructors
	My_BigInteger() = default;

	//Parametric Constructor
	My_BigInteger(const unsigned int integer){ setValue(integer);}
	//My_BigInteger(unsigned int integer){ setValue(integer);}

	My_BigInteger(const std::string& str){ setValue(str);}
	My_BigInteger(std::string& str){ setValue(str);}

	//Copy Constructors
	My_BigInteger(My_BigInteger& temp) = default; //: biginteger{temp.biginteger} {}
	My_BigInteger(const My_BigInteger& temp) = default; // : biginteger{temp.biginteger} {}

	//Move Constructor
	My_BigInteger(My_BigInteger&& temp) = default; // : biginteger{std::move(temp.biginteger)} {}

	//getValue and setValue and appendable
	const std::string appendable( std::string& app) const {
		std::string temp{};
		for( auto x = app.rbegin(); x < app.rend(); x++)
			temp += *x;
		return temp;
	}

	std::string appendable( std::string& app) {
		std::string temp{};
		for( auto x = app.rbegin(); x < app.rend(); x++)
			temp += *x;
		return temp;
	}

	void setValue( const std::string& a){ biginteger = a;}
	void setValue( std::string& a){	biginteger = a;}

	void setValue( const unsigned int a)
	{
		unsigned int temp = a;
		std::string temp_string{};
		while(temp)
		{
			int digit = temp%10;
			temp_string += (char)('0' + digit);
			temp /= 10;
		}
		setValue(appendable(temp_string));
	}

	const std::string getValue() const { std::string temp{biginteger}; return temp;}
	std::string getValue() { std::string temp{biginteger}; return temp;}

	//Assignments
	My_BigInteger& operator=(const My_BigInteger&);
	My_BigInteger& operator=(My_BigInteger&);
	My_BigInteger& operator=(My_BigInteger&&);

	//Addition
	My_BigInteger operator+(const My_BigInteger&);
	My_BigInteger operator+(const std::string& a) { My_BigInteger temp(a); My_BigInteger result(this->operator+(temp)); return result;}
	My_BigInteger operator+(const unsigned int a) { My_BigInteger temp(a); My_BigInteger result(this->operator+(temp)); return result;}

	//+=
	My_BigInteger operator+=(const My_BigInteger& a) { *this = *this + a; return *this;}
	My_BigInteger operator+=(const std::string& a) { My_BigInteger temp(a); *this = *this + a; return *this;}
	My_BigInteger operator+=(const unsigned int a) { My_BigInteger temp(a); *this = *this + a; return *this;}

	//Multiplication
	My_BigInteger operator*(const My_BigInteger&);
	My_BigInteger operator*(const std::string& a) { My_BigInteger temp(a); My_BigInteger result(this->operator*(temp)); return result;}
	My_BigInteger operator*(const unsigned int a) { My_BigInteger temp(a); My_BigInteger result(this->operator*(temp)); return result;}

	//*=
	My_BigInteger operator*=(const My_BigInteger& a) { *this = *this * a; return *this;}
	My_BigInteger operator*=(const std::string& a) { My_BigInteger temp(a); *this = *this * a; return *this;}
	My_BigInteger operator*=(const unsigned int a) { My_BigInteger temp(a); *this = *this * a; return *this;}

	My_BigInteger inser_zero( int n)
	{
		for(int index = 0; index < n; index++)
			biginteger += '0';
		return *this;
	}

	My_BigInteger squar()
	{
		My_BigInteger ans{};
		if(biginteger.length() <= 5)
		{
			ans = biginteger;
			ans *= ans;
		}
		else
		{
			std::string temp1{}, temp2{};
			for(int index = 0; index < biginteger.length()/2; index++)
				temp1 += biginteger[index];
			for(int index = biginteger.length()/2; index < biginteger.length(); index++)
				temp2 += biginteger[index];
			My_BigInteger one{temp1}, two{temp2};
			My_BigInteger pro = one*two*2;
			ans += ( (one.squar()).inser_zero((biginteger.length() - biginteger.length()/2)*(2)) + two.squar() + pro.inser_zero(biginteger.length() - biginteger.length()/2) );
		}

		return ans;
	}

	~My_BigInteger() = default;
	
};

My_BigInteger& My_BigInteger::operator=(const My_BigInteger& a){ biginteger = a.getValue(); return *this;}
My_BigInteger& My_BigInteger::operator=(My_BigInteger& a){ biginteger = a.getValue(); return *this;}
My_BigInteger& My_BigInteger::operator=(My_BigInteger&& a){ biginteger = std::move(a.biginteger); return *this;}

My_BigInteger My_BigInteger::operator+( const My_BigInteger& a)
{
	int size{};
	std::string temp{};
	std::string ytemp = a.getValue(), xtemp = biginteger;
	ytemp = appendable(ytemp);
	xtemp = appendable(xtemp);
	int sizex = xtemp.length(), sizey = ytemp.length();
	if( sizex <= sizey) size = sizex;
	else size = sizey;

	for( int index = 0; index < size; index++)
	{
		temp += (char)(xtemp[index] + ytemp[index] - '0');
	}

	if(size == sizex)
		for(int index = sizex; index < sizey; index++) temp += ytemp[index];
	else
		for(int index = sizey; index < sizex; index++) temp += xtemp[index];
	
	for( int index = 0; index < temp.length() - 1; index++)
		if( temp[index] > '9')
		{
			char ch1 = temp[index + 1], ch = temp[index];
			temp[index + 1] = (char)(ch1 + ((ch - '0')/10));  
			temp[index] = (char)((ch - '0')%10 + '0');    // ((temp[index] - '0')/10)
		}
	if( temp[temp.length() - 1] > '9')
	{
		char incre = (char)((temp[temp.length() - 1] - '0')/10 + '0');
		temp[temp.length() - 1] = (char)((temp[temp.length() - 1] - '0')%10 + '0');
		temp += incre;
	}

	My_BigInteger result(appendable(temp));
	return result;
}

My_BigInteger My_BigInteger::operator*( const My_BigInteger& a)
{
	My_BigInteger result{};
	std::string ytemp = a.getValue(), xtemp = biginteger;
	ytemp = appendable(ytemp);
	xtemp = appendable(xtemp);
	int sizex = xtemp.length(), sizey = ytemp.length();
	for( int x = 0; x < sizex; x++)
	{
		std::string temp{};
		int numx = 0, numy = 0 , carry = 0;
		numx = xtemp[x] - '0';
		for( int y = 0; y < sizey; y++)
		{
			
			numy = ytemp[y] - '0';
			char ch = (char)(((numx*numy)%10 + carry) + '0');
			temp += ch;
			carry = (numy*numx)/10;
		}
		if(carry > 0) {
			temp += (char)('0' + carry);
		}

		temp = appendable(temp);
		for( int zeros = 0; zeros < x; zeros++)
			temp += '0';
		result += temp;
	}
	
	return result;
}

ostream& operator<<( ostream& out, My_BigInteger& a)
{
	std::string temp(a.getValue());
	out << temp;
	return out;
}

My_BigInteger sol[20];

void calc1(int t)
{
	//std::cout << "called\n";
	sol[t-1] = sol[t-2].squar() + sol[t-3];
	std::cout << sol[t - 1] << " " << t << "\n";
}

My_BigInteger fibonacciModified(int n) {
    // Complete this function
    for(int index = 3; index <= n; index++)
    	calc1(index);
    return sol[n-1];
}

int main() {
    int t1;
    int t2;
    int n;
    for(int index  = 0; index < 20; index++)
    	sol[index] = -1;
    cin >> t1 >> t2 >> n;
    sol[0] = t1;
    sol[1] = t2;
    My_BigInteger result = fibonacciModified(n);
    cout << result << endl;
    return 0;
}
