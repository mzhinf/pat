/**
    <cctype>
    isalnum() 判断是否是字母数字
    isalpha() 判断是否是英文字母
    isdigit() 判断是否是数字
    toupper() 将字母转化为大写字母
    tolower() 将字母转化为小写字母

    <string>
    assign() 拷贝
    append() 连接
*/
#include <cstdio>
#include <cctype>//判断是否是字母 数字
#include <algorithm>
#include <string>
#include <map>

using namespace std;

map<string, int> s_map;
map<string,int>::iterator s_it;

int main(){
    char c;
    string str = "";
    //一次获取一个字符
    while(~scanf("%c", &c)){
        if(isalnum(c)){
            str += tolower(c);
        } else {
            if(str.length() != 0){
                //printf("%s\n", str.c_str());
                s_map[str]++;
                str = "";
            }
        }
        if(c == '\n')break;
    }
    int s_max = -1;
    for(s_it = s_map.begin(); s_it != s_map.end(); s_it++){
        if(s_it->second > s_max){
            str = s_it->first;
            s_max = s_it->second;
        }
    }
    printf("%s %d\n", str.c_str(), s_max);
    return 0;
}
/**
qu:
Can1: "Can1 a can1 can a can?  It can!"
an:
can 3

qu:
Can1: "Can a can can a can?  It can
an:
can 5

*/

/**
//较麻烦
#include <cstdio>
#include <cctype>//判断是否是字母 数字
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<string, int> s_map;
map<string,int>::iterator s_it;
struct Str{
    string str;
    int count;
}s_count[1050000];
int s_num = 0;
bool cmp(const Str &a, const Str &b){
    return a.count > b.count;
}
vector<string> s_out;
char str[1050000];
char t_str[1050000];


int main(){
    gets(str);
    for(int i = 0, j = 0; ; i++){
        if(isalnum(str[i])){
            t_str[j++] = tolower(str[i]);
        } else {
            if(j != 0){
                t_str[j] = '\0';
                j = 0;
                //insert
                s_it = s_map.find(t_str);
                if(s_it == s_map.end()){
                    s_map.insert(make_pair(t_str, s_num));
                    s_count[s_num].str.append(t_str);
                    //printf("s_count:%s\n", s_count[s_num].str.c_str());
                    s_count[s_num].count = 1;
                    s_num++;
                } else {
                    s_count[s_it->second].count++;
                }
            } else if(str[i] == '\0') break;
        }
    }
    sort(s_count, s_count + s_num, cmp);
    int flag = s_count[0].count;
    for(int i = 0; i < s_num; i++){
        if(flag == s_count[i].count){
            s_out.push_back(s_count[i].str);
            //printf("s_out:%s\n", s_count[i].str.c_str());
        } else {
            break;
        }
    }
    sort(s_out.begin(), s_out.end());
    printf("%s %d\n", s_out[0].c_str(), flag);
    return 0;
}
*/
