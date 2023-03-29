#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <limits.h>
#include "main.h"

int print_to_file(char *filename,void (*func)());
int compare(char *filename1, char *filename2);

void c0() {_printf("Let's print a simple sentence.\n");}
void e0() { printf("Let's print a simple sentence.\n");}
void c1() {_printf("%c", 'S');}
void e1() { printf("%c", 'S');}
void c2() {_printf("A char inside a sentence: %c. Did it work?\n", 'F');}
void e2() { printf("A char inside a sentence: %c. Did it work?\n", 'F');}
void c3() {_printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);}
void e3() { printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);}
void c4() {_printf("%s", "This sentence is retrieved from va_args!\n");}
void e4() { printf("%s", "This sentence is retrieved from va_args!\n");}
void c5() {_printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");}
void e5() { printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");}
void c6() {_printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);}
void e6() { printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);}
void c7() {_printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');}
void e7() { printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');}
void c8() {_printf("%%");}
void e8() { printf("%%");}
void c9() {_printf("Should print a single percent sign: %%\n");}
void e9() { printf("Should print a single percent sign: %%\n");}
void c10() {_printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');}
void e10() { printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');}
void c11() {_printf("css%ccs%scscscs", 'T', "Test");}
void e11() { printf("css%ccs%scscscs", 'T', "Test");}
void c12() {_printf("%c", '\0');}
void e12() { printf("%c", '\0');}
void c13() {_printf("%");}
void e13() { printf("");}

void c14() {_printf("%d", 1024);}
void e14() { printf("%d", 1024);}
void c15() {_printf("%d", -1024);}
void e15() { printf("%d", -1024);}
void c16() {_printf("%d", 0);}
void e16() { printf("%d", 0);}
void c17() {_printf("%d", INT_MAX);}
void e17() { printf("%d", INT_MAX);}
void c18() {_printf("%d", INT_MIN);}
void e18() { printf("%d", INT_MIN);}
void c19() {_printf("%d", INT_MAX + 1024); }
void e19() { printf("%d", INT_MAX + 1024); }
void c20() {_printf("%d", INT_MIN - 1024); }
void e20() { printf("%d", INT_MIN - 1024); }
void c21() {_printf("There is %d bytes in %d KB\n", 1024, 1);}
void e21() { printf("There is %d bytes in %d KB\n", 1024, 1);}
void c22() {_printf("%d - %d = %d\n", 1024, 2048, -1024);}
void e22() { printf("%d - %d = %d\n", 1024, 2048, -1024);}
void c23() {_printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e23() { printf("%d + %d = %d\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c24() {_printf("%i", 1024);}
void e24() { printf("%i", 1024);}
void c25() {_printf("%i", -1024);}
void e25() { printf("%i", -1024);}
void c26() {_printf("%i", 0);}
void e26() { printf("%i", 0);}
void c27() {_printf("%i", INT_MAX);}
void e27() { printf("%i", INT_MAX);}
void c28() {_printf("%i", INT_MIN);}
void e28() { printf("%i", INT_MIN);}
void c29() {_printf("%i", INT_MAX + 1024); }
void e29() { printf("%i", INT_MAX + 1024); }
void c30() {_printf("%i", INT_MIN - 1024); }
void e30() { printf("%i", INT_MIN - 1024); }
void c31() {_printf("There is %i bytes in %i KB\n", 1024, 1);}
void e31() { printf("There is %i bytes in %i KB\n", 1024, 1);}
void c32() {_printf("%i - %i = %i\n", 1024, 2048, -1024);}
void e32() { printf("%i - %i = %i\n", 1024, 2048, -1024);}
void c33() {_printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void e33() { printf("%i + %i = %i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));}
void c34() {_printf("%d == %i\n", 1024, 1024);}
void e34() { printf("%d == %i\n", 1024, 1024);}
void c35() {_printf("iddi%diddiiddi\n", 1024);}
void e35() { printf("iddi%diddiiddi\n", 1024);}
void c36() {_printf("%d", 10000);}
void e36() { printf("%d", 10000);}
void c37() {_printf("%i", 10000);}
void e37() { printf("%i", 10000);}
void c38() {_printf("%b", 1024);}
void e38() { printf("10000000000");}
void c39() {_printf("%b", -1024);}
void e39() { printf("11111111111111111111110000000000");}
void c40() {_printf("%b", 0);}
void e40() { printf("0");}
void c41() {_printf("%b", UINT_MAX);}
void e41() { printf("11111111111111111111111111111111");}
void c42() {_printf("%b", UINT_MAX + 1024); }
void e42() { printf("1111111111"); }
void c43() {_printf("There is %b bytes in %b KB\n", 1024, 1);}
void e43() { printf("There is 10000000000 bytes in 1 KB\n");}
void c44() {_printf("%b - %b = %b\n", 2048, 1024, 1024);}
void e44() { printf("100000000000 - 10000000000 = 10000000000\n");}
void c45() {_printf("%b + %b = %b\n", INT_MAX, INT_MAX, INT_MAX * 2); }
void e45() { printf("1111111111111111111111111111111 + 1111111111111111111111111111111 = 11111111111111111111111111111110\n"); }


int main() {
  int i,j;
  void (*checks[])() = { &c0, &c1, &c2, &c3, &c4, &c5, &c6, &c7, &c8, &c9, &c10, &c11, &c12, &c13,
                          &c14, &c15, &c16, &c17, &c18, &c19, &c20, &c21, &c22, &c23, &c24, &c25,
                           &c26, &c27, &c28, &c29, &c30, &c31, &c32, &c33, &c34, &c35, &c36, &c37, &c38, &c39, &c40, &c41, &c42, &c43, &c44, &c45};
  void (*expects[])() = { &e0,&e1, &e2, &e3, &e4, &e5, &e6, &e7, &e8, &e9, &e10, &e11, &e12, &e13,
                          &e14, &e15, &e16, &e17, &e18, &e19, &e20, &e21, &e22, &e23, &e24, &e25,
                           &e26, &e27, &e28, &e29, &e30, &e31, &e32, &e33, &e34, &e35, &e36, &e37, &e38, &e39, &e40, &e41, &e42, &e43, &e44, &e45};
  int breakpoints[] = {0,13,38,46};
  int count = sizeof(checks) / sizeof(checks[0]);
  int breakpointsCount = sizeof(breakpoints) / sizeof(breakpoints[0]);
  for (i = 0; i < count; i++)
  {
    for (j = 0; j < breakpointsCount; j++)
    {
      if (breakpoints[j] == i)
      {
        printf("-------------------");
        printf("check %d", j);
        printf("-------------------\n");
      }
    }

    printf("check %d ", i);
    print_to_file("expected_output.txt", expects[i]);
    print_to_file("output.txt", checks[i]);
    compare("output.txt", "expected_output.txt");


  }
}


//print output to file

int print_to_file(char *filename,void (*func)()) {
  FILE *fp;
  int stdout_fd, redir_fd;

  // Delete the file if it exists
	remove(filename);

	 // Create a new file
	fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Failed to create output.txt file.\n");
		return 1;
	}

	// Close the file
	fclose(fp);

	fflush(stdout);
	stdout_fd = dup(STDOUT_FILENO);
	redir_fd = open(filename, O_WRONLY);

	dup2(redir_fd, STDOUT_FILENO);
	close(redir_fd);
	func();
	fflush(stdout);
	dup2(stdout_fd, STDOUT_FILENO);
	close(stdout_fd);
  return 0;
}

// compare output files

int compare(char *filename1, char *filename2){
  FILE *fp1, *fp2;
    char line1[100], line2[100];
    int line_num = 0;
    int result = 0;

    fp1 = fopen(filename1, "r");
    fp2 = fopen(filename2, "r");

    if (fp1 == NULL || fp2 == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    while (fgets(line1, 100, fp1) && fgets(line2, 100, fp2)) {
        line_num++;
        if (strcmp(line1, line2) != 0) {
        printf("line %d:\n%s\n%s\n", line_num, line1, line2);
            result = 1;
        }
    }
    if (fgets(line1, 100, fp1)) {
        line_num++;
        printf("missing line %d:\n%s\n", line_num, line1);
        result = 1;
    }
    if (fgets(line2, 100, fp2)) {
        line_num++;
        printf("missing line %d:\n%s\n", line_num, line2);
        result = 1;
    }

    fclose(fp1);
    fclose(fp2);
	  remove(filename1);
	  remove(filename2);

    if(result == 0) {
        printf("Passed.\n");
    } else {
        printf("Failed.\n");
    }

    return 0;
}
