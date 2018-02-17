#include<iostream>

using namespace std;

class ArregloMovido{
    public:
    ArregloMovido(float* v, int k){
        tamanio = k;
        vector = new float[k];
    }
//copia:  ArregloMovido(const arm&)
    ~ArregloMovido(){ delete vector; }

    short* loc(short* a1, short* a2, int n1, int n2){
        short* end1 = a1 + n1;
        for (short* p1 = a1; p1 < end1; p1++)
            if (*p1 == *a2){
                int j;
                for (j = 0; j < n2; j++)
                    if (p1[j] != a2[j]) break;
                if (j == n2) return p1;
            }
        return 0;
    }

    float& component(int k) { return vector[k-1]; }

    private:
    float *vector;
    int tamanio;
};

float& component(float* v, int k) { return v[k-1]; }

int main() {
    float v[4];
    for (int k = 1; k <= 4;k++)
      component(v,k) = 1.0/k;
      for (int i = 0; i < 4;i++)
        cout << "v[" << i << "] = " <<v[i] << endl;
}

//int main() { short a[] = {22, 33, 44, 55, 66}; cout << "a = " << a << ", *a = " << *a <<endl; for (short* p = a; p < a + 5;p++) cout << "p = " << p << ", *p = " << *p <<endl; }
