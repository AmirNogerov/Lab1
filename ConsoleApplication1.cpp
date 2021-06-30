#include <iostream>

#include <vector>

#include <cmath>

using namespace std;

int main()

{

	const size_t SCREEN_WIDTH = 80;

	const size_t MAX_ASTERISK = SCREEN_WIDTH - 3 - 1;

	size_t number_count;

	cerr << "Enter number count:";

	cin >> number_count;

	vector <double> numbers(number_count);

	cerr << "Enter numbers:";

	for (int i = 0; i < number_count; i++)

	{
		cin >> numbers[i];
	}

	size_t bin_count;

	cerr << "Enter bin count:";

	cin >> bin_count;

	size_t scale;

	cerr << "Enter number of scale:";

	cin >> scale;

	if (scale > 9 || scale < 4)

	{
		cout << "ERROR";

		return 0;
	}

	double min, max;

	min = numbers[0];

	max = numbers[0];

	for (double x : numbers)

	{
		if (min > x)

			min = x;

		if (max < x)

			max = x;

	}

	vector <size_t> bins(bin_count, 0);

	for (double x : numbers)

	{
		size_t bin_index = (x - min) / (max - min) * bin_count;

		if (bin_index == bin_count)

		{
			bin_index--;
		}

		bins[bin_index]++;
	}

	size_t max_bin = bins[0];

	for (size_t bin : bins)

	{
		if (bin > max_bin)

		{
			max_bin = bin;
		}
	}

	if (max_bin > MAX_ASTERISK)

	{
		double factor = MAX_ASTERISK / static_cast<double>(max_bin);

		for (size_t bin : bins)

		{
			if (bin < 100)

			{
				cout << " ";

				if (bin < 10)

				{
					cout << " ";
				}
			}

			cout << bin << "|";

			size_t height = bin * factor;

			for (int i = 0; i < height; i++)

			{
				cout << "*";
			}

			cout << endl;
		}
	}

	else

	{
		for (size_t bin : bins)

		{
			if (bin < 100)

			{
				cout << " ";

				if (bin < 10)

				{
					cout << " ";
				}
			}

			cout << bin << "|";

			for (int i = 0; i < bin; i++)

			{
				cout << "*";
			}

			cout << endl;

		}
	} cout << " " << "|";

	size_t interval;

	if (max_bin % scale != 0)

		interval = max_bin / scale + 1;

	else

	{
		interval = max_bin / scale;

		for (int i = 1; i <= interval * scale; i++)

		{
			if (i % scale == 0)

				cout << "|";

			else

				cout << "-";

		}

		cout << '\n';

		cout << " 0";

		for (int i = 1; i < interval * scale; i++)

		{
			if ((i % scale != 0) || ((i % scale == 0) && ((i > scale))))

				cout << " ";

			else

				cout << i;
		}

		cout << interval * scale << endl;

		return 0;

	}
}