//
// Created by admin on 2018/7/7.
//
#include <stdio.h>

typedef struct {
    short low_pass_vcf;
    short filter_coupler;
    short reverb;
    short sequential;
    //后面还有很多字段
} synth;

typedef struct {
    //使用无符号整形表示
    unsigned int low_pass_vcf:1;
    unsigned int filter_coupler:1;
    unsigned int reverb:12;
    unsigned int sequential:1;
    unsigned int sequential2:1;
} synth2;

int main(int argc, char *argv[]) {
    printf("%i\n", sizeof(synth2));
    printf("%i\n", sizeof(short));
    printf("%i\n", sizeof(unsigned int));
    return 0;
}

