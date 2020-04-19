#include "Chapter6.h"

int fact(int n){
    int res = 1;
    while(n > 1)
        res *= n--;
    return res;
}