#include "expr_assert.h"
#include "mylib.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
void test_fibonacci_series_it_produce_series_upto_5_term(){
	int *arrayOfFibo,i,term=5;
	arrayOfFibo =(int*)malloc(sizeof(int)*term);
	assertEqual(fibo(term,arrayOfFibo),1);
	assertEqual(arrayOfFibo[0],0);
	assertEqual(arrayOfFibo[1],1);
	assertEqual(arrayOfFibo[2],1);
	assertEqual(arrayOfFibo[3],2);
	assertEqual(arrayOfFibo[4],3);
	free(arrayOfFibo);
};

void test_concanate_array1_array2__as_result_array_1_2_2_3(){
	int a []={1,2},b[]={2,3};
	int *result_array;
	assertEqual(concat(a,2,b,2,&result_array),4);
	assertEqual(result_array[0],1);
	assertEqual(result_array[1],2);
	assertEqual(result_array[2],2);
	assertEqual(result_array[3],3);
	free(result_array);
};

void test_filter_should_give_100_and_90_from_array_100_90_80(){
	int *result_array;
	int scores[]={100,90,80};
 	assertEqual(filter(scores,3,85,&result_array),2);
 	assertEqual(result_array[0],100);
 	assertEqual(result_array[1],90);
 	free(result_array);
};

void test_reverse_the_array_scores_as_42_12_54_43_23(){
	int *array,length = 5,*result_array;
	int scores [] = {23,43,54,12,42};
	assertEqual(reverse(scores,5,&result_array),5);
	assertEqual(result_array[0],42);
	assertEqual(result_array[1],12);
	assertEqual(result_array[4],23);
	free(result_array);
};

void test_slice_the_array1_which_gives_the_array_from_the_indexof_2_to_5(){
	int length_of_array,start_index,end_index,*result_array;
	int scores [] = {23,43,54,12,42,90};
	assertEqual(slice(scores,6,2,5,&result_array),3);
	assertEqual(result_array[0],54);
	assertEqual(result_array[1],12);
	assertEqual(result_array[2],42);
	free(result_array);
};

void test_slice_the_array1_which_gives_the_array_from_0_to_3_if_slice_with_minus_6_4(){
	int start_index,end_index,*result_array;
	int scores [] = {1,2,3,4,5,6,7,8,9,10};
	assertEqual(slice(scores,10,-2,4,&result_array),4);
	assertEqual(result_array[0],1);
	assertEqual(result_array[1],2);
	assertEqual(result_array[2],3);
	assertEqual(result_array[3],4);
	free(result_array);

};

void test_give_the_4_numberOfprimes_between_1_to_10(){
	int start=1,end=10,*result_array;
	assertEqual(prime(1,10,&result_array),4);
	assertEqual(result_array[0],2);
	assertEqual(result_array[1],3);
	assertEqual(result_array[2],5);
	free(result_array);
};

void test_give_the_168_numberOfprimes_between_2_to_1000(){
	int start=1,end=10,*result_array;
	assertEqual(prime(2,1000,&result_array),168);
	assertEqual(result_array[0],2);
	assertEqual(result_array[1],3);
	assertEqual(result_array[2],5);
	free(result_array);
};

void test_give_the_669_numberOfprimes_between_2_to_5000(){
	int start=1,end=10,*result_array;
	assertEqual(prime(2,5000,&result_array),669);
	assertEqual(result_array[0],2);
	assertEqual(result_array[1],3);
	assertEqual(result_array[2],5);
	free(result_array);
};

void test_give_the_1754_numberOfprimes_between_2_to_15000(){
	int start=1,end=10,*result_array;
	assertEqual(prime(2,15000,&result_array),1754);
	assertEqual(result_array[0],2);
	assertEqual(result_array[1],3);
	assertEqual(result_array[2],5);
};

void test_gives_the_hello_and_hello_are_same(){
	char *str1="hello",*str2="hello";
	assertEqual(stringCompare(str1,str2),1);
	assertEqual(stringCompare(str2,str1),1);

};

void test_gives_the_reja_and_rani_are_not_same(){
	char *str1="reja",*str2="rani";
	assertEqual(stringCompare(str1,str2),4);
	assertEqual(stringCompare(str2,str1),-4);
};

void test_gives_helloooo_and_hello_difference_is_111(){
	char *str1="helloooo",*str2="hello";
	assertEqual(stringCompare(str1,str2),111);
	assertEqual(stringCompare(str2,str1),-111);
};

int print (int x,int i,int* array) { 
	printf("value:\t%d\tIndex:%d\t\n",x+5,i);
	return x;
};

void test_it_prints_1_2_3_4_5(){
	int (*fun)(int,int,int*);
	int array[]={1,12,3,4,5};
	fun = print;
	assertEqual(forEach(array,5,fun),1);
};

char* printString(char *string,int length,char** array){
	printf("%s\n",string);
	return string;
};

void test_it_prints_a_b_c_d(){
	char* (*fun)(char *,int,char**);
	char string[] = {'a','b','\0'}; 
	char string1[] = {'a','b','c','\0'}; 
	char *array[] = {string,string1};
	fun = printString;
	assertEqual(stringforEach(array,2,fun),2);
};

int isGreaterThan4(int x,int index,int* array){
	return (x>4)?x:0;
};

void test_filter_return_5_6_7_from_the_array(){
	int *result_array;
	int array[6] = {2,3,4,5,6,7};
	int resultLength;
	result_array = (int*) malloc(sizeof(int)*6);
	resultLength = jsFilter(array,6,result_array,isGreaterThan4);
	assertEqual(resultLength,3);
	assertEqual(result_array[0],5);
	free(result_array);
};

int isNotEqual(char* x,int index,char** array){
	int yes;
	yes = strcmp(x,"hi");
	return (yes==0)?0:1;
};

void test_filter_return_lenth_3_after_filter_the_array(){
	char **result_array;
	char *array[] = {"hi","hi","hi","hello","hello","man"};
	int resultLength;
	result_array = (char**) malloc(sizeof(char*)*6);
	resultLength = stringFilter(array,6,result_array,isNotEqual);
	assertEqual(resultLength,3);
	assertEqual(strcmp(result_array[0],"hello"),0);
	assertEqual(strcmp(result_array[2],"man"),0);
	free(result_array);
};

int multiplyBy2(int x,int index,int* array){
	return x*2;
};

void test_map_returns_the_value_after_multiplyby2_of_each_element(){
	int array[6] = {2,3,4,5,6,0};
	int *result_array;
	result_array = intMap(array,6,multiplyBy2);
	assertEqual(result_array[0],4);
	free(result_array);
};

char* changeString(char* x,int index,char** array){
	int i=0;
	if(strcmp(x,"hiiiii")==0){
		return x;
	}
	return x="hmmmmmm";
};

void test_map_return_lenth_6_after_and_change_hiiiii_string_by_hmmmmm(){
	char *array[] = {"hiiiii","hiiiii","hiiiii","helliiiio","helliiiio","mannnnnn"};
	char **result_array;
	result_array = stringMap(array,6,changeString);
	assertEqual(strcmp(result_array[0],"hiiiii"),0);
	assertEqual(strcmp(result_array[5],"hmmmmmm"),0);
	free(result_array);
};

float multiplyBy3(float x,int index,float* array){
	return x*3;
};

void test_floatmap_returns_the_value_after_multiplyby2_of_each_element(){
	float array[6] = {2.1,3.7,4.8,5.0,6.9,0};
	float *result_array;
	result_array = floatMap(array,6,multiplyBy3);
	assertEqual(abs(result_array[0]),6);
	assertEqual(abs(result_array[1]),11);
	free(result_array);
};

int add(int x,int y,int index,int* array){
	return x+y;
};

void test_reduce_will_return_20(){
	int array[6] = {2,3,4,5,6,0};
	int result;
	result = intReduce(array,6,add,0);
	assertEqual(result,20);
};


char* stringConcat(char* x,char* y,int index,char** array ){
	char* result = malloc(sizeof(char)*strlen(x)+strlen(y)+1);
	strcpy(result,x);
	strcat(result,y);
	return result;
};


void test_reduceString_it_retunr_the_concanate_string_TThihihihehe(){
	char *array[] = {"hi","hi","hi","he","he"};
	char *initialValue = "TT";
	char *result;
	result = stringReduce(array,5,stringConcat,initialValue);
	assertEqual(strcmp(result,"TThihihihehe"),0);
};

char* maxLengthString(char* x,char* y,int index,char** array){
	return (strlen(x)>strlen(y))?x:y;
};

void test_reduceString_it_return_the_maxLength_string_parmatma(){
	char *array[] = {"hi","hoooi","heeei","hellll","parmatma"};
	char *initialValue = "TT";
	char *result;
	result = stringReduce(array,5,maxLengthString,initialValue);
	assertEqual(strcmp(result,"parmatma"),0);
};

char charConcat(char x,char y,int index,char* araray){
	return (x>y)?x:y;
};

void test_reduceChar_it_returns_string_Thello(){
	char array[] = {'h','e','l','l','o','\0'};
	char initialValue = 'T';
	char result;
	result = charReduce(array,5,charConcat,initialValue);
	assertEqual(result,'o');
};

void test_indexOf_will_return_the_2_index_of_r(){
	char* string = "parmatma";
	char character = 'r';
	int index;
	index = indexOf(string,character);
	assertEqual(index,2);
};

void test_stringindexOf_will_return_the_2_index_of_rma(){
	char* string = "parmatma";
	char* substring = "rma";
	int index;
	index = stringindexOf(string,substring);
	assertEqual(index,2);
};

void test_stringindexOf_will_return_the_minus_3_index_of_ram(){
	char* string = "hello";
	char* substring = "lo";
	int index;
	index = stringindexOf(string,substring);
	assertEqual(index,3);
};

void test_stringindexOf_will_return_the_3_index_of_ma(){
	char* string = "parmatma";
	char* substring = "ma";
	int index;
	index = stringindexOf(string,substring);
	assertEqual(index,3);
};