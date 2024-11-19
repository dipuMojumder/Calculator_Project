#include <stdio.h>
#include "all_func.c"

void print_menu(char menu_name[], char prompt[], char options[][30], int no_of_options);
void print_repeated_char(char ch, int length);
int print_centered_str(char str[], int width);

void main_menu();
void add_menu();
void subt_menu();
void div_menu();
void mult_menu();
void eqn_menu();
void misc_menu();
void area_menu();



void main_menu() {
	char menu_name[] = "Main Menu";
	char prompt[] = "Which operation would you like to perform?";
	char options[][30] = {
		"Add",
		"Subtract",
		"Divide",
		"Multiply",
		"Solve Equation",
		"Miscellaneous",
		"Exit",
		"Extra"
	};

	while (1) {
		int no_of_options = sizeof(options) / sizeof(options[0]);

		print_menu(menu_name, prompt, options, no_of_options);

		int choice;
		scanf("%d", &choice);

		switch (choice) {
			case 1: add_menu(); break;
			case 2: subt_menu(); break;
			case 3: div_menu(); break;
			case 4: mult_menu(); break;
			case 5: eqn_menu(); break;
			case 6: misc_menu(); break;
			case 7: return;
			case 8: extra_menu(); break;
			default: invalid();
		}
	}
}


void add_menu() {
	char menu_name[] = "Addition Menu";
	char prompt[] = "Which type of addition would you like to perform?";
	char options[][30] = {
		"Simple Addition",
		"Advanced Addition",
		"Matrix Addition",
		"Return to Main Menu",
	};

	int no_of_options = sizeof(options) / sizeof(options[0]);

	while (1) {
		print_menu(menu_name, prompt, options, no_of_options);

		int choice;
		scanf("%d", &choice);

		switch (choice) {
			case 1: add_simple(); break;
			case 2: add_advanced(); break;
			case 3: add_matrix(); break;
			case 4: return;
			default: invalid();
		}
	}
}


void subt_menu() {
	char menu_name[] = "Subtraction Menu";
	char prompt[] = "Which type of subtraction would you like to perform?";
	char options[][30] = {
		"Simple Subtraction",
		"Absolute Difference",
		"Return to Main Menu",
	};

	int no_of_options = sizeof(options) / sizeof(options[0]);

	while (1) {
		print_menu(menu_name, prompt, options, no_of_options);

		int choice;
		scanf("%d", &choice);

		switch (choice) {
			case 1: subt_simple(); break;
			case 2: subt_absolute(); break;
			case 3: return;
			default: invalid();
		}
	}
}


void div_menu() {
	char menu_name[] = "Division Menu";
	char prompt[] = "Which type of division would you like to perform?";
	char options[][30] = {
		"Simple Division",
		"Advanced Division",
		"Return to Main Menu"
	};

	int no_of_options = sizeof(options) / sizeof(options[0]);

	while (1) {
		print_menu(menu_name, prompt, options, no_of_options);

		int choice;
		scanf("%d", &choice);

		switch (choice) {
			case 1: div_simple(); break;
			case 2: div_advanced(); break;
			case 3: return;
			default: invalid();
		}
	}
}


void mult_menu() {
	char menu_name[] = "Multiplication Menu";
	char prompt[] = "Which type of multiplication would you like to perform?";
	char options[][30] = {
		"Simple Multiplication",
		"Modulo Multiplication",
		"Matrix Multiplication",
		"Exponentiation",
		"Return to Main Menu"
	};

	int no_of_options = sizeof(options) / sizeof(options[0]);

	while (1) {
		print_menu(menu_name, prompt, options, no_of_options);

		int choice;
		scanf("%d", &choice);

		switch (choice) {
			case 1: mult_simple(); break;
			case 2: mult_modulo(); break;
			case 3: mult_matrix(); break;
			case 4: mult_exponent(); break;
			case 5: return;
			default: invalid();
		}
	}
}


void eqn_menu() {
	char menu_name[] = "Equation Menu";
	char prompt[] = "Which type of equation would you like to solve?";
	char options[][30] = {
		"Simple Equation",
		"Complex Equation",
		"Return to Main Menu",
	};

	int no_of_options = sizeof(options) / sizeof(options[0]);

	while (1) {
		print_menu(menu_name, prompt, options, no_of_options);

		int choice;
		scanf("%d", &choice);

		switch (choice) {
			case 1: eqn_simple(); break;
			case 2: eqn_complex(); break;
			case 3: return;
			default: invalid();
		}
	}
}


void misc_menu() {
	char menu_name[] = "Miscellaneous Menu";
	char prompt[] = "Which operation would you like to perform?";
	char options[][30] = {
		"Calculate Area",
		"Calculate Age",
		"Statistics",
		"Return to Main Menu",
	};

	int no_of_options = sizeof(options) / sizeof(options[0]);

	while (1) {
		print_menu(menu_name, prompt, options, no_of_options);

		int choice;
		scanf("%d", &choice);

		switch (choice) {
			case 1: area_menu(); break;
			case 2: misc_age(); break;
			case 3: misc_statistics(); break;
			case 4: return;
			default: invalid();
		}
	}
}


void area_menu() {
	char menu_name[] = "Area Menu";
	char prompt[] = "Which type of area would you like to calculate?";
	char options[][30] = {
		"Triangle",
		"Rectangle",
		"Trapezium",
		"Circle",
		"Return to Miscellaneous Menu",
	};

	int no_of_options = sizeof(options) / sizeof(options[0]);

	while (1) {
		print_menu(menu_name, prompt, options, no_of_options);

		int choice;
		scanf("%d", &choice);

		switch (choice) {
			case 1: area_triangle(); break;
			case 2: area_rectangle(); break;
			case 3: area_trapezium(); break;
			case 4: area_circle(); break;
			case 5: return;
			default: invalid();
		}
	}
}


void extra_menu() {
	char menu_name[] = "Extra Menu";
	char prompt[] = "Which operation would you like to perform?";
	char options[][30] = {
		"Divisibility",
		"Combinatorics",
		"Return to Main Menu",
	};

	int no_of_options = sizeof(options) / sizeof(options[0]);

	while (1) {
		print_menu(menu_name, prompt, options, no_of_options);

		int choice;
		scanf("%d", &choice);

		switch (choice) {
//			case 1: area_triangle(); break;
//			case 2: area_rectangle(); break;
//			case 3: area_trapezium(); break;
//			case 4: area_circle(); break;
//			case 5: return;
			default: invalid();
		}
	}
}



void print_menu(char menu_name[], char prompt[], char options[][30], int no_of_options) {

    int box_width = 60;
    char horizontal_line_char = '-';
    char vertical_line_char = '|';
    char corner_char = '+';

	// line 1 - top border
    putchar('\n');
	putchar(corner_char);
    print_repeated_char(horizontal_line_char, box_width-2);
	putchar(corner_char);
    putchar('\n');

	// line 2 - menu name
	putchar(vertical_line_char);
	print_centered_str(menu_name, box_width-2);
	putchar(vertical_line_char);
    putchar('\n');

	// line 3 - divider
	putchar(vertical_line_char);
	print_repeated_char(horizontal_line_char, box_width-2);
	putchar(vertical_line_char);
    putchar('\n');

	// line 4 - prompt
	putchar(vertical_line_char);
	int left_spaces = print_centered_str(prompt, box_width-2);
	putchar(vertical_line_char);
    putchar('\n');

	// line 5 - blank
	putchar(vertical_line_char);
	print_repeated_char(' ', box_width-2);
	putchar(vertical_line_char);
    putchar('\n');


    // options
	int num_width = left_spaces + 1;
	int option_width = box_width - num_width - 4;

	for (int i = 0; i < no_of_options; i++) {
		putchar(vertical_line_char);
		printf("%*d. ", num_width, i+1);
		printf("%-*s", option_width, options[i]);
		putchar(vertical_line_char);
		putchar('\n');
	}

	// last line - bottom border
	putchar(corner_char);
    print_repeated_char(horizontal_line_char, box_width-2);
	putchar(corner_char);
    putchar('\n');

    printf("\nEnter your choice: ");
}


//*/
