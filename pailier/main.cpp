#include<bits/stdc++.h>

using namespace std;



typedef unsigned long long ull;

ull gcd(ull a, ull b){
    if(b==0){
        return a;
    }
    else{
        return gcd(b, a%b);
    }
}
ull extended_gcd(ull a, ull b, ull * x, ull * y){

    if(a==0){
        *x=0;
        *y=1;
        return b;
    }
    ull gcd= extended_gcd(b % a, a, x, y);
    ull x1=*x;
    ull y1=*y;
    *x=y1-(b/a)*x1;
    *y=x1;
    return gcd;
}

ull modinverse(ull a, ull b){
    ull x,y;
    ull gcd= extended_gcd(a, b, &x, &y);
    if(gcd!=1){
        cout<<"Modular Inverse not available"<<endl;
        return 0;
    }
    else{
        ull temp= ((x % b) + b) % b;
        return temp;
    }
}

ull modpow(ull x, ull y, ull p){
    ull temp=1;
    x=x%p;
    if(x==0){
        return 0;
    }
    else if(y==0){
        return 1;
    }
    while(y>0){
        if(y&1){
            temp=(temp*x)%p;
        }
        y=y>>1;
        x=(x*x)%p;
    }
    return temp%p;
}

ull lcm(ull a, ull b){
    return ((a/ gcd(a,b))*b);
}
int main() {

    ull p=37;
    ull q=41;

    ull n= p * q;

    ull lemda=lcm(p - 1, q - 1);
    ull g=1+(rand()%(n*n));

    ull xx,yy;
    while(extended_gcd(g,n*n,&xx,&yy)!=1){
        g=(ull)1+(rand()%(n*n));
    }

//    ull g=13;

    ull temporary= modpow(g, lemda, n * n);
    ull L= (temporary - 1) / n;
    ull miu= modinverse(L, n);

    cout<<"Public key: "<<"n "<<n<<" "<<"g "<<g<<endl;
    cout<<"Private key: "<<"lemda: "<<lemda<<" miu: "<<miu<<endl;

    ull m;
    cout<<"Enter the message to be encrypted:";
    cin>>m;

    ull r=1+(rand()%n);
    while(gcd(r,n)!=1){
        r=1+::rand()%n;
    }
//    ull r=11;
    cout<<"r: "<<r<<endl;

    ull cipher_text= (modpow(g,m,n*n)* modpow(r,n,n*n))%(n*n);
    cout<<"Encrypted message: "<<cipher_text<<endl;

    ull temp1= ((modpow(cipher_text,lemda,n*n)-1)/n)%n;
    ull decrypted_text=(temp1*miu)%n;
    cout<<"Decrypted_text: "<<decrypted_text<<endl;

}