#include<iostream>
#include<ncurses.h>
using namespace std;

int main()
{
	initscr();
	raw();
	cout<<"hello";
	endwin();
	return 0;
}
