#include <bits/stdc++.h>

using namespace std;

int check_digits( long num)
{
	long temp = num;
	int digit = 0;
	while(temp)
	{
		digit++;
		temp %= 10;
	}
	return digit;
}

void create_char( std::string &str, long num)
{
	std::string temp {};
	//str = temp;
	while(num)
	{
		temp += (char)(num%10 + '0');
		num /= 10;
	}

	for(int index = 0; index < temp.length(); index++)
		str += temp[temp.length() - 1 - index];
}

//correct
long create_num( std::string str, int len)
{
	long ans = 0;
	long multiplier = 1;
	for(int index = len - 1; index >= 0; index--)
	{
		ans += (str[index] - '0')*multiplier;
		multiplier *= 10;
	}

	return ans;
}

bool check_beautiful( std::string num, int d)
{
	//std::cout << endl << d << endl;
	int len = num.length();
	long curr = create_num( num, d);
	int start_index_curr = d;
	bool possibility = true, check = true;

	while(possibility)
	{
		std::string next_num_char {};
		long next_num = curr + 1;
		create_char( next_num_char, next_num);
		//std::cout << curr << " " << next_num << " " << next_num_char << endl;
		if(start_index_curr + next_num_char.length() > len)
			{
				//std::cout << " ddd " << endl;
				possibility = false;
				check = false;
			}

		if(possibility)
		{
			for(int index = 0; index < next_num_char.length() && check; index++)
				if(num[start_index_curr + index] != next_num_char[index])
					{
						//std::cout << " ggg " << endl;
						possibility = false;
						check = false;
					}
		}

		start_index_curr += next_num_char.length();
		curr = next_num;

		if(start_index_curr == len)
		{
			//std::cout << " hhh " << endl;
			possibility = false;
		}
	}

	return check;
}

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        // your code goes here
        int len = s.length();
        bool check = false;
        for(int index = 1; index <= len/2 && (!check); index++)
        {
        	if(check_beautiful( s, index))
        	{
        		check = true;
        		std::cout << "YES " << create_num( s, index) << endl;
        	}
        }

        if(!check)
        	std::cout << "NO" << endl;
    }
    return 0;
}
