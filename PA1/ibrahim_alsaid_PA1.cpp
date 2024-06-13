#include <iostream>
#include<cstdlib>
#include<ctime>
#include <cstring>
using namespace std;

const int MAX_SIZE = 16;


void operations_fun(char sec_num[], int N) {

	char user_guess[MAX_SIZE];
	int iteration = 0;

	while (true) {
		cin >> user_guess;
		iteration++;
		int user_input = 0;
		for (int i = 0; i < MAX_SIZE; i++) {//to make sure the input length will be the same as N length 
			if (user_guess[i] != '\0') {
				user_input++;
			}
			else {

				break;//break out this for loop
			}
			if (user_guess[i] == '0' || user_guess[i] == '1' || user_guess[i] == '2' || user_guess[i] == '3' || user_guess[i] == '4' || user_guess[i] == '5' || user_guess[i]== '6' || user_guess[i] == '7' || user_guess[i] == '8' || user_guess[i] == '9' || user_guess[i] == 'a' || user_guess[i] == 'b' || user_guess[i] == 'c' || user_guess[i] == 'd' || user_guess[i] == 'e') {
				//do no thing (;
													//here just im makin sure the input in the range...

			}
			else {
				cout << "E2"; exit(0);
			}
		}
		if (user_input != N) {
			cout << "E1" << endl;
			exit(0);
		}
		int Cexact = 0;
		int Cmisplased = 0;

		for (int i = 0; i < N; i++) {
			if (user_guess[i] == sec_num[i]) {//to get the Count of exact
				Cexact++;
			}
			else {//to get the Count of misplaced

				for (int j = 0; j < N; j++) {

					if (user_guess[i] == sec_num[j]) {
						Cmisplased++;
					}
				}

			}
		}
		if (Cexact == N || iteration == 100) {// check if the user has won or not yet, and if the user reaches to the max iteration

			if (Cexact == N) {
				cout << "FOUND " << iteration;
			}
			else {
				cout << "FAILED";
			}

			exit(0);
		}

		cout << Cexact << " " << Cmisplased<<endl;

	}
}

int convert(char *value) {// to convert the second arqument that has sent to the main to integer "_" ((to get N as int))
	
		int num = atoi(value);
		if (num>=16||num<=0) {
			cout << "E0";
			exit(0);
		}
		return num;
}

bool isCharInArray(const char* arr, int size, char c) {
	for (int j = 0; j < size; j++) {
		if (arr[j] == c) {
			return true; // Return true if the character exists in the array
		}
	}
	return false; // Return false if the character does not exist in the array
}



void funr(int N) {
	srand(time(0));
	char sec_num[MAX_SIZE];
	//to make sure the fist num not 0
	do {
		if (rand() % 10 < 5) {
			sec_num[0] = '1' + rand() % 9; // Random number between '1' and '9'
		}
		else {
			sec_num[0] = 'a' + rand() % 5; // Random lowercase letter between 'a' and 'e'
		}
	} while (sec_num[0] == '0');
		
	for (int i = 1; i < N; i++) {
		char new_char;
		do {
			if (rand() % 10 < 5) {
				new_char = '0' + rand() % 10; // Random number between '0' and '9'
			}
			else {
				new_char = 'a' + rand() % 5; // Random lowercase letter between 'a' and 'e'
			}
		} while (isCharInArray(sec_num, i, new_char)); // Check if the character already exists
		sec_num[i] = new_char;
	}
	

	operations_fun(sec_num,N);
	
}

int check_sec_number(char user_input[]) {//this function to check the user's secret number ((" -u "))

	int counter=0;
	while (user_input[counter]!='\0') {
		counter++;
	
	}
	if (counter >= 1 && counter<=15) {//check if the input in the range
	
		for (int i = 0; i < counter;i++) {
		
			if (user_input[i] == '0'||user_input[i]== '1'|| user_input[i] == '2'|| user_input[i] == '3'|| user_input[i] == '4'|| user_input[i] == '5'|| user_input[i] == '6' || user_input[i] == '7'|| user_input[i] == '8'|| user_input[i] == '9'|| user_input[i] == 'a'|| user_input[i] == 'b'|| user_input[i] == 'c'|| user_input[i] == 'd'|| user_input[i] == 'e') {
					
					//do nothing
			}
			else {
				cout << "E2";
				exit(0);
			}
		}
		
		return counter;
	}
	else {
		cout << "E0";
		exit(0);
	}

}

int main(int argc, char* argv[]) {

	if (strcmp(argv[1], "-r") == 0) {// if the argv -r
		char *n = argv[2];
		int N = convert(n);
		funr(N);
	}
	else if (strcmp(argv[1], "-u") == 0) { //if the argv -u

		char* user_in = argv[2];
		int counter=check_sec_number(user_in);
		operations_fun(user_in,counter);
		
	}
	else
		cout << "E0";

	return 0 ;
}