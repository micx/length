#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
double str2double(string s){
    int i=0,j,len=s.length();
    double ret=0,m=10;
    while(i<len&&s[i]!='.'){
        ret=ret*10+s[i++]-'0';
    }
    ++i;
    while(i<len){
        ret=ret+(s[i++]-'0')/m;
        m*=10;
    }
    return ret;
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    //mail:
    cout<<"micx0124@163.com"<<endl<<endl;
    int rules=6;
    double x,y;
    map<string,double> umap;
    umap["m"]=1.0;
    string unit1,unit2,eq;
    //input rules
    for(int i=0;i<rules;++i){
        cin>>x>>unit1>>eq>>y>>unit2;
        umap[unit1]=y/x;
        if(unit1=="foot"){
            umap["feet"]=y/x;
        }else if(unit1=="inch"){
            umap["inches"]=y/x;
        }else{
            umap[unit1+"s"]=y/x;
        }
    }
    //calculate
    string s;
    while(getline(cin,s)){
        int len=s.length(),i=0;
        if(len==0)continue;
        char sign='+';
        double sum=0;
        string str="";
        while(i<len){
            str="";
            while(i<len&&s[i]==' ')++i; //skip the space
            while(i<len&&s[i]!=' ')     //read the number
                str+=s[i++];

            x=str2double(str);


            str="";
            while(i<len&&s[i]==' ')++i; //skip the space
            while(i<len&&s[i]!=' ')     //read the unit
                str+=s[i++];
            x=umap[str]*x;
            if(sign=='+')
                sum+=x;
            else
                sum-=x;

            str="";
            while(i<len&&s[i]==' ')++i; //skip the space
            while(i<len&&s[i]!=' ')     //read the sign
                str+=s[i++];
            if(str.length()>0){
                sign=str[0];
            }
        }
        printf("%.2lf m\n",sum);
    }
    return 0;
}
