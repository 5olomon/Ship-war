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