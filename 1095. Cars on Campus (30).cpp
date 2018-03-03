#include <cstdio>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

map<string, int> plate;
map<string, int>::iterator pit;
map<int, string> out;
map<int, string>::iterator oit;
vector<string> sout;
vector<string>::iterator it;

struct TimeInf{
    int time;
    int no;
    bool state;//in/true out/false
    bool use;
}timepoint[10005];

bool cmpTimeInf(const TimeInf &a, const TimeInf &b){
    return a.time < b.time;
}

struct SumTime{
    int no;
    int time;
    int st;//-1
}sumtime[10005];

bool cmpSumTime(const SumTime &a, const SumTime &b){
    return a.time > b.time;
}

int n, pn, num;
int ans = 0;
void work(int t){
    int no;
    for(;timepoint[ans].time <= t && ans < n; ans++){
        if(!timepoint[ans].use)continue;
        no = timepoint[ans].no;
        if(timepoint[ans].state){//in
            num++;
            sumtime[no].st = timepoint[ans].time;
        } else {//out
            num--;
            sumtime[no].time += timepoint[ans].time - sumtime[no].st;
            sumtime[no].st = -1;
        }
    }
}

int inTime[10005];
void init_work(){//删去为配对数据+预处理
    int no;
    for(int i = 0; i < pn; i++){
        inTime[i] = -1;
        sumtime[i].no = i;
        sumtime[i].time = 0;
        sumtime[i].st = -1;
    }
    for(int i = 0; i < n; i++){
        no = timepoint[i].no;
        if(timepoint[i].state){//in
            inTime[no] = i;
        } else {//out
            if(inTime[no] != -1) {
                timepoint[i].use = true;
                timepoint[inTime[no]].use = true;
                inTime[no] = -1;
            }
        }
    }
}

void printTime(int t){
    double st = t;
    int hh, mm, ss;
    hh = st / 3600;
    mm = (st / 3600 - hh) * 60;
    ss = t % 60;
    printf("%02d:%02d:%02d\n", hh, mm, ss);
}

int main(){
    int k, number = 0;
    char pnumber[10], state[5];
    int hh, mm, ss;
    scanf("%d%d", &n, &k);
    //scan
    for(int i = 0; i < n; i++){
        int no;
        scanf("%s %d:%d:%d %s", pnumber, &hh, &mm, &ss, state);
        //处理map
        pit = plate.find(pnumber);
        if (pit == plate.end()) {//判断是否存在
            no = number++;
            plate.insert(make_pair(pnumber, no));
            out.insert(make_pair(no, pnumber));
        } else no = pit->second;
        //TimeInf
        timepoint[i].time = hh * 3600 + mm * 60 + ss;
        timepoint[i].no = no;
        timepoint[i].state = state[0]=='i' ? true : false;
        timepoint[i].use = false;
    }
    pn = plate.size();
    sort(timepoint, timepoint + n, cmpTimeInf);
    init_work();
    //work
    for(int i = 0; i < k; i++) {
        int t;
        scanf("%d:%d:%d", &hh, &mm, &ss);
        t = hh * 3600 + mm * 60 + ss;
        //printf("%d\n", t);
        work(t);
        printf("%d\n", num);
    }
    work(23 * 60 * 60 + 59 * 60 +59);//全部处理
    sort(sumtime, sumtime + pn, cmpSumTime);
    //int st = sumtime[0].time;
    for(int i = 0; i < pn; i++){
        if(sumtime[0].time > sumtime[i].time)break;
        oit = out.find(sumtime[i].no);
        sout.push_back(oit->second);
    }
    sort(sout.begin(),sout.end());
    for(it = sout.begin(); it!=sout.end(); ++it)printf("%s ", (*it).c_str());
    printTime(sumtime[0].time);
    return 0;
}
