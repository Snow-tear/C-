#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)


typedef unsigned char byte;
typedef unsigned short dbyte;
typedef unsigned long int dword;
typedef unsigned short word;


/*******************************************
*����bmp�ļ���ͷ�����ݽṹ
********************************************/
#pragma pack(push,2)  //����2�ֽڶ���


struct tagBITMAPFILEHEADER {
    //bmp file header
    dbyte bfType;        //�ļ�����
    dword bfSize;            //�ļ���С���ֽ�Ϊ��λ
    word bfReserved1;   //����������Ϊ0
    word bfReserved2;   //����������Ϊ0
    dword bfOffBits;         //���ļ�ͷ��ʼ��ƫ����


    //bmp info head
    dword  biSize;            //�ýṹ�Ĵ�С
    dword  biWidth;           //ͼ��Ŀ�ȣ�������Ϊ��λ
    dword  biHeight;          //ͼ��ĸ߶ȣ�������Ϊ��λ
    word biPlanes;          //ΪĿ���豸˵��λ��������ֵ������Ϊ1
    word biBitCount;        //˵��������/����
    dword biCompression;     //ͼ������ѹ������
    dword biSizeImage;       //ͼ���С�����ֽ�Ϊ��λ
    dword biXPelsPerMeter;   //ˮƽ�ֱ��ʣ�����/��
    dword biYPelsPerMeter;   //��ֱ�ֱ��ʣ�ͬ��
    dword biClrUsed;         //λͼʵ��ʹ�õĲ�ɫ���е���ɫ������
    dword biClrImportant;    //��ͼ����ʾ����ҪӰ�����ɫ��������Ŀ

    //bmp rgb quad
     //����16λ��24λ��32λ��λͼ����Ҫɫ�ʱ�
    //unsigned char rgbBlue;    //ָ����ɫǿ��
    //unsigned char rgbGreen;   //ָ����ɫǿ��
    //unsigned char rgbRed;     //ָ����ɫǿ��
    //unsigned char rgbReserved; //����������Ϊ0 
}BMPFILEHEADER;
#pragma (pop)


struct tagBITMAPFILEHEADER* bmp_p;  //����bmp�ļ�ͷ�ṹ��ָ��
FILE* fd;    //����һ���ļ����͵�ָ��


/*************************************************************
*��ʼ��bmp�ļ�ͷ��������bmpͼƬ
**************************************************************/


void Init_bmp_head(void)
{
    bmp_p = &BMPFILEHEADER;
    bmp_p->bfType = 0x4D42;    //�ļ�����
    bmp_p->bfSize = 0x25836;   //�ļ���С���ֽ�Ϊ��λ
    bmp_p->bfReserved1 = 0x0;   //����������Ϊ0
    bmp_p->bfReserved2 = 0x0;   //����������Ϊ0
    bmp_p->bfOffBits = 0x36;         //���ļ�ͷ��ʼ��ƫ����

    //bmp info head
    bmp_p->biSize = 0x28;            //�ýṹ�Ĵ�С
    bmp_p->biWidth = 320;           //ͼ��Ŀ�ȣ�������Ϊ��λ
    bmp_p->biHeight = 240;          //ͼ��ĸ߶ȣ�������Ϊ��λ
    bmp_p->biPlanes = 0x01;          //ΪĿ���豸˵��λ��������ֵ������Ϊ1
    bmp_p->biBitCount = 16;        //˵��������/����
    bmp_p->biCompression = 0;     //ͼ������ѹ������
    bmp_p->biSizeImage = 0x25800;//0x09f8;       //ͼ���С�����ֽ�Ϊ��λ
    bmp_p->biXPelsPerMeter = 0x60;//0x60;   //ˮƽ�ֱ��ʣ�����/��
    bmp_p->biYPelsPerMeter = 0x60;   //��ֱ�ֱ��ʣ�ͬ��
    bmp_p->biClrUsed = 0;         //λͼʵ��ʹ�õĲ�ɫ���е���ɫ������
    bmp_p->biClrImportant = 0;    //��ͼ����ʾ����ҪӰ�����ɫ��������Ŀ

}


int main(void)
{
    static char* file_name = NULL;    //�����ļ�����ָ��
    static long file_length = 0x25836;  //�ļ��Ĵ�С�������ļ���
    unsigned char* file_p = NULL;       //д������ָ��
    unsigned char* file_p_tmp = NULL;    //д��������ʱָ��
    unsigned char* byte_copy_p = NULL;   //�ļ�ͷ������ָ��
    unsigned char byte_copy = 0;        //�ļ�ͷ�����ݿ�������
    int i = 0;
    file_name = "test1.bmp";
    Init_bmp_head();
    file_p = (unsigned char*)malloc(sizeof(char) * 153654);   //����һ���ڴ�
    file_p_tmp = file_p;
    for (i = 0; i < 153654; i++)
    {
        if (i % 2 == 0)
        {
            *file_p_tmp = 0x00;    //ͼ��ǰ8λֵ 
        }
        else
        {
            *file_p_tmp = 0xf0;    //ͼ���8λֵ 
        }
        file_p_tmp++;
    }
    byte_copy_p = (unsigned char*)bmp_p;
    file_p_tmp = file_p;
    for (i = 0; i < 54; i++)
    {
        *file_p_tmp = *byte_copy_p;
        file_p_tmp++;
        byte_copy_p++;
    }
    fd = fopen(file_name, "w");
    fwrite(file_p, file_length, 1, fd);
    free(file_p);                        //�ͷ�������ڴ棨��Ҫ��
    fclose(fd);
    printf("Done success!!!\n");
    getchar();
    return (0);
}