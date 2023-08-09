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