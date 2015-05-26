#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OP_ADD '+'
#define OP_SUB '-'
#define OP_MUL '*'
#define OP_DIV '/'
#define OP_DEF '='

int compute_add(char* expr) {
	int sum = 0;

	while (*expr != ')') {
		if (*expr == ' ') {
			expr++; continue;
		}

		int m = 0;
		sscanf(expr++, "%d", &m);
		sum += m;
	}

	return sum;
}

int compute_mul(char* expr) {
	int prod = 1;

	while (*expr != ')') {
		if (*expr == ' ') {
			expr++; continue;
		}

		int m = 0;
		sscanf(expr++, "%d", &m);
		prod *= m;
	}

	return prod;
}

int compute_div(char* expr) {
	int m = 0;
	int n = 0;

	while(*(++expr) == ' ');

	sscanf(expr, "%d", &m);
	++expr;
	
	while(*(++expr) == ' ');

	sscanf(expr, "%d", &n);

	return m / n;
}

int eval(char* expr) {

	if (*(expr++) != '(') {
		printf("Expression must begin with a '('\n");
		return -1;
	}

	char op = *(expr++);

	switch (op) {
		case OP_ADD:
			return compute_add(expr);
		case OP_MUL:
			return compute_mul(expr);
		case OP_DIV:
			return compute_div(expr);
		default:
			return 0;
	}
	
	return 0;
}

char* read() {
	char* expr = malloc(256);
	fgets(expr, 256, stdin);

	return expr;
}


int main(int argc, char** argv) {

	while (1) {
		printf("-> %d\n", eval(read()));
	}

	return 0;
}
