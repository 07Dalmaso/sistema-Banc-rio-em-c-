#pragma once
#ifndef TC_H
#define TC_H

#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <termios.h>

#define TC_RST  "\x1B[0m"
#define TC_BLK  "\x1B[30m"
#define TC_RED  "\x1B[31m"
#define TC_GRN  "\x1B[32m"
#define TC_YEL  "\033[33m"
#define TC_BLU  "\x1B[34m"
#define TC_MAG  "\x1B[35m"
#define TC_CYN  "\x1B[36m"
#define TC_WHT  "\x1B[37m"
#define TC_GRY  "\033[2;37m"

#define TC_B_NRM  "\x1B[0m"
#define TC_B_RED  "\x1B[0;31m"
#define TC_B_GRN  "\x1B[0;32m"
#define TC_B_YEL  "\x1B[0;33m"
#define TC_B_BLU  "\x1B[0;34m"
#define TC_B_MAG  "\x1B[0;35m"
#define TC_B_CYN  "\x1B[0;36m"
#define TC_B_WHT  "\x1B[0;37m"

#define TC_BG_NRM "\x1B[40m"
#define TC_BG_RED " \x1B[41m"
#define TC_BG_GRN "\x1B[42m"
#define TC_BG_YEL "\x1B[43m"
#define TC_BG_BLU "\x1B[44m"
#define TC_BG_MAG "\x1B[45m"
#define TC_BG_CYN "\x1B[46m"
#define TC_BG_WHT "\x1B[47m"

#define term_cls() puts("\x1B[2J")
#define term_move_xy(X, Y) printf("\033[%d;%dH", Y, X)

#define HideCursor() printf("\e[?25l");
#define ShowCursor() printf("\e[?25h");
#define ClearScreen() printf("\e[H\e[2J");

//-------------------FUNCIONALIDADES--------------------

void tc_get_cols_rows (int *cols, int *rows);
void tc_echo_off ();
void tc_echo_on ();
void tc_canon_on ();
void tc_canon_off ();
int kbhit ();
void NumToStr (unsigned long long value, char* str, short base);
void SetCursorPosition (short x, short y);
void Upper_Case (char* frase);
void Lower_Case (char* frase);

//-----------------------FUNÇÕES------------------------

void tc_get_cols_rows (int *cols, int *rows) {

	struct winsize size;
	ioctl(1, TIOCGWINSZ, &size);
	*cols = size.ws_col;
	*rows = size.ws_row;

}//tec_get_cols_rows*/

void tc_echo_off () {

	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ECHO;
	tcsetattr(1, TCSANOW, &term);

}//tc_echo_off*/

void tc_echo_on () {

	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ECHO;
	tcsetattr(1, TCSANOW, &term);

}//tc_echo_on*/

void tc_canon_on () {

	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag |= ICANON;
	tcsetattr(1, TCSANOW, &term);

}//tc_canon_on*/

void tc_canon_off () {

	struct termios term;
	tcgetattr(1, &term);
	term.c_lflag &= ~ICANON;
	tcsetattr(1, TCSANOW, &term);

}//tc_canon_off*/

int kbhit () {
	struct termios oldt, newt;
	int ch;
	int oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

	ch = getchar();

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);

	if (ch != EOF) {
		ungetc(ch, stdin);
		return 1;
	}
	return 0;
}

void NumToStr (unsigned long long value, char* str, short base) {
	char neg = 0;
	char* ini = str;
	int div = 0;

	if (base > 16 || base < 2) {
		str = 0;
		return;
	}
	if (value < 0) {
		neg = 1;
		value *= -1;
	}
	while (1) {
		short num = value % base;
		if (!num && !value)
			break;
		if (base > 10 && num > 9)
			*str = 'A' + num - 10;
		else
			*str = num + '0';
		str++;
		div = value /= base;
	}
	if (div) {
		if (base > 10 && div > 9)
			*str = 'A' + div - 10;
		else
			*str = div + '0';
		str++;
	}
	if (neg) {
		*str = '-';
		str++;
	}
	*str = 0;
	str--;
	char aux;

	while (1){
		if (ini >= str)
			break;
		aux = *str;
		*str = *ini;
		*ini = aux;
		ini++;
		str--;
	}
}

void SetCursorPosition (short x, short y) {
	printf("\033[%d;%dH", y, x);
}

void Upper_Case (char* frase) {
	size_t cont = 0;

	while (frase[cont]) {
		if (frase[cont] >= 'a' && frase[cont] <= 'z') {
			char aux = frase[cont] - 'a';
			frase[cont] = 'A' + aux;
		}
		cont++;
	}
}

void Lower_Case (char* frase) {
	size_t cont = 0;

	while (frase[cont]) {
		if (frase[cont] >= 'A' && frase[cont] <= 'Z') {
			char aux = frase[cont] - 'A';
			frase[cont] = 'a' + aux;
		}
		cont++;
	}
}

#endif