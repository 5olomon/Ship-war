#include<iostream>
#include<time.h>
#include<iomanip>
#include<Windows.h>
using namespace std;

void bots_logic(int arr[][10], int arr1[][10], int ship[10], int ship_num, int* arr_naprav, int naprav) {
	int X = 0, Y = 0;
	int first_coord_x = 0;
	int first_coord_y = 0;
	int side;
	int random;
	bool povt = false;
	int result;
	if (povt == 0) {
		X = rand() % 10;
		Y = rand() % 10;
		result = atack(arr, arr1, ship, X, Y);
		if (result == 2) {
			first_coord_x = X - 1;
			first_coord_y = Y - 1;
			povt = true;
			naprav = 4;
			fulling(arr_naprav, naprav);
			cout << "you hit,but dont kill";
		}
		else
		{
			arr[X - 1][Y - 1] = -1;
			cout << "You dont hit";
		}
	}
	if (povt == 1) {
		side = rand() % naprav;
		random = arr_naprav[side];
		if (random == 0) {
			arr_naprav = del(arr_naprav, naprav, side);
			if (arr[X][Y] >= 1)
			{
				if (X > 0) {
					X--;
				}
			}
			else
			{
				arr_naprav = del(arr_naprav, naprav, side);
				X = first_coord_x;
			}
		}
		if (random == 1)
		{
			arr_naprav = del(arr_naprav, naprav, side);
			if (arr[X][Y] >= 1) {
				if (X < 10) {
					X++;
				}

			}
			else
			{

				arr_naprav = del(arr_naprav, naprav, side);
				X = first_coord_x;
			}
		}
		if (random == 2) {
			arr_naprav = del(arr_naprav, naprav, side);
			if (arr[X][Y] >= 1)
			{
				if (Y > 0) {
					Y--;
				}
			}
			else
			{
				arr_naprav = del(arr_naprav, naprav, side);
				Y = first_coord_y;
			}
		}
		if (random == 3)
		{
			arr_naprav = del(arr_naprav, naprav, side);
			if (arr[X][Y] >= 1) {
				if (X < 10) {
					Y++;
				}

			}
			else
			{
				arr_naprav = del(arr_naprav, naprav, side);
				Y = first_coord_y;
			}
		}
		if (arr[X][Y] == 1 && ship_num > 1)
		{
			arr[X][Y] = -2;
			cout << "you hit ,but dont kill";
		}
		else if (arr[X][Y] == 1 && ship_num == 1)
		{
			arr[X][Y] = -2;
			cout << "You kill";
			povt = false;
		}
		Sleep(1000);
	}
}