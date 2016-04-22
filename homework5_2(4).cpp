#include<iostream>
#include<vector>
std::vector<char> chvec;
std::vector<int> numvec;
int x, y;
bool judge = false;
void search(int n,std::vector<char> direction);

int main(void) {
	std::vector<char> direction;
	std::cin >> x >> y;
	char ch;
	for (int ix = 0; ix < x*y; ++ix)
	{
		std::cin >> ch;
		chvec.push_back(ch);
		numvec.push_back(0);
		direction.push_back(' ');
	}

	for (int ix = 0; ix < x*y; ++ix)
	{
		if (numvec[ix] == 0)
		{
			numvec[ix]++;
			search(ix,direction);
		}
		if (judge == true)
		{
			std::cout << "Yes" << std::endl;
			break;
		}
	}
	if (judge == false)
		std::cout << "No" << std::endl;

	return 0;
}

void search(int n, std::vector<char> direction)
{
	if (judge == true)
		return;
	if ((n + y) <= (x*y - 1))
	{
		if (chvec[n + y] == chvec[n])
		{
			if (direction[n] != 'u')
			{
				direction[n+y] = 'd';
				numvec[n + y]++;
				if (numvec[n + y] >= 2)
					judge = true;
				search(n + y,direction);
			}
		}
	}

	if ((n + 1) <= ((n / y)*y + y - 1))
	{
		if (chvec[n + 1] == chvec[n])
		{
			if (direction[n] != 'l')
			{
				direction[n+1] = 'r';
				numvec[n + 1]++;
				if (numvec[n + 1] >= 2)
					judge = true;
				search(n + 1,direction);
			}
		}
	}

	if ((n - y) >= 0)
	{
		if (chvec[n - y] == chvec[n])
		{
			if (direction[n] != 'd')
			{
				direction[n-y] = 'u';
				numvec[n - y]++;
				if (numvec[n - y] >= 2)
					judge = true;
				search(n - y,direction);
			}
		}
	}
	if ((n - 1) >= 0 && (n - 1) >= (n / y)*y)
	{
		if (chvec[n - 1] == chvec[n])
		{
			if (direction[n] != 'r')
			{
				direction[n-1] = 'l';
				numvec[n - 1]++;
				if (numvec[n - 1] >= 2)
					judge = true;
				search(n - 1,direction);
			}
		}
	}
}