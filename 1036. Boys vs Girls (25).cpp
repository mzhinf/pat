#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Person{
	char name[11];
	char id[11];
	int grade;
	bool operator < (const Person &p) const{
		return grade < p.grade;
	}
};

int main(){
	int n;
	vector<Person> male, female;
	Person *p;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i){
		char gender;
		Person person;
		scanf("%s %c %s %d", person.name, &gender, person.id, &person.grade);
		if (gender == 'M') {
			male.push_back(person);
		} else {
			female.push_back(person);
		}
	}
	sort(male.begin(), male.end());
	sort(female.begin(), female.end());
	int res;
	bool flag = false;
	//female
	if(female.size() == 0){
		printf("Absent\n");
		flag = true;
	} else {
		p = &female[female.size() - 1];
		printf("%s %s\n", p->name, p->id);
		res = p->grade;
	}
	//male
	if(male.size() == 0){
		printf("Absent\n");
		flag = true;
	} else {
		p = &male[0];
		printf("%s %s\n", p->name, p->id);
		res -= p->grade;
	}
	//judge
	if (flag){
		printf("NA\n");
	} else {
		printf("%d\n", res);
	}
	return 0;
}