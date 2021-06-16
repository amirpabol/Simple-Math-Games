#ifndef GROUP_H
#define GROUP_H
#include<iostream>
using namespace std;

class Group
{
    private:
        string groupname;
        int amount;
    public:
        Group(){}
        ~Group(){};

        void setData(string grp, int A)
        {
            groupname = grp;
            amount = A;
        }
        string getGroup()
        {
            return groupname;
        }
        int getAmount(){
            return amount;
        }

};
#endif