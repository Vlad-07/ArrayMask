#include <iostream>

#include "vendor/stb_image/stb_image.h"

#include "ArrayMask.h"


int main()
{
	std::string path = "data/test.png";

	ArrayMask mask(path);
	
	for (int y = 0; y < mask.GetImage().m_Height; y++)
	{
		for (int x = 0; x < mask.GetImage().m_Width; x++)
		{
			std::cout << mask.GetImage().GetPixel(x, y) << "|";
		}
		std::cout << '\n';
	}

	std::cout << mask.CheckCoords(6, 0, ArrayMask::ChannelTarget::Red);

	return 0;
}