

#include<bits/stdc++.h>
using namespace std;
typedef  long long int ll;
typedef pair<ll,ll> pll;

ll extended_gcd(ll a,ll b,ll * xx,ll * yy){
    if(a==0){
        *xx=0;
        *yy=1;
        return b;
    }
    ll gcd= extended_gcd(b%a,a,xx,yy);
    ll x1=*xx;
    ll y1=*yy;
    *yy=x1;
    *xx=y1-int(b/a)*x1;
    return gcd;
}

ll inverse_modulo(ll k,ll p){
    ll xx,yy;
    ll temp= extended_gcd(k,p,&xx,&yy);
    if(temp==1){
        ll temp2=((xx%p)+p)%p;
        return temp2;
    }
    return -1;
}

ll powmod(ll a,ll b,ll p){
    a=a%p;
    ll res=1;
    while(b){
        if(b&1){
            res=(res*a)%p;
            b=b-1;
        }
        else{
            a=(a*a)%p;
            b=b>>1;
        }
    }
    return res;
}
ll generate_premitive(ll p){

    for (ll i=2;i<p;i++){
        vector<ll> rem;
        for(ll j=0;j<p-1;j++) {
            rem.push_back(powmod(i, j, p));
        }
        sort(rem.begin(), rem.end());
        ll j=0;
        ll k=1;
        bool flag=true;
        while(j<p-1){
            if(rem[j]!=k){
                flag=false;
                break;
            }
            j+=1;
            k+=1;
        }
        if(flag){
            return i;
        }
        else{
            continue;
        }
    }
    return -1;
}
pair<ll,ll> signature(ll p,ll g,ll d,ll m){
    ll k=35;
    ll r=powmod(g,k,p);
    ll temp= inverse_modulo(k,p-1);
    ll s=(((m-d*r)%(p-1))*temp)%(p-1);
    cout<<"Signature is:"<<s<<endl;
    pair<ll,ll> tempp={r,s};
    return tempp;
}
ll verification(ll s,ll r,ll h,ll p,ll g,ll m){
    ll lhs= powmod(g,m,p);
    ll rhs= (powmod(h,r,p)* powmod(r,s,p))%p;
    cout<<lhs<<" "<<rhs<<endl;
    if(lhs==rhs){
        cout<<"varified"<<endl;
    }
    else{
        cout<<"Not verified"<<endl;
    }
}
int main(){
    ll p,g,h;
    p=2039;
//    cout<<powmod(2,5,13)<<endl;
//    cout<<generate_premitive(p);
    g= 5;
    ll d=3;
    h=powmod(g,d,p);
    cout<<"The public keys are :"<<p<<" "<<g<<" "<<h<<endl;
    cout<<"The private key is :"<<d<<endl;
    ll m;
    cout<<"Enter the message:";
    cin>>m;
    pair<ll,ll> temp= signature(p,g,d,m);
    ll r=temp.first;
    ll s=temp.second;
    cout<<"The signature text is: "<<s<<endl;
    cout<<r<<" "<<s<<endl;
    verification(s,r,h,p,g,m);
}