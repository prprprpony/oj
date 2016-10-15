#ifndef LIB1164_H_INCLUDED
#define LIB1164_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

typedef struct { int m, k; int *x, *y, *len; } MAP;

MAP* _d;
int* _tlen;
int _N, _i, _j;

int compar(const void* a, const void* b)
{
    return (*(int*)a > *(int*)b ? 1 : -1);
}

int init() {
    scanf("%d", &_N);
    _d = (MAP*)malloc(sizeof(MAP) * _N);
    _tlen = (int*)malloc(sizeof(int) * _N);
    for (_i = 0; _i < _N; _i++) {
        scanf("%d%d%d", &_d[_i].m, &_d[_i].k, _tlen + _i);
        _d[_i].x = (int*)malloc(sizeof(int) * _d[_i].k);
        _d[_i].y = (int*)malloc(sizeof(int) * _d[_i].k);
        _d[_i].len = (int*)malloc(sizeof(int) * _d[_i].k);
        for (_j = 0; _j < _d[_i].k; _j++) scanf("%d%d%d", &_d[_i].x[_j], &_d[_i].y[_j], &_d[_i].len[_j]);
    }
    return _N;
}

int query(int a, int b) {
    return (_tlen[a] > _tlen[b] ? 1 : 0);
}

MAP getct(int a) {
    return _d[a];
}

void answer(int a, int b)
{
    qsort(_tlen, _N, sizeof(int), compar);
    printf("%d %d\n%d %d\n", a, b, _tlen[_N - 1], _tlen[0]);
    puts((_tlen[0] == b && _tlen[_N - 1] == a) ? "correct" : "incorrect");

    for (_i = 0; _i < _N; _i++) {
        free(_d[_i].x);
        free(_d[_i].y);
        free(_d[_i].len);
    }
    free(_d);
    free(_tlen);
    exit(0);
}

#endif // LIB1164_H_INCLUDED
