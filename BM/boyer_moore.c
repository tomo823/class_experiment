#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ALPHABET_SIZE 256 // ASCII文字数

// バッドキャラクタルールのテーブルを作成
void createBadCharacterTable(const char *pattern, int patternLength, int badCharTable[]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        badCharTable[i] = -1; // 初期化
    }
    for (int i = 0; i < patternLength; i++) {
        badCharTable[(unsigned char)pattern[i]] = i; // パターン中の各文字の最後の出現位置を記録
    }
}

// Boyer-Moore法による文字列検索
void boyerMooreSearch(const char *text, const char *pattern) {
    int textLength = strlen(text);
    int patternLength = strlen(pattern);

    if (patternLength > textLength) {
        printf("パターンがテキストより長いので、何も見つかりません。\n");
        return;
    }

    int badCharTable[ALPHABET_SIZE];
    createBadCharacterTable(pattern, patternLength, badCharTable);

    int shift = 0; // シフト量

    while (shift <= textLength - patternLength) {
        int j = patternLength - 1;

        // 後ろから前に向かってパターンを比較
        while (j >= 0 && pattern[j] == text[shift + j]) {
            j--;
        }

        if (j < 0) {
            // パターンが見つかった場合
            printf("パターンが見つかりました: インデックス %d\n", shift);

            // 次の位置に移動
            shift += (shift + patternLength < textLength) ? patternLength - badCharTable[(unsigned char)text[shift + patternLength]] : 1;
        } else {
            // バッドキャラクタルールによるシフト
            char badChar = text[shift + j];
            int badCharShift = (badCharTable[(unsigned char)badChar] != -1) ? j - badCharTable[(unsigned char)badChar] : j + 1;
            shift += (badCharShift > 1) ? badCharShift : 1; // シフト量は1以上
        }
    }
}

int main() {
    const char *text = "deonionliciousonionsoup";
    const char *pattern = "onion";

    printf("テキスト: %s\n", text);
    printf("パターン: %s\n", pattern);

    boyerMooreSearch(text, pattern);

    return 0;
}
