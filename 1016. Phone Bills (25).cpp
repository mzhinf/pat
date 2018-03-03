#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Record {
    int dd, hh, mm, time;//dd * 24 * 60 + hh * 60 + mm
    bool state;//true:on-line false:off-line
    string name;
    Record():state(false){}
    Record(char *name, int dd, int hh, int mm, bool state)
        :dd(dd), hh(hh), mm(mm), time(dd * 24 * 60 + hh * 60 + mm),
        state(state), name(name){}
};

bool cmp(const Record &a, const Record &b){
    return a.name == b.name ? a.time < b.time : a.name < b.name;
}

double calRecond(Record r, int *rate){
    double res = r.dd * 60 * rate[24] + r.mm * rate[r.hh];
    for(int i = 0; i < r.hh; i++) res += 60 * rate[i];
    return res / 100;
}

int main(){
    int rate[25] = {0};
    for(int i = 0; i < 24; i++){
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    int n, month, dd, hh, mm;
    char name[25], state[10];
    vector<Record> records;
    vector<Record>::iterator vit;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s%d:%d:%d:%d%s", name, &month, &dd, &hh, &mm, state);
        Record record(name, dd, hh, mm, strcmp(state, "on-line") == 0 ? true : false);
        records.push_back(record);
    }
    sort(records.begin(), records.end(), cmp);
    map<string, vector<Record>> customer;
    map<string, vector<Record>>::iterator mit;
    for(int i = 1; i < n; i++){
        if(records[i - 1].name == records[i].name){
            if(records[i - 1].state && !records[i].state){
                customer[records[i].name].push_back(records[i - 1]);
                customer[records[i].name].push_back(records[i]);
            }
        }
    }
    for(mit = customer.begin(); mit != customer.end(); mit++){
        printf("%s %02d\n", mit->first.c_str(), month);
        vector<Record> rec = mit->second;
        double charge = 0;
        for(int i = 1; i < rec.size(); i += 2){
            double temp = calRecond(rec[i], rate) - calRecond(rec[i - 1], rate);
            charge += temp;
            printf("%02d:%02d:%02d ", rec[i - 1].dd, rec[i - 1].hh, rec[i - 1].mm);
            printf("%02d:%02d:%02d ", rec[i].dd, rec[i].hh, rec[i].mm);
            printf("%d $%.2f\n", rec[i].time - rec[i - 1].time, temp);
        }
        printf("Total amount: $%.2f\n", charge);
    }
    return 0;
}
