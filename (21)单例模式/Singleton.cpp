
#include<iostream>

class Singleton{
private:
static Singleton* instance;
Singleton(){}

public:
    static Singleton* GetInstance(){
        if(instance==nullptr){
            instance=new Singleton();
        }
        return instance;
    }
};
Singleton* Singleton::instance=nullptr;


int main(){
    auto S1=Singleton::GetInstance();
    auto S2=Singleton::GetInstance();
    if(S1==S2){
        printf("S1和S2相同");

    }
}