#include <stdio.h>
#include <math.h>
#include <string.h>
#include <limits.h>

//main() { while (1) misc_statistics(); }

// alert for invalid choice
void invalid() {
	puts("Invalid choice! Please select a valid option");
}

// prints a centered title with underline
void heading(char title[]) {
    int width = 60;
    char horizontal_line_char = '-';

	// title
    putchar('\n');
	print_centered_str(title, width);
    putchar('\n');

	// underline
    print_repeated_char(horizontal_line_char, width);
    putchar('\n');
}

// repeatedly prints a character for a specified number of times
void print_repeated_char(char ch, int length) {
	while (length--)
		putchar(ch);
}

// prints a string centered within a given width,
// by printing equal amount of spaces on both sides
int print_centered_str(char str[], int width) {
	int spaces = width - strlen(str);
	int left_spaces = spaces / 2;
	int right_spaces = spaces - left_spaces;

	print_repeated_char(' ', left_spaces);
	printf("%s", str);
	print_repeated_char(' ', right_spaces);

	return left_spaces;
}


// adds two numbers
void add_simple() {
	heading("Simple Addition");
	printf("Enter two numbers: ");

	double num1, num2;
	scanf("%lf %lf", &num1, &num2);
	printf("Sum: %.15g\n", num1+num2);
}

// adds multiple numbers
void add_advanced() {
	heading("Advanced Addition");
	puts("How many numbers would you like to add?");
	int n;
	scanf("%d", &n);

	printf("Enter %d numbers: ", n);
	double sum = 0;

	while (n--) {
		double num;
		scanf("%lf", &num);
		sum += num;
	}

	printf("Sum: %.15g\n", sum);
}

// adds two matrix
void add_matrix() {
	heading("Matrix Addition");
	printf("Enter the the number of rows and columns of the matrix: ");
	int row, col;
	scanf("%d %d", &row, &col);

	puts("Enter the first matrix:");
	double A[row][col];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%lf", &A[i][j]);
		}
	}

	puts("Enter the second matrix:");
	double B[row][col];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			scanf("%lf", &B[i][j]);
		}
	}

	puts("Sum matrix:");
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%.15g ", A[i][j] + B[i][j]);
		}
		puts("");
	}
}


// subtracts one number from another
void subt_simple() {
	heading("Simple Subtraction");
	printf("Enter two numbers: ");

	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("Subtraction result: %.15g\n", a-b);
}

// finds the absolute difference between two numbers
void subt_absolute() {
	heading("Absolute Difference");
	printf("Enter two numbers: ");
	double a, b;
	scanf("%lf %lf", &a, &b);

	double dif = a-b;
	if (dif < 0) dif *= -1;
	printf("Absolute difference: %.15g\n", dif);
}


// finds the ratio of two numbers
void div_simple() {
	heading("Simple Division");
	printf("Enter two numbers: ");

	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("Ratio: %.15g\n", a/b);
}

// divides an integer with another and shows the quotient and remainder
void div_advanced() {
	heading("Advanced Division");
	printf("Enter two numbers: ");
	long long a, b;
	scanf("%lld %lld", &a, &b);

	long long quotient = a / b;
	long long remainder = a % b;
	printf("Quotient: %lld, Remainder: %lld\n", quotient, remainder);
}


// multiplies two numbers
void mult_simple() {
	heading("Simple Multiplication");
	printf("Enter two numbers: ");

	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("Product: %.15g\n", a*b);
}

// multiplies two integers and shows the remainder of the product with respect to another integer
void mult_modulo() {
	heading("Modulo Multiplication");
	printf("Enter three numbers: ");
	long long a, b, m;
	scanf("%lld %lld %lld", &a, &b, &m);

	long long res = (a % m * b % m) % m;
	printf("Result: %lld\n", res);
}

// multiplies two matrix
void mult_matrix() {
	heading("Matrix Multiplication");
	printf("Enter the the dimension of the first matrix: ");
	int a, b;
	scanf("%d %d", &a, &b);

	puts("Enter the first matrix:");
	double X[a][b];
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++) {
			scanf("%lf", &X[i][j]);
		}
	}

	printf("Enter the the dimension of the second matrix: ");
	int c, d;
	scanf("%d %d", &c, &d);

	puts("Enter the second matrix:");
	double Y[c][d];
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < d; j++) {
			scanf("%lf", &Y[i][j]);
		}
	}

	if (b != c) {
		puts(
			"The two matrix can't be multiplied because "
			"the number of rows in the first matrix does not "
			"match the number of rows in the second matrix"
		);
		return;
	}

	puts("Result matrix:");
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < d; j++) {
			float z = 0;
			for (int k = 0; k < b; k++) {
				z += X[i][k] * Y[k][j];
			}
			printf("%.15g ", z);
		}
		puts("");
	}
}

// raises one integer to the power of another integer and shows the remainder with respect to another integer
void mult_exponent() {
	heading("Exponentiation");
	printf("Enter three numbers: ");
	long long a, b, m;
	scanf("%lld %lld %lld", &a, &b, &m);

	a %= m;
	int res = 1;

	while (b--) {
		res *= a;
		res %= b;
	}

	printf("Result: %lld\n", res);
}


// solves a system of linear equations with two variables
void eqn_simple() {
	heading("Simple Equation");
	puts("(Two-Variable Linear) ax + by = c");
	printf("Enter the coefficients of the first equation: ");

	double a1, b1, c1;
	scanf("%lf %lf %lf", &a1, &b1, &c1);

	printf("Enter the coefficients of the second equation: ");
	double a2, b2, c2;
	scanf("%lf %lf %lf", &a2, &b2, &c2);

	// cramer's rule
	double det = a1*b2 - b1*a2;
	double detx = c1*b2 - b1*c2;
	double dety = a1*c2 - c1*a2;

	double x;
	double y;

	if (det == 0) {
		if (detx != 0) {
			puts("There are no solution!");
			return;
		}
		else {
			puts("There are infinite possible solutions!");
			printf("One Possible ");
			x = 0;
			y = c1/b1;
		}
	}
	else {
		x = detx / det;
		y = dety / det;
	}

	// fixing negative zero
	if (x == -0.0) x = 0;
	if (y == -0.0) y = 0;

	printf("Solution: x = %.15g, y = %.15g\n", x, y);
}


void eqn_complex() {
	heading("Complex Equation");
	puts("(Quadratic) ax^2 + bx + c = 0");
	printf("Enter the coefficients of the quadratic equation: ");
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	printf("Solution: x = ");

	if (a == 0) { // linear solution
		printf("%g\n", -c/b);
		return;
	}

	// quadratic solution
	double d = b*b - 4*a*c;
	double x = -b / (2*a);
	double y = sqrt(fabs(d)) / (2*fabs(a)); // sqrt(discriminant)/2a, with absolute function to keep the result positive

	if (d == 0) {
		printf("%.15g\n", x);
	}
	else if (d > 0) {
		printf("{ %.15g, %.15g }\n", x+y, x-y);
	}
	else { // complex number solution
		if (x != 0) printf("%.15g ", x);
		printf("%c", 241); // plusminus (±) symbol
		if (y != 1) printf(" %.15g ", y);
		printf("i\n");
	}

}



void misc_age() {
	heading("Calculate Age");

	printf("Enter your birth date (DD/MM/YYYY): ");
	int birth_day, birth_month, birth_year;
	scanf("%d/%d/%d", &birth_day, &birth_month, &birth_year);

	printf("Enter the current date (DD/MM/YYYY): ");
	int current_day, current_month, current_year;
	scanf("%d/%d/%d", &current_day, &current_month, &current_year);

	int age_day, age_month, age_year;
	age_year = current_year - birth_year;
	age_month = current_month - birth_month;
	age_day = current_day - birth_day;

	if (age_day < 0) {
		age_day += days_in_previous_month(current_month, current_year);
		age_month--;
	}

	if (age_month < 0) {
		age_month += 12;
		age_year--;
	}

	printf("You are %d years %d months and %d days old\n", age_year, age_month, age_day);
}


int days_in_previous_month(int current_month, int current_year) {
	int days = 31;

	if (current_month == 3) {
		if (current_year % 400 == 0 || (current_year % 4 == 0 && current_year % 100 != 0))
			days = 29;
		else
			days = 28;
	}
	else if (current_month ==  5 || current_month ==  7 || current_month ==  10 || current_month ==  12)
		days = 30;

	return days;
}


void selection_sort(long long A[], int n) {
	for (int i = 0; i < n; i++) {
		int k = i;
		for (int j = i+1; j < n; j++) {
			if (A[j] < A[k]) {
				k = j;
			}
		}

		long long tmp = A[i];
		A[i] = A[k];
		A[k] = tmp;
	}
}


void misc_statistics() {
	heading("Statistics");

	printf("How many numbers would you like to analyze? ");
	int n;
	scanf("%d", &n);

	printf("Enter %d integers: ", n);
	long long data[n];
	long long sum = 0;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &data[i]);
		sum += data[i];
	}

	double avg = (double) sum / n; //?

	selection_sort(data, n);
	long long min = data[0];
	long long max = data[n-1];

	double median = data[n/2];
	if (n % 2 == 0) {
		median = (data[n/2] + data[n/2-1]) / 2.0; //?
	}

	for (int i = 0; i < n; i++) {
		printf("%lld ", data[i]);
	}
	puts("");

	// frequency counting
	int freq[n]; // freq[i] corresponds to count of data[i]
	freq[0] = 1;
	int counting_index = 0;

	for (int i = 1; i < n; i++) {
		if (data[i] == data[i-1]) {
			freq[counting_index]++;
			freq[i] = 0; // duplicates are counted as zero
		}
		else {
			freq[i] = 1;
			counting_index = i;
		}
	}

	int max_frequency = 0;
	for (int i = 0; i < n; i++) {
		if (freq[i] > max_frequency) {
			max_frequency = freq[i];
		}
	}

	int uniq = 0;
	for (int i = 0; i < n; i++) {
		if (freq[i] > 0) {
			uniq++;
		}
	}


	float variance = 0;
	for (int i = 0; i < n; i++) {
		variance += pow(avg-data[i], 2);
	}

	variance /= n-1;

	// outputs
	printf(
		"Minimum: %lld\n"
		"Maximum: %lld\n"
		"Average: %.15g\n",
		min, max, avg
	);

	// most frequent values
	printf("Most frequent value(s): ");
	for (int i = 0; i < n; i++) {
		if (freq[i] == max_frequency) {
			printf("%lld ", data[i]);
		}
	}
	printf("\n");

	printf(
		"Number of unique values: %d\n"
		"Median: %.15g\n"
		"Variance: %.15g\n",
		uniq, median, variance
	);
}


void area_triangle() {
	heading("Area of Triangle");

	printf("Enter the side lengths of the triangle: ");
	double a, b, c;
	scanf("%lf %lf %lf", &a, &b, &c);

	// validity check
	if (a + b < c || b + c < a || c + a < b) {
		puts("This is not a valid triangle!");
		return;
	}

	double s = (a+b+c) / 2.0;
	double area = sqrt(s * (s-a) * (s-b) * (s-c));
	printf("Area: %.15g\n", area);
}


void area_rectangle() {
	heading("Area of Rectangle");
	printf("Enter the two side lengths of the rectangle: ");
	int a, b;
	scanf("%d %d", &a, &b);
	printf("Area: %d\n", a*b);
}


void area_trapezium() {
	heading("Area of Trapezium");

	printf("Enter the two parallel side lengths of the trapezium: ");
	double a, b;
	scanf("%lf %lf", &a, &b);

	printf("Enter the other two side lengths: ");
	double c, d;
	scanf("%lf %lf", &c, &d);

	double base = fabs(a-b);

	// validity check
	if (c + d < base || d + base < c || base + c < d) {
		puts("This is not a valid trapezium!");
		return;
	}

	double s = (c+d+base) / 2;
	double tri_area = sqrt(s * (s-c) * (s-d) * (s-base));
	double height = 2 * tri_area / base;

	double area = (a+b) * height / 2;
	printf("Area: %.15g\n", area);
}


void area_circle() {
	heading("Area of Circle");
	printf("Enter the radius of the circle: ");
	double radius;
	scanf("%lf", &radius);
	double pi = acos(-1);
	double area = pi*radius*radius;
	printf("Area: %.15g\n", area);
}
















