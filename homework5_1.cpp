#include<iostream>
#include<vector>

int main(void) {
	std::vector<char> vec;
	char ch;
	while (vec.size() < 16)
	{
		std::cin >> ch;
		vec.push_back(ch);
	}
	int judge=0;
	for (int ix = 0; ix < 4; ++ix)
	{
		for (int iy = 0; iy < 3; ++iy)
		{
			if (vec[ix * 4 + iy] == vec[ix * 4 + iy + 1])
			{
				if (ix == 0)
				{
					if (vec[(ix + 1) * 4 + iy] == vec[ix * 4 + iy] || vec[(ix + 1) * 4 + iy + 1] == vec[ix * 4 + iy + 1])
					{
						std::cout << "YES" << std::endl;
						judge = 1;
						break;
					}
				}
				else if (ix == 3)
				{
					if (vec[(ix - 1) * 4 + iy] == vec[ix * 4 + iy] || vec[(ix - 1) * 4 + iy + 1] == vec[ix * 4 + iy + 1])
					{
						std::cout << "YES" << std::endl;
						judge = 1;
						break;
					}
				}
				else
				{
					if (vec[(ix - 1) * 4 + iy] == vec[ix * 4 + iy] || vec[(ix - 1) * 4 + iy + 1] == vec[ix * 4 + iy + 1]
						|| vec[(ix + 1) * 4 + iy] == vec[ix * 4 + iy] || vec[(ix + 1) * 4 + iy + 1] == vec[ix * 4 + iy + 1])
					{
						std::cout << "YES" << std::endl;
						judge = 1;
						break;
					}
				}
			}
		}
		if (judge == 1)
			break;
	}
	if (judge == 0)
		std::cout << "NO" << std::endl;
	return 0;
}