#include<iostream>
#include<cstdio>
#include<string>
#include<conio.h>
 
using namespace std;
int W, K, curW = 0, curP = 0, bestP = 0, lostP = 0, MaxP = 0;
 
 
void metodvg(int j, int *p, int *w, int *x, int *y) {
    if (j == K) {
        if (bestP < curP && curW <= W) {
            for (int i = 0; i < K; ++i) y[i] = x[i];
            bestP = curP;
        }
        return;
    }
    lostP += p[j];
    
    if(bestP <= MaxP - lostP) metodvg(j + 1, p, w, x, y);
    lostP -= p[j];
    curW += w[j];
    curP += p[j];
    
    if(curW <= W) {
        x[j] = 1;
        metodvg(j + 1, p, w, x, y);
        x[j] = 0;
    }
    curW -= w[j];
    curP -= p[j];
}
 
 
int main(){
        setlocale(LC_ALL, "Russian");
        cout<<"Введите W - грузоподъемность рюкзака = "; 
        cin>>W;
        cout<<"Введите k - количество предметов = "; 
        cin>>K;
        string  *s = new string[K];
        int *p = new int[K];
        int *w = new int[K];
        int *x = new int[K];
        int *y = new int[K];
        
        for(int i = 0; i < K; ++i) {
            x[i] = 0;
            y[i] = 0;
        }
        
        for(int i = 0; i < K; ++i) cin >> s[i] >> w[i] >> p[i];
 
        for(int i = 0; i < K; ++i) cout << "s[" << i << "] = " << s[i] << ", w[" << i << "] = " << w[i] << ", p[" << i << "] = " << p[i] << endl;
 
        for(int i = 0; i < K; i++) MaxP += p[i];
        metodvg(0, p, w, x, y);
        
        for(int i = 0; i < K; ++i) 
            if(y[i]) cout << s[i] << endl;
        cout << endl;               
        cout << "Сумма стоимости в лучшем наборе = " << bestP << endl;
}
