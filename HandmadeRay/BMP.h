#pragma once
#include <cstdint>
#include <cstdint>
#include <string>
#include <unordered_set>
#include "image.h"



class BMP
{
#pragma pack(push, 1)
	struct BITMAPFILEHEADER
	{
		uint16_t bfType;
		uint32_t bfSize;
		uint16_t bfReserved1;
		uint16_t bfReserved2;
		uint32_t bfOffBits;
	};
#pragma pack(pop)

#pragma pack(push, 1)
	struct BITMAPINFOHEADER
	{
		uint32_t biSize;
		int32_t  biWidth;
		int32_t  biHeight;
		uint16_t biPlanes;
		uint16_t biBitCount;
		uint32_t biCompression;
		uint32_t biSizeImage;
		int32_t  biXPelsPerMeter;
		int32_t  biYPelsPerMeter;
		uint32_t biClrUsed;
		uint32_t biClrImportant;
	};
#pragma pack(pop)

#pragma pack(push, 1)
	struct RGBQUAD
	{
		uint8_t rgbBlue;
		uint8_t rgbGreen;
		uint8_t rgbRed;
		uint8_t rgbReserved;
	};
#pragma pack(pop)


	static void BMP::CreateBitmapColors(vector<RGBQUAD*> *bitmapColors, vector<Vector3<uint8_t>> &colors);
	static void WriteBMP(string filename, const BITMAPFILEHEADER *fileHeader, const BITMAPINFOHEADER *infoHeader, vector<RGBQUAD*> &bitmapColors);

	public:

	static void TurnImageToBMP(string filename, Image image);
};

