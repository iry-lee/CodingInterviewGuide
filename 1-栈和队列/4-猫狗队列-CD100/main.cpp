#include <climits>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class CatDogQueue{
private:
    queue<int> dogs, cats, types;
public:
    CatDogQueue()= default;
    // type = 1 --> dog
    // type = 2 --> cat
    void add(int type, int num){
        types.push(type);
        if(type == 1) dogs.push(num);
        else if(type == 2) cats.push(num);
    }

    void pollAll(){
        while(!types.empty()){
            if(types.front() == 1){
                cout << "dog " << dogs.front() << endl;
                dogs.pop();
            }
            else if(types.front() == 2){
                cout << "cat " << cats.front() << endl;
                cats.pop();
            }
            types.pop();
        }
    }

    void pollDog(){
        if(dogs.size() > 0){
            while(!dogs.empty()){
                cout << "dog " << dogs.front() << endl;
                dogs.pop();
            }
            while(!types.empty()){
                types.pop();
            }
            for(int i = 0; i < cats.size(); i++){
                types.push(2);
            }
        }
    }

    void pollCat(){
        if(cats.size() > 0){
            while (!cats.empty()){
                cout << "cat " << cats.front() << endl;
                cats.pop();
            }
            while(!types.empty()){
                types.pop();
            }
            for(int i = 0; i < dogs.size(); i++){
                types.push(1);
            }
        }
    }

    void isEmpty(){
        if(types.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    void isDogEmpty(){
        if(dogs.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    void isCatEmpty(){
        if(cats.empty()) cout << "yes\n";
        else cout << "no\n";
    }
};

int main(void){
    int n;
    stack<int> st;
    cin >> n;
    cin.get(); 	// 别忘了吃掉这个回车
    CatDogQueue cdq;
    for(int i = 0; i < n; i++) {
        string line;
        getline(cin, line);
        if(line[0] == 'a'){
            int num = stoi(line.substr(8));
            if(line[4] == 'd') cdq.add(1, num);
            else if(line[4] == 'c') cdq.add(2, num);
        }
        else if(line[0] == 'p'){
            if(line[4] == 'A') cdq.pollAll();
            else if(line[4] == 'D') cdq.pollDog();
            else if(line[4] == 'C') cdq.pollCat();
        }
        else if(line[0] == 'i'){
            if(line[2] == 'E') cdq.isEmpty();
            else if(line[2] == 'D') cdq.isDogEmpty();
            else if(line[2] == 'C') cdq.isCatEmpty();
        }
    }
    return 0;
}


// 注意这个题求的是子数组，不是子序列