#include <iostream>
#include <math.h>

class big{
    private:
        int array_len = 0;
        typedef struct _couple{
            __uint8_t left:4;
            __uint8_t right:4;
        }couple;
    public:
        int n_digits = 0;
        couple* data;
        big(int n_digits_local): n_digits(n_digits_local){
            array_len = n_digits/2; if(n_digits%2) array_len++;
            data = (couple*)malloc(array_len*sizeof(couple));
        }
        void set_digit(int i_digit, char digit){
            if(digit > 57 || digit < 48) return ; 
            i_digit = n_digits - i_digit - 1;
            int array_index = (i_digit - (i_digit%2))/2;
            if(i_digit%2){
                data[array_index].right = digit - 48;
            }else{
                data[array_index].left = digit - 48;
            }
        }
        void set(const char* str){
            for(int i_digit = 0; i_digit < n_digits; i_digit++){
                set_digit(i_digit, str[i_digit]);
            }
        }
        int get_digit(int i_digit){
            int array_index = (i_digit - (i_digit%2))/2;
            if(i_digit%2){
                return data[array_index].right;
            }else{
                return data[array_index].left;
            }
        }
        void print(){
            for(int i_digit = n_digits - 1; i_digit >=0 ; i_digit--){
                std::cout << get_digit(i_digit);
            }
        }
        void add(big big_number){
            if(big_number.n_digits > n_digits) return;
        }
};

int main(){
    big number1(5);
    big number2(2);
    number1.set("12300");
    number2.set("45");
    number1.add(number2);
    // below line should print 12345
    number1.print();
    return 0;
}