#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <cstdlib>
#include <ctime>

using namespace std;

    vector<int>p;
    vector<char>inVector;
    string ss2;
    string s;
    string str;
    string input;
    char ans = ' ';
    int counter = 1;
    string answer;
    char index;


string GetInput(string additional = "  "){
  string input;

  if (additional != "  ") cout << additional << ": ";

  getline(cin, input);

	return input;
}

string editStr (string s){
int firstIndex = -1;
int lastIndex = -1;
int x = s.size()-1;
int i = 0;
if (s.size()==2 || s.size()==1 || s.size()==0) return s;
   for(int z = 0; z < s.size() - 1; z++ ){

        if (i == x || (firstIndex != -1 && lastIndex != -1)) return s.substr(firstIndex, lastIndex - firstIndex + 1);

        if(s[i] != ' ' && firstIndex == -1) firstIndex = i;
        else if(s[i] == ' ' && firstIndex == -1) i++;

        if (s[x] != ' ' && lastIndex == -1) lastIndex = x;
        else if(s[x] == ' ' && lastIndex == -1) x--;
    }
}

string removeToSpace(string str){
    int i=0, j;
    string empty = "";
    for(int i = 0; i < (int)str.size(); i++) {
        if (str.size()==1 || str.size()==0)return str;
        if (str[i] == ' ' && str[i+1]==' ') {
            int pos = i;
        str.replace(pos,1,empty);
        return removeToSpace(str);
      }
   }
return str;
}

bool foolish (string s){
    unsigned pos = s.find(' ');
    for (int i =0; i < s.size(); i++){
        if (s[pos+1]== ' ')
            return true;
        else pos = s.find(' ',pos+1);
    }
    return false;
}

bool isEqual(string x ,string y){
    if (x==y) return true;
    else return false;
}


int pickRand(vector<int>p){
    srand((unsigned) time(0));
    mt19937 engine( rand()); // generator
    uniform_int_distribution<int> choose( 1 , p.size() - 4); // number distribution
return p[choose(engine)];
}


char genDash(string s){
for (int i = 0 ; i < s.size(); i++)return '-';
}


string dashedString (string whole, string part , int start , int endd){

for (int j = start+1; j < endd; j++){
       whole[j] = genDash(part);
    }
    return whole;
}

void stupidity(string s){
if (foolish(s)){
        cout<<"It seems like you 're blind!"<<endl;
}
}

void menu(){
int endd;
        cout<<"Enter a plain text: "<<endl;
        getline(cin,str);

    for (int i= 0; i < str.size(); i++){
        if (str[i]== ' '){
            counter++;
            p.push_back(i);
        }
    }
    for (int i = 0 ; i < p.size(); i++){
        if (p[i] == pickRand(p)){
        endd = p[i+3];
        }
    }
    for (int j = pickRand(p);  j < endd; j++){
        inVector.push_back(str[j]);
    }


    s = str.substr(pickRand(p)+1,inVector.size()-1);
    s = editStr(removeToSpace(s));

    cout<<dashedString(str, s , pickRand(p) , endd)<<endl;

    getline(cin,input);

    stupidity(input);

    input = editStr(removeToSpace(input));

        if(isEqual(input,s)){cout<<"TRUE!"<<"\n";}
        else {cout<<"FALSE!"<<"\n";}

    s.clear();
    str.clear();
    inVector.clear();
    p.clear();

    do {
    answer = GetInput("Do you wish to play again? \n");
    index = answer[0];
        if(index == 'y')return menu();
        else if(index == 'n')return;

    }while(index != 'y' || index !='n');
}









int main()
{
    menu();
}
