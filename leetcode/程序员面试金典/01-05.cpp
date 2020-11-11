#include <string>
using namespace std;


bool oneEditAway(string first, string second) {
    if(abs((int)(first.size() - second.size())) > 1) return false;
    int diff = 0;
    if(first.size() == second.size()){
        for(int i = 0; i < first.size(); i++)
            if(first[i] != second[i]) diff++;
        if(diff > 1) return false;
        else return true;
    }
    if(first.size() < second.size())
        return oneEditAway(second, first);
    int fi = 0, se = 0;
    while(se < second.size() && fi < first.size()){
        if(first[fi] == second[se]){
            fi++; se++; continue;
        }
        else{
            diff++; fi++;
            if(diff > 1) return false;
        }
    }
    return true;
}

bool oneEditAway2(string first, string second) {
    int len = first.size() - second.size();
    if(len > 1 || len < -1) return false;
    int diff = 0;
    for(int i = 0, j = 0; i < first.size() && j < second.size(); i++, j++){
        if(first[i] != second[j]){
            if(len == 1) j--;
            else if (len == -1) i--;
            diff++;
        }
    }
    if(diff > 1) return false;
    return true;
}


bool oneEditAway3(string first, string second) {
        int len1 = first.size(), len2 = second.size();
        if (abs(len1 - len2) >= 2)
            return false;
        if (len2 > len1) //为了方便保证first更长
            return oneEditAway(second, first);
        for (int i = 0; i < len2; ++i) {
            if (first[i] != second[i]) {
                return first.substr(i + 1) == second.substr(len1 == len2 ? i+1 : i);
            }
        }
        return true;
}


int main(){
    string first = "pales";
    string second = "pal";
    printf("%s", oneEditAway(first, second) ? "true":"false");

    return 0;
}