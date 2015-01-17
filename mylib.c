#include "mylib.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int fibo(int term, int *arrayOfFibo){
	static int i=0,first=-1,second=1,next;
	if(term<=0)
		return 0;
	next = first + second;
	arrayOfFibo[i] = next;
	first = second;
	second = next;
	i++;
	fibo(term-1,arrayOfFibo);
	return 1;
};

int concat(int *array1, int len_of_array1, int *array2, int len_of_array2, int **result_array){
	int i=0,result_array_len,j=0;
	result_array_len = len_of_array1+len_of_array2;
	*result_array = (int *)malloc(sizeof(int)*result_array_len);
	for(i=0;i<len_of_array1;i++){
		(*result_array)[i] = array1[i];	
	}
	for(i=len_of_array1;i<result_array_len;i++){
		(*result_array)[i] = array2[j];
		j++;
	}
	return result_array_len;
};

int filter(int *array, int length, int threshold, int **result_array){
	int i,count=0;
	for(i=0;i<length;i++){
		if(array[i]>threshold){
			count++;
		};
	};
	*result_array = malloc(sizeof(int)*count);
	for(i=0;i<count;i++)
		(*result_array)[i]=array[i];
	return count;
};

int reverse(int *array, int length,int **result_array){
	int i,count=0;
	*result_array = (int*)malloc(sizeof(int)*length);
	for(i=length-1;i>=0;i--){
		(*result_array)[count] = array[i];
		count++;
	}
	return count;
};


int slice(int *array, int length_of_array, int start_index, int end_index, int **result_array){
	int i=0,count=0,diff;
	if(start_index<0)
		start_index = 0;
	diff = end_index - start_index;
	*result_array = (int*)malloc(sizeof(int)*diff);
	for(i=0;i<length_of_array;i++){
		if((start_index>=0) && (end_index>0)){
			if(i>=start_index && i< end_index){
				(*result_array)[count]=array[i];
				count++;
			};
		};
	};
	return count;
};

int checkPrime(int i){
	int flag=0,j;
	for(j=2;j<=i/2;j++){
		if(i%j==0){flag = 1;break;};
		};
	return flag; 
};


int prime(int start, int end, int **result_array){
	int i,count=0,j,flag=0,index=0,diff;
	diff = end-start/2;
	*result_array =(int*) malloc(sizeof(int)*diff);
	if(start<2)
		start=2;
	for(i=start;i<=end;i++){
		flag = checkPrime(i);
		if(flag==0){
			(*result_array)[index]=i; count++; index++;
		};
		flag = 0;
	};
	return count;
};



int stringCompare(char *str1,char *str2){
	int length1,length2,i=0,length;
	length1 = strlen(str1);
	length2 = strlen(str2);
	length = (length1>length2)?length1:length2;
	while(i<length){
		if(str1[i]!=str2[i])
			return str1[i]-str2[i];
		i++;
	}
	return 1;
};


int forEach(int *array,int length,int (*fun)(int,int)){
	int i;
	int localArray[length]; 
	for(i=0;i<length;i++){
		localArray[i] = (*fun)(array[i],i);
	};
	for(i=0;i<length;i++){
		if(localArray[i]!=array[i])
			return 0;
	}
	return 1;
};

int stringforEach(char **array,int length,char* (*fun)(char *,int)){
	int i;
	for(i=0;i<length;i++){
		(*fun)(array[i],i);
	};
	return i;
};


int jsFilter(int* src,int srcLength,int* dst,Predicate* test){
	int i,count=0;
	for(i=0;i<srcLength;i++){
		if(test(src[i],i)){ 
			dst[count++] = src[i];
		}
	};
	return count;
};

int stringFilter(char **src,int srcLength,char** dst,stringPredicate* test){
	int dstLength=0,i,yes;
	for(i=0;i<srcLength;i++){
		if(test(src[i],i)) 
			dst[dstLength++] = src[i];
	};
	return dstLength;
};

int* intMap(int* src,int srcLength,Implement operate){
	int dstLength=0,i;
	int *dst;
	dst = (int*)malloc(sizeof(int)*srcLength);
	for(i=0;i<srcLength;i++){
		dst[dstLength++] = operate(src[i],i);
	};
	return dst; 
};

char** stringMap(char** src,int srcLength,stringImplement* test){
	int dstLength=0,i;
	char** dst;
	dst = (char**)malloc(sizeof(char*)*srcLength);
	for(i=0;i<srcLength;i++){
		dst[dstLength++] =  test(src[i],i);
	};
	return dst;
};


float* floatMap(float* src,int srcLength,floatImplement* operate){
	int dstLength=0,i;
	float* dst;
	dst = (float*)malloc(sizeof(float)*srcLength);
	for(i=0;i<srcLength;i++){
		dst[dstLength++] =  operate(src[i],i);
	};
	return dst;
};

int intReduce(int* src,int srcLength,task* operate,int initialvalue){
	int i,result;
	for(i=0;i<srcLength;i++){ 
		result = operate(initialvalue,src[i]);
		initialvalue = result;
	};
	return initialvalue;
};

char* stringReduce(char** src,int srcLength,stringConcate* operate,char* initialvalue){
	int i;
	for(i=0;i<srcLength;i++){ 
		initialvalue = operate(initialvalue,src[i]);
	}
	return initialvalue;
};

char charReduce(char* src,int srcLength,charConcate* operate,char initialvalue){
	int i;
	for(i=0;i<srcLength;i++){
		initialvalue = operate(initialvalue,src[i]);
	};
	return initialvalue;
};

int indexOf(char *string,char character){
	int index,length;
	length = strlen(string);
	for(index=0;index<length;index++){
		if(string[index]==character){ 
			break;
		}
	};
	return index;
};

int stringindexOf(char *string,char* substring){
	int index,stringLength,substringLength,i,count=0;
	char* str = malloc(sizeof(char)*strlen(string)+1);
	char* substr = malloc(sizeof(char)*strlen(string)+1);
	strcpy(str,string);
	strcpy(substr,substring);
	stringLength = strlen(string);
	substringLength = strlen(substring);
	for(index=0;index<stringLength;index++){
		for(i=0;i<substringLength;i++){
			if(str[index+i]==substr[i]){
				count++;
				if(count==substringLength)
					return index;
			};
		};
		count = 0;
	};
	return -1;
};