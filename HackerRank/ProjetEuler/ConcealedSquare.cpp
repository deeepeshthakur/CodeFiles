#include <bits/stdc++.h>

using namespace std;
long long countt = 0;
int n = 0, k = 0;
bool ansNotFound = true;
std::vector< int > givenSquare;
std::vector < std::vector < int > > lastDigits(10);
std::vector< int > firstDigits( 10, 0);
std::vector< std::vector < int > > secondDigits(10);

struct SquareStruct{
    std::vector< int > currNum{};
    std::vector< int > currSq{};
    int currDigits;
};

std::vector< SquareStruct > elementArray{};

void getPrelim( int index1, int index2){
    for(int index = 0; index < elementArray[index1].currNum.size(); index++){
        elementArray[index2].currNum[index] = elementArray[index1].currNum[index];
    }

    for(int index = 0; index < elementArray[index1].currSq.size(); index++){
        elementArray[index2].currSq[index] = elementArray[index1].currSq[index];
    }

    elementArray[index2].currDigits = elementArray[index1].currDigits;
}

void addSquare( int iindex, int x, int y, int dig){
    int num = 10*x + y;
    int sq = num*num;
    int indexToAdd = 2*elementArray[iindex].currDigits;
    while(sq){
        elementArray[iindex].currSq[indexToAdd] += (sq%10);
        sq /= 10;
        indexToAdd++;
    }

    indexToAdd = elementArray[iindex].currDigits;
    for(int index = 0; index < elementArray[iindex].currDigits; index++){
        elementArray[iindex].currSq[indexToAdd] += (2*num*elementArray[iindex].currNum[index]);
        indexToAdd++;
    }

    for(int index = 0; index < elementArray[iindex].currSq.size() - 1; index++){
        elementArray[iindex].currSq[index + 1] += (elementArray[iindex].currSq[index]/10);
        elementArray[iindex].currSq[index] %= 10;
    }

    elementArray[iindex].currNum[elementArray[iindex].currDigits] = y;
    elementArray[iindex].currNum[elementArray[iindex].currDigits + 1] = x;
    elementArray[iindex].currDigits += dig;
}

void ansFound(){
    ansNotFound = false;
    for(int index = n - 1; index >= 0; index--){
        std::cout << elementArray[k - 1].currNum[index];
    }
    std::cout << std::endl;
}

void finalCheck(){
    int sqfd = givenSquare[givenSquare.size() - 1], fd = firstDigits[sqfd], sd;
    if(n%2 == 1){
        for(int index = 0; index < secondDigits[sqfd].size() && ansNotFound; index++){
            if(ansNotFound){
                sd = secondDigits[sqfd][index];
                getPrelim( k - 2, k - 1);
                addSquare( k - 1, fd, sd, 2);
                bool flag = true;
                for(int index = n - 1; index >= 0 && flag; index--){
                    if(givenSquare[2*index] != elementArray[k - 1].currSq[2*index]){
                        flag = false;
                    }
                }
                if(flag){
                    ansFound();
                }
            }
        }
    }
    else{
        if(ansNotFound){
            getPrelim( k - 2, k - 1);
            addSquare( k - 1, 0, fd, 1);
            bool flag = true;
            for(int index = n - 1; index >= 0 && flag; index--){
                if(givenSquare[2*index] != elementArray[k - 1].currSq[2*index]){
                    flag = false;
                }
            }

            if(flag){
                ansFound();
            }
        }        
    }
}

void dfsModified( int kIndex){
    if(ansNotFound){
        if(kIndex < k - 2){
            for(int x = 0; x < 10 && ansNotFound; x++){
                for(int y = 0; y < 10 && ansNotFound; y++){
                    getPrelim( kIndex, kIndex + 1);
                    addSquare( kIndex + 1, x, y, 2);
                    if(elementArray[kIndex + 1].currSq[elementArray[kIndex + 1].currDigits - 1] == givenSquare[elementArray[kIndex + 1].currDigits - 1]){
                        dfsModified( kIndex + 1);
                    }
                }
            }
        }
        else{
            finalCheck();
        }
    }
}

void getResult(){
    for(int index = 0; index < lastDigits[givenSquare[0]].size(); index++){
        if(ansNotFound){
            elementArray[0].currNum[0] = lastDigits[givenSquare[0]][index];
            elementArray[0].currDigits = 1;
            int sq = lastDigits[givenSquare[0]][index]*lastDigits[givenSquare[0]][index];
            int dig = 0;
            while(sq){
                elementArray[0].currSq[dig] = sq%10;
                sq /= 10;
                dig++;
            }
            dfsModified(0);
        }
    }
}

void PrePrelims(){
    // elementArray.clear();
    elementArray.resize(k);
    for(int index = 0; index < k; index++){
        elementArray[index].currNum.resize( n, 0);
        elementArray[index].currSq.resize(2*n - 1, 0);
        elementArray[index].currDigits = 0;
    }
}
void fillLastDigits(){
    for(int index = 0; index < 10; index++){
        int sq = index*index;
        lastDigits[sq%10].push_back(index);
    }
}
void fillFirstDigtis(){
    for(int index = 0; index < 10; index++){
        if(index > 0 && index < 4){
            firstDigits[index] = 1;
        }
        if(index >= 4 && index < 9){
            firstDigits[index] = 2;
        }
        if(index == 9){
            firstDigits[index] = 3;
        }
    }
}
void fillSecondDigits(){
    secondDigits[1] = { 0, 1, 2, 3, 4};
    secondDigits[2] = { 4, 5, 6, 7};
    secondDigits[3] = { 7, 8, 9};
    secondDigits[4] = { 0, 1, 2};
    secondDigits[5] = { 2, 3, 4};
    secondDigits[6] = { 4, 5, 6};
    secondDigits[7] = { 6, 7, 8};
    secondDigits[8] = { 8, 9};
    secondDigits[9] = { 0, 1}; 
}

int main(){
    std::cin >> n;
    k = (n/2) + 1;
    givenSquare.clear();
    givenSquare.resize( 2*n - 1, 0);
    for(int index = givenSquare.size() - 1; index >= 0; index = index - 2){
        std::cin >> givenSquare[index];
    }
    int start_s = clock();
    PrePrelims();
    fillLastDigits();
    fillFirstDigtis();
    fillSecondDigits();
    getResult();
    // for(int index = 0; index < k; index++){
    //     elementArray[index].~SquareStruct();
    // }
    int stop_s = clock();
    std::cout << "time: " << (stop_s - start_s)/double(CLOCKS_PER_SEC)*1000 << std::endl;
    return 0;
}