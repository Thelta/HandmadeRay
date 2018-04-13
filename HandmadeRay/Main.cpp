#include <iostream>

#include "Image.h"
#include "BMP.h"

using namespace std;

int main(int argc, char* argv[])
{
	Image blue(1024, 1024);

	for (int y = 0; y < blue.GetHeight(); y++)
	{
		for (int x = 0; x < blue.GetWidth(); x++)
		{
			blue.AddPixel(Vector3<uint8_t>(0, 0, 255));
		}
	}

	BMP::TurnImageToBMP("heavenly_blue.bmp", blue);

	return 0;
}
