#include<iostream>
#include<vector>
std::vector<char> chvec;
std::vector<int> numvec;
int x, y,k;
void search_for_wall(int n, std::vector<char> &direction, int &count);

int main(void) {
	std::cin >> x >> y>>k;
	char ch;
	int count=0;
	std::vector<char> direction;
	for (int ix = 0; ix < x*y; ++ix)
	{
		std::cin >> ch;
		chvec.push_back(ch);
		numvec.push_back(0);
		direction.push_back(' ');
	}
	for (int iy = 0; iy < x*y; ++iy)
	{
		numvec[iy]++;
		if (chvec[iy] == '.')
		{
			search_for_wall(iy, direction, count);
			break;
		}
	}

	for (int iz = 0; iz <x; ++iz)
	{
		for (int it = 0; it < y; ++it)
		{
			std::cout << chvec[it + iz*y];
		}
		std::cout << std::endl;
	}

	return 0;
}

void search_for_wall(int n,std::vector<char> &direction,int &count)
{
	if ((n + y) <= (x*y - 1))
	{
		if (chvec[n + y] == chvec[n])
		{
			if (direction[n] != 'u')
			{
				numvec[n + y]++;
				if (numvec[n + y] >= 2)
				{
					numvec[n + y]--;
				}
				else
				{
					direction[n + y] = 'd';
					search_for_wall(n + y, direction,count);
				}
			}
		}
	}
	if ((n + 1) <= ((n / y)*y + y - 1))
	{
		if (chvec[n + 1] == chvec[n])
		{
			if (direction[n] != 'l')
			{
				numvec[n + 1]++;
				if (numvec[n + 1] >= 2)
				{
					numvec[n + 1]--;
				}
				else
				{
					direction[n + 1] = 'r';
					search_for_wall(n + 1, direction,count);
				}
			}
		}
	}
	if ((n - y) >= 0)
	{
		if (chvec[n - y] == chvec[n])
		{
			if (direction[n] != 'd')
			{
				numvec[n - y]++;
				if (numvec[n - y] >= 2)
				{
					numvec[n - y]--;
				}
				else
				{
					direction[n - y] = 'u';
					search_for_wall(n - y, direction,count);
				}
			}
		}
	}
	if  ((n - 1) >= (n / y)*y)
	{
		if (chvec[n - 1] == chvec[n])
		{
			if (direction[n] != 'r')
			{
				numvec[n - 1]++;
				if (numvec[n - 1] >= 2)
				{
					numvec[n - 1]--;
				}
				else
				{
					direction[n - 1] = 'l';
					search_for_wall(n - 1, direction,count);
				}
			}
		}
	}
	if (count == k)
	{
		return;
	}
	chvec[n] = 'X';
	count++;
}