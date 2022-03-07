#ifndef MAIN_C_ISWORDLETTERSSUBSETSTR_H
#define MAIN_C_ISWORDLETTERSSUBSETSTR_H
#include "../string_.h"



bool isWordLettersSubsetStr(char *s, WordDescriptor w){
    bool isSubset[256] = {0};
    while(*s){
        isSubset[*s] = true;
        s++;
    }

    while (*w.begin && w.begin != w.end)
        if(!isSubset[*w.begin++])
            return false;

    return  true;
}

#endif //MAIN_C_ISWORDLETTERSSUBSETSTR_H
