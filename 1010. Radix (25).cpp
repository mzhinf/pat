/*
    *进制转换
*/
#include <cstdio>
#include <cstring>
#include <cmath>
typedef long long ll;

ll anyToDec(char *s, ll radix){
	ll res = 0, temp;
	for(int i = 0; s[i] != '\0'; i++){
        if(s[i] >='0' && s[i] <= '9') temp = s[i] - '0';
        else temp = s[i] - 'a' + 10;
        if(temp >= radix) return -1;//检查是否符合该进制
        res = res * radix + temp;
	}
	return res;
}

//确定范围[lr, hr]
void calRadix(ll &hr, ll &lr, char *s, ll y){
	double base, len = strlen(s) - 1;
	if(len == 0){//对于一位数的处理
        hr = y + 1;//y + 1 防止 y = 1 产生一进制错误
        lr = 2;
	} else {
	    if(s[0] >='0' && s[0] <= '9') base = s[0] - '0';
        else base = s[0] - 'a' + 10;
        hr = (ll)ceil(pow(y / base, 1.0 / len));
        lr = (ll)floor(pow(y / (base + 1), 1.0 / len));
	}
}

//二分查找[l, h] => [l, mi-1] mi [mi+1, l]
ll binSearch(ll l, ll h, char *s, ll y){
    if(h < l) return -1;
    /*
        当进制不符合时 即此时进制过小 应取[mi+1, l]
        此时返回 -1 符合之后的y > -1 取[mi+1, l]
    */
    ll mi = (h + l) / 2, t = anyToDec(s, mi);
    if(y == t) return mi;
    else if(y > t) return binSearch(mi + 1, h, s, y);
    else return binSearch(l, mi -1, s, y);
}

int main(){
	char n[2][20];
	int tag, radix;
	ll y, hr, lr, ans = -1;
	scanf("%s%s%d%d", n[0], n[1], &tag, &radix);
	tag--;
    y = anyToDec(n[tag], radix);
    calRadix(hr, lr, n[!tag], y);
    ans = binSearch(lr, hr, n[!tag], y);
    if(ans == -1) printf("Impossible\n");
    else printf("%lld\n", ans);
	return 0;
}
