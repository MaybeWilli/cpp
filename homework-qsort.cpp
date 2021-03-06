#include "std_lib_facilities.h"
#include <iterator>
#include <time.h>
#include "find.h"

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

int findd(vector<int>&source, int num);

void quick_sort(vector<int>source, vector<int>&result){
	int current;
	for (int i=0; i<source.size(); i++) {
		current = source[i];
		int position = findd(result, current);
		if (position==-1) {
			result.push_back(current);
		}
		else {
			result.insert(result.begin()+position, current);
		}
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

	
	quick_sort(numbers, numbers3);
	cout<<"Did it work?"<<endl;
	for (ptr = numbers3.begin(); ptr < numbers3.end(); ptr++){
		cout<<*ptr<<endl;
	}//*/
	//cout<<find(test1, 11);
}
