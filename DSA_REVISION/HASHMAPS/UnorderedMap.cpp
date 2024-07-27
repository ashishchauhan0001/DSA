#include <iostream>
#include<unordered_map>
using namespace std;
// pair is used to take two distinct datatype together
int main()
{
    unordered_map<string,int>ourmap;
    //insert
    pair<string,int>p("abc",1);
    ourmap.insert(p);
    // another easy way to insert in CPP
    ourmap["def"]=2;
    // find and access
    cout<<ourmap["abc"]<<endl;
    cout<<ourmap.at("abc")<<endl;
    // below normal bracket gives us a error but if we use
    //...square bracket it will add 0 to the unknown key below
    //cout<<ourmap.at("ghi")<<endl;
    cout<<"size is "<<ourmap.size()<<endl;
    cout<<ourmap["gji"]<<endl;
    // check presence
    if(ourmap.count("gji")>0)
    {
        cout<<" gji is present"<<endl;
    }
    if(ourmap.find("gji")!=ourmap.end()){
        cout<<" yes ghi is present"<<endl;
    }
    // size
    cout<<"size is "<<ourmap.size()<<endl;

    // erase
    ourmap.erase("gji");
    if(ourmap.count("gji")>0)
    {
     cout<<"ghi is present"<<endl;
    }
    cout<<"after erase size is "<<ourmap.size()<<endl;
    return 0;
}