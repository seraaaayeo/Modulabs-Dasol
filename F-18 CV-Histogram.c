#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

/* 영상의 가로와 세로 길이는 본인 사진 사이즈에 맞게 지정해주세요 */
#define WIDTH      640              // 영상의 가로 크기
#define HEIGHT     360             // 영상의 세로 크기
#define Pix_Range  256          // 흑백 영상 범위

#define Max_Pix    255
#define Min_Pix    0

#define alpha      30  //더하기 연산을 위한 변수 선언 --> 출력 영상 = 원본 영상 + alpha 
#define beta       30  //빼기 연산을 위한 변수 선언 --> 출력 영상 = 원본 영상 - beta 
#define gamma      1.2 //곱하기 연산을 위한 변수 선언 --> 출력 영상 = 원본 영상 * gamma 
#define delta      1.2 //나누기 연산을 위한 변수 선언 --> 출력 영상 = 원본 영상 / delta 


typedef struct _Image_Buffer
{
	FILE *Input_Original; // 원본 영상을 불러오기 위해 파일 변수 선언

	FILE *Output_Arith_Oper_Add;
	FILE *Output_Arith_Oper_Sub;
	FILE *Output_Arith_Oper_Mul;
	FILE *Output_Arith_Oper_Div;


	unsigned char *Ori_pix; //원본 영상 저장을 위한 변수 선언

	unsigned char *Arith_Oper_Add;
	unsigned char *Arith_Oper_Sub;
	unsigned char *Arith_Oper_Mul;
	unsigned char *Arith_Oper_Div;

}Img_Buf;


void Open_Image(Img_Buf *image)
{
	// 원본 영상 읽기 모드로 읽어오기
	fopen_s(&image->Input_Original, "Dasol_whitsundays_640X360.raw", "rb");

	// 출력할 영상을 저장할 영상을 쓰기 모드로 열기, 저장할 영상의 파일명
	fopen_s(&image->Output_Arith_Oper_Add, "Histo-test_Add.raw", "wb");
	fopen_s(&image->Output_Arith_Oper_Sub, "Histo-test_Sub.raw", "wb");
	fopen_s(&image->Output_Arith_Oper_Mul, "Histo-test_Mul.raw", "wb");
	fopen_s(&image->Output_Arith_Oper_Div, "Histo-test_Div.raw", "wb");

	// 영상의 크기만큼 메모리 할당
	image->Ori_pix = (unsigned char*)malloc(sizeof(unsigned char) * (WIDTH * HEIGHT));
	image->Arith_Oper_Add = (unsigned char*)malloc(sizeof(unsigned char) * (WIDTH * HEIGHT));
	image->Arith_Oper_Sub = (unsigned char*)malloc(sizeof(unsigned char) * (WIDTH * HEIGHT));
	image->Arith_Oper_Mul = (unsigned char*)malloc(sizeof(unsigned char) * (WIDTH * HEIGHT));
	image->Arith_Oper_Div = (unsigned char*)malloc(sizeof(unsigned char) * (WIDTH * HEIGHT));

	//초기화
	memset(image->Ori_pix, 0, sizeof(unsigned char) * (WIDTH * HEIGHT));
	memset(image->Arith_Oper_Add, 0, sizeof(unsigned char) * (WIDTH * HEIGHT));
	memset(image->Arith_Oper_Sub, 0, sizeof(unsigned char) * (WIDTH * HEIGHT));
	memset(image->Arith_Oper_Mul, 0, sizeof(unsigned char) * (WIDTH * HEIGHT));
	memset(image->Arith_Oper_Div, 0, sizeof(unsigned char) * (WIDTH * HEIGHT));

	// fread(저장할 변수명, 한번에 읽을 메모리 크기, 메모리 크기(개수), 불러올 파일 이름);
	fread(image->Ori_pix, sizeof(unsigned char), (WIDTH * HEIGHT), image->Input_Original);
	// 원본 영상의 픽셀 정보 저장(원본 영상의 픽셀 값을 배열 변수에 저장)
}

void Close_Image(Img_Buf *image)
{
	free(image->Ori_pix);
	free(image->Arith_Oper_Add);
	free(image->Arith_Oper_Sub);
	free(image->Arith_Oper_Mul);
	free(image->Arith_Oper_Div);

	fclose(image->Input_Original);
	fclose(image->Output_Arith_Oper_Add);
	fclose(image->Output_Arith_Oper_Sub);
	fclose(image->Output_Arith_Oper_Mul);
	fclose(image->Output_Arith_Oper_Div);

}

void Image(Img_Buf *image, int Bool)
{
	if (Bool)
		Open_Image(image);
	else
		Close_Image(image);
}


unsigned char clipping(double pix_range)
{
	if (pix_range > Max_Pix) {
		return pix_range = Max_Pix;
	}
	else if (pix_range < Min_Pix) {
		return pix_range = Min_Pix;
	}
	else
		return pix_range;
}


void Arithmetic_Operation(Img_Buf *image)
{
	for (int i = 0; i < WIDTH*HEIGHT; i++) // 영상 사이즈 만큼 반복문 선언 (화소 처리)
	{
		//클리핑 주의 : 영상 픽셀값을 더하거나 곱하는 과정에서 허용 픽셀 강도(0~255) 값을 벗어나는 경우가 있기 때문에 제한해줌.
		image->Arith_Oper_Add[i] = clipping(image->Ori_pix[i] + alpha);
		image->Arith_Oper_Sub[i] = clipping(image->Ori_pix[i] - beta);
		image->Arith_Oper_Mul[i] = clipping((image->Ori_pix[i] * gamma) + 0.5);
		image->Arith_Oper_Div[i] = clipping((image->Ori_pix[i] / delta) + 0.5);
	}
}

void Output_image(Img_Buf *image)
{
	fwrite(image->Arith_Oper_Add, sizeof(unsigned char), WIDTH*HEIGHT, image->Output_Arith_Oper_Add);
	fwrite(image->Arith_Oper_Sub, sizeof(unsigned char), WIDTH*HEIGHT, image->Output_Arith_Oper_Sub);
	fwrite(image->Arith_Oper_Mul, sizeof(unsigned char), WIDTH*HEIGHT, image->Output_Arith_Oper_Mul);
	fwrite(image->Arith_Oper_Div, sizeof(unsigned char), WIDTH*HEIGHT, image->Output_Arith_Oper_Div);
}

void Output_Histogram(Img_Buf *image)
{
	//영상의 화소 수 카운트
	int    Ori_LUT[Pix_Range] = { 0 };
	int    Add_LUT[Pix_Range] = { 0 };
	int    Sub_LUT[Pix_Range] = { 0 };
	int    Mul_LUT[Pix_Range] = { 0 };
	int    Div_LUT[Pix_Range] = { 0 };

	//영상의 화소 수를 정규화 (히스토그램 정규화)
	double Normal_Ori_LUT[Pix_Range] = { 0 };
	double Normal_Add_LUT[Pix_Range] = { 0 };
	double Normal_Sub_LUT[Pix_Range] = { 0 };
	double Normal_Mul_LUT[Pix_Range] = { 0 };
	double Normal_Div_LUT[Pix_Range] = { 0 };

	//히스토그램 출력
	unsigned char Output_ori[Pix_Range][Pix_Range] = { 0 };
	unsigned char Output_add[Pix_Range][Pix_Range] = { 0 };
	unsigned char Output_sub[Pix_Range][Pix_Range] = { 0 };
	unsigned char Output_mul[Pix_Range][Pix_Range] = { 0 };
	unsigned char Output_div[Pix_Range][Pix_Range] = { 0 };

	int max_ori = 0;
	int max_add = 0;
	int max_sub = 0;
	int max_mul = 0;
	int max_div = 0;

	for (int i = 0; i < WIDTH*HEIGHT; i++) // 영상 사이즈 만큼 반복문 선언
	{
		// 히스토그램 출력을 위한 화소 카운트
		// Original 영상 카운트 // Ori_LUT[i]
		Ori_LUT[image->Ori_pix[i]]++;
		Add_LUT[image->Arith_Oper_Add[i]]++;
		Sub_LUT[image->Arith_Oper_Sub[i]]++;
		Mul_LUT[image->Arith_Oper_Mul[i]]++;
		Div_LUT[image->Arith_Oper_Div[i]]++;
	}

	for (int i = 0; i < Pix_Range; i++)
	{
		// 가장 많은 화소의 개수 찾기
		// 가장 많은 pixel intensity의 개수(frequency) 찾기
		// Original 영상 화소의 최대 수 //max_ori

		if (Ori_LUT[i] > max_ori) {
			max_ori = Ori_LUT[i];
		}
		if (Add_LUT[i] > max_add) {
			max_add = Add_LUT[i];
		}
		if (Sub_LUT[i] > max_sub) {
			max_sub = Sub_LUT[i];
		}
		if (Mul_LUT[i] > max_mul) {
			max_mul = Mul_LUT[i];
		}
		if (Div_LUT[i] > max_div) {
			max_div = Div_LUT[i];
		}
	}

	for (int i = 0; i < Pix_Range; i++)
	{
		// 히스토그램 정규화
		Normal_Ori_LUT[i] = (double)(Ori_LUT[i] * 255 / max_ori);
		Normal_Add_LUT[i] = (double)(Add_LUT[i] * 255 / max_add);
		Normal_Sub_LUT[i] = (double)(Sub_LUT[i] * 255 / max_sub);
		Normal_Mul_LUT[i] = (double)(Mul_LUT[i] * 255 / max_mul);
		Normal_Div_LUT[i] = (double)(Div_LUT[i] * 255 / max_div);
	}

	for (int i = 0; i < Pix_Range; i++)
	{
		for (int j = 0; j <= Normal_Ori_LUT[i]; j++)
		{
			Output_ori[Pix_Range - 1 - j][i] = 255;
		}

		for (int j = 0; j <= Normal_Add_LUT[i]; j++)
		{
			Output_add[Pix_Range - 1 - j][i] = 255;
		}

		for (int j = 0; j <= Normal_Sub_LUT[i]; j++)
		{
			Output_sub[Pix_Range - 1 - j][i] = 255;
		}

		for (int j = 0; j <= Normal_Mul_LUT[i]; j++)
		{
			Output_mul[Pix_Range - 1 - j][i] = 255;
		}

		for (int j = 0; j <= Normal_Div_LUT[i]; j++)
		{
			Output_div[Pix_Range - 1 - j][i] = 255;
		}
	}

	FILE  *His_ori, *His_add, *His_sub, *His_mul, *His_div;

	fopen_s(&His_ori, "Histo-test_His_Ori.raw", "wb");
	fopen_s(&His_add, "Histo-test_His_Add.raw", "wb");
	fopen_s(&His_sub, "Histo-test_His_Sub.raw", "wb");
	fopen_s(&His_mul, "Histo-test_His_Mul.raw", "wb");
	fopen_s(&His_div, "Histo-test_His_Div.raw", "wb");

	fwrite(Output_ori, sizeof(unsigned char), Pix_Range*Pix_Range, His_ori);
	fwrite(Output_add, sizeof(unsigned char), Pix_Range*Pix_Range, His_add);
	fwrite(Output_sub, sizeof(unsigned char), Pix_Range*Pix_Range, His_sub);
	fwrite(Output_mul, sizeof(unsigned char), Pix_Range*Pix_Range, His_mul);
	fwrite(Output_div, sizeof(unsigned char), Pix_Range*Pix_Range, His_div);

	fclose(His_ori);
	fclose(His_add);
	fclose(His_sub);
	fclose(His_mul);
	fclose(His_div);

}


typedef enum {
	false = 0,
	true = 1
} _bool;

_bool bool(int num) {
	if (num > 0) return true;
	return false;
}


void main()
{
	Img_Buf image;

	Image(&image, bool(true));     // 영상 열기 및 불러오기

	// 산술 연산
	Arithmetic_Operation(&image);
	Output_image(&image);
	Output_Histogram(&image);

	Image(&image, bool(false));   // 영상 닫기

	printf("Image processing all done!\n");
}