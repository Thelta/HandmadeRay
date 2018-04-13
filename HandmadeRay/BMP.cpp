#include <fstream>
#include <iterator>
#include "BMP.h"

#pragma warning(disable:4996)
using namespace std;

void BMP::TurnImageToBMP(string filename, Image image)
{
	vector<Vector3<uint8_t>> pixels = image.GetPixels();

	unordered_set<Vector3<uint8_t>, VECTOR3_UINT8_HASH> colorTable = image.GetColors();
	

	int bitmapColorBitCount = 32;

	size_t bitmapOffset = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
	uint32_t filesize = bitmapOffset + sizeof(RGBQUAD) * pixels.size();

	vector<RGBQUAD*> *bitmapColors = new vector<RGBQUAD*>();
	CreateBitmapColors(bitmapColors, pixels);

	const BITMAPFILEHEADER fileHeader = { 0x4D42, filesize, 0, 0, bitmapOffset };
	const BITMAPINFOHEADER infoHeader = {
		sizeof(BITMAPINFOHEADER), //biSize
		image.GetWidth(), image.GetHeight(), 1, //biWidth, biHeight, biPlanes
		bitmapColorBitCount, //biBitCount
		0, //biCompression = BI_RGB
		filesize, //biSizeImage
		2835, 2835, //biXPelsPerMeter, biYPelsPerMeter
		0, 0 // biClrUsed, biClrImportant
	};


	WriteBMP(filename, &fileHeader, &infoHeader, *bitmapColors);
	
	for(auto color : *bitmapColors)
	{
		delete color;
	}
	delete bitmapColors;

}

void BMP::CreateBitmapColors(vector<RGBQUAD*> *bitmapColors, vector<Vector3<uint8_t>> &colors)
{
	for (auto color : colors)
	{
		bitmapColors->push_back(new RGBQUAD{ color.z, color.y, color.x, 0 });
	}
}

void BMP::WriteBMP(string filename, const BITMAPFILEHEADER *fileHeader, const BITMAPINFOHEADER *infoHeader, vector<RGBQUAD*> &bitmapColors)
{
	ofstream bmpFile(filename, ofstream::binary);
	bmpFile.imbue(std::locale::classic());
	bmpFile.write((char*)fileHeader, sizeof(BITMAPFILEHEADER));
	bmpFile.write((char*)infoHeader, sizeof(BITMAPINFOHEADER));
	for (auto color : bitmapColors)
	{
		bmpFile.write((char*)color, sizeof(RGBQUAD));
	}

	bmpFile.close();
}


