#include <bits/stdc++.h>

using namespace std;
int mini = 0;
std::string gene {};

void adjust_plus( char a, std::vector < int > &bk)
{
	if(a == 'A')
		bk[0]++;
	else
		if(a == 'C')
			bk[1]++;
		else
			if(a == 'G')
				bk[2]++;
			else
				bk[3]++;
}

void adjust_minus( char a, std::vector < int > &bk)
{
	if(a == 'A')
		bk[0]--;
	else
		if(a == 'C')
			bk[1]--;
		else
			if(a == 'G')
				bk[2]--;
			else
				bk[3]--;
}

bool check( std::vector < int > temp, std::vector < int > bk)
{
	bool flag = true;
	for( int i = 0; i < 4; i++)
		if((bk[i] > 0) && (bk[i] > temp[i]))
			flag = false;
	return flag;
}

void improvedsteadygene()
{
	std::vector < int > bk(4);
	// for( int index = 0; index < gene.length(); index++)
	// 	std::cout << index << " " << gene[index] << "     ";
	// std::cout << endl;
	for( int index = 0; index < gene.length(); index++)
	{
		if(gene[index] == 'A')
			bk[0]++;
		else
			if(gene[index] == 'C')
				bk[1]++;
			else
				if(gene[index] == 'G')
					bk[2]++;
				else
					bk[3]++;
	}

	bk[0] -= gene.length()/4;
	bk[1] -= gene.length()/4;
	bk[2] -= gene.length()/4;
	bk[3] -= gene.length()/4;

	// for( auto x : bk)
	// 	std::cout << x << " ";
	// std::cout << endl;

	if(bk[0] == 0 && bk[1] == 0 && bk[2] == 0 && bk[3] == 0)
	{
		mini = 0;
	}
	else
	{
		std::vector < int > temp_book(4);
		int first = 0, last = -1;

		while(!check(temp_book, bk))
		{
			last++;
			if(gene[last] == 'A')
				temp_book[0]++;
			else
				if(gene[last] == 'C')
					temp_book[1]++;
				else
					if(gene[last] == 'G')
						temp_book[2]++;
					else
						temp_book[3]++;
		}

		mini = last - first + 1;
		//std::cout << first << " " << last << endl;
		adjust_minus(gene[first], temp_book);
		first++;
		last++;
		adjust_plus( gene[last], temp_book);
		while(last < gene.length())
		{
			// for( auto x : temp_book)
			// 	std::cout << x << " ";
			// std::cout << "     " ;
			if(!check( temp_book, bk))
			{
				//std::cout << "1 " << first << " " << last << endl;
				adjust_minus( gene[first], temp_book);
				first++;
				last++;
				adjust_plus( gene[last], temp_book);
			}
			else
			{
				//std::cout << "2 " << first << " " << last << endl;
				while(check( temp_book, bk))
				{
					adjust_minus( gene[first], temp_book);
					first++;
				}

				first--;
				adjust_plus( gene[first], temp_book);

				while(check( temp_book, bk))
				{
					adjust_minus( gene[last], temp_book);
					last--;
				}

				last++;
				adjust_plus( gene[last], temp_book);

				if( last - first + 1 < mini)
					mini = last - first + 1;

				adjust_minus( gene[first], temp_book);
				first++;
				last++;
				adjust_plus( gene[last], temp_book);
			}
		}
	}
}

int main() {
    int n;
    std::cin >> n;
    mini = n;
    std::cin >> gene;
    improvedsteadygene();
    int result = mini;
    std::cout << result << endl;
    return 0;
}