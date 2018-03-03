#include <cstdio>
#include <cctype>

int main(){
    char stra[100], strb[100], c, tc;
    bool smap[40] = {0};
    scanf("%s%s", stra, strb);
    for(int i = 0; strb[i] != '\0'; i++){
        c = strb[i];
        c = isalpha(c) ? toupper(c) : c;
        strb[i] = c;
        if(isalpha(c)){
            smap[c - 'A' + 10] = true;
        } else if(c == '_') {
            smap[36] = true;
        } else {
            smap[c - '0'] = true;
        }
    }
    for(int i = 0; stra[i] != '\0'; i++){
        c = stra[i];
        c = isalpha(c) ? toupper(c) : c;
        if(isalpha(c)){
            if(!smap[c - 'A' + 10]){
                smap[c - 'A' + 10] = true;
                printf("%c", c);
            }
        } else if(c == '_'){
            if(!smap[36]){
                smap[36] = true;
                printf("%c", '_');
            }
        } else {
            if(!smap[c - '0']){
                smap[c - '0'] = true;
                printf("%c", c);
            }
        }
    }
    return 0;
}
