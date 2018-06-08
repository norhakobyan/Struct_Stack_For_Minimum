#include <iostream>

const int size = 5;

struct Stack {
	int stack[size];
	int res;
	int minIndex;
	int minArray[size];
};

void push(Stack *, int);
int pop(Stack *);
int get_minimum(Stack *);


int main() {
	Stack * tmp = new Stack;
	tmp->res = -1;
	tmp->minIndex = 0;
	tmp->minArray[size] = { 0 };
	push(tmp, 15);
	push(tmp, 1);
	push(tmp, 4);
	push(tmp, 3);
	std::cout << "pop items " << pop(tmp) << std::endl;
	push(tmp, -5);
	std::cout << "pop items " << pop(tmp) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	int ptr = get_minimum(tmp);
	std::cout<< "Minimum Item" << std::endl;
	std::cout << ptr << std::endl;
}

void push(Stack * tmp, int sum) {
	if (tmp->res >= size)
		return;
	tmp->stack[++tmp->res] = sum;
	int items = sum;
	if (tmp->minIndex == 0 || ( tmp->minArray[tmp->minIndex-1] > sum)) {
		tmp->minArray[tmp->minIndex] = sum;
		++tmp->minIndex;
	}
	std::cout << "push items " << sum << std::endl;
}

int pop(Stack * tmp) {
	int sum = tmp->stack[tmp->res--];
	if (sum == tmp->minArray[tmp->minIndex-1]) {
		--tmp->minIndex;
	}
	return  sum;
}

int get_minimum(Stack * tmp) {
	return tmp->minArray[tmp->minIndex-1];
}
