long long mod = 1e9+7;
class Mint {
public:
  long long x;
  Mint(){}; // 引数なしでも定義できるように引数なしコンストラクタも用意しておく
  Mint(long long a){
    x = a%mod;
    while(x<0){
      x += mod;
    }
  };
  Mint& operator += (const Mint &a){
    x+=a.x;
    x%=mod;
    return *this;
  }
  Mint& operator -= (const Mint &a){
    x += (mod - a.x);
    x%=mod;
    return *this;
  }
  Mint& operator *= (const Mint &a){
    x*=a.x;
    x%=mod;
    return *this;
  }

  // a^n mod を計算する
  // Useaeg: Mint z = Mint(2).pow(n);
  Mint pow(long long n) const {
    if (n==0) return Mint(1);
    Mint y = pow(n>>1); // pow(n/2)を計算する
    y *= y;
    if (n%2==1) y *= *this;
    return y;
  }

  // a^{-1} mod を計算する
  Mint modinv(const Mint &a) const {
    return a.pow(mod-2);
  }

  Mint& operator /= (const Mint &a) {
    x *= modinv(a).x;
    x %= mod;
    return *this;
  }

  Mint operator + (Mint &a) const {
    Mint y(*this);
    y += a;
    return y;
  }

  Mint operator - (Mint &a) const {
    Mint y(*this);
    y -= a;
    return y;
  }

  Mint operator * (Mint &a) const {
    Mint y(*this);
    y *= a;
    return y;
  }

  Mint operator / (Mint &a) const {
    Mint y(*this);
    y/=a;
    return y.x;
  }

  // nCk @mod を計算する
  Mint nCk(Mint &n, const long long k) const {
    Mint y = Mint(1);
    Mint one = Mint(1);
    for (Mint i(0); (i.x)<k; i.x++){
      y *= (n-i);
      y /= (i + one);
    }
    return y;
  }

  // nPk @mod を計算する
  Mint nPk(Mint &n, long long k) const {
    Mint y(1);
    for (Mint i(0); (i.x)<k; i.x++){
      y *= (n-i);
    }
    return y;
  }
};


