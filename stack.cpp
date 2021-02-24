#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
#define MAX_STACK_SIZE 100000

class max_stack{
    private:
    int stack[MAX_STACK_SIZE];
    int max_values[MAX_STACK_SIZE];
    int length = 0;
    public:
    // constructor
    max_stack(){
        length = 0;
    }
    
    // push
    void push(int value){
        length++;
        stack[length - 1] = value; // append
        if(length > 1){
            if(max_values[length - 2] < value){
                max_values[length - 1] = value;
            }else{
                max_values[length - 1] = max_values[length - 2];
            }
        }else{
            max_values[length - 1] = value;
        }
    }
    
    // pop 
    void pop(){
        // update max_element
        if(length > 0) length--;
    }
    
    // getmax
    int getmax(){
        return max_values[length-1];
    }
};

int main() {
    
    max_stack stack1;
    int testcases;
    int test_type;
    int val;
    ifstream test_in;
    ofstream test_out;
    test_in.open("stack_in");
    test_out.open("stack_out");

    test_in >> testcases;
    for (int i = 0; i < testcases; i++) {
        // get input type
        test_in  >> test_type;
        if(test_type == 1){
            test_in >> val;
            // push
            stack1.push(val);
        }else if (test_type == 2) {
            // pop
            stack1.pop();
        }else if (test_type == 3) {
            test_out << stack1.getmax() << "\n";
        }
        
    }
    return 0;
}
