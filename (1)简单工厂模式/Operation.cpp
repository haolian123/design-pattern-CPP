#include<iostream>
#include<stdexcept>
class Operation{
private:
    double numberA=0;
    double numberB=0;

public:
    double getNumberA(){return numberA;}
    double getNumberB(){return numberB;}
    void setNumberA(double n){numberA=n;}
    void setNumberB(double n){numberB=n;}

public:
    virtual double getResult(){
        double result=0;
        return result;
    }
};


// 加减乘除类
class OperationAdd:public Operation{
public:
    double getResult(){
        return getNumberA()+getNumberB();
    }

};

class OperationSub:public Operation{
public:
    double getResult(){
        return getNumberA()-getNumberB();
    }

};

class OperationMul:public Operation{
public:
    double getResult(){
        return getNumberA()*getNumberB();
    }

};

class OperationDiv:public Operation{
public:
    double getResult(){
        if(getNumberB()==0.0){
            /*抛出异常*/
            throw std::runtime_error("Division by zero is not allowed.");
        }
        return getNumberA()/getNumberB();
    }

};

// 简单工厂
class OperationFactory{
public:
    static Operation* createOperation(char operate){
        Operation *oper=nullptr;
        switch (operate){
            case '+':
            oper=new OperationAdd();
            break;
            case '-':
            oper=new OperationSub();
            break;
            case '/':
            oper=new OperationDiv();
            break;
            case '*':
            oper=new OperationMul();
            break;
        }
        return oper;
    }
};

int main(){
    Operation *oper=OperationFactory::createOperation('+');
    oper->setNumberA(5);
    oper->setNumberB(6);
    double result=oper->getResult();
    std::cout<<"result="<<result<<std::endl;

}