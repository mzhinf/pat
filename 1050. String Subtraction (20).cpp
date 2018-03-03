#include <cstdio>
#include <cstring>

int main(){
	char a[10005], b[10005];
	bool smap[300];
	memset(smap, 0, sizeof(smap));
	gets(a);
	gets(b);
	for(int i = 0; b[i] != '\0'; i++){
		smap[b[i]] = true;
	}
	for(int i = 0; a[i] != '\0'; i++){
		if(!smap[a[i]])printf("%c", a[i]);
	}
	return 0;
}
