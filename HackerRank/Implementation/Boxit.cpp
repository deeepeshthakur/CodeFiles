#include<bits/stdc++.h>

using namespace std;

//Implement the class Box  
class Box
{    
    private:
    int l, b, h;     //l,b,h are integers representing the dimensions of the box
    
    public:
    
    // The class should have the following functions :     // Constructors:     // Box();    // Box(int,int,int);    // Box(Box);
    
    Box() : l{}, b{}, h{} {}
    Box( int length, int breadth, int height) : l{length}, b{breadth}, h{height} {}
    Box( const Box &temp) : l{temp.l}, b{temp.b}, h{temp.h} {}

    const int getLength() const { return l;} // int getLength(); // Return box's length
        
    const int getBreadth() const { return b;} // int getBreadth (); // Return box's breadth
        
    const int getHeight() const { return h;} // int getHeight ();  //Return box's height

    const long double CalculateVolume() { long double temp_vol; temp_vol = (double)l * (double)b * (double)h; return temp_vol;}// long long CalculateVolume(); // Return the volume of the box
    
    bool operator<( const Box& temp)  //Overload operator < as specified //bool operator<(Box& b)
    {
        if((l < temp.l) || ((b < temp.b) && (l == temp.l)) || ((h < temp.h) && (b == temp.b) && (l == temp.l))) return true;
        else return false;
    }
};
    
std::ostream& operator<<(std::ostream& out, const Box& B)    //Overload operator << as specified //ostream& operator<<(ostream& out, Box& B)
{
    return out << B.getLength() << " " << B.getBreadth() << " " << B.getHeight();    
}



void check2()
{
    int n;
    std::cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        std::cin>>type;
        if(type ==1)
        {
            std::cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            std::cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            std::cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            std::cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                std::cout<<"Lesser\n";
            }
            else
            {
                std::cout<<"Greater\n";
            }
        }
        if(type==4)
        {
            std::cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            std::cout<<NewBox<<endl;
        }

    }
}

int main()
{
    check2();
}
