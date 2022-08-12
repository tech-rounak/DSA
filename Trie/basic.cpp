#include<bits/stdc++.h>
#include<string.h>
#include<stdio.h>
#define ll long long
#define mod 1000000007
#define loopforward(i,a,b) for(ll i=a;i<b;i++)
#define loopbackward(i,b,a) for(ll i=b;i>a;i--)
#define ff first
#define ss second
#define pb push_back
#define eb emplace_back
#define yes cout<<"YES"<<endl;
#define no  cout<<"NO"<<endl;
#define all(x) x.begin(),x.end()
#define lb lower_bound
#define ub upper_bound
#define vv vector<ll>
#define vvp vector<pair<ll,ll>>
#define endl "\n"
ll dx[]={-1,1,1,-1};
ll dy[]={1,-1,1,-1};
// const ll N=1e6;
const double pi = 3.14159265358979323846;
using namespace std;
struct Node{
    Node *arr[26];
    bool flag=0;

    bool isContain(char c){
        return (arr[c-'a']!=NULL);
    }

    Node *getNext(char c){
        return arr[c-'a'];
    } 
    void put(char c ,Node* newNode){
        arr[c-'a'] = newNode;
    }
    void setFlag(){
        flag=true;
        return;
    }
    bool isFlagSet(){
        return flag;
    }
};
class Trie{
public: 
    Node *root = new Node();
    Trie(){
        root = new Node();
    }
    void insert(string word){
        Node *tmp = root; 
        for(int i = 0 ; i < word.length() ; i++){
            if(!tmp->isContain(word[i])){
                tmp->put(word[i],new Node());
            }
            tmp = tmp->getNext(word[i]);
        }
        tmp->setFlag();
    }
    void search(string word){
        Node *tmp = root;
        for(int  i = 0 ; i < word.length() ; i++){
            if(tmp->isContain(word[i])){
                tmp = tmp->getNext(word[i]);
            }
            else return false;
        }
        return tmp->isFlagSet();
    }
};
    void fast_io(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
    }
void solve(){
}
int main(){

    fast_io();
    long long  t=1; 
    cin>>t;
    for(long long test = 0 ; test < t; test++){
        // cout<<"Case #"<<test+1<<": ";
        solve();
    }
}   

