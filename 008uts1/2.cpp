#include <stdio.h>

double fact(int y) {
	if (y < 2){
		return 1;
	}
	else {
		return (y * fact(y - 1));
	}
}

int main() {
	unsigned int i, n;
	double res;

	scanf("%d", &n);
	for (i = 0; i <= n ; i++){
		res = res + (1 / fact(i));
	}

	printf("Hasil dari operasi adalah %lf\n", res);
}
