#include<stdio.h>
#include<cstdint>
#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;

// 함수 역활 : 4비트씩 한 단워(word)로 만들고
int make_nibble_list(uint32_t temp, uint8_t* u8List){
    
    // printf("32 int : 0x%x \n", temp);

    for(int i=0; i < sizeof(u8List) / sizeof(*u8List); i++){
        memcpy(u8List + i, &temp, sizeof(uint8_t));
        temp = (temp >> 8);
    }
    
    // printf("u8List int : 0x%x \n", *(u8List + 1));
    
    return 0;
};



int main(int argc, char *argv[]){

    int size = 4;

    FILE* pFile1 = fopen(argv[1], "rb");
    char sFile1[size * 2];
    FILE* pFile2 = fopen(argv[2], "rb");
    char sFile2[size * 2];
    uint32_t u32int_1;
    uint32_t u32int_2;
    
    fread(&u32int_1, sizeof(char), 8, pFile1);
    fread(&u32int_2, sizeof(char), 8, pFile2);

    uint8_t u8List[size];
    
    make_nibble_list(u32int_1, u8List);
    // uint8[] to uint32
    for(int i=0; i<size; i++){
        u32int_1 = (u32int_1 << 8) | u8List[i];
    }
    make_nibble_list(u32int_2, u8List);
    // uint8[] to uint32
    for(int i=0; i<size; i++){
        u32int_2 = (u32int_2 << 8) | u8List[i];
    }


    printf("%d(0x%x) + %d(0x%x) = %d(0x%x) \n", u32int_1, u32int_1,
    u32int_2,u32int_2, u32int_1 + u32int_2, u32int_1 + u32int_2);

    // char name[] = "허남정";
    // printf("[sdev-2024]add-nbo[%s] \n\n", name);


    return 0;
};