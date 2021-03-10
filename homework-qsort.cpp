#include "std_lib_facilities.h"
#include <iterator>
#include <time.h>

void bubble_sort(vector<int>source, vector<int>&result) {
	vector<int>::iterator i1;
	vector<int>::iterator i2;
	while (source.size()>0){
		i1 = source.begin();
		for (i2 = source.begin(); i2<source.end(); i2++) {
			if (*i1<*i2) {}
			else {i1=i2;}
		}
		result.push_back(*i1);
		source.erase(i1);
	}
}

int find(vector<int>source, int num) {
	int i1 = 0;
	int i2 = source.size()-1;
	int current = num;
	
	
	while (true) {
		if (source[i1]==current) {
			return i1;
		}
		else if (source[i2]==current) {
			return i2;
		}
		else if (source[(i1+i2)/2]==current) {
			return (i1+i2)/2;
		}
		else if (i2-i1==1&&current<source[i1]) {
			return i1;
		}
		else if (i2-i1==1&&source[i1]<=current<=source[i2]) {
			return i2;
		}
		else if (source[(i2+i1)/2]>current) {
			i2 = (i2+i1)/2;
		}
		else if (source[(i2+i1)/2]<current) {
			//cout<<"So apparently source[i] is "<<source[(i2+i1)/2]<<endl;
			//if ((source[(i2+i1)/2]<5)) {cout<<"Why?";}
			i1 = (i2+i1)/2;
		}
		else {}
	}
}

void quick_sort(vector<int>source, vector<int>&result){
	int current;
	
	for (int i = 1; i<source.size(); ++i) {
		current = source[i];
	}
		
}


int main() {
	vector <int> numbers;
	vector <int> numbers2;
	vector <int> numbers3;
	srand (time(NULL));
	for (int i = 0; i<100; ++i) {
		numbers.push_back(rand()%5001);
	}
	vector<int>::iterator ptr;
	vector<int>::iterator ptr2;
	for (ptr = numbers.begin(); ptr < numbers.end(); ptr++){
		cout<<*ptr<<endl;
	}
	bubble_sort(numbers, numbers2);
	cout<<"Num2:"<<endl;
	for (ptr = numbers2.begin(); ptr < numbers2.end(); ptr++){
		cout<<*ptr<<endl;
	}
	cout<<"A whole new homework:"<<endl;

	vector <int> test1 = {1, 3, 7, 6};
	vector <int> test2;
	/*quick_sort(test1, test2);
	for (ptr = test2.begin(); ptr < test2.end(); ptr++){
		cout<<*ptr<<endl;
	}*/
	cout<<test2[0];
}
