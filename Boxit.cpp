#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int BoxesCreated,BoxesDestroyed;

class Box {
private:
    int length, breadth, height;
public:
    Box() {
        length = 0;
        breadth = 0;
        height = 0;
        BoxesCreated++;
    }
    
    Box(int a, int b, int c) {
        length = a;
        breadth = b;
        height = c;
        BoxesCreated++;
    }
    Box (Box& b) {
        this->length = b.getLength();
        this->breadth = b.getBreadth();
        this->height = b.getHeight();
        BoxesCreated++;
    }
    ~Box() {
        BoxesDestroyed++;
    }
    int getLength() {
        return this->length;
    }
    int getBreadth() {
        return this->breadth;
    }
    int getHeight() {
        return this->height;
    }
    long long CalculateVolume() {
        return (long long) this->length * this->breadth * this->height;
    }
    void operator= (Box& b) {
        this->length = b.getLength();
        this->breadth = b.getBreadth();
        this->height = b.getHeight();
    }
};

bool operator< (Box& a, Box& b) {
    if (a.getLength() < b.getLength()) {
        return true;
    } else if (a.getLength() == b.getLength() && a.getBreadth() < b.getBreadth()) {
        return true;
    } else if (a.getLength() == b.getLength() && a.getBreadth() == b.getBreadth() && a.getHeight() < b.getHeight()) {
        return true;
    } else {
        return false;
    }
}
//Overload operator << as specified
//ostream& operator<<(ostream& out, Box B)
ostream& operator<<(ostream& out, Box& B) {
    out<< B.getLength() << ' ' << B.getBreadth() << ' ' << B.getHeight();
    return out;
}

void check2()
{
    int n;
    cin>>n;
    Box temp;
    for(int i=0;i<n;i++)
    {
        int type;
        cin>>type;
        if(type ==1)
        {
            cout<<temp<<endl;
        }
        if(type == 2)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            temp=NewBox;
            cout<<temp<<endl;
        }
        if(type==3)
        {
            int l,b,h;
            cin>>l>>b>>h;
            Box NewBox(l,b,h);
            if(NewBox<temp)
            {
                cout<<"Lesser"<<endl;
            }
            else
            {
                cout<<"Greater"<<endl;
            }
        }
        if(type==4)
        {
            cout<<temp.CalculateVolume()<<endl;
        }
        if(type==5)
        {
            Box NewBox(temp);
            cout<<NewBox<<endl;
        }
        
    }
}

int main()
{
    BoxesCreated = 0;
    BoxesDestroyed = 0;
    check2();
    cout<<"Boxes Created : "<<BoxesCreated<<endl<<"Boxes Destroyed : "<<BoxesDestroyed<<endl;
}

