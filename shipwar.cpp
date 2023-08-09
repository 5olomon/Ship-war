#include<iostream>
#include<time.h>
#include<iomanip>
#include<Windows.h>
using namespace std;

FILE* file;

enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
}​;
void save_file(int arr[][10], int arr1[][10]) {
	fopen_s(&file, "game.dat", "wb");
	fwrite((char*)arr, sizeof(int), 100, file);
	fwrite((char*)arr1, sizeof(int), 100, file);
	fclose(file);
}
void load_file(int arr[][10], int arr1[][10]) {
	fopen_s(&file, "game.dat", "rb");
	fread((char*)arr, sizeof(int), 100, file);
	fread((char*)arr1, sizeof(int), 100, file);
	fclose(file);
}
void fulling(int* f_arr, int& length) {
	for (int i = 0; i < length; i++)
	{
		f_arr[i] = i;
	}
}
int* del(int array[], int& size, int position)
{
	if (position >= size) return 0;

	int* temp = new int[size];
	for (size_t i = 0; i < size; ++i) temp[i] = array[i];

	delete[] array;
	array = new int[size - 1];

	for (size_t i = 0, j = 0; i < size; ++i, ++j)
		if (i != position) array[j] = temp[i];
		else --j;
	--size;

	delete[] temp;
	return array;
}
void field(int arr[][10], int arr1[][10]) {
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	int numb = 0;
	cout << "  1 2 3 4 5 6 7 8 9 10		  1 2 3 4 5 6 7 8 9 10" << endl;
	for (size_t i = 0; i < 10; i++)
	{
		cout << setw(2) << left << ++numb;
		for (size_t j = 0; j < 10; j++)
		{
			Sleep(5);
			if (arr[i][j] == 0) {
				SetConsoleTextAttribute(h, (0 << 4) | 8);
				cout << char(176) << char(176);
			}
			else if (arr[i][j] >= 1) {
				SetConsoleTextAttribute(h, (0 << 4) | 6);
				cout << char(219) << char(219);
			}
			else if (arr[i][j] == -2) {
				SetConsoleTextAttribute(h, (0 << 4) | 4);
				cout << char(177) << char(177);
			}
			else if (arr[i][j] == -1) {
				SetConsoleTextAttribute(h, (0 << 4) | 14);
				cout << char(176) << char(176);
			}
			//cout << arr[i][j]<<" ";
			SetConsoleTextAttribute(h, (0 << 4) | 15);
		}
		cout << "\t\t";
		cout << setw(2) << left << numb;
		for (size_t z = 0; z < 10; z++)
		{
			if (arr1[i][z] == 0) {
				SetConsoleTextAttribute(h, (0 << 4) | 6);
				cout << char(176) << char(176);
			}
			else if (arr1[i][z] >= 1) {
				SetConsoleTextAttribute(h, (0 << 4) | 8);
				cout << char(219) << char(219);
			}
			else if (arr1[i][z] == -2) {
				SetConsoleTextAttribute(h, (0 << 4) | 4);
				cout << char(177) << char(177);
			}
			else if (arr1[i][z] == -1) {
				SetConsoleTextAttribute(h, (0 << 4) | 14);
				cout << char(176) << char(176);
			}
			//cout << arr1[i][z] << " ";
			SetConsoleTextAttribute(h, (0 << 4) | 15);

		}
		cout << "\n";
	}

}
void ships(int arr[][10], int length, int ship_num) {
	int X, Y;
	int count = 0;
	int napravlen;
	while (count != 1)
	{
		X = rand() % 10;
		Y = rand() % 10;
		int first_x = X, first_y = Y;
		napravlen = rand() % 4;
		bool rules = 1;

		for (size_t i = 0; i < length; i++)
		{
			if (X < 0 || Y < 0 || X > 10 || Y>10)
			{
				rules = false;
				break;
			}
			if (arr[X][Y] >= 1 ||
				arr[X][Y - 1] >= 1 ||
				arr[X][Y + 1] >= 1 ||
				arr[X - 1][Y] >= 1 ||
				arr[X + 1][Y] >= 1 ||
				arr[X - 1][Y - 1] >= 1 ||
				arr[X + 1][Y + 1] >= 1 ||
				arr[X + 1][Y - 1] >= 1 ||
				arr[X - 1][Y + 1] >= 1) {
				rules = false;
				break;
			}
			if (napravlen == 0)
				X++;
			else if (napravlen == 1)
				Y++;
			else if (napravlen == 2)
				X--;
			else if (napravlen == 3)
				Y--;
		}
		if (rules == 1)
		{
			X = first_x;
			Y = first_y;
			for (size_t i = 0; i < length; i++)
			{

				arr[X][Y] = ship_num;

				if (napravlen == 0)
				{
					X++;
				}
				else if (napravlen == 1)
				{
					Y++;
				}
				else if (napravlen == 2)
				{
					X--;
				}
				else if (napravlen == 3)
				{
					Y--;
				}
			}
			count++;
		}
	}
}
void ships_in_field(int arr[][10], int ship[10]) {
	for (size_t i = 0; i <= 10; i++)
	{
		ships(arr, ship[i], i);
	}
}
bool ship_show(int arr[][10], int X, int  Y, int napravlen, int length) {
	bool rules = 1;
	int first_X = X;
	int first_Y = Y;


	for (size_t i = 0; i < length; i++)
	{
		if (X < 0 || Y < 0 || X > 10 || Y>10)
		{
			rules = false;
			return rules;

		}
		if (arr[X][Y] >= 1 ||
			arr[X][Y - 1] >= 1 ||
			arr[X][Y + 1] >= 1 ||
			arr[X - 1][Y] >= 1 ||
			arr[X + 1][Y] >= 1 ||
			arr[X - 1][Y - 1] >= 1 ||
			arr[X + 1][Y + 1] >= 1 ||
			arr[X + 1][Y - 1] >= 1 ||
			arr[X - 1][Y + 1] >= 1) {
			rules = false;
			return rules;
		}
		if (napravlen == 0)
			X++;
		else if (napravlen == 1)
			Y++;
		else if (napravlen == 2)
			X--;
		else if (napravlen == 3)
			Y--;
	}

	if (rules == 1) {
		X = first_X;
		Y = first_Y;
		for (size_t i = 0; i < length; i++)
		{
			arr[X][Y] = 1;
			if (napravlen == 0)
			{
				X++;
			}
			else if (napravlen == 1)
			{
				Y++;
			}
			else if (napravlen == 2)
			{
				X--;
			}
			else if (napravlen == 3)
			{
				Y--;
			}
		}
	}
	return rules;
}
int atack(int arr[][10], int arr1[][10], int ship[], int person_X, int person_Y) {
	int popal = 0;
	if (arr[person_X - 1][person_Y - 1] >= 1)
	{
		ship[arr[person_X][person_Y]]--;
		if (ship[arr[person_X][person_Y]] < 0) {
			popal = 2;
			Sleep(1000);
		}
		else {
			popal = 1;
			Sleep(1000);
		}
		arr[person_X - 1][person_Y - 1] = -2;
	}
	else
	{
		arr[person_X - 1][person_Y - 1] = -1;
	}
	save_file(arr, arr1);
	return popal;
}
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
int main() {
	srand(time(NULL));
	int menu = 0;
	bool rules = 1;
	const int nn = 10;
	int ship_num = 1;
	int punkt = 1;
	int ship[11]{ 0,4,3,3,2,2,2,1,1,1,1 };
	int handle_ship[10]{ 4,3,3,2,2,2,1,1,1,1 };
	int ship1[11]{ 0,4,3,3,2,2,2,1,1,1,1 };
	int arr[10][10]{};
	int arr1[10][10]{};
	int naprav = 4;
	int* arr_naprav = new int[naprav] {};
	int result;
	int person_X = 0, person_Y = 0;
	int napravlen;
	cout << "New game(1)" << "\n" << "Continue(2)" << "\n";
	cin >> menu;
	field(arr, arr1);
	if (menu == 1)
	{
		cout << "Input punkt :\n1-automaticaly ships\n2-handle ships\n";
		cin >> punkt;
		ships_in_field(arr1, ship1);
		ships_in_field(arr, ship);
	}
	if (menu == 2)
	{
		load_file(arr, arr1);
	}
	field(arr, arr1);

	if (punkt == 1) {
		do
		{
			
			field(arr, arr1);
			cout << "Input coordinats(with space):";
			cin >> person_Y >> person_X;
			result = atack(arr1, arr, ship1, person_X, person_Y);
			if (result == 2)
			{
				cout << "You hit,but dont kill" << endl;
				Sleep(1000);
			}
			else if (result == 1)
			{
				cout << "You kill" << endl;
				Sleep(1000);
			}
			else
			{
				cout << "You dont hit" << endl;
				Sleep(1000);
			}

			bots_logic(arr, arr1, ship, ship_num, arr_naprav, naprav);

		} while (true);
	}
	else if (punkt == 2)
	{
		for (size_t i = 0; i < 10; i++)
		{
			field(arr, arr1);
			cout << "Input coords:";
			cin >> person_Y;
			cin >> person_X;
			cout << "Input which side:\n0-down\n1-right\n2-up\n3-left\n";
			cin >> napravlen;
			if (ship_show(arr, person_X - 1, person_Y - 1, napravlen, handle_ship[i]) != 1) {
				i--;
			}
		}
		field(arr, arr1);
		do
		{
			field(arr, arr1);
			cout << "Input coordinats(with space):";
			cin >> person_Y >> person_X;
			result = atack(arr1, arr, ship1, person_X, person_Y);
			if (result == 2)
			{
				cout << "You hit,but dont kill" << endl;
				Sleep(1000);
			}
			else if (result == 1)
			{
				cout << "You kill" << endl;
				Sleep(1000);
			}
			else
			{
				cout << "You dont hit" << endl;
				Sleep(1000);
			}
			bots_logic(arr, arr1, ship, ship_num, arr_naprav, naprav);

		} while (true);
	}
}