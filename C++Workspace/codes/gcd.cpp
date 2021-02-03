int gcd(int a,int b){
    if(a==0||b==0)return max(a,b);
    int mi=min(a,b);int ma=max(a,b);
    int c=ma%mi;
    return gcd(mi,c);
}
int extgcd(int a, int b, int &x, int &y) { //ax+by=gcd(a,b)なるx,yを求める
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int d = extgcd(b, a % b, y, x); 
    y -= (int)(a / b) * x;
    return d;//gcd(a,b)を返す
}