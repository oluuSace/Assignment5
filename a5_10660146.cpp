#include<iostream>
#include<fstream>
#include<string>

using namespace std;

struct student{

	string name;
	char gender;
	int age;
	double score;
	char grade;
	string id;
};

int main(){

	int sum=0;
	double avg=0;
	int i;
	int n=0,f=0,m=0;

	student arr[5];

	cout<<"Enter the following details about you "<<endl;

	for(i=0; i<5; i++){
	cout<<"Student ID"<<"\t"<<"Name"<<"\t"<<"Age"<<"\t"<<"Gender"<<"\t"<<"Score"<<endl;
		cin>> arr[i].id>> arr[i].name>> arr[i].age>> arr[i].gender>> arr[i].score;
		cout<<endl;
	}

	for(i=0; i<5; i++){
		if(arr[i].score>=80){
			arr[i].grade='A';
		}
		else if(arr[i].score>=70){
			arr[i].grade='B';
		}
		else if(arr[i].score>=60){
			arr[i].grade='C';
		}
		else if(arr[i].score>=50){
			arr[i].grade='D';
		}
		else if(arr[i].score>=40){
			arr[i].grade='E';
		}
		else{
			arr[i].grade='F';
		}

		sum= sum + arr[i].score;
	}

	for(i=0; i<5; i++){
		if(arr[i].gender=='m' || 'M'){
			m++;
		}
		else if(arr[i].gender=='f' || 'F'){
			f++;
		}
		else{
			cout<<"Check your gender"<<endl;
		}

		n++;
	}

	avg = sum/n;

	for(i=0; i<5; i++){

		fstream my_file;

		my_file.open("Student_Details.txt");

		my_file<<"ID Number"<<"\t"<<"Name"<<"\t"<<"Age"<<"\t"<<"Gender"<<"\t"<<"Score"<<"\t"<<"Grade"<<endl;
		my_file<<"**************************************************************"<<endl;

		my_file<<arr[i].id<<"\t"<<arr[i].name<<"\t"<<arr[i].age<<"\t"<<arr[i].gender<<"\t"<<arr[i].score<<"\t"<<arr[i].grade<<endl;
		my_file<<"**************************************************************";
		my_file<<"Average Score : "<<avg<<endl;
		my_file<<"Number of Males :"<<m<<endl;
		my_file<<"Number of Females :"<<f<<endl;

		my_file.close();
	}

	return 0;
}
