#include<iostream>

class Receiver{
public:
    void Action(){
        printf("执行请求\n");
    }
};

class Command{
protected:
    Receiver* receiver;
public:
    Command(Receiver* receiver){
        this->receiver=receiver;
    }

    virtual void Execute()=0;

};

class ConcreteCommand: public Command{
public:
    ConcreteCommand(Receiver* receiver):Command(receiver){}

    void Execute() override{
        receiver->Action();
    }
};

class Invoker{
private:
    Command * command=nullptr;
public:
    void SetCommand(Command* command){
        this->command=command;
    }

    void ExecuteCommand(){
        command->Execute();
    }
};

int main(){
    Receiver* receiver=new Receiver();
    Command* command=new ConcreteCommand(receiver);
    Invoker* invoker=new Invoker();
    invoker->SetCommand(command);
    invoker->ExecuteCommand();
}