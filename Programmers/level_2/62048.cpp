using namespace std;

long long gcd(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long solution(int w, int h) {
    long long answer = 1;
    long long ww = w;
    long long hh = h;
    answer = ww * hh - (w + h - gcd(w, h));

    return answer;
}