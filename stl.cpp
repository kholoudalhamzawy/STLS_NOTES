#include <iostream>
using namespace std;
#include <iomanip>
#include <algorithm>
#include <string>
#include <cmath>
#include <utility>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <stack>
#include <array>
#include <deque>
#include <functional>
#include <utility>
int main() {

/// ######  array  ######

    array<int,5> arr;
    int arry[5]={1,2};

//   can be initialized later or at the decleration
    arr={3,2,6};
//    another way to initialize called uniform initialization
    array <int,5> arr2 {1,2,3};


//   doesn't return the pointer (adress)
//   cout<<arr; doesn't work

    cout<<arry<<" : "; // gives adress
    cout<<*arry<<'\n';

    cout<<arr.data()<<" : "; // that works
    cout<<*arr.data()<<'\n';

//   both fill the un initialized indeces with 0 by defult

//    has many more functions, it,s more of a class
    cout<<arry[0]<<" "<<arry[4]<<"\n";
    cout<<arr.front()<<" "<<arr.back()<<" "<<arr.at(2)<<" "<<arr[4]<<'\n';

    arr.fill(12);
    cout<<arr.front()<<" "<<arr.back()<<" "<<arr.at(2)<<" "<<arr[4]<<'\n';


/// ######  vector  #######

//  is basiclly a dynamic array or a linked list array that combines easy access to indeces -o(1)- and luxury of the dynamic properties of not knowing the size

vector<int> arr1;
vector<int> ar2(5,20); //puts five twenties
vector<int> ar3 ={1,2,3};
vector<int> ar4 {1,2,3}; //uniform initialization

//   when adding elemnts it creats an array, then doubles it every time it exceeds its size and the adress doesn't change when copying the values to the new doubled array
//arr1.reserve(1000);
cout<<"size: "<<arr1.size()<<" capacity: "<<arr1.capacity()<<" adress: "<<arr1.data()<<"\n";

for(int i=1;i<33;i++){
    arr1.push_back(i);
    ar2.push_back(i);
    cout<<"size: "<<arr1.size()<<" capacity: "<<arr1.capacity()<<" adress: "<<arr1.data()<<"\n";
}

//even when popping the elements capacity don,t change
    for(int i=0;i<arr1.size();){
        ar2.pop_back();
        arr1.pop_back();
        arr1.shrink_to_fit();
        cout<<"shrinked"<<": "<<arr1.capacity()<<" "<<arr1.size()<<" ";
        cout<<"not shrinked: "<<ar2.capacity()<<" "<<ar2.size()<<"\n";

    }
    ar2.clear();
    cout<<ar2[1]<<" "<<ar2.size()<<"\n";
    ar2.shrink_to_fit();
   // cout<<ar2[1]<<" "<<ar2.size()<<"\n"; //won't work because the capacity is zerro so the index is out of range

//because it takes linear time everytime it doubles the array to copy the values
ar2.resize(20); // this will put 20 zeros in thearray and when pushing back it will push after 20,but depends on the compiler, and is reachable by ar2[index]=value not push back
arr1.reserve(20); //this will only affect capacity to be 20 to maintain time complixity and not doubling the array kol 4waya
for(int i=1;i<=21;i++){
    cout<<ar2[i]<<" ";
    ar2.push_back(i);
    cout<<"size: "<<ar2.size()<<" capacity: "<<ar2.capacity()<<"\n";
}
for(int i=1;i<=21;i++){
    arr1.push_back(i);
    cout<<"size: "<<arr1.size()<<" capacity: "<<arr1.capacity()<<"\n";

}

//   in vector the arr.at() function will raise an exception when the index is not defined instead of giving a garbage value
 cout<<arr1.at(3)<<"\n";
cout<<ar3[3]<<"\n"; //gives garbage
// cout<<ar3.at(3); will not work because the array didn't exist yet


///################################
///################################


//    decltype --> the variable which is already initialized, it takes its type
//    auto --> whatever the variable type is, it costumes its type to whatever the given value is
//      auto must be initialized, and cant be given as a ype of vector
    int jj=9;
    decltype(jj) d=5;
    auto sss=3;
///   can only be used in headers files
//    templete<typename Type>
//            Type sumgeneric(Type a,Type b){
//        return a+b;
//    }
    cout<<typeid(d).name()<<"\n";
    cout<<typeid(sss).name()<<"\n";


//// function that returns a 'reference to int' type
//int& fun() {   }

//// m will default to int type instead of int& type
//auto m = fun();

//// n will be of int& (is also refrence instead of int) type because of use of extra & with auto keyword
//auto& n = fun();


/// ######  set  ########

    vector<set<int>> v;

// when setting container inside a container u should resize first so it doesn't give u exit code
//and not reserve, cause resize make the vector exist and reachable by index
    v.resize(50);

    for(int i=0;i<3;i++){
        for(int j=1;j<4;j++){
            v[i].insert(j);
        }
    }
    v[3]={1,3,4,5};
//    if u don't know the size of the vector try using the nested loop used in maps
    for(int i=0;i<4;i++){
        set<int>::iterator j;
        for(j=v[i].begin();j!=v[i].end();j++){
            cout<<*j<<"\t";
        }
//        or instead of iterator use auto
        for( auto it =v[i].begin();it!=v[i].end();it++){
            cout<<*it<<"\t";
        }
        for(const auto &e: v[i]){
            cout<<e<<"\t";
        }
        cout<<"\n";
    }

///  #####  map  ######

    map<string,int> sd;
    sd["a"]=1;
    sd["aa"]=2;
    sd.insert(make_pair("aa",22));
    for(auto& el1: sd){
        cout<<el1.first<<" "<<el1.second<<"\n";
    }
    map<string,vector<int>,std::less<string>> sa;
    sa["aa"].push_back(1010);
    sa["aa"].push_back(11);
    sa["dd"].push_back(21);

//    for(int i=0;i<3;i++){
//        string s;
//        cin>>s;
//        int u;cin>>u;
//        for(int i=0;i<u;i++){
//            int j;
//            cin>>j;
//            sa[s].push_back(j);
//        }
//    }


    for(auto& el1: sa){
        cout<<el1.first<<" ";
        for(auto &el2: el1.second){
            cout<<el2<<" ";
        }
        vector<int>::iterator itt;
        for(itt=el1.second.begin();itt!=el1.second.end();itt++){
            cout<<*itt<<" ";
        }
        cout<<"\n";

    }

///   #####  pair  ######

    pair <int, char> PAIR1 ;
    pair <string, double> PAIR2 ("GeeksForGeeks", 1.23) ;
    pair <string, double> PAIR3 ;

    PAIR1.first = 100;
    PAIR1.second = 'G' ;
    PAIR3=PAIR2;

    pair<int, int>pair1 = make_pair(12, 1);
    pair<int, int>pair2 = make_pair(1, 12);

//    == returns first AND second
//    != if any of them is not equal gives 1
//    the rest it checks only the first one, if in > or < and the first one was equal, it checks the second one


    cout << (pair1 == pair2) << endl;
    cout << (pair1 != pair2) << endl;
    cout << (pair1 >= pair2) << endl;
    cout << (pair1 <= pair2) << endl;
    cout << (pair1 > pair2) << endl;
    cout << (pair1 < pair2) << endl;


/// #####  deque  #####
//  have a fixed size initialized array
//  is cheaper than vector while expanding in time, and space if the number of elements are greater than the fixed size array
//  work with two pointer derefrences: one to select the array, another to select the index in the array
//  if it needs to be compared, it could be compared to a vector not a queue
//  rear is top ( first to be inserted ), front is ironicaly back ( last inserted )
//  for further reminders :
//  https://www.youtube.com/watch?v=uGWeixb7HMo&list=PLk6CEY9XxSIA-xo3HRYC3M0Aitzdut7AA&index=14


    deque<int> que;
    que.push_back(2);
    que.push_back(3);
    cout<<que[1]<<"\n";


/// ####  stack #####

//  LIFO
//  is a container adapter, that means it's actually a deque, but it's adapted to only be taken from one side, top is first inserted

//  if u want to make it adapt to a vector instead of , it will only differ working internally
    stack <int,vector<int>> stk;
    stk.push(2);
    stk.push(4);
    stk.push(3);
//    can't be iterated, nor the queue
    //    for(auto& i:stk){
    //        cout<<i;
    //    }

// has to pop all the tops, same as queue
    while(!stk.empty()){
        cout<<stk.top()<<"\n";
        stk.pop();
    }

///   ##### priority queue #####

//    is basicly a max heap, that could be turned into a min heap
//    is a container adapter that is basedon vectors
//    can't also be iterated, have to pop the top every time


}
