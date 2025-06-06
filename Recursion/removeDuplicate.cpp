#include<iostream>
#include<string>
using  namespace std;
int removeDuplicate(string str, string ans, int i, int map[26]){

    if(i == str.size()){
        cout<< " ans:" << ans <<endl;
    }

    int mapidx = (int)(str[i] - 'a');

if(map[mapidx]==true){ // duplicate 
    removeDuplicate(str, ans, i+1, map);
}
else{
    map[mapidx] = true;
    removeDuplicate(str, ans + str[i], i+1, map );
}

}

int main(){
    string str = "Vikas gangwar";
    string ans = "";
    int map[26] = {false};
    removeDuplicate(str, ans, 0, map);
    return 0;
}