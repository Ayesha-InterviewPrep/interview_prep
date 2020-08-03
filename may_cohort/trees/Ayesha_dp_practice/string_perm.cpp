#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;
unordered_map<char, int> c_map;
vector<string> result;
void perm_cal(string & input, string &temp){
  //return condition
    if(temp.length() == input.length()) {
        result.push_back(temp);
        //cout<<temp<<"\t";
        return;
    }
  //logic
  for(int i =0; i<input.length();i++){
      //action
      int count = c_map[input[i]];
      if(count!=0){
          count--;
          temp.push_back(input[i]);
          c_map[input[i]]= count;
      }else{
          continue;
      }
      //recurse
      perm_cal(input,temp);
      
      //backtrack
      temp.pop_back();
      count++;
      c_map[input[i]]= count;
  }
  return;
}

void perm(string & input){
    //edge
    if(input.length()==0) return;
    
    //hashmap & call
    for(int i=0; i<input.length(); i++)
        ++c_map[input[i]];
    string temp;
    perm_cal(input, temp);
    return ;
}
int main() {
    cout<<"GfG!";
    //return
    //vector<string> result;
    string input = "ABCd";
    perm(input);
    for(int i=0; i<result.size(); i++){
        cout<<result[i]<<"\t";
    }
    cout<<"\n";
    return 0;
}

