#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Student{
	string name;
	string id;
	int grade;
};

vector<Student> M, F;

bool sort_by_grade(const Student &a, const Student &b)
{
	return a.grade < b.grade;
}

int main(void)
{
	int nrecord;
	int i;
	int absent = 0;
	Student tmp_student;
	char sex[3];

	scanf("%d", &nrecord);
	for(i = 0; i < nrecord; ++i){
		cin >> tmp_student.name;
		cin >> sex;
		cin >> tmp_student.id;
		cin >> tmp_student.grade;
		if(sex[0] == 'F')
			F.push_back(tmp_student);
		else
			M.push_back(tmp_student);
	}
	if(F.size()){
		sort(F.begin(), F.end(), sort_by_grade);
		printf("%s %s\n", F[F.size() - 1].name.c_str(),
			F[F.size() - 1].id.c_str());
	}else{
		absent = 1;
		printf("Absent\n");
	}
	if(M.size()){
		sort(M.begin(), M.end(), sort_by_grade);
		printf("%s %s\n", M[0].name.c_str(), M[0].id.c_str());
	}else{
		absent = 1;
		printf("Absent\n");
	}
	if(absent)
		printf("NA\n");
	else
		printf("%d\n", F[F.size() - 1].grade - M[0].grade);

	return 0;
}