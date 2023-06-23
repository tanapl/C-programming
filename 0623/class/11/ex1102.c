#include <stdio.h>

int main(void) {
    char str[] = "ABCDEF"; // 配列による文字列
    char *strp = "abcdef"; // ポインタによる文字列

    printf("1: str  %s\n", str);

    // 配列による文字列は，要素に文字を代入できる
    str[0] = '0'; str[1] = '1';
    printf("2: str  %s\n", str);

    // 配列による文字列には，文字列リテラルの代入はできない
    // （コンパイルエラー）
    // str = "123456";
    // printf("3: str  %s\n");

    printf("4: strp %s\n", strp);
    // ポインタによる文字列は，要素に文字を代入できない
    // （参照しているのが，文字列リテラルの場合）
    // （実行時エラー）
    // strp[0] = '0'; strp[1] = '1';
    // printf("5: strp %s\n", strp);

    // ポインタによる文字列には別の文字列リテラルを代入できる．
    // 具体的には文字列リテラルの先頭要素のアドレスが代入される．
    strp = "123456" + 1; // "123456"の先頭要素に1を足したアドレスなので，"2"以降になる
    printf("6: strp %s\n", strp);

    // ポインタはアドレス値でしか無いので，配列による文字列の先頭要素の
    // アドレスを代入して参照することができる．
    strp = str;
    printf("7: strp %s\n", strp);

    // 配列による文字列を参照している場合は，要素の変更もできる．
    strp[2] = '2'; strp[3] = '3';
    printf("8: strp %s\n", strp);

    // 実際にはstrpを通して参照先の文字列であるstrのが変更されている．
    printf("9: str  %s\n", str);

    return 0;
}