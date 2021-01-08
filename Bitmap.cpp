#include<iostream>
#include<fstream>
#define MAX 64

using namespace std;

long long bmap[MAX] = {0,};
long long tmap[MAX] = {0,};
long long tmp;

int main(){
    ifstream ifs("7.inp");
    ofstream ofs("7.output");
    for(int i = 0; i < MAX; i++){
        ifs >> bmap[i];
        for(int j = MAX-1; j >= 0; j--){
            tmap[j] |= ((bmap[i] & 1) << ((MAX - 1) - i));  // shift 연산자로 bmap의 값을 이용해 tmap을 채운
            bmap[i] = bmap[i] >> 1;                        // tmap[j]를 한번채우고 나서 tmap[j-1]을 채우기 위해서 비트연산자를 통해 bmap[i]의 해당하는 bit를 오른쪽으로 한칸 이동
        }
    }
    for(int i=0; i<MAX; i++){
        ofs << tmap[i] << endl;
    }

    ifs.close();
    ofs.close();
    return 0;
}