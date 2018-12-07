#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool spe_check( int page_num, int start, int end)
{
	//std::cout << " spe_check called " << endl;
	if((start <= page_num) && (end >= page_num))
		{
			//std::cout << " bbbb " << endl;
			return true;
		}
	else
		{
			//std::cout << " nnn " << endl;
			return false;
		}
}

int chap_spe( int start_page, int num_prob, int k)
{
	//std::cout << " In chap_spe " << endl;
	int pages = num_prob/k;
	if((num_prob%k) != 0)
		pages++;
	//std::cout << " Pages = " << pages << endl;
	int spe_prob = 0;
	for( int index = 0; index < pages; index++)
	{
		//std::cout << " Loop test " << endl;
		int start_prob = index*k + 1;
		int last_prob;
		if((index+1)*k > num_prob)
			last_prob = num_prob;
		else
			last_prob = (index+1)*k;
		if(spe_check( start_page + index, start_prob, last_prob))
			{
				spe_prob++;
				//std::cout << " jjj ";
			}
	}

	return spe_prob;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int c, k;
    std::cin >> c >> k;
    std::vector < int > problems(c);
    for( int index = 0; index < c; index++)
    	std::cin >> problems[index];

    int page = 1;
    int spe_prob = 0;
    int chap = 0;
    while(chap < c)
    {	
    	//std::cout << page << " " << problems[chap] << " " << k << endl;
    	spe_prob += chap_spe( page, problems[chap], k);
    	int temp = problems[chap]/k;
    	if((problems[chap]%k) != 0)
    		temp++;
    	page += temp;
    	chap++;
    }

    std::cout << spe_prob << endl;
    return 0;
}
