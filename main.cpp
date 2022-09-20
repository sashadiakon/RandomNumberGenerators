#include <iostream>
#include <string>
#include <math.h> 
#include <vector>

using namespace std;
const int n = 1000;
// const int M = 9001;
// ++
vector<int> method1(int repeat = n){
    vector<int> vect = {};
    int a = 3;
    int m = 9001;
    int c = 5;
    int x0 = time(0);
    for (int i = 0; i <= repeat; i++){
        x0 = (a*x0 + c) % m;
        vect.push_back(x0);
        float u = float(x0) / m;
    }
    return vect;
}

// ??
vector<int> method2(int repeat = n){
    vector<int> vect = {};
    int x0 = time(0);
    int a = 17;
    int m = 9001;
    int c = 31;
    int d = 12;
    
    for (int i = 0; i <= repeat; i++){
        x0 = (d*x0*x0+a*x0+c)%m;
        vect.push_back(x0);
        float u = float(x0)/m;
    }

    return vect;
}

// ++
vector<int> method3(int repeat = n){
    vector<int> vect = {};
    int x0 = time(0);
    int x1 = time(0)+321124;
    int m = 9001;
    for (int i = 0; i <= repeat; i++){
        int n_x0 = x1;
        x1 = (x0+x1)%m;
        x0 = n_x0;
        vect.push_back(x1);
        float u = float(x1)/m;
    }
    return vect;
}


int mod_inverse(int x, int m){
    for (int x1 = 0; x1<=m; x1++){
        if (x1*x%m == 1){
            return x1;
        }
    }
    return 0;
}

// ++
vector<int> method4(int repeat = n){
    vector<int> vect = {};
    int a = 3;
    int m = 9001;
    int c = 5;
    int x0 = 1;
    for (int i = 0; i <= repeat; i++){
        x0 = (a*mod_inverse(x0, m)+c)%m;
        vect.push_back(x0);
        float u = float(x0)/m;
        // distribution[int(u*10)]++;
    }
    return vect;
}

// ++
vector<int> method5(int repeat = n){
    vector<int> vect = {};
    vector<int> x_v = method1(repeat);
    vector<int> y_v = method2(repeat);
    int m = 9001;
    int diff;
    for (int i = 0; i <= repeat; i++){
        diff = x_v[i] - y_v[i];
        while (diff <0){
            diff +=m;
        }
        vect.push_back(diff);
        float u = float(diff%m) / m;
    }
    return vect;
}

// ++
vector<float>  method6(int repeat = n){
    vector<float> vect = {};
    vector<int> x_v = method1(repeat);
    int m = 9001;
    int x0 = time(0);
    for (int i = 0; i <= repeat; i++){
        float sum = 0;
        for (int j = 0; j<12; j++){
            float u = float(x_v[i+j])/m;
            sum += u;
        }
        float x = sum-6;
        if (-3<=x<=3){
            vect.push_back(x);
        }
    }
    return vect;
}

// normal dist
vector<float> method7(int repeat = n){
    vector<float> vect = {};
    vector<int> x_v = method1(repeat);
    vector<int> y_v = method3(repeat);
    int m = 9001;
    float u1, u2, v1, v2, s, x1, x2;
    for (int i = 0; i <= repeat/2; i++){
        u1 = float(x_v[i])/m;
        u2 = float(y_v[i])/m;
        v1 = 2*u1-1;
        v2 = 2*u2-1;
        s = v1*v1+v2*v2;
        if (s<1){
            x1 = v1*sqrt(-2*log(s)/s);
            x2 = v2*sqrt(-2*log(s)/s);
            if (-3<=x1<=3){
                vect.push_back(x1);
            }
            if (-3<=x2<=3){
                vect.push_back(x1);
            }
        }
    }
    return vect;
}

vector<float> method8(int repeat = n){

    vector<float> vect = {};
    vector<int> x_v = method1(repeat);
    vector<int> y_v = method3(repeat);
    int m = 9001;
    float x, u, v;
    for (int i = 0; i <= repeat; i++){
        u = x_v[i]/m;
        v = y_v[i]/m;
        if (u != 0) {
            x = sqrt(8/M_E) * (v-0.5) / u;
            if (x * x <= -4 * log(u)) {
                vect.push_back(x);
            }
        }
    }

}


int menu(){
    cout<< "1: Linear congruent method"<<endl;
    cout<< "2: Quadr congruent method"<<endl;
    cout<< "3: Fibonachi numbers"<<endl;
    cout<< "4: Inverse congruent method"<<endl;
    cout<< "Merge method"<<endl;
    cout<< "6: \"3 sigma\" rule" << endl;
    cout<< "7: Polar coordinate method" << endl;
    cout<< "8: The method of relations" << endl;
    cout<< "9: Logarithm method for generating an indicative distribution" << endl;
    cout<< "10: Ahrens method for generating a gamma distribution of order a > 1" << endl;

    int num;
    cin >> num;
    return num;
}

void hist1_6(vector<int> x = {}, int repeat = n){
    int m = 9001;
    int distribution[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i <= x.size(); i++){
        cout<<x[i]<<endl;
        distribution[int(float(x[i])/m*10)]++;
    }
    for (int i = 0; i < 10; i ++){
        cout<<1231;
        cout << "[" + to_string(i*0.1) + "; 0, "+ to_string((i+1)*0.1)+"]:  "<<float(distribution[i])/repeat<<endl;
    }
}

void hist6_8(vector<float> x = {}, int repeat = n){
    cout<<1;
    int m = 9001;
    int distribution[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i <= x.size(); i++){
        distribution[int(float(x[i]+3)/6*10)]++;
    }
    for (int i = 0; i < 10; i ++){
        cout << "[" <<i*0.6-3 << "; 0, "<< (i+1)*0.6-3<<"]:  "<<float(distribution[i])/repeat<<endl;
    }

}
int main(){
    int num = menu();
    switch (num){
        case 1: 
            hist1_6(method1()); 
            break;
        case 2: 
            hist1_6(method2());
            break;
        case 3: 
            hist1_6(method3());
            break;
        case 4: 
            hist1_6(method4());
            break;
        case 5:
            hist1_6(method5());
            break;
        case 6: 
            hist6_8(method6());
            break;
        case 7:
            hist6_8(method7());
            break;
        case 8:
        // case 9:
        // case 10:
        default: break;
    }
    return 0;
}