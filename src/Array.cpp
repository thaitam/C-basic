#include<stdio.h>
#define MAXSIZE 50
typedef struct Array{
    int numbers[MAXSIZE];
    int size;
};
void enter(Array &input);
bool isPrimeNumber(int &check_number);
Array findPrimeNumbers(Array source);
Array findEvenNumbers(Array source);
void printValue(Array output);
int printNumberOfPrimeNumbers(Array source);
void printEvenNumbers(Array source);
void printPrimeNumbers(Array source);
int main(){
    Array array;
    enter(array);
    printf("\nprint value of number: ");
    printValue(array);
    printEvenNumbers(array);
    printPrimeNumbers(array);
    printNumberOfPrimeNumbers(array);
    return 0;
}
void enter(Array &input){
    int temp;
    printf("enter amount of numbers: ");
    scanf("%d",&input.size);
    printf("enter value of numbers: \n");
    for(int index=0;index<input.size;index++){
        printf("value at %d position in numbers: ",index);
        scanf("%d",&temp);
        input.numbers[index] = temp;
    }
}
void printValue(Array output){
    for (int index = 0; index < output.size; index++)
    {
        printf(" %d",output.numbers[index]);
    }    
}
bool isPrimeNumber(int &check_number){
    bool is_prime_number = true;
    for(int previous_number = 2; previous_number<check_number;previous_number++){
        if(check_number%previous_number==0){
            is_prime_number = false;
            break;
        }
    }
    return is_prime_number;
}
Array findEvenNumbers(Array source){
    Array even_array;
    even_array.size = 0;
    for(int index = 0; index < source.size; index++){
        if(source.numbers[index]%2==0){
            even_array.size++;
            even_array.numbers[even_array.size-1] = source.numbers[index];
        }
    }
    return even_array;
}
Array findPrimeNumbers(Array source){
    Array prime_array;
    prime_array.size = 0;
    for(int index = 0;index < source.size;index++){
        int check_number = source.numbers[index];
        if(isPrimeNumber(check_number)){
            prime_array.size++;
            prime_array.numbers[prime_array.size-1] = check_number;
        }
    }
    return prime_array;
}
void printEvenNumbers(Array source){
    Array even_array = findEvenNumbers(source);
    printf("\n Even numbers in array:");
    printValue(even_array);
}
void printPrimeNumbers(Array source){
    Array prime_array = findPrimeNumbers(source);
    printf("\nPrime numbers in array:");
    printValue(prime_array);
}
int printNumberOfPrimeNumbers(Array source){
    Array prime_array = findPrimeNumbers(source);
    printf("\namount prime numbers: %d",prime_array.size);
}