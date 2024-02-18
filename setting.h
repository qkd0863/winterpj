#pragma once
#include <SDKDDKVer.h>

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <tchar.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#include "TreeNode.h"

const int Map_x = 60;
const int Map_y = 60;

const int UP = 72;
const int DOWN = 80;
const int LEFT = 75;
const int RIGHT = 77;
const int ESC = 27;
const int ENTER = 13;
const int SPACE = 32;
const int TAP = 9;
const int Q = 113;



const int SIZE_ARR_X = 60;
const int SIZE_ARR_Y = 60;
extern int arr[SIZE_ARR_X][SIZE_ARR_Y];
extern int roomnum;
using namespace std;


void gotoxy(int x, int y);


struct xy
{
	int x, y;
};