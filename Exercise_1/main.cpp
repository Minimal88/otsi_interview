#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std; 

#define BUFF_MAX 100
#define UNS_MAX 100

// Variables Definitions
string str;
char r_str[BUFF_MAX];
int str_len;

unsigned int rnd_number;
unsigned int uns_int[UNS_MAX];



// Functions Definitions
unsigned int rnd(){
	// Initialize random seed
	srand (time(NULL));

	unsigned int part;
	part = rand() % 1000000000 + 999999999;	
	
	return part;
}



int main(int argc, char* argv[]) {

	
	cout<<"\n\n--------------------------\n";
	cout<<"--->EXERCISE 1.1 & 1.3<---\n";
	cout<<"--------------------------\n\n";

	cout<<"Insert a string of "<<BUFF_MAX<<" characters maximun:\n";
	cin>>str;
	str_len = str.length();
	
	//Check for memory leaks
	if (str_len>BUFF_MAX){
		cout<<"Error: String is bigger than expected!!\n";
	}else{

		// Reverse the given string
		for (int i=0,j=str_len-1; i < str_len; ++i,j--){
			r_str[i] = str[j];			
		}

		cout<<"\nThe reversed string is: "<<r_str<<"\n";	

		//Compare the two strings
		if (str.compare(r_str)==0){
			cout<<"The string IS a palladium"<<"\n";	
		}else{
			cout<<"The string INS'T a palladium"<<"\n";	
		}
	}


	cout<<"\n\n--------------------------\n";
	cout<<"--->   EXERCISE 1.2   <---\n";
	cout<<"--------------------------\n\n";

	cout<<"\nGenerating 10 unsigned integers...\n";
	rnd_number = rnd();

	

	cout<<"Random number: "<<rnd_number<<"\n";

	for (int i = 9; i >= 0; i--) {
	    uns_int[i] = rnd_number % 10;
	    rnd_number /= 10;
	    //cout<<"Array: "<<uns_int[i]<<"\n";
		
	}

	cout<<"\nEvery 3 interger in the list:\n";
	for (int i = 2; i < 9; i=i+3){
		cout<<uns_int[i]<<"-";
	}
	cout<<"\n";
}